
//������������Ų��

#include"SortTestHelper.h"
using namespace SortTestHelper;

void insertSort(int arr[],int length) {
	if (arr == nullptr || length < 0)
		return;

	for (int i = 1; i < length; i++) {
		int preIndex = i - 1;
		int current = arr[i]; //������O(1)�ռ䱣���˵�ǰֵ
		while (preIndex >= 0 && arr[preIndex] > current) { //��arr[i]���ǰ���ֵ��������Ų��
			arr[preIndex+1] = arr[preIndex];
			preIndex--; //������ǰ��
		}
		arr[preIndex + 1] = current; //����ǰֵ���뵽��λ��
		printArray(arr, length);
	}
}
