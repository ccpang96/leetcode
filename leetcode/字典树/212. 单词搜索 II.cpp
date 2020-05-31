/************************************************************************/
/*@File Name         : 212. 单词搜索 II.cpp
/*@Created Date      : 2020/5/29 15:07
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 使用字典树和DFS解决这个问题
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
	int rows, cols;
	vector<string> res;
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		rows = board.size();
		cols = rows ? board[0].size() : 0;
		if (rows == 0 || cols == 0) return res;

		//建立字典树的模板
		TrieNode* root = new TrieNode();
		for (string word : words) {
			TrieNode *cur = root;
			for (int i = 0; i < word.size(); ++i) {
				int idx = word[i] - 'a';
				if (cur->nodes[idx] == 0) cur->nodes[idx] = new TrieNode();
				cur = cur->nodes[idx];
			}
			cur->word = word;
		}

		//DFS模板
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				dfs(board, root, i, j);
			}
		}
		return res;
	}

	void dfs(vector<vector<char>>& board, TrieNode* root, int x, int y) {
		char c = board[x][y];
		//递归边界
		if (c == '.' || root->nodes[c - 'a'] == 0) return;
		root = root->nodes[c - 'a'];
		if (root->word != "") {
			res.push_back(root->word);
			root->word = "";
		}

		board[x][y] = '.';
		if (x > 0) dfs(board, root, x - 1, y);
		if (y > 0) dfs(board, root, x, y - 1);
		if (x + 1 < rows) dfs(board, root, x + 1, y);
		if (y + 1 < cols) dfs(board, root, x, y + 1);
		board[x][y] = c;
	}
};
