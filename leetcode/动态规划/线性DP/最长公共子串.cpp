/*
	�����������ȷֱ���N��M���ַ���A��B�������A������������B�������еĳ��ȷֱ��Ƕ��٣�

	��һ�а�����������N��M��

	�ڶ��а���һ������ΪN���ַ�������ʾ�ַ���A��

	�����а���һ������ΪM���ַ�������ʾ�ַ���B��

	�ַ�������Сд��ĸ����

	1��N,M��1000

	����������
	4 5
	acbd
	abedc
	���������
	3
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
char s[N];
char w[N];
int f[N][N]; //�ڵ�һ���ַ�����ǰi���ַ��г������ڵڶ����ַ�����ǰj���ַ��г��ֵ��Ӵ�
			 //�������Ӵ��ĳ���
int main() {

	cin >> n >> m;
	scanf("%s%s", s + 1, w + 1);   //�ӵ�s+1��w+1���ַ���ʼ��ȡ

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[i][j] = max(f[i - 1][j], f[i][j - 1]); //�ֱ�����Ӵ�������a[i]��b[j]������a[i]���ǲ�����b[j]������b[j]���ǲ�����a[i]������a[i]��b[j]
			if (s[i] == w[j])
				f[i][j] = max(f[i - 1][j - 1] + 1, f[i][j]);
		}
	}

	cout << f[n][m] << endl;
	system("pause");
	return 0;
}
*/