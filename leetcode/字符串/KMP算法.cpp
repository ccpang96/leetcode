/*
����һ��ģʽ��S���Լ�һ��ģ�崮P�������ַ�����ֻ������СдӢ����ĸ�Լ����������֡�

ģ�崮P��ģʽ��S�ж����Ϊ�Ӵ����֡�

���ģ�崮P��ģʽ��S�����г��ֵ�λ�õ���ʼ�±ꡣ
*/

//�����ʱ�临�Ӷ�ΪO(n)

//�±�Ϊ1��д��
/*
#include<iostream>

using namespace std;

const int N = 10010, M = 10010;
int n, m;
char p[N], s[M];  //p��ģ�崮��s��ģʽ��
int ne[N];  //next����ĺ����ǣ�next[i] = j; ����p[1,j] = p[i-j+1,j] ���ĺ�׺����ǰ׺
 
int main() {


	cin >> n >> p + 1 >> m >> s + 1;

	//��next����
	for (int i = 2,j = 0; i <= n; i++) {
		while (j != 0 && p[i] != p[j + 1]) j = ne[j];
		if (p[i] == p[j + 1]) j++;
		ne[i] = j;
	}

	//KMPƥ�����
	for (int i = 1,j = 0; i <= m; i++) { //m��ģ�崮�ĳ���
		while (j != 0 && s[i] != p[j + 1]) j = ne[j];  //���ˣ�ֱ��j==0,���j����0����i��ǰ��һλ
		if (s[i] == p[j + 1]) j++; 
		if (j == n) {
			//ƥ��ɹ�
			printf("%d", i - n + 1); //���ص���ƥ��ɹ�ʱ��ģ�崮����ʼ����
			j = ne[j]; //ƥ��ɹ��Ժ���������һ��������ƥ��
		}
	}



	return 0;
}

*/


//�±�Ϊ0��д��


//�����ʱ�临�Ӷ�ΪO(n)
/*
#include<iostream>

using namespace std;

const int N = 1000010, M = 1000010;
int n, m;
char p[N], s[M];  //p��ģ�崮��s��ģʽ��
int ne[N] = { -1 };  //next����ĺ����ǣ�next[i] = j; ����p[1,j] = p[i-j+1,j] ���ĺ�׺����ǰ׺

int main() {


	cin >> n >> p >> m >> s;
	
	
	//��next����
	for (int i = 1, j = -1; i < n; i++) {
		while (j > -1 && p[i] != p[j + 1]) j = ne[j];
		if (p[i] == p[j + 1]) j++;
		ne[i] = j;
	}



 

	
	//KMPƥ�����
	for (int i = 0, j = -1; i < m; i++) { //m��ģ�崮�ĳ���
		while (j > -1 && s[i] != p[j + 1]) j = ne[j];  //���ˣ�ֱ��j==0,���j����0����i��ǰ��һλ
		if (s[i] == p[j + 1]) j++;
		if (j == n - 1) {
			//ƥ��ɹ�
			printf("%d ", i - n + 1); //���ص���ƥ��ɹ�ʱ��ģ�崮����ʼ����
			j = ne[j]; //ƥ��ɹ��Ժ���������һ��������ƥ��
		}
	}
	return 0;
}
*/