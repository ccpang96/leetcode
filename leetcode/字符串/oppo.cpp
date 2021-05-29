#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t;
int n;


int func(int start,int end, vector<int>&arr) {
	int res = 0;
	int d = (end - start) / (arr.size() - 1);
	for (int i = 1; i < arr.size(); i++) {
		if (abs(arr[i] - start) > 1 + d) {
			return -1;
		}
		else {
			res += abs(arr[i] - start);
			start = start + d;
		}
	}
	return res;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>arr(n,0);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr.begin(), arr.end());  //ÏÈÅÅ¸öĞò
		int len = arr.size();
		
		int result = INT_MAX;
		int res = 0;
		
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				res = func(arr[0]+ i , arr[len - 1] + j, arr);
				if(res != -1)
					result = min(result, res);
			}
			
		}
		
		cout << result << endl;
	}
	system("pause");
	return 0;
}