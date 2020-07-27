/************************************************************************/
/*@File Name         : 1.�ڵ��ͨ·.cpp
/*@Created Date      : 2020/6/15 17:20
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ����⿼����������ڵ�֮���Ƿ����һ��·��
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

		//���ڱ�ʶ�ýڵ��Ƿ񱻷��ʹ�
		vector<bool>visited(n, false);
		return dfs(edge, start, target, visited);
	}

	bool dfs(vector<vector<int>>&vec, int start, int target, vector<bool>&visited) {
		//��������ڵ��Ѿ������ʹ�
		visited[start] = true;

		vector<int>endFromNodes = vec[start]; //�ҵ���start�����ıߣ������յ��ǲ���
		vector<int>::iterator it;
		it = find(endFromNodes.begin(), endFromNodes.end(), target);
		if (it != endFromNodes.end())		//˵���ڵ�һ�����о��ҵ���
			return true; 
		
		//���û�ҵ����������м̽ڵ�������
		for (auto &v : endFromNodes) {
			if (!visited[v] && dfs(vec, v, target, visited))
				return true;
		}
		return false;
	}
};
 