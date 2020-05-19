/************************************************************************/
/*@File Name         : 567.�ַ���������.cpp
/*@Created Date      : 2020/5/19 17:09
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

/* Includes *************************************************************/

/************************************************************************/
/*@ Problem Name         : 567.�ַ���������
/*@ Description 		 :���������ַ��� s1 �� s2��дһ���������ж� s2 �Ƿ���� s1 �����С�
���仰˵����һ���ַ���������֮һ�ǵڶ����ַ������Ӵ���


*************************************************************************
/*@ Example1-Input	 	 :s1 = "ab" s2 = "eidbaooo"
/*@ Example1-Output		 :True
/*@ Example1-Explanation : s2 ���� s1 ������֮һ ("ba").
*************************************************************************
/*@ Example1-Input	 	 :s1= "ab" s2 = "eidboaoo"
/*@ Example1-Output		 : False
/*@ Example1-Explanation :

/*@����˵����//���ⴰ�ڲ��䣬�պõ���s1�Ĵ�С
/************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

bool checkInclusion(string s1, string s2) {

	//���������Ч���ж�
	if (s2.size() < s1.size() || s2.size() == 0 || s1.size() == 0)
		return false;


	int hash[256] = { 0 };
	
	for (int i = 0; i < s1.size(); i++) {
		hash[s1[i]]++;
	}

	int l = 0;		//�󴰿�
	int count = 0; //ƥ��ĸ���
	int found = false; //���ս��

	for (int r = 0; r < s2.size(); r++) {
		hash[s2[r]]--;	

		if (hash[s2[r]] >= 0)  //�ɹ�����s1�е��ַ�,ƥ��ɹ�һ��
			count++;

		//���ڴ���Ĵ��ڲ��䣬�Ǹպõ���s1.size()������Ҫ��r > s1.size()-1ʱ����ҪŲ����ָ��
		if (r > s1.size() - 1) {
			hash[s2[l]]++;	

			if (hash[s2[l]] > 0)  //�������0��˵�����Ԫ����s2�еģ���˵�����Ԫ�ص�ƥ���ǲ��Ե�
				count--;	//������count--
			l++;
		}

		if (count == s1.size()) {
			found = true;
		}
	}
	return found;
}