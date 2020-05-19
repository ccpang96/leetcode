/************************************************************************/
/*@File Name         : 76. ��С�����Ӵ�.cpp
/*@Created Date      : 2020/5/18 17:43
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

#include<iostream>
#include<vector>
using namespace std;



/************************************************************************/
/*@ Problem Name         : 76. ��С�����Ӵ�
/*@ Description 		 :����һ���ַ��� S��һ���ַ��� T�������ַ��� S �����ҳ������� T �����ַ�����С�Ӵ���


*************************************************************************
/*@ Example1-Input	 	 :	S = "ADOBECODEBANC", T = "ABC"
/*@ Example1-Output		 :	"BANC"
/*@ Example1-Explanation :
*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :

/*@����˵������� S �в����������Ӵ����򷵻ؿ��ַ��� ""��
��� S �д����������Ӵ������Ǳ�֤����Ψһ�Ĵ𰸡�
/************************************************************************/

/************************************************************************/
/*@FullName:  minWindow
/*@Brief:     ��S���ҵ�����T�������ַ�������ַ��� ����������Ǳ仯��
/*@Parameter: s : ������t : ģʽ��
/*@Returns:   string : ������t�������ַ���s����̵��ַ���
/*@time:      2020/5/18 17:45
/*@author:    ccpang
/************************************************************************/
string minWindow(string s, string t) {

	//���������Ч���ж�
	if (t.size() <= 0 || s.size() <= 0 || s.size() < t.size())
		return "";
	

	int hash[256] = { 0 };
	for (int i = 0; i < t.size(); i++)
		hash[t[i]]++;		//��ģʽ���е���ĸ����hash��

	int l = 0, count = t.size(), max = s.size() + 1;
	string result;
	
	for (int r = 0; r < s.size(); r++) {
		hash[s[r]]--;	//��������s��ȥ����hash���е�t��Ԫ��

		if (hash[s[r]] >= 0)	//ƥ����һ��
			count--;


		while (l < r && hash[s[l]] < 0) { //����Щ��Ϊ-1��Ԫ���ټ�����
			hash[s[l]]++; 
			l++;		//���ƴ���
		}

		//���½����ֻ���µĴ��ڵĳ��ȱ�maxС�����л������
		if (count == 0 && r - l + 1 < max) { //���count ==0 ,˵���պ�t�е��ַ�ȫ��ƥ��
			max = r - l + 1;
			result = s.substr(l, r -l + 1); 
		}
	}
	 
	return result;
}


int main() {

	system("pause");
	return 0;
}