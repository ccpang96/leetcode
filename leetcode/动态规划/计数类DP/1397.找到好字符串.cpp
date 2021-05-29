/*
	给你两个长度为 n 的字符串 s1 和 s2 ，以及一个字符串 evil 。请你返回 好字符串 的数目。

好字符串 的定义为：它的长度为 n ，字典序大于等于 s1 ，字典序小于等于 s2 ，且不包含 evil 为子字符串。

由于答案可能很大，请你返回答案对 10^9 + 7 取余的结果。
*/

//数位统计DP：
//下界为s1,上界为s2,要求不能出现evil字符

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
		
		//先求出模式串的next数组：最长前缀和最长后缀相同的长度
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

	
	
	// 求 next 数组: 下标从0开始
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