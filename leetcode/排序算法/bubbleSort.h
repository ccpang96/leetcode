#pragma once
#include<algorithm>
#include"SortTestHelper.h"
using namespace SortTestHelper;
//冒泡属于交换排序，将最大的数冒泡到最末尾。
namespace BubbleSort {
	void bubbleSort(int arr[], int length) {
		int swapNumber = 0;
		cout << length << endl;
		for (int i = 0; i < length - 1; ++i) {
			for (int j = length - 1; j > i; --j) {
				if (arr[j] < arr[j - 1]) {
					swap(arr[j], arr[j - 1]);
					swapNumber++;
					//printArray(arr, length);
				}
			}
		}
	}
}
