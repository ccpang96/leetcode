/*
����N��������[ai,bi]�Լ�һ���߶�����[s,t]������ѡ�����ٵ����䣬��ָ���߶�������ȫ���ǡ�

�������������������޷���ȫ���������-1��

*/

#include<iostream>
#include<algorithm>
using namespace std;

/*
1.�����䰴����˵��С������
2. ��ǰ����ö��ÿ�����䣬�������ܸ��ǿ�ʼλ�õ�start�������У�ѡ��һ���Ҷ˵����ġ�
3.ѡ����֮�󣬽�start����Ϊ�Ҷ˵�����ֵ

*/

/*
int n;
int result = 0;  //�ǿ��ܽ�����Сֵ
const int N = 100010;

struct Range {
	int l, r;	

	bool operator<(const Range& w) const {
		return l < w.l; 
	}
}ab[N];


int main() {
	
	int st, ed;
	scanf("%d%d", &st, &ed);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &ab[i].l, &ab[i].r);
	}
	
	sort(ab, ab +n);

	int res = 0;
	bool success = false;
	for (int i = 0; i < n; i++) {
		int j = i, r = -2e9;
		while (j < n&& ab[j].l <= st) {
			r = max(r, ab[j].r); //������ϵ�С�ڵ���st�����䣬Ѱ���Ҷϵ���������
			j++;
		}

		if (r < st) {  //˵���Ҷ˵�����������Ҷ˵㶼С��st����Ȼ�п�϶���ڣ�ʧ��
			break;
		}
		res++; 

		if (r >= ed) {  //�ɹ��ҵ�
			success = true;
			break;
		}

		st = r;
		i = j - 1;
	}
	if (!success) res = -1;
	printf("%d\n", res);

	return 0;
}*/