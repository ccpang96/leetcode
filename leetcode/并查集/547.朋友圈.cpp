/************************************************************************/
/*@File Name         : 547. ����Ȧ.cpp
/*@Created Date      : 2020/5/22 15:49
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ʹ�ò��鼯union-find
/************************************************************************/

/* Includes *************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;


/************************************************************************/
/*@ Problem Name         : 547. ����Ȧ
/*@ Description 		 :������ N ��ѧ����������Щ�������ѣ���Щ���ǡ����ǵ���������Ǵ����ԡ������֪ A �� B �����ѣ�B �� C �����ѣ���ô���ǿ�����Ϊ A Ҳ�� C �����ѡ���ν������Ȧ����ָ�������ѵļ��ϡ�
����һ�� N * N �ľ��� M����ʾ�༶��ѧ��֮������ѹ�ϵ�����M[i][j] = 1����ʾ��֪�� i ���� j ��ѧ����Ϊ���ѹ�ϵ������Ϊ��֪����������������ѧ���е���֪������Ȧ������

*************************************************************************
/*@ Example1-Input	 	 :
110
110
001
/*@ Example1-Output		 : 2
/*@ Example1-Explanation :��֪ѧ��0��ѧ��1��Ϊ���ѣ�������һ������Ȧ��
��2��ѧ���Լ���һ������Ȧ�����Է���2��

*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :

/*@����˵����
/************************************************************************/

class Solution {
public:
	//vector<int>fa;		//���׽ڵ�'
	int fa[200];
	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);		//·��ѹ��
	}


	int findCircleNum(vector<vector<int>>& M) {

		int N = M.size();
		//��ʼ�����ڵ�
		for (int i = 0; i < N; i++)
			fa[i] = i;

		int res = N;		//��ʼ����N��Ȧ�ӣ�˭��˭����������
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) {
				if (M[i][j] == 0) continue;

				//�ڵ�ϲ� union
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