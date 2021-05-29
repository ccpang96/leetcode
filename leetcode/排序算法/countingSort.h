#pragma once
//ʲô�Ǽ�������
//ʱ�临�ӶȺͿռ临�Ӷȶ���O(n+k) k�����������ķ�Χ 
//��Ҫ���鳤��Ϊk��Ԫ�ش洢Ԫ�صķ�Χ
namespace CountingSort {




	//ʱ�临�Ӷ���O(n)
	//�ҵ���ǰ���������е����ֵ:Ȼ�������minValue ~maxValue֮���ÿ�����ĸ����Ƕ���
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
		int maxValue = findArrMaxValue(arr, length);  //ʱ�临�Ӷ���O(n)
		_countingSort(arr, maxValue, length); //ʱ�临�Ӷ���
	}
}
