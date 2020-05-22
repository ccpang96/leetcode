/************************************************************************/
/*@File Name         : 200.��������.cpp
/*@Created Date      : 2020/5/21 15:38
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 
/************************************************************************/

/* Includes *************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;

/************************************************************************/
/*@ Problem Name         : 200.��������
/*@ Description 		 :����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������
�������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�������ֱ���������ڵ�½�������γɡ�
���⣬����Լ��������������߾���ˮ��Χ��


*************************************************************************
/*@ Example1-Input	 	 :
11110
11010
11000
00000
/*@ Example1-Output		 : 1
/*@ Example1-Explanation :
*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :

/*@����˵����
/************************************************************************/
 



class Solution {
public:
	void dfs(vector<vector<char>> &grid, int cur_i, int cur_j) {
		//�ݹ��:�������ĵ���0�����ߴﵽ�߽磬�˻أ�����̽���������� 
		//����ط�һ��Ҫ���жϱ߽磬�����ж��Ƿ�Ϊ���ػ�Խ��grid[cur_i][cur_j]
		if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != '1')
			return ;
		grid[cur_i][cur_j] = 0; //ÿ������ֻ��̽��һ��

								//�����ߣ������ߣ������ߣ�������
		int di[4] = { 0,0,1,-1 };
		int dj[4] = { 1,-1,0,0 };
		int ans = 1;
		//������ǰ���ص��ĸ�����
		for (int index = 0; index != 4; ++index) {
			int next_i = cur_i + di[index], next_j = cur_j + dj[index];
			dfs(grid, next_i, next_j);
		}
		 
	}

	int numIslands(vector<vector<char>>& grid) {
		int result = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == '1') {
					dfs(grid, i, j);
					result++;
				}
			}
		}
		return result;
	}
};


/**
int main() {

	int m, n; 
	char a;			//���ڶ�ȡ���з�
	while (2 == scanf("%d %d\n", &m, &n)) {
		vector<vector<char>>grid(m, vector<char>(n, 0));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j <= n; j++) {
				if (j == n)
					scanf("%c", &a);			//��ȡ���з�
				else
					scanf("%c", &grid[i][j]);
			}
		}

		//������ִ��Solution�㷨
		cout << Solution().numIslands(grid) << endl;
	}

	system("pause");
	return 0;
}
*/