/*
	������������Ϊ n ���ַ��� s1 �� s2 ���Լ�һ���ַ��� evil �����㷵�� ���ַ��� ����Ŀ��

���ַ��� �Ķ���Ϊ�����ĳ���Ϊ n ���ֵ�����ڵ��� s1 ���ֵ���С�ڵ��� s2 ���Ҳ����� evil Ϊ���ַ�����

���ڴ𰸿��ܴܺ����㷵�ش𰸶� 10^9 + 7 ȡ��Ľ����
*/

//��λͳ��DP��
//�½�Ϊs1,�Ͻ�Ϊs2,Ҫ���ܳ���evil�ַ�

#include<iostream>
#include<vector>

using namespace std;
#define mst(x, a) memset(x, a, sizeof(x))

typedef long long ll;
const ll mod = 1e9 + 7;

ll dp[510][51][2];
int ne[55] = { 0 };

class Solution {
public:
	int findGoodStrings(int n, string s1, string s2, string evil) {
		
		//�����ģʽ����next���飺�ǰ׺�����׺��ͬ�ĳ���
		build(evil);

		// --s1 
		bool flag = false;
		for (int i = n - 1; i >= 0; i--) {
			if (s1[i] > 'a') {
				s1[i]--;
				flag = true;
				break;
			}
			else {
				s1[i] = 'z';
			}
		}

		if (flag) {
			return (helper(n, s2, evil) - helper(n, s1, evil) ) % mod;
		}
		else {
			return helper(n, s2, evil);
		}
	}

	int helper(int n, const string& s, const string& evil) {
		// printf("%s\n", s.c_str());
		mst(dp, 0);
		dp[0][0][1] = 1;
		for (int i = 0; i < n; i++) {
			for (int state = 0; state < evil.size(); state++) {
				for (char c = 'a'; c <= 'z'; c++) {
					int ns = getNextState(state, c, evil);
					dp[i + 1][ns][0] = (dp[i + 1][ns][0] + dp[i][state][0]) % mod;
				}
				for (char c = 'a'; c < s[i]; c++) {
					int ns = getNextState(state, c, evil);
					dp[i + 1][ns][0] = (dp[i + 1][ns][0] + dp[i][state][1]) % mod;
				}
				int ns = getNextState(state, s[i], evil);
				dp[i + 1][ns][1] = (dp[i + 1][ns][1] + dp[i][state][1]) % mod;
			}
		}

		int ans = 0;
		for (int i = 0; i < evil.size(); i++) {
			ans = (ans + dp[n][i][0]) % mod;
			ans = (ans + dp[n][i][1]) % mod;
		}
		return ans;
	}

	int getNextState(int state, char c, const string& evil) {
		int j = state;
		while (~j && evil[j] != c) j = ne[j];
		return j + 1;
	}

	
	
	// �� next ����: �±��0��ʼ
	void build(const string &p) {
		int n = p.length();
		
		
		for (int i = 1, j = -1; i < n; ++i) {
			while (j != -1  && p[i] != p[j+1]) j = ne[j];
			if (p[i] == p[j+1]) ++j;
			ne[i] = j;
		}
		
		for (auto &m : ne)
			cout << m << " ";
	}

	/*
	  void build(const string &pattern){
		int n = pattern.length();
		ne.resize(n + 1);
		for (int i = 0, j = ne[0] = -1; i < n; ne[++i] = ++j){
			while(~j && pattern[j] != pattern[i]) j = ne[j];
		}

		for (auto &m : ne)
			cout << m << " ";
	}
	*/

};

/*
int main() {
	
	int n = 8; 
	string s1 = "leetcode";
	string s2 = "leetgoes";
	string evil = "sdka";

	int result = Solution().findGoodStrings(n, s1, s2, evil);
	cout << result << endl;


	system("pause");
	return 0;
}*/