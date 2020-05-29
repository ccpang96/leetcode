/************************************************************************/
/*@File Name         : 211. 添加与搜索单词 - 数据结构设计.cpp
/*@Created Date      : 2020/5/29 13:46
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 字典树的应用 ，匹配多个就应该考虑到使用递归的思路
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


class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {

	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		WordDictionary * root = this;
		for (const auto & m : word) {
			if (root->next[m - 'a'] == nullptr) root->next[m - 'a'] = new WordDictionary();
			root = root->next[m - 'a'];
		}
		root->is_string = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return searchWord(this, word);
			
	}
	bool searchWord(WordDictionary* root, string word) {
		//递归基在此处写
		if (word.size() == 1) {
			if (word[0] >= 'a' && word[0] <= 'z') { //如果一个是字符
				if (root->next[word[0] - 'a'] && root->next[word[0] - 'a']->is_string)
					return true;
				return false;
			}
			else {
				for (int i = 0; i < 26; i++) 
					if (root->next[i] && root->next[i]->is_string)
						return true;
					return false;
			}
		}
		else {
			if (word[0] >= 'a' && word[0] <= 'z') { //是字母
				if (root->next[word[0] - 'a'])
					return searchWord(root->next[word[0] - 'a'], word.substr(1, word.size() - 1));
				else
					return false;
			}
			else {	//是通配符
				bool result;
				for (int i = 0; i < 26; i++) {
					if (root->next[i]) {
						result = searchWord(root->next[i], word.substr(1, word.size() - 1));
						if (result) return true;
					}
				}
				return false;
			}
		}
	}
private:
	bool is_string = false;
	WordDictionary *next[26] = { nullptr };
};