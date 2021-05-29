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
	cout << "Êý×é³¤¶ÈÊÇ: " << length << endl;

	//1.²âÊÔÃ°ÅÝÅÅÐò
	cout << "*****************²âÊÔÃ°ÅÝÅÅÐò£º********************" << endl;

	printArray(arr, num);
	//bubbleSort(arr,num);
	printArray(arr, num);
	cout << endl << endl;

	//2.²âÊÔ¿ìËÙÅÅÐò ²»ÊÇ
	cout << "*****************²âÊÔ¿ìËÙÅÅÐò£º********************" << endl;
	//printArray(arr, num);
	quickSort(arr, 0,length-1);
	//printArray(arr, num);
	cout << endl << endl;

	//3.²âÊÔ²åÈëÅÅÐò ²»ÊÇ
	cout << "*****************²âÊÔ²åÈëÅÅÐò£º********************" << endl;
	printArray(arr, num);
//insertSort(arr, length);
	printArray(arr, num);
	cout << endl << endl;
	
	//4.²âÊÔÏ£¶ûÅÅÐò (ËõÐ¡ÔöÁ¿²åÈëÅÅÐò) ²»ÊÇ
	cout << "*****************²âÊÔÏ£¶ûÅÅÐò£º********************" << endl;
	printArray(arr, num);
//shellSort(arr, length);
	printArray(arr, num);
	cout << endl << endl;
	
	//5.²âÊÔÑ¡ÔñÅÅÐò
	cout << "*****************²âÊÔÑ¡ÔñÅÅÐò£º********************" << endl;
	printArray(arr, num);
//selectionSort(arr, length);
	printArray(arr, num);
	cout << endl << endl;
	
	
	
	//6.2²âÊÔÐ¡¶¥¶ÑÅÅÐò
	cout << "*****************²âÊÔ¶ÑÅÅÐò£º********************" << endl;
	printArray(arr, num);
//heapLittleSort(arr, length);
	printArray(arr, num);
	cout << endl << endl;


	//7.¹é²¢ÅÅÐò
	cout << "*****************²âÊÔ¹é²¢ÅÅÐò£º********************" << endl;
	//printArray(arr, num);
//mergeSort(arr, length);
	//printArray(arr, num);
	cout << endl << endl;

	//7.¼ÆÊýÅÅÐò
	cout << "*****************²âÊÔ¼ÆÊýÅÅÐò£º********************" << endl;
	printArray(arr, num);
//countingSort(arr, length);
	printArray(arr, num);
	cout << endl << endl;

	//8.Í°×ÓÅÅÐò
	cout << "*****************²âÊÔÍ°ÅÅÐò£º********************" << endl;
	printArray(arr, num);
//bucketSort(arr, length);
	printArray(arr, num);
	cout << endl << endl;

	//10 »ùÊýÅÅÐò
	cout << "*****************²âÊÔ»ùÊýÅÅÐò£º********************" << endl;
	printArray(arr, num);
	//radixSort(arr, length);
	printArray(arr, num);
	cout << endl << endl;

	system("pause");
	return 0;
}


*/