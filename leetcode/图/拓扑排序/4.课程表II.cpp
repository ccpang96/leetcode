/************************************************************************/
/*@File Name         : 4.�γ̱�II.cpp
/*@Created Date      : 2020/6/16 9:38
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ������Ҫ���ص���ѧϰ�γ̵�˳��
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
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int>indregee(numCourses); //��ȱ�
		vector<vector<int>>vec(numCourses); //�ڽӾ���
		for (int i = 0; i < prerequisites.size(); i++) {
			vec[prerequisites[i][1]].push_back(prerequisites[i][0]);
			indregee[prerequisites[i][0]]++;
		}
		return bfs(vec, indregee, numCourses);
	}

	vector<int> bfs(vector<vector<int>>&vec, vector<int>&indregee, int numCourses) {
		queue<int>q1;
		vector<int>result;
		for (int i = 0; i < indregee.size(); i++) {
			if (indregee[i] == 0)
				q1.push(i);
		}
		while (!q1.empty()) {
			int cur = q1.front();
			numCourses--;
			result.push_back(cur);
			q1.pop();
			for (int i = 0; i < vec[cur].size(); i++) {
				indregee[vec[cur][i]]--;
				if (indregee[vec[cur][i]] == 0)
					q1.push(vec[cur][i]);
			}
		}
		if (numCourses != 0)
			result.clear();
		return result;
	}
};