#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
//具体思路 编写一个split 
class Solution {
public:
	string validIPAddress(string IP) {
		if (isValidIPv4(IP)) return "IPv4";
		if (isValidIPv6(IP)) return "IPv6";
		return "Neither";
	}


	//split函数，用来分割字符串，保存在vector<string>里面 //分隔符是默认的空格，因为是单元素，一定是' '
	void split(const string s, vector<string>& vs, const char delim = ' ')
	{
		istringstream iss(s); //使用stringstream也可以， 但是输入输出状态转换容易出错
		string temp;
		while (getline(iss, temp, delim))
		{
			//vs.emplace_back(move(temp)); //速度更快
			vs.push_back(temp);                            //调用移动构造函数，掏空str，掏空后，最好不要使用str
		}
		if (!s.empty() && s.back() == delim) {
			vs.push_back({}); // !!! /加这句的原因是getline不会识别最后一个delim,避免误判"172.16.254.1." 
		}
	}
	// 1. 3个'.', 4个 0~255
	// 2. 每个数字的首字母不能为0 
	bool isValidIPv4(string IP)
	{
		vector<string> vs;
		split(IP, vs, '.'); 
		if (vs.size() != 4) return false;

		for (auto &v : vs)
		{
			if (v.empty() || (v.size() > 1 && v[0] == '0') || v.size() > 3) return false;
			for (auto c : v)
			{
				if (!isdigit(c)) return false;
			}
			int n = stoi(v);
			if (n < 0 || n > 255) return false;
		}
		return true;
	}
	//1. 7 个':',8 个16进制，0-9, a-f, A-F
	//2.  不能为空，但是也不能多余的长度
	bool isValidIPv6(string IP)
	{
		vector<string> vs;
		split(IP, vs, ':');
		if (vs.size() != 8) return false;

		for (auto &v : vs)
		{
			if (v.empty() || v.size() > 4) return false;

			for (auto c : v)
			{
				if (!(isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) return false;
			}
		}
		return true;

	}
};
