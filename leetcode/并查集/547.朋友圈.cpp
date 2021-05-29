/************************************************************************/
/*@File Name         : 547. 朋友圈.cpp
/*@Created Date      : 2020/5/22 15:49
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。
所谓的朋友圈，是指所有朋友的集合。
给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。
*************************************************************************/

  

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;

 
class Solution {
public:
	//vector<int>fa;		//父亲节点'
	int fa[200];
	int find(int x) {
		if (fa[x] != x)
			fa[x] = find(fa[x]);
		return fa[x];
	}


	int findCircleNum(vector<vector<int>>& M) {

		int N = M.size();
		//初始化父节点
		for (int i = 0; i < N; i++)
			fa[i] = i;

		int res = N;		//初始化有N个圈子：谁跟谁都不是朋友
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) {
				if (M[i][j] == 0) continue;

				//节点合并 union
				int fx = find(i), fy = find(j);
				if (fx != fy) {
					fa[fx] = fy;
					res--;
				}
			}
		}
		return res;
	}
};