/*
一共有n个数，编号是1~n，最开始每个数各自在一个集合中。

现在要进行m个操作，操作共有两种：

“M a b”，将编号为a和b的两个数所在的集合合并，如果两个数已经在同一个集合中，则忽略这个操作；
“Q a b”，询问编号为a和b的两个数是否在同一个集合中；

输入格式

第一行输入整数n和m。

接下来m行，每行包含一个操作指令，指令为“M a b”或“Q a b”中的一种。
输出格式

对于每个询问指令”Q a b”，都要输出一个结果，如果a和b在同一集合内，则输出“Yes”，否则输出“No”。

每个结果占一行。
数据范围

1≤n,m≤105

输入样例：

4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4

输出样例：

Yes
No
Yes

*/

/*
#include<iostream>
using namespace std;

const int N = 100010;
int fa[N];  //父节点集合
int n, m; 


int find_fa(int x) {  //查找x节点的所在集合编号+路径压缩
	if (fa[x] != x) 
		fa[x] = find_fa(fa[x]);  //如果x的父节点不等于该节点(即x不是根节点)，就将x的祖父节点作为x的父节点
	return fa[x];
}


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) //将每个节点的根节点都置为自己
		fa[i] = i;

	char op[2];
	int a, b;
	while (m--) {
		scanf("%s %d %d", op, &a, &b);
		if (op[0] == 'M') {  //合并两个集合操作
			if (find_fa(a) != find_fa(b)) {
				fa[find_fa(a)] = find_fa(b);  //就将a集合的祖宗节点的父亲   变为  b的祖宗节点
			}
		}
		if(op[0] == 'Q') {  //查询操作
			if (find_fa(a) != find_fa(b))
				puts("No");
			else
				puts("Yes");
		}
	}
	return 0;
}*/