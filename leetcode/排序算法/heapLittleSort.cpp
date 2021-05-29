/*
	原理：将待排序的序列构造成一大顶堆，此时整个序列的最大值就是堆顶值，然后将堆顶元素与堆数组的末尾元素交换，然后将剩余的n-1个元素重新构造成一个堆，这样就会得到
	n个元素中的次大值，反复执行，就能得到一个有序序列了.

	时间复杂度：构建堆的时间复杂度是O(n)；第i次取堆顶元素重建堆的时间是O(logn),因为需要n-1次取堆顶元素，所以重建堆的时间复杂度是O(nlogn)

	稳定性：【21 20a 20b 12 11 8 7 】对于上述数据，在将21放在最后以后，在将20放在最后变成了【7 8 11 12 20b 20a 21】

	用优先级队列构建小顶堆：priority_queue<int,vector<int>,greater<int>>LittleHeap;
*/


#include<iostream>
#include<vector>
using namespace std;


class LittleHeap {
public:

	//堆调整 node是要调整的那个节点 i是堆的大小
	void adjustHeap(vector<int>&input, int node, int length) {
		int temp = input[node];
		for (int k = 2 * node + 1; k < length; k = k * 2 + 1) {

			if (k + 1 < length && input[k + 1] < input[k])	//选择左右孩子中最大的节点
				k = k + 1;

			if (input[k] < temp) {
				input[node] = input[k]; //将子节点的值赋给父节点
				node = k;				//再对子节点进行调整
			}
			else
				break; //如果子节点都比父节点大，则不需要调整，直接退出
		}
		input[node] = temp; //让原来的父节点的值等于temp
	}


	//建堆
	void buildHeap(vector<int>&input) {
		for (int i = floor(input.size() / 2 - 1); i >= 0; i--) {  //从第一个非叶子节点开始往上调整 floor是向左取整 ceil是向右取整
			adjustHeap(input, i, input.size());
		}
	}


	void heapLittleSort(vector<int>&input) {
		buildHeap(input);

		for (int i = input.size() - 1; i > 0; i--) {
			swap(input[0], input[i]);
			adjustHeap(input, 0, i);  //i代表的是要调整的堆的大小
		}
	}
};


/*

int main() {
	vector<int>input{ 5,3,4,7,2,1,8,9,6 };
	LittleHeap().heapLittleSort(input);
	for (auto &m : input)
		cout << m << " ";
	cout << endl;
	system("pause");
	return 0;
}*/