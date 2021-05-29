/*
	字符串转为double：实现atof函数
*/

#include<iostream>
#include<string>
using namespace std;

double stringToDouble(string str) {
	int i = 0;
	int minus = 1; //正负号
	while(str[i] == ' ') i++;   //去掉前缀空格
	if (str[i] == '-') minus = -1;	//判断负数
	if (str[i] == '+' || str[i] == '-') i++;  //去掉正负号

	int result_pre = 0;		//记录整数部分
	long long  result_post = 0;	//记录小数部分
	int decimal_number = 0;
	while (i < str.size()) {
		if (isdigit(str[i])) {
			result_pre = result_pre * 10 + minus * (str[i] - '0');
			i++;
		}
		if (str[i] == '.') {
			i++;
			break;
		}
	}

	while (i < str.size())
		if (isdigit(str[i])) {
			result_post = result_post *10 + minus * (str[i] - '0');
			i++;
			decimal_number++;
		}

	return static_cast<double>(result_pre + result_post*pow(0.1,decimal_number));
}

/*
int main() {
	double res = stringToDouble("  -12.894291490077");
	//cout << res << endl;
	printf("%18.12lf\n", res);
	system("pause");
	return 0;
}*/