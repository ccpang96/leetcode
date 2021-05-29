#pragma once
//什么是计数排序：
//时间复杂度和空间复杂度都是O(n+k) k是数组中数的范围 
//需要数组长度为k的元素存储元素的范围
namespace CountingSort {




	//时间复杂度是O(n)
	//找到当前输入数组中的最大值:然后计算在minValue ~maxValue之间的每个数的个数是多少
	int  findArrMaxValue(int arr[],int length) {
		int maxValue = arr[0];
		for (int i = 0; i < length; i++) {
			if (arr[i] > maxValue)
				maxValue = arr[i];
		}
		return maxValue;
	}
	

	void _countingSort(int arr[], int maxValue,int length) {
		int *bucket = new int[maxValue + 1];
		for (int i = 0; i < maxValue + 1; ++i)
			bucket[i] = 0;

		int bucketLen = maxValue + 1;
		
		
		for (int i = 0; i < length; ++i) {
			bucket[arr[i]]++;
		}




		int sortIndex = 0;
		for (int j = 0; j < bucketLen; j++) {
			while (bucket[j] > 0) {
				arr[sortIndex] = j;
				sortIndex++;
				bucket[j]--;
			}
		}
		delete []bucket;
	}

	void countingSort(int arr[], int length) {
		int maxValue = findArrMaxValue(arr, length);  //时间复杂度是O(n)
		_countingSort(arr, maxValue, length); //时间复杂度是
	}
}
