/*
	��N����Ʒ��һ������ΪV�ı����������ܳ��ܵ����������M��ÿ����Ʒֻ����һ�Ρ������ vi�������� mi����ֵ�� wi��
	��⽫��Щ��Ʒװ�뱳������ʹ��Ʒ��������������������������������������ɳ��ܵ�����������Ҽ�ֵ�ܺ����������ֵ��
*/


/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int N = 1005;

int f[N][N];  //����Ϊi�����Ϊj������£�����������ֵ
int n, v, m;  //������Ʒ��������Ʒ�������Ʒ����
int cv[N], cm[N], w[N];

int main() {

	cin >> n >> v >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &cv[i], &cm[i], &w[i]);
	}

	for (int i = 0; i < n; i++) { 
		for (int j = m; j >= cm[i]; j--) {  //j������
			for (int k = v; k >= cv[i]; k--) {  //k�����
				f[j][k] = max(f[j][k], f[j- cm[i]][k - cv[i]] + w[i]); //����Ϊjʱ�����Ϊkʱ�ı�������Ʒ������ֵ
			}
		}
	}
	cout << f[m][v] << endl;
	system("pause");
	return 0;
}
*/