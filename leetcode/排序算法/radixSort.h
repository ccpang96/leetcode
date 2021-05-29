#pragma once
//基数排序:原理是通过将整数按位数切割成不同的数字，然后按每个位数分别比较。 根据键值的每位数字来分配桶

//求出数组的最大位数：
#include"SortTestHelper.h"
using namespace SortTestHelper;
//时间复杂度为O(n)


namespace RadixSort {
	int maxBit(int arr[], int n) {

		//先求出最大数再求出最大位数
		int maxData = arr[0];
		for (int i = 1; i < n; i++) {
			if (arr[i] > maxData)
				maxData = arr[i];
		}

		int d = 1;
		int  p = 10;
		while (maxData >= p) {
			maxData /= 10;
			d++;
		}
		return d;
	}

	void radixSort(int arr[], int n) {
		int digit = maxBit(arr, n);  //最大位数
		int *temp = new int[n];
		int *count = new int[n];
		int j, k;
		int radix = 1;

		//// 按照从低位到高位的顺序执行排序过程 :首先对个位数进行排序，然后再进行对10位数进行排序。。。。。。
		for (int d = 1; d <= digit; d++) {

			//置空各个桶的数据统计
			for (j = 0; j < 10; j++)
				count[j] = 0; //每次分配前清空计数器]


							  //统计每个桶中的记录数
			for (j = 0; j < n; j++)
			{
				k = (arr[j] / radix) % 10;
				count[k]++;
			}

			//将tmp中的位置依次分配给每个桶
			for (j = 1; j < 10; j++)
				count[j] = count[j - 1] + count[j];

			//将所有桶中记录依次收集到tmp中
			for (j = n - 1; j >= 0; j--)
			{
				k = (arr[j] / radix) % 10;
				temp[count[k] - 1] = arr[j];
				count[k]--;

			}

			for (j = 0; j < n; j++) //将临时数组的内容复制到data中
				arr[j] = temp[j];
			radix = radix * 10;

			
		}
		delete[]temp;
		delete[]count;
	}

}
