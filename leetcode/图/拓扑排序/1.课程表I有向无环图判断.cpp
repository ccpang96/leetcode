/************************************************************************/
/*@File Name         : 3.�γ̱�I.cpp
/*@Created Date      : 2020/6/16 8:50
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ��Ե�����з��õ���[1,0]
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

 


//�ж������޻�ͼ
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {



		//������ȱ����ж��ٸ��ڵ������Լ�
		vector<int>indegree(numCourses);
		//��ת��Ϊ�ڽӾ������ʽ
		vector<vector<int>>vec(numCourses);
		for (int i = 0; i < prerequisites.size(); i++) {
			vec[prerequisites[i][1]].push_back(prerequisites[i][0]); //��һָ��0�ıߣ�
			indegree[prerequisites[i][0]]++; //	[i][0]�����յ�
		}

		
		return bfs(vec, indegree, numCourses);



	}


	//�����Ϊ0�Ľڵ������У�Ȼ������ӣ�Ȼ��������������Ľڵ㣬��С����ȣ����������Ȳ�Ϊ0�Ľڵ㣬��ô���ڻ�
	bool bfs(vector<vector<int>>&vec, vector<int>&indegree, int numCourses) {
		queue<int>q1;
		for (int i = 0; i < indegree.size(); i++) {
			if (indegree[i] == 0)
				q1.push(i);		//���Ϊ0�����
		}
		while (!q1.empty()){
			int cur = q1.front();
			numCourses--;
			q1.pop();
			//����cur�ڵ����������нڵ����ȼ�С1
			for (int i = 0; i < vec[cur].size(); i++) {
				indegree[vec[cur][i]]--;
				if (indegree[vec[cur][i]] == 0)
					q1.push(vec[cur][i]);
			}
		}
		return numCourses == 0;
	}
};