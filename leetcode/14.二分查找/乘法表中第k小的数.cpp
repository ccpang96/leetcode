#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	//Binary Search for value
	//����ͨ���ֲ�һ�� ��ͨ���ְ��±��������߽磬������Ķ������ǰ�ֵ�������߽�
	int fun(int m, int n, int num) {//�������ܣ������m*n�ĳ˷����У��ҳ��ж��ٸ�ֵ <= num����������������ֵ������
		int count = 0;
		for (int i = 1; i <= m; ++i) {//�дӵ�һ�п�ʼ
			count += min(num / i, n);//�˱��ʽ�ĺ��壺num���ֵ�ڵ�ǰ��i�У��ж��ٸ�ֵ��������<=num�ĸ�����
		}
		return count;
	}
	int findKthNumber(int m, int n, int k) {
		if (k == 1) return 1;
		if (k == m * n) return m * n;
		int left = 1, right = m * n, mid;//ֵ�������߽磬�˷���m*n����С��1�������m*n
		while (left < right) {
			mid = (left + right) >> 1;
			int temp = fun(m, n, mid);//�õ��ڳ˷����� ֵ <= mid ������
			if (temp >= k) { //temp��
				right = mid;//���temp < k, ˵����ǰmid���ֵ��Ŀ��ֵ����ߣ���Ŀ��ֵС�������Կ�����С�߽�
			}
			else left = mid + 1;//temp >= k�� ��temp>kʱ��Ϊʲô��ȡ right = mid-1������right = mid����Ϊ���ǵ�Ŀ��ֵ���ܴ����ظ������� 123334�������ѡ��Ҫ�ҵ�3С��������mid��ǰǡ��=3����ôtemp�õ��Ľ������5��<=mid�����������ѡ��right = mid-1=2����ô�������д����½��������temp = kʱ��Ϊʲô���������ؽ���أ����Ǽ���������С�߽磿��Ϊ���ǵ�ǰ��mid������һ�����ڳ˷����е�ֵ���Ͼ�mid=(left+right) >> 1; �����������ؿ��ܷ��ش���𰸡�����һ��������Χ ֱ��left=right�����շ��ص�һ������ȷֵ������t��temp = k�� ��ĳһ�Ǳ�ֵx��tempҲ=k�� ��ôtһ����xС������xҲ�ᱻright��С���³��֣���
		}
		return left;
	}
};


 