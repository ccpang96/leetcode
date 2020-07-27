/************************************************************************/
/*@File Name         : 4.课程表II.cpp
/*@Created Date      : 2020/6/16 9:38
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 本题需要返回的是学习课程的顺序
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
		vector<int>indregee(numCourses); //入度表
		vector<vector<int>>vec(numCourses); //邻接矩阵
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