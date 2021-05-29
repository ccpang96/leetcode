#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int aux(string& str, int& idx, int len) {
	while (idx < len && !(isdigit(str[idx]))) {
		++idx;
	}
	if (idx == len) {
		idx = -1;
		return 0;
	}
	int start = idx;
	while (idx < len && isdigit(str[idx])) {
		++idx;
	}
	string sub = str.substr(start, idx - start);
	return atoi(sub.data());
}
int main() {
	string input;
	getline(cin, input);
	int len = input.size();
	vector<int> out;
	int idx = 0;
	while (idx >= 0 && idx < len) {
		int tmp = aux(input, idx, len);
		if (idx > 0) out.emplace_back(tmp);
	}
	sort(out.begin(), out.end());
	for (auto& ele : out) {
		cout << ele << endl;
	}
	return 0;
}


//测试用例：a0125b1c0d00 He75l154lo87wor7l87d

/*

int main() {

	string s;
	cin >> s;
	int len = s.length(); //字符串长度
	int a, b, bit, num;
	int flag = 0;
	for (a = 0; a < len; a++) {
		if (s[a] >= '0'&&s[a] <= '9')//过滤掉外形是非数字的字符
		{
			flag++;
			b = a;
			num = 0;//num每次循环的初值置为0
			while (b < len&&s[b] >= '0'&&s[b] <= '9')
			{
				bit = s[b] - '0';
				num = num * 10 + bit;
				b++;
			}
			cout << num << endl;
			a = b;
		}
	}
	if (flag == 0)
		cout << "字符串中无数字" << endl;

	system("pause");
	return 0;
}*/