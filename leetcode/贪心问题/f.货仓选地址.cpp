/*
	��һ���������� N ���̵꣬���ǵ�����ֱ�Ϊ A1~AN��
������Ҫ�������Ͻ���һ�һ��֣�ÿ���峿���ӻ��ֵ�ÿ���̵궼Ҫ����һ����Ʒ��Ϊ�����Ч�ʣ���ѻ��ֽ��ںδ�������ʹ�û��ֵ�ÿ���̵�ľ���֮����С��


�����ʽ
��һ����������N��
�ڶ���N������A1~AN��
�����ʽ

���һ����������ʾ����֮�͵���Сֵ��
���ݷ�Χ

1��N��100000

����������

4
6 2 9 1

���������

12

*/

/*
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;
int a[N];

int n;


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	sort(a + 1, a + n + 1);
	
	int mid = a[n / 2 + 1];
	int result = 0;
	for (int i = 1; i <= n; i++) {
		result += a[i] - mid;
	}

	cout << result << endl;
	return 0;

}
*/