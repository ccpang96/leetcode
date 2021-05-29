//�����ظ����ֵ�ȫ����
/*

����: [1,1,2]
���:
[
[1,1,2],
[1,2,1],
[2,1,1]
]

*/

#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;


class Solution {
public:
	vector<vector<int>> ans;
	vector<int> temp;
	void DFS(int index, vector<int>&nums, vector<bool>&st) {

		if (index == nums.size())
		{
			ans.push_back(temp);
			return;
		}
		unordered_set<int>hash;
		for (int i = 0; i < nums.size(); i++) {
			if (!st[i]) { //��i������û�б����ʹ�
						  //�ȼ�֦ȥ��
				
				if(hash.find(nums[i]) != hash.end())
					continue; //��ֹ
				hash.insert(nums[i]);

				temp.push_back(nums[i]);
				st[i] = true;
				DFS(index + 1, nums, st);
				//����
				st[i] = false;
				temp.pop_back();
			}
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.empty())
			return {};
		vector<bool> st(nums.size(), false);  //��ʾû�б�ʹ�ù�
		DFS(0, nums, st);
		return ans;
	}
};




/*
int main() {
	vector<int> nums{ 1, 1, 2 };
	vector<vector<int>> res = Solution().permuteUnique(nums);
	for (auto &m : res) {
		for (auto &n : m)
			cout << n << "  ";
		cout << endl;
	}
	system("pause");
	return 0;
}*/