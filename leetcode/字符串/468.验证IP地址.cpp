#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
//����˼· ��дһ��split 
class Solution {
public:
	string validIPAddress(string IP) {
		if (isValidIPv4(IP)) return "IPv4";
		if (isValidIPv6(IP)) return "IPv6";
		return "Neither";
	}


	//split�����������ָ��ַ�����������vector<string>���� //�ָ�����Ĭ�ϵĿո���Ϊ�ǵ�Ԫ�أ�һ����' '
	void split(const string s, vector<string>& vs, const char delim = ' ')
	{
		istringstream iss(s); //ʹ��stringstreamҲ���ԣ� �����������״̬ת�����׳���
		string temp;
		while (getline(iss, temp, delim))
		{
			//vs.emplace_back(move(temp)); //�ٶȸ���
			vs.push_back(temp);                            //�����ƶ����캯�����Ϳ�str���Ϳպ���ò�Ҫʹ��str
		}
		if (!s.empty() && s.back() == delim) {
			vs.push_back({}); // !!! /������ԭ����getline����ʶ�����һ��delim,��������"172.16.254.1." 
		}
	}
	// 1. 3��'.', 4�� 0~255
	// 2. ÿ�����ֵ�����ĸ����Ϊ0 
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
	//1. 7 ��':',8 ��16���ƣ�0-9, a-f, A-F
	//2.  ����Ϊ�գ�����Ҳ���ܶ���ĳ���
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
