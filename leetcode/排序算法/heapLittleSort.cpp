/*
	ԭ��������������й����һ�󶥶ѣ���ʱ�������е����ֵ���ǶѶ�ֵ��Ȼ�󽫶Ѷ�Ԫ����������ĩβԪ�ؽ�����Ȼ��ʣ���n-1��Ԫ�����¹����һ���ѣ������ͻ�õ�
	n��Ԫ���еĴδ�ֵ������ִ�У����ܵõ�һ������������.

	ʱ�临�Ӷȣ������ѵ�ʱ�临�Ӷ���O(n)����i��ȡ�Ѷ�Ԫ���ؽ��ѵ�ʱ����O(logn),��Ϊ��Ҫn-1��ȡ�Ѷ�Ԫ�أ������ؽ��ѵ�ʱ�临�Ӷ���O(nlogn)

	�ȶ��ԣ���21 20a 20b 12 11 8 7 �������������ݣ��ڽ�21��������Ժ��ڽ�20����������ˡ�7 8 11 12 20b 20a 21��

	�����ȼ����й���С���ѣ�priority_queue<int,vector<int>,greater<int>>LittleHeap;
*/


#include<iostream>
#include<vector>
using namespace std;


class LittleHeap {
public:

	//�ѵ��� node��Ҫ�������Ǹ��ڵ� i�ǶѵĴ�С
	void adjustHeap(vector<int>&input, int node, int length) {
		int temp = input[node];
		for (int k = 2 * node + 1; k < length; k = k * 2 + 1) {

			if (k + 1 < length && input[k + 1] < input[k])	//ѡ�����Һ��������Ľڵ�
				k = k + 1;

			if (input[k] < temp) {
				input[node] = input[k]; //���ӽڵ��ֵ�������ڵ�
				node = k;				//�ٶ��ӽڵ���е���
			}
			else
				break; //����ӽڵ㶼�ȸ��ڵ������Ҫ������ֱ���˳�
		}
		input[node] = temp; //��ԭ���ĸ��ڵ��ֵ����temp
	}


	//����
	void buildHeap(vector<int>&input) {
		for (int i = floor(input.size() / 2 - 1); i >= 0; i--) {  //�ӵ�һ����Ҷ�ӽڵ㿪ʼ���ϵ��� floor������ȡ�� ceil������ȡ��
			adjustHeap(input, i, input.size());
		}
	}


	void heapLittleSort(vector<int>&input) {
		buildHeap(input);

		for (int i = input.size() - 1; i > 0; i--) {
			swap(input[0], input[i]);
			adjustHeap(input, 0, i);  //i�������Ҫ�����ĶѵĴ�С
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