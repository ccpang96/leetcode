/*
#include<cmath>
#include<vector>
#include"insertionSort.h"
using namespace SortTestHelper;
//δ���Ͱ����
using std::vector;

namespace BucketSort {

	//���arr�����е����ֵ
	int getArrMaxValue(int arr[], int length) {
		int maxValue = arr[0];
		for (int i = 0; i < length; i++) {
			if (arr[i] > maxValue)
				maxValue = arr[i];
		}
		return maxValue;
	}

	//���arr�����е���Сֵ��
	int getArrMinValue(int arr[], int length) {
		int minValue = arr[0];
		for (int i = 0; i < length; i++) {
			if (arr[i] < minValue)
				minValue = arr[i];
		}
		return minValue;
	}




	//bucketSize:Ͱ������
	void _bucketSort(int arr[], int length,int minValue,int maxValue,int bucketSize) {
		if (length <= 0)
			return;
		//int DEFAULT_BUCKET_SIZE = 5; //Ĭ��Ͱ�ӵ�����
		//������СΪbucketCount��С��Ͱ����
		int bucketCount = floor((maxValue - minValue) / bucketSize) + 1;
		
		int **buckets = new int *[bucketSize];
		for (int i = 0; i < bucketSize; i++)
			buckets[i] = new int[bucketCount];
		//ȫ����ʼ��Ϊ0
		for (int i = 0; i < bucketSize; i++)
			for (int j = 0; j < bucketCount; j++)
				buckets[i][j] = 0;

	//	vector<vector<int>>buckets;

		//��arr�����е���ӳ�䵽bucket��
		for (int i = 0; i < length; i++) {
			int bucket_number = (arr[i] - minValue) % bucketSize;
			int bucket_size = sizeof(buckets[bucket_number]) / sizeof(buckets[bucket_number][0]);
			buckets[bucket_number][bucket_size] = arr[i];
		}
		
		int sortIndex = 0;
		//��ÿ��Ͱ��������
		for (int i = 0; i < bucketSize; i++) {
			int bucket_length = sizeof(buckets[i]) / sizeof(buckets[i][0]);
			insertSort(buckets[i], bucket_length);
			for (int j = 0; j < bucket_length; j++)
				arr[sortIndex++] = buckets[i][j];
		}
		for(int j =0;j< bucketSize;j++)
		delete[] buckets[j];
	}

	void bucketSort(int arr[], int length) {
		int minValue = getArrMinValue(arr, length);
		cout << minValue << endl;
		int maxValue = getArrMaxValue(arr, length);
		cout << maxValue << endl;
		_bucketSort(arr, length, minValue, maxValue, 5);
	}
}
*/