/************************************************************************/
/*@File Name         : 417. ̫ƽ�������ˮ������.cpp
/*@Created Date      : 2020/5/24 16:33
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ��һ�⻹�Ǵӱ߽�������Ա߽��ϵĽ���DFS������ֻ����Ҫͬʱ������������һ���Ǵ�����һ����̫ƽ�󣬷ֱ������������ȥ��
�ȵ�ǰֵС�ĵ㡣
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
/*@ Problem Name         : 417. ̫ƽ�������ˮ������
/*@ Description 		 :����һ�� m x n �ķǸ�������������ʾһƬ��½�ϸ�����Ԫ��ĸ߶ȡ���̫ƽ�󡱴��ڴ�½����߽���ϱ߽磬���������󡱴��ڴ�½���ұ߽���±߽硣
�涨ˮ��ֻ�ܰ����ϡ��¡������ĸ�������������ֻ�ܴӸߵ��ͻ�����ͬ�ȸ߶���������
���ҳ���Щˮ���ȿ�����������̫ƽ�󡱣������������������󡱵�½�ص�Ԫ�����ꡣ
*************************************************************************
/*@ Example1-Input	 	 : 
/*@ Example1-Output		 :
/*@ Example1-Explanation :
*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :

/*@����˵����
/************************************************************************/

class Solution {
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return matrix;

		vector<vector<int>> result;

		int m = matrix.size();
		int n = matrix[0].size();

		//�ȶԿ���̫ƽ��ı߽�����DFS��������̫ƽ��ɴﵽ�ĵ���Ϊtrue
		vector<vector<bool>>canRechT(m, vector<bool>(n, false));
		vector<vector<bool>>canRechD(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++) {
			dfs(canRechT, matrix, i, 0);		//���һ��
			dfs(canRechD, matrix, i, n - 1);	//�ұ�һ��
		}
		for (int j = 0; j < n ; j++) {			//����Ϊʲô����j= 0; j < n-1,������������ͻ����
			dfs(canRechT, matrix, 0, j);		//�ϱ�һ��
			dfs(canRechD, matrix, m - 1, j);	//�±�һ��
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (canRechT[i][j] && canRechD[i][j]) {
					result.push_back(vector<int>{i, j});
				}
			}
		}
		return result;
	}

	void dfs(vector<vector<bool>>& canRech, vector<vector<int>>& matrix, int cur_i, int cur_j) {
		if (canRech[cur_i][cur_j])
			return;
	
		canRech[cur_i][cur_j] = true;
		int dx[4] = { 1,-1,0,0 };
		int dy[4] = { 0,0,1,-1 };

		for (int index = 0; index < 4; index++) {
			int next_i = cur_i + dx[index], next_j = cur_j + dy[index];
			if (next_i < 0 || next_i >= matrix.size() || next_j < 0 || next_j >= matrix[0].size() || matrix[cur_i][cur_j] > matrix[next_i][next_j])
				continue;
			dfs(canRech, matrix, next_i, next_j);
		}
	}


};