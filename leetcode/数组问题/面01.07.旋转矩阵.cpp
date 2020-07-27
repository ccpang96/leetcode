/************************************************************************/
/*@File Name         : ��01.07.��ת����.cpp
/*@Created Date      : 2020/7/11 9:07
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :  ����һ���� N �� N �����ʾ��ͼ������ÿ�����صĴ�СΪ 4 �ֽڡ��������һ���㷨����ͼ����ת 90 �ȡ�
/************************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;

 

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {

		int n = matrix[0].size();

		for (int i = 0; i < n / 2; i++) {   //�ضԽ���������ȥ
			for (int k = 0; k < (n + 1) / 2; k++) { //ÿ�ν����Ķ���k��ʾ���ǲ��ϱ仯����һ�� ��i��������еĸ���
				int temp = matrix[i][k];
				matrix[i][k] = matrix[n - 1 - k][i]; //�����½ǵ�ֵ�滻�����Ͻ�
				matrix[n - 1 - k][i] = matrix[n - 1 - i][n - 1 - k];
				matrix[n - 1 - i][n - 1 - k] = matrix[k][n - 1 - i];
				matrix[k][n - 1 - i] = temp;
			}
		}
	}
};

//int main() {
//	vector<vector<int>> matrix{ {1,2,3}, {4,5,6 }, { 7,8,9 } };
//	Solution().rotate(matrix);
//
//	system("pause");
//	return 0;
//}