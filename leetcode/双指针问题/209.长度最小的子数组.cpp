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
	int minSubArrayLen(int s, vector<int>&arr) {
		if (arr.empty())
			return 0;


		int l = 0, r = 0;
		int sum = 0;

		int result = INT_MAX;
		for (; r < arr.size(); r++) {
			sum += arr[r];

			while (sum >= s) {
				result = min(result, r - l + 1);
				sum -= arr[l];
				l++;
			}
		}
		return result == INT_MAX ? 0 : result;
	}
};