#include<vector>
#include<iostream>
using namespace std;


//不重复数字的全排列
/*

输入: [1,2,3]
输出:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
*/

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> temp;
	void DFS(int index, vector<int>&nums, vector<bool>&st) {

		if (index == nums.size()) {
			ans.push_back(temp);

			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (!st[i]) {
				temp.push_back(nums[i]);
				st[i] = true; //st[i]已经被访问
				DFS(index + 1, nums, st);
				st[i] = false; //设置成未访问
				temp.pop_back(); //回溯
			}

		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.empty())
			return {};
		vector<bool>st(nums.size(), false);
		DFS(0, nums, st);
		return ans;
	}
};

/*
int main() {
	vector<int> nums{ 1, 2, 3 };
	vector<vector<int>> res = Solution().permute(nums);
	for (auto &m : res) {
		for (auto &n : m)
			cout << n << "  ";
		cout << endl;
	}
	system("pause");
	return 0;
}*/