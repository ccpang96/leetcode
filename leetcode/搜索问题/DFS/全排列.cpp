/*
给定一个整数n，将数字1~n排成一排，将会有很多种排列方法。现在，请你按照字典序将所有的排列方法输出。

输入格式
共一行，包含一个整数n。

输出格式
按字典序输出所有排列方案，每个方案占一行。
数据范围

1≤n≤7

输入样例：

3

输出样例：

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1


*/



#include<iostream>

const int N = 10;
bool st[N]; //表示该点是否被用过
int path[N]; //表示全排列的路径

/*
int n;

void dfs(int x) {

	//当x=n时，表示已经到达叶子节点
	if (x == n) {
		for (int i = 0; i < n; i++) {
			printf("%d ", path[i]);
		}
		puts(" ");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!st[i]) {
			path[x] = i;
			st[i] = true;

			dfs(x + 1);
			//恢复现场
			st[i] = false;
		}
	}
}


int main() {

	scanf("%d", &n);

	dfs(0);


	return 0;
}

#include<vector>
using namespace std;
class Solution {
public:
	
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>>result;

		vector<bool>st(nums.size(), false);
		if (nums.empty())
			return result;
		vector<int>path;
		dfs(0,result,st,path);
		return result;
	}

	void dfs(int x, vector<vector<int>>&result, vector<bool>&st,vector<int>&path) {
		
		//递归出口
		if (x == n) {
			result.push_back(path);
			return;
		}

		for (int i = 1; i <= n; i++) {
			if (!st[i]) {  //如果i还没有被访问过
				path[i] = i;
				st[i] = true;

				dfs(x + 1,result,st,path); 
				//恢复现场
				st[i] = false;
			}
		}
	}
};*/