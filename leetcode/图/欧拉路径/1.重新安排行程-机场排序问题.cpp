/************************************************************************/
/*@File Name         : 1.重新安排行程-机场排序问题.cpp
/*@Created Date      : 2020/6/16 14:52
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 这道题的本质是求得有向图的欧拉路径。
严谨地说，一个连通有向图 G 有欧拉路径，指存在一个顶点，从它出发，沿着有向边的方向，可以不重复地遍历图中所有的边。*/
/************************************************************************/



//给定起点，求一条字典顺序最小的欧拉路径。
//使用贪心策略，优先访问字典序小的节点ATL

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<map>
using namespace std;

 


class Solution {
public:
	typedef unordered_map<string, map<string, int>>adjacent;

	vector<string>min_path;
};
