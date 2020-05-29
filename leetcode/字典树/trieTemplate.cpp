/************************************************************************/
/*@File Name         : trieTemplate.cpp
/*@Created Date      : 2020/5/29 13:41
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :�ֵ�����ģ��
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


class Trie
{
private:
	bool is_string = false;			//��ʾ����һ���ַ�����
	Trie* next[26] = { nullptr };
public:
	Trie() {}

	void insert(const string& word)//���뵥��
	{
		Trie* root = this;
		for (const auto& w : word) {
			if (root->next[w - 'a'] == nullptr) root->next[w - 'a'] = new Trie();
			root = root->next[w - 'a'];
		}
		root->is_string = true;
	}

	bool search(const string& word)//���ҵ���
	{
		Trie* root = this;
		for (const auto& w : word) {
			if (root->next[w - 'a'] == nullptr)	return false;
			root = root->next[w - 'a'];
		}
		return root->is_string;
	}

	bool startsWith(const string& prefix)//����ǰ׺
	{
		Trie* root = this;
		for (const auto& p : prefix) {
			if (root->next[p - 'a'] == nullptr)return false;
			root = root->next[p - 'a'];
		}
		return true;
	}
};


//int main() {
//
//	Trie* trie = new Trie();
//
//	trie->insert("apple");
//	cout << trie->search("apple") << endl;   // ���� true
//	cout << trie->search("app") << endl;     // ���� false
//	cout << trie->startsWith("app") << endl; // ���� true
//	trie->insert("app");
//	cout << trie->search("app") << endl;     // ���� true
//
//	system("pause");
//	return 0;
//}