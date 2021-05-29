/*
给定一个模式串S，以及一个模板串P，所有字符串中只包含大小写英文字母以及阿拉伯数字。

模板串P在模式串S中多次作为子串出现。

求出模板串P在模式串S中所有出现的位置的起始下标。
*/

//代码的时间复杂度为O(n)

//下标为1的写法
/*
#include<iostream>

using namespace std;

const int N = 10010, M = 10010;
int n, m;
char p[N], s[M];  //p是模板串，s是模式串
int ne[N];  //next数组的含义是：next[i] = j; 代表p[1,j] = p[i-j+1,j] 最大的后缀等于前缀
 
int main() {


	cin >> n >> p + 1 >> m >> s + 1;

	//求next数组
	for (int i = 2,j = 0; i <= n; i++) {
		while (j != 0 && p[i] != p[j + 1]) j = ne[j];
		if (p[i] == p[j + 1]) j++;
		ne[i] = j;
	}

	//KMP匹配过程
	for (int i = 1,j = 0; i <= m; i++) { //m是模板串的长度
		while (j != 0 && s[i] != p[j + 1]) j = ne[j];  //回退，直到j==0,如果j等于0，则i往前进一位
		if (s[i] == p[j + 1]) j++; 
		if (j == n) {
			//匹配成功
			printf("%d", i - n + 1); //返回的是匹配成功时，模板串的起始索引
			j = ne[j]; //匹配成功以后，再往后退一步，继续匹配
		}
	}



	return 0;
}

*/


//下标为0的写法


//代码的时间复杂度为O(n)
/*
#include<iostream>

using namespace std;

const int N = 1000010, M = 1000010;
int n, m;
char p[N], s[M];  //p是模板串，s是模式串
int ne[N] = { -1 };  //next数组的含义是：next[i] = j; 代表p[1,j] = p[i-j+1,j] 最大的后缀等于前缀

int main() {


	cin >> n >> p >> m >> s;
	
	
	//求next数组
	for (int i = 1, j = -1; i < n; i++) {
		while (j > -1 && p[i] != p[j + 1]) j = ne[j];
		if (p[i] == p[j + 1]) j++;
		ne[i] = j;
	}



 

	
	//KMP匹配过程
	for (int i = 0, j = -1; i < m; i++) { //m是模板串的长度
		while (j > -1 && s[i] != p[j + 1]) j = ne[j];  //回退，直到j==0,如果j等于0，则i往前进一位
		if (s[i] == p[j + 1]) j++;
		if (j == n - 1) {
			//匹配成功
			printf("%d ", i - n + 1); //返回的是匹配成功时，模板串的起始索引
			j = ne[j]; //匹配成功以后，再往后退一步，继续匹配
		}
	}
	return 0;
}
*/