/************************************************************************/
/*@File Name         : 2.判断二分图.cpp
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
		vector<int>cols(N, 0);	//用于确定是否染色
		for (int i = 0; i < N; i++) {
			if (cols[i] == 0 && !bfs(graph, i, 1, cols)) {	//cols[i]==0:代表节点是未被访问过的；代表从i节点出发，未出现false，即没有出现两个相连的节点是同色的。
				return false;
			}
		}
		return true;
	}

	bool bfs(vector<vector<int>>& graph, int cur, int col, vector<int>&cols) {
		cols[cur] = col; //染色 
 		for (auto j : graph[cur]) {
			if (cols[j] == cols[cur])
				return false;
			if (cols[j] == 0 && !bfs(graph, j, -col, cols))	//这里是说虽然相连节点不同色，但是与相连节点相连的节点是同色的
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


 

 