/************************************************************************/
/*@File Name         : 6.从有序数组中构造二叉查找树.cpp
/*@Created Date      : 2020/6/14 20:56
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

 
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode * sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())
			return nullptr;
		return arrayToBST(nums, 0, nums.size() - 1);
	}

	TreeNode* arrayToBST(vector<int>&nums,int left,int right){

		if (left > right)
			return nullptr;
		int mid = left + (right - left) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = arrayToBST(nums, left, mid - 1);
		root->right = arrayToBST(nums, mid + 1, right);
		return root;
	}
};