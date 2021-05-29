#pragma once
//��������:ԭ����ͨ����������λ���и�ɲ�ͬ�����֣�Ȼ��ÿ��λ���ֱ�Ƚϡ� ���ݼ�ֵ��ÿλ����������Ͱ

//�����������λ����
#include"SortTestHelper.h"
using namespace SortTestHelper;
//ʱ�临�Ӷ�ΪO(n)


namespace RadixSort {
	int maxBit(int arr[], int n) {

		//������������������λ��
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
		int digit = maxBit(arr, n);  //���λ��
		int *temp = new int[n];
		int *count = new int[n];
		int j, k;
		int radix = 1;

		//// ���մӵ�λ����λ��˳��ִ��������� :���ȶԸ�λ����������Ȼ���ٽ��ж�10λ���������򡣡���������
		for (int d = 1; d <= digit; d++) {

			//�ÿո���Ͱ������ͳ��
			for (j = 0; j < 10; j++)
				count[j] = 0; //ÿ�η���ǰ��ռ�����]


							  //ͳ��ÿ��Ͱ�еļ�¼��
			for (j = 0; j < n; j++)
			{
				k = (arr[j] / radix) % 10;
				count[k]++;
			}

			//��tmp�е�λ�����η����ÿ��Ͱ
			for (j = 1; j < 10; j++)
				count[j] = count[j - 1] + count[j];

			//������Ͱ�м�¼�����ռ���tmp��
			for (j = n - 1; j >= 0; j--)
			{
				k = (arr[j] / radix) % 10;
				temp[count[k] - 1] = arr[j];
				count[k]--;

			}

			for (j = 0; j < n; j++) //����ʱ��������ݸ��Ƶ�data��
				arr[j] = temp[j];
			radix = radix * 10;

			
		}
		delete[]temp;
		delete[]count;
	}

}
