#pragma once
#include<exception>
#include<algorithm>
#include"SortTestHelper.h"
using namespace SortTestHelper;
namespace QuickSort {
	int partition(int arr[],   int start, int end) {
		 
	 

		int small = start - 1;
		for (int index = start; index < end; ++index) {
			if (arr[index] < arr[end]) {
				++small;
				std::swap(arr[small], arr[index]); //小值在左边 大值在右边
			}
		}
		++small;
		std::swap(arr[end], arr[small]); //再交换基准值和small
	 
		return small;
	}


	void quickSort(int arr[],int start, int end) {
		if (start == end)
			return;
		
		//交换比较点
		int index = rand() % (end - start) + start;
		swap(arr[index], arr[end]);


		
		int pirot = partition(arr,   start, end);

		if (pirot > start)
			quickSort(arr, start, pirot - 1);
		if (pirot < end)
			quickSort(arr,   pirot + 1, end);
	}
}
