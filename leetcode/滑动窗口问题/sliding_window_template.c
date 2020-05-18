/************************************************************************/
/*@File Name         : sliding_window.c
/*@Created Date      : 2020/5/18 14:51
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 滑动窗口问题的模板
/************************************************************************/

/* Includes *************************************************************/
#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>

using namespace std;



/************************************************************************/
/*@FullName:  slidingWindowTemplate
/*@Brief:     滑动窗口问题的模板
/*@Parameter: 输入字符串s
/*@Returns:   int : 某个长度
/*@time:      2020/5/18 15:04
/*@author:    ccpang
/************************************************************************/
int slidingWindowTemplate(string s) {

	//输入参数有效性判断
	if (...) {
		...
	}

	//申请一个散列，用于记录窗口中具体元素的个数情况
	unordered_set<char>hash;	//如果是判断是否重复的问题，也可以这样做int hash[256] = {0}; ，Ascill码的总数是256个
	

	//预处理（可省略），一般情况下是改变hash

	//l 表示左指针
	//count 记录当前的条件，具体根据题目要求定义
	//result 存放结果

	int l = 0, count = ..., result = ...,
		for (int r = 0; r < s.size(0; r++) {
			//更新元素在哈希表中的数量
			hash[s[r]]--; //hash[s[r]]++

				// 根据窗口的变更结果来改变条件值
				if (hash[s[r]] == ...) {
					count++;
				}

			// 如果当前条件不满足，移动左指针直至条件满足为止
			while (count > K || ...) {
				...
					if (...) {
						count--;
					}
				hash[A[l]]++; //滑动左窗口
				l++; //滑动左窗口
			}

			// 更新结果
			results = ...
		}
	return results;
}



/************************ (C) COPYRIGHT ccpang *****END OF FILE****/