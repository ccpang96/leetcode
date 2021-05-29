#include<iostream>
#include"SortTestHelper.h"
#include"bubbleSort.h"
#include"quickSort.h"
#include"insertionSort.h"
#include"shellSort.h"
#include"selectionSort.h"
#include"mergeSort.h"
#include"countingSort.h"
#include"bucketSort.h"
#include"radixSort.h"
using namespace std;
using namespace SortTestHelper;
using namespace BubbleSort;
using namespace QuickSort;
using namespace ShellSort;
using namespace SelectionSort;

using namespace MergeSort;
using namespace CountingSort;
using namespace RadixSort;
/*
int main() {
	const int num = 9;
	int arr[num] = { 25,84,21,47,15,27,68,35,20};
	int length = sizeof(arr) / sizeof(arr[0]);
	cout << "���鳤����: " << length << endl;

	//1.����ð������
	cout << "*****************����ð������********************" << endl;

	printArray(arr, num);
	//bubbleSort(arr,num);
	printArray(arr, num);
	cout << endl << endl;

	//2.���Կ������� ����
	cout << "*****************���Կ�������********************" << endl;
	//printArray(arr, num);
	quickSort(arr, 0,length-1);
	//printArray(arr, num);
	cout << endl << endl;

	//3.���Բ������� ����
	cout << "*****************���Բ�������********************" << endl;
	printArray(arr, num);
//insertSort(arr, length);
	printArray(arr, num);
	cout << endl << endl;
	
	//4.����ϣ������ (��С������������) ����
	cout << "*****************����ϣ������********************" << endl;
	printArray(arr, num);
//shellSort(arr, length);
	printArray(arr, num);
	cout << endl << endl;
	
	//5.����ѡ������
	cout << "*****************����ѡ������********************" << endl;
	printArray(arr, num);
//selectionSort(arr, length);
	printArray(arr, num);
	cout << endl << endl;
	
	
	
	//6.2����С��������
	cout << "*****************���Զ�����********************" << endl;
	printArray(arr, num);
//heapLittleSort(arr, length);
	printArray(arr, num);
	cout << endl << endl;


	//7.�鲢����
	cout << "*****************���Թ鲢����********************" << endl;
	//printArray(arr, num);
//mergeSort(arr, length);
	//printArray(arr, num);
	cout << endl << endl;

	//7.��������
	cout << "*****************���Լ�������********************" << endl;
	printArray(arr, num);
//countingSort(arr, length);
	printArray(arr, num);
	cout << endl << endl;

	//8.Ͱ������
	cout << "*****************����Ͱ����********************" << endl;
	printArray(arr, num);
//bucketSort(arr, length);
	printArray(arr, num);
	cout << endl << endl;

	//10 ��������
	cout << "*****************���Ի�������********************" << endl;
	printArray(arr, num);
	//radixSort(arr, length);
	printArray(arr, num);
	cout << endl << endl;

	system("pause");
	return 0;
}


*/