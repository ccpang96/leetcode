/************************************************************************/
/*@File Name         : 121.������Ʊ�����ʱ��.cpp
/*@Created Date      : 2020/7/8 8:46
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


int max(vector<int>& input) {
	int minPrice = INT_MAX;
	int maxProfit = 0;
	for (int price : input) {
		maxProfit = max(maxProfit, price - minPrice);  //��¼��������
		minPrice = min(minPrice, price);  //��¼��С������ʱ��
	}
	return maxProfit;
}