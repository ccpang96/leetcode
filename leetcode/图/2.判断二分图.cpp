/************************************************************************/
/*@File Name         : 2.�ж϶���ͼ.cpp
/*@Created Date      : 2020/6/16 8:00
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/



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
	bool isBipartite(vector<vector<int>>& graph) {
		int N = graph.size();
		vector<int>cols(N, 0);	//����ȷ���Ƿ�Ⱦɫ
		for (int i = 0; i < N; i++) {
			if (cols[i] == 0 && !bfs(graph, i, 1, cols)) {	//cols[i]==0:����ڵ���δ�����ʹ��ģ������i�ڵ������δ����false����û�г������������Ľڵ���ͬɫ�ġ�
				return false;
			}
		}
		return true;
	}

	bool bfs(vector<vector<int>>& graph, int cur, int col, vector<int>&cols) {
		cols[cur] = col; //Ⱦɫ 
 		for (auto j : graph[cur]) {
			if (cols[j] == cols[cur])
				return false;
			if (cols[j] == 0 && !bfs(graph, j, -col, cols))	//������˵��Ȼ�����ڵ㲻ͬɫ�������������ڵ������Ľڵ���ͬɫ��
				return false;
		}
		return true;
	}
};
//
//int main() {
//	vector<vector<int>>graph{ {1,3},{0,2},{1,3},{0,2} };
//	bool result = Solution().isBipartite(graph);
//	system("pause");
//	return 0;
//}


 

 