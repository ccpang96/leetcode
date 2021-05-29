

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>

using namespace std;

 

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	if (intervals.size() <= 1)
		return intervals;

	sort(intervals.begin(), intervals.end(), [=](vector<int>&i, vector<int>&j) {return i[0] < j[0]; });

	vector<int>cur(2, 0);
	vector<vector<int>>result;
	cur = intervals[0];
	for (int i = 1; i < intervals.size(); i++) {
		if (intervals[i][1] <= cur[1]) { //d落入ab之中，继续判断
			cur[1] = cur[1];
		}
		else if (intervals[i][0] >= cur[0] && intervals[i][0] <= cur[1]) { //c在ab之中且d不在ab之中，	可以合并
			cur[1] = intervals[i][1];
		}
		else {
			result.push_back(cur);
			cur = intervals[i];
		}
	}
	result.push_back(cur);
	return result;
}



