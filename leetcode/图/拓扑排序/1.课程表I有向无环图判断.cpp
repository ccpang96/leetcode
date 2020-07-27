/************************************************************************/
/*@File Name         : 3.课程表I.cpp
/*@Created Date      : 2020/6/16 8:50
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 边缘条件中放置的是[1,0]
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

 


//判断有向无环图
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {



		//构建入度表，即有多少个节点连向自己
		vector<int>indegree(numCourses);
		//先转换为邻接矩阵的形式
		vector<vector<int>>vec(numCourses);
		for (int i = 0; i < prerequisites.size(); i++) {
			vec[prerequisites[i][1]].push_back(prerequisites[i][0]); //从一指向0的边；
			indegree[prerequisites[i][0]]++; //	[i][0]才是终点
		}

		
		return bfs(vec, indegree, numCourses);



	}


	//将入度为0的节点加入队列，然后将其出队，然后遍历与其相连的节点，减小其入度，如果还有入度不为0的节点，那么存在环
	bool bfs(vector<vector<int>>&vec, vector<int>&indegree, int numCourses) {
		queue<int>q1;
		for (int i = 0; i < indegree.size(); i++) {
			if (indegree[i] == 0)
				q1.push(i);		//入度为0的入队
		}
		while (!q1.empty()){
			int cur = q1.front();
			numCourses--;
			q1.pop();
			//将与cur节点相连的所有节点的入度减小1
			for (int i = 0; i < vec[cur].size(); i++) {
				indegree[vec[cur][i]]--;
				if (indegree[vec[cur][i]] == 0)
					q1.push(vec[cur][i]);
			}
		}
		return numCourses == 0;
	}
};