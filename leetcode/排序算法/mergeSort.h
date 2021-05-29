#pragma once
#include<iostream>
#include<cmath>
#include"SortTestHelper.h"
using namespace SortTestHelper;

//Ӧ����ִ�й鲢�Ĺ�����ʼ��ʹ��һ��temp���飬������������Ĵ����Ϳ�������
namespace MergeSort {
	void merge(int *arr, int start, int mid, int end, int *temp) {
		int i = start;
		int j = mid + 1;
		int t = 0;
		while (i <= mid && j <= end) {
			if (arr[i] <= arr[j])  //��֤�˹鲢�������ȶ���
				temp[t++] = arr[i++];
			else
				temp[t++] = arr[j++];
		}
		while (i <= mid)
			temp[t++] = arr[i++];

		while (j <= end)
			temp[t++] = arr[j++];

		t = 0;
		while (start <= end)
			arr[start++] = temp[t++];
	}

	void _mergesort(int *arr, int start, int end, int *temp) {
		if (start >= end)
			return;
		int mid = start + (end - start) / 2;

		//�ݹ����
		_mergesort(arr, start, mid, temp); //�˴���mid
		_mergesort(arr, mid + 1, end, temp);

		//�Ż����������Ͳ���Ҫ�ٹ鲢��
		if (arr[mid] < arr[mid + 1])
			return;

		merge(arr, start, mid, end, temp);
	}

	void mergeSort(int *arr, int length) {
		//O(n)�Ŀռ�

		int *temp = new int[length];

		_mergesort(arr, 0, length - 1, temp);

		temp = nullptr;  //��ֹҰָ��
		delete[]temp;	//��ֹ�ڴ�й¶

	}



}
