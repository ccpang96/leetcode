/*
����һ���ǿյ��ַ������ж����Ƿ����������һ���Ӵ��ظ���ι��ɡ��������ַ���ֻ����СдӢ����ĸ�����ҳ��Ȳ�����10000��
*/

//���ȹ���s+s��Ȼ����s+s�в���s��������ֵ�λ�øպ�Ϊs.size()����ô�����ظ����Ӵ����ɣ������ǡ�

#include<string>
using std::string;

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		return (s + s).find(s, 1) != s.size();
	}
};