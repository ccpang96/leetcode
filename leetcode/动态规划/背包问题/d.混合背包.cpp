/*
��N����Ʒ��һ������ΪV�ı���

��Ʒһ�������ࣺ
	��һ����Ʒֻ����1�Σ�01��������
	�ڶ�����Ʒ���������޴Σ���ȫ��������
	��������Ʒ���ֻ���� si�Σ����ر�����

ÿ�������vi����ֵ��wi

��⽫��Щ��Ʒװ�뱳������ʹ��Ʒ����ܺͲ����������������Ҽ�ֵ�ܺ�����������ֵ��
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
struct Thing {
	int kind;
	int c, w;
};

int n, m;
vector<Thing>things;
int f[N];

int main() {
	
	cin >> n >> m; //��Ʒ�����࣬�Լ�����������m
	
	for (int i = 0; i < n; i++) {
		int c, w, s;
		cin >> c >> w >> s;
		if (s < 0)  things.push_back({ -1,c,w });		//01��������
		else if (s == 0) things.push_back({ 0,c,w });	//��ȫ��������
		else {  //���鱳��ͨ�������Ʒֽ��logs��01����
			for (int k = 1; k <= s; k <<= 1) {
				things.push_back({ -1,c*k,w*k });
				s -= k;
			}
			if (s) things.push_back({ -1,c*s,w*s });
		}
	}

	for (auto &thing  : things) {
		
		if (thing.kind == 0) { //��ȫ��������
			for (int j = thing.c; j <= m; j++)
				f[j] = max(f[j], f[j - thing.c] + thing.w);
		}
		else {   //01��������
			for (int j = m; j >= thing.c; j++)
				f[j] = max(f[j], f[j - thing.c] + thing.w);
		}
	}

	cout << f[m] << endl;

	system("pause");
	return 0;
}*/