/*
����һ������n��������1~n�ų�һ�ţ������кܶ������з��������ڣ����㰴���ֵ������е����з��������

�����ʽ
��һ�У�����һ������n��

�����ʽ
���ֵ�������������з�����ÿ������ռһ�С�
���ݷ�Χ

1��n��7

����������

3

���������

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1


*/



#include<iostream>

const int N = 10;
bool st[N]; //��ʾ�õ��Ƿ��ù�
int path[N]; //��ʾȫ���е�·��

/*
int n;

void dfs(int x) {

	//��x=nʱ����ʾ�Ѿ�����Ҷ�ӽڵ�
	if (x == n) {
		for (int i = 0; i < n; i++) {
			printf("%d ", path[i]);
		}
		puts(" ");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!st[i]) {
			path[x] = i;
			st[i] = true;

			dfs(x + 1);
			//�ָ��ֳ�
			st[i] = false;
		}
	}
}


int main() {

	scanf("%d", &n);

	dfs(0);


	return 0;
}

#include<vector>
using namespace std;
class Solution {
public:
	
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>>result;

		vector<bool>st(nums.size(), false);
		if (nums.empty())
			return result;
		vector<int>path;
		dfs(0,result,st,path);
		return result;
	}

	void dfs(int x, vector<vector<int>>&result, vector<bool>&st,vector<int>&path) {
		
		//�ݹ����
		if (x == n) {
			result.push_back(path);
			return;
		}

		for (int i = 1; i <= n; i++) {
			if (!st[i]) {  //���i��û�б����ʹ�
				path[i] = i;
				st[i] = true;

				dfs(x + 1,result,st,path); 
				//�ָ��ֳ�
				st[i] = false;
			}
		}
	}
};*/