/*
	��һ��������1�Σ�������������3�Σ��ҳ�ֻ����һ�ε��Ǹ���
	�ⷨ����λ���㣺
*/

#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		
		for (int i = 0; i < 32; i++) { //����32λ
			int count = 0;
			for (auto & m : nums) {  //����ÿ�����ĵ�iλ
				if (m & (1 << i))
					count++;
			}
			if (count % 3 == 1)  //
				res = res ^  (1 << i);
		}
		return res;

	}
};


 