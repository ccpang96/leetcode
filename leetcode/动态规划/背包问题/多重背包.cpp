/*
�� N ����Ʒ��һ�������� V�ı������� i����Ʒ����� si ����ÿ������� vi����ֵ�� wi��

��⽫��Щ��Ʒװ�뱳������ʹ��Ʒ����ܺͲ����������������Ҽ�ֵ�ܺ�����������ֵ��
�����ʽ
��һ������������N��V���ÿո�������ֱ��ʾ��Ʒ�����ͱ����ݻ���

�������� N�У�ÿ���������� vi,wi,si���ÿո�������ֱ��ʾ�� i����Ʒ���������ֵ��������
�����ʽ
���һ����������ʾ����ֵ��
���ݷ�Χ

0<N,V��100

0<vi,wi,si��100

��������
4 5
1 2 3
2 4 1
3 4 3
4 5 2

���������10
*/


//����ѭ���������

/*
f[i] : �����Ϊi������£���Ʒ������ֵf[i]

��01��������İ��ӣ�
for(int i = 1; i <= n; i ++) {
for(int j = m;j >= c[i]; j--)

f[j] = max(f[j],f[j-c[i]] + w[i]); //����01������������ֻ������ѡ�� ҪôѡҪô��ѡ�������ڶ��ر���������mi��ѡ��

//�ĳ��������ַ�����
f[j] = max(f[j],f[j-c[i]] + w[i], f[j- 2*c[i]] + 2* w[i],f[j- 3*c[i]] + 3* w[i],  ...)
}

//���յĽ����
1 f[i] = 0; //����������£����ǲ�Ҫ����������������������ֵ����f[i]

2.f[0] = 0; f[i] = -INF;  //������������Ǳ�����������
max(f[0...m])
*/


/*
//ʱ�临�Ӷ���n3�η�
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;


const int N = 105;
int n, m;
int c[N];  //c�������ĵ����
int w[N]; //w��������
int s[N];  //s�������
int f[N];   //f�������Ϊiʱ����װ�µ��������ֵ


int main() {

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &c[i], &w[i], &s[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= c[i]; j--) {
			for (int k = 0; k <= s[i] && k*c[i] <= j; k++) {  //k*c[i] <=j ��һ��СС���Ż�
				f[j] = max(f[j], f[j - k * c[i]] + k * w[i]);
			}
		}
	}

	cout << f[m] << endl;
	system("pause");
	return 0;
}

*/



/*
//�ö������Ż�
//���Ӷ��� n*log2(s[i]) *v
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;


const int N = 2005; //������Ʒ��������
int n, m; //��Ʒ�����ͱ���������
int c[N];
int w[N];
int s[N];
int f[N];

struct Good {
	int c;
	int w;
};
int main() {

	scanf("%d%d", &n, &m); //��Ʒ�����ͱ���������

	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &c[i], &w[i], &s[i]);

	}
	vector<Good> goods;
	for (int i = 0; i <= n; i++) {
	//��s�ݲ�ɶ����Ʒ���
		for (int k = 1; k <= s[i]; k *= 2) {
			s[i] -= k;
			goods.push_back({ k*c[i],k*w[i] });
		}
		if (s[i] > 0)
			goods.push_back({ s[i] * c[i],s[i] * w[i] });
	}


	//Ȼ����01����������
	for (auto &good : goods) {
		for (int j = m; j >= good.c; j--) {
			f[j] = max(f[j], f[j - good.c] + good.w);
		}
	}
	cout << f[m] << endl;
	return 0;

}

*/