/*
�� N ����Ʒ��һ�������� V�ı�����ÿ����Ʒֻ��ʹ��һ�Ρ�

�� i����Ʒ������� vi����ֵ�� wi��

��⽫��Щ��Ʒװ�뱳������ʹ��Щ��Ʒ��������������������������ܼ�ֵ����������ֵ��
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
int c[N]; //����ֵ
int w[N]; //ӯ��ֵ

int f[N][N]; //����Ϊ��������ֻ����ǰi����Ʒ���������������j��ѡ���ļ��� ���ԣ���max
int n, m;  //n����Ʒ�����������������m

int main() {

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &c[i], &w[i]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[i][j] = f[i - 1][j]; //���õ�i����Ʒ  ����Ϊ�㣺���õ�i����Ʒ+�õ�i����Ʒ
			if (j >= c[i])
				f[i][j] = max(f[i][j], f[i - 1][j - c[i]] + w[i]);
			}
	}
	cout << f[n][m] << endl;

	return 0;
}
*/

/*
//�ռ��Ż�һά
const int N = 1005;
int c[N]; //����ֵ
int w[N]; //ӯ��ֵ

int f[N]; //����Ϊ���������������j��ѡ���ļ��� ���ԣ���max
int n, m;  //n����Ʒ�����������������m

int main() {

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &c[i], &w[i]);

	for (int i = 1; i <= n; i++)
		for (int j = m; j >= c[i]; j--) {
			f[j] = max(f[j], f[j - c[i]] + w[i]);
		}

	cout << f[m] << endl;
	return 0;
}
*/