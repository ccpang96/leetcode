/************************************************************************/
/*@File Name         : 992. K ����ͬ������������.cpp
/*@Created Date      : 2020/5/19 17:37
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/


/* Includes *************************************************************/

#include<iostream>
#include<vector>
using namespace std;


/************************************************************************/
/*@ Problem Name         : 992. K ����ͬ������������
/*@ Description 		 :����һ������������ A����� A ��ĳ���������в�ͬ�����ĸ���ǡ��Ϊ K��
��� A �������������һ��������������Ϊ�������顣
�����磬[1,2,3,1,2] ���� 3 ����ͬ��������1��2���Լ� 3�������� A �к����������Ŀ��
*************************************************************************
/*@ Example1-Input	 	 :A = [1,2,1,2,3], K = 2
/*@ Example1-Output		 :7
/*@ Example1-Explanation :ǡ���� 2 ����ͬ������ɵ������飺[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
*************************************************************************
/*@ Example1-Input	 	 :A = [1,2,1,3,4], K = 3
/*@ Example1-Output		 :3
/*@ Example1-Explanation :ǡ���� 3 ����ͬ������ɵ������飺[1,2,1,3], [2,1,3], [1,3,4].

/*@����˵����
/************************************************************************/


int subarraysWithKDistinct(vector<int>& A, int K) {

	//���������Ч���ж�
	if (A.size() == 0 || A.size() < K)
		return 0;


	//vector<int>hash(A.size() + 1, 0);
	int *hash = new int[A.size()+1];
	for (int i = 0; i < A.size() + 1; i++) {
		hash[i] = 0;
	}

	int l = 0; //��ָ��
	int results = 0; //���ս��
	int count = 0;	//��¼����������
	int result = 1;

	for (int r = 0; r < A.size(); ++r) {
		hash[A[r]]++;

		if (hash[A[r]] == 1)  //�ڲ�ͬ������һ�γ���ʱ+1s
			count++;

		while (hash[A[l]] > 1 || count > K) {
			if (count > K) {	//���µ�Ԫ�ؽ������Ƶ�ǰ�����ͻ�ʹ����������»ص�1,
				result = 1;
				count--;
			}
			else {
				result++;		//�µ�Ԫ�ؽ�������������1�����������count>K��������ÿ�ε���������ǰһ�ε������Ļ����ϼ�1
			}
			hash[A[l]]--;  //��A�е�Ԫ���˳�hash��
			l++;		//�ƶ��󴰿�
		}
		if (count == K)
			results += result;
	}
	delete [] hash;		//�ͷ�����
	return results;
}


 


//int main() {
//
//	vector<int> A = { 1,2,1,2,3 };
//	int result =  subarraysWithKDistinct(A, 2);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}