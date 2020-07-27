/************************************************************************/
/*@File Name         : 5.��Ļ����Ӵ�.cpp
/*@Created Date      : 2020/6/26 9:03
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

 

class Solution {
public:
	string longestPalindrome(string s) {

		string ans;
		vector<vector<bool>>dp(s.size(), vector<bool>(s.size(), false));
		for (int l = 0; l < s.size(); l++) {
			for (int i = 0; i + l < s.size(); i++) {
				int j = i + l;

				//�Խ������
				if (l == 0) {
					dp[i][j] = true;
				}
				//�ζԽ�������������ַ��������ţ��Ƿ��ǻ���ȡ���������ַ����Ƿ����
				else if (l == 1) {
					dp[i][j] = (s[i] == s[j]);
				}
				//����������
				else {
					dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]); //�ӶԽ��������½ǵ���
				}


				if (dp[i][j] && l + 1 > ans.size()) {
					ans = s.substr(i, l + 1); //��i
				}

			}
		}
		return ans;

	}
};


//int main() {
//	string input = "babad";
//	string result = Solution().longestPalindrome(input);
//	cout << result << endl;
//
//	system("pause");
//	return 0;
//}