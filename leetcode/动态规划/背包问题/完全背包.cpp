
/*
�� N ����Ʒ��һ�������� V�ı�����ÿ����Ʒ�������޼����á�
��i����Ʒ������� vi����ֵ�� wi
��⽫��Щ��Ʒװ�뱳������ʹ��Щ��Ʒ��������������������������ܼ�ֵ���
�������ֵ��
�����ʽ
��һ������������N��V���ÿո�������ֱ��ʾ��Ʒ�����ͱ����ݻ���

�������� N�У�ÿ���������� vi,wi���ÿո�������ֱ��ʾ�� i����Ʒ������ͼ�ֵ��
�����ʽ
���һ����������ʾ����ֵ��
���ݷ�Χ

0<N,V��1000
0<vi,wi��1000
��������
4 5
1 2
2 4
3 4
4 5

���������
10

*/


/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;



const int N = 1005;
int n, m;
int c[N];
int w[N];
int f[N];  //�����Ϊi������£�����ֵ�Ƕ��� ��Ҫ��ǡ��װ�������Ҫ��ǡ��װ������ôֻ��f[0] = 0,���ǺϷ�״̬��������Ҫ��ʼ��Ϊ������


int main() {

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &c[i], &w[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = c[i]; j <= m; j++) {
			f[j] = max(f[j], f[j - c[i]] + w[i]);
		}
	}

	cout << f[m] << endl;
	return 0;
}*/