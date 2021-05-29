/*

�ʷ�һ������n�������壬ȥ���2�����߶���ͬ������������ɵ����ĸ߶ȵ����ֵ�Ƕ���
�ʷ��������ױ��ԣ�n����Ʒ�������˾��֣��������ӵ�����Ʒ�Ƕ��٣�

���ӣ�
����
5
1 3 4 5 2
�ʷ�һ�����7
�ʷ��������1
*/

/*
״̬��ʾ�� dp[i][j]:��ʾ��ȡ��i��������ʱ��˫���߶Ȳ�Ϊjʱ���ϸ����ĸ߶�ֵ
���ԣ�max

״̬���֣���ȡ��i����Ʒʱ�������������
1.�ӵ������Ʒ  dp[i][j] = max(dp[i-1][j],dp[i][j]
2.���ڸ�����    d[i][j]  = max(dp[i-1][j-a[i]] + a[i]),dp[i][j])  j�������a[i]
3.���ڵ����ϣ���1���������������� ��2����������Ȼ���ڸ���
dp[i][j] = max(dp[i-1][a[i] - j] +j,dp[i][j])  j < a[i]
dp[i][j] = max(dp[i-1][j+a[i]],dp[i][j])

��󷵻أ�dp[n][0] ��ʾ������n����Ʒ���߶Ȳ�Ϊ0�����
*/

/*
#include<iostream>
#include<algorithm>


const int N = 1010;
using namespace std;

int n;
int a[N];
int f[N][N];


int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	memset(f, -0x3f, sizeof f);

	f[0][0] = 0;  //ǰi��ľ����ɵ�˫�����ĸ߶�Ϊ0ʱ��ľ���С

	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += a[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			f[i][j] = max(f[i - 1][j], f[i][j]);  //�ӵ������Ʒ
			if (j >= a[i]) {  //���ڸ�����
				f[i][j] = max(f[i][j], f[i - 1][j - a[i]] + a[i]);
			}
			if (j < a[i]) { //���ڵ�����
				f[i][j] = max(f[i - 1][a[i] - j] + j, f[i][j]); //������������
			}
			//���ڵ����ϣ�������Ȼ��������
			f[i][j] = max(f[i - 1][j + a[i]], f[i][j]);
		}
	}

	if (f[n][0] <= 0)
		cout << "Impossiable " << endl;
	else
		cout << f[n][0] << endl;

	system("pause");
	return 0;
}


*/