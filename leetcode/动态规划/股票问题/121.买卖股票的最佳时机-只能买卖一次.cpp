/************************************************************************/
/*@File Name         : 121.买卖股票的最佳时机.cpp
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
		maxProfit = max(maxProfit, price - minPrice);  //记录最大的利润
		minPrice = min(minPrice, price);  //记录最小的卖出时间
	}
	return maxProfit;
}