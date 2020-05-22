/************************************************************************/
/*@File Name         : 992. K 个不同整数的子数组.cpp
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
/*@ Problem Name         : 992. K 个不同整数的子数组
/*@ Description 		 :给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，
则称 A 的这个连续、不一定独立的子数组为好子数组。
（例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）返回 A 中好子数组的数目。
*************************************************************************
/*@ Example1-Input	 	 :A = [1,2,1,2,3], K = 2
/*@ Example1-Output		 :7
/*@ Example1-Explanation :恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
*************************************************************************
/*@ Example1-Input	 	 :A = [1,2,1,3,4], K = 3
/*@ Example1-Output		 :3
/*@ Example1-Explanation :恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].

/*@补充说明：
/************************************************************************/


int subarraysWithKDistinct(vector<int>& A, int K) {

	//输入参数有效性判断
	if (A.size() == 0 || A.size() < K)
		return 0;


	//vector<int>hash(A.size() + 1, 0);
	int *hash = new int[A.size()+1];
	for (int i = 0; i < A.size() + 1; i++) {
		hash[i] = 0;
	}

	int l = 0; //左指针
	int results = 0; //最终结果
	int count = 0;	//记录整数的种类
	int result = 1;

	for (int r = 0; r < A.size(); ++r) {
		hash[A[r]]++;

		if (hash[A[r]] == 1)  //在不同的数第一次出现时+1s
			count++;

		while (hash[A[l]] > 1 || count > K) {
			if (count > K) {	//当新的元素进来打破当前条件就会使这个增量重新回到1,
				result = 1;
				count--;
			}
			else {
				result++;		//新的元素进来，窗口增加1，如果不打破count>K的条件，每次的增量就在前一次的增量的基础上加1
			}
			hash[A[l]]--;  //让A中的元素退出hash表
			l++;		//移动左窗口
		}
		if (count == K)
			results += result;
	}
	delete [] hash;		//释放数组
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