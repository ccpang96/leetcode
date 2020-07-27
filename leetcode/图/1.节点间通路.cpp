/************************************************************************/
/*@File Name         : 1.节点间通路.cpp
/*@Created Date      : 2020/6/15 17:20
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 这个题考查的是两个节点之间是否存在一条路径
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
	bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
		if (graph.empty())
			return false;
		vector<vector<int>>edge;
		int size = graph.size();
		for (int i = 0; i < size; i++) {
			edge[graph[i][0]].push_back(graph[i][1]);
		}

		//用于标识该节点是否被访问过
		vector<bool>visited(n, false);
		return dfs(edge, start, target, visited);
	}

	bool dfs(vector<vector<int>>&vec, int start, int target, vector<bool>&visited) {
		//表明这个节点已经被访问过
		visited[start] = true;

		vector<int>endFromNodes = vec[start]; //找到从start出发的边，看看终点是不是
		vector<int>::iterator it;
		it = find(endFromNodes.begin(), endFromNodes.end(), target);
		if (it != endFromNodes.end())		//说明在第一条边中就找到了
			return true; 
		
		//如果没找到，继续在中继节点往下找
		for (auto &v : endFromNodes) {
			if (!visited[v] && dfs(vec, v, target, visited))
				return true;
		}
		return false;
	}
};
 