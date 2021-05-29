/*
	给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";

		int m = num1.size(), n = num2.size();
		vector<int>arr(m + n, 0);

		//先计算一个乘法 时间复杂度O(m*n) 空间复杂度O(m+n)
		for (int i = m - 1; i >= 0; i--) {
			int x = num1[i] - '0';
			for (int j = n - 1; j >= 0; j--) {
				int y = num2[j] - '0';
				arr[i + j + 1] += x * y;
			}
		}

		//将数除掉
		for (int i = m + n - 1; i > 0; i--) {
			arr[i - 1] += arr[i] / 10;
			arr[i] = arr[i] % 10;
		}

		int index = arr[0] == 0 ? 1 : 0;
		string result;
		for (int i = index; i < m + n - 1; i++) {
			result.push_back(arr[i] + '0');
		}
		return result;
	}
};

 