/*
�� n �����Ŷӵ� 1 ��ˮ��ͷ����ˮ���� i ����װ��ˮͰ�����ʱ���� ti��������ΰ������ǵĴ�ˮ˳�����ʹ�����˵ĵȴ�ʱ��֮����С��
�����ʽ
	��һ�а������� n���ڶ��а��� n�����������е� i ��������ʾ�� i ����װ��ˮͰ�����ѵ�ʱ�� ti��
�����ʽ
���һ����������ʾ��С�ĵȴ�ʱ��֮�͡�

���ݷ�Χ
1��n��105,1��ti��104

����������
7
3 6 1 4 2 5 7

���������
56
*/

/*
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

int n;
int t[N];

typedef long long LL;

bool cmp(int a, int b) {
	return a < b;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &t[i]);

	sort(t, t + n,cmp); //�ȴ�С��������

	LL result = 0;  
	for (int i = 0; i < n; i++) {  //����ʱ��
		result += t[i] * (n -1-i);
	}

	cout << result << endl;
	return 0;
}*/
