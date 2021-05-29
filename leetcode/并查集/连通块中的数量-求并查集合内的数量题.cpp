/*
给定一个包含n个点（编号为1~n）的无向图，初始时图中没有边。

现在要进行m个操作，操作共有三种：

“C a b”，在点a和点b之间连一条边，a和b可能相等；
“Q1 a b”，询问点a和点b是否在同一个连通块中，a和b可能相等；
“Q2 a”，询问点a所在连通块中点的数量；

输入格式

第一行输入整数n和m。

接下来m行，每行包含一个操作指令，指令为“C a b”，“Q1 a b”或“Q2 a”中的一种。
输出格式

对于每个询问指令”Q1 a b”，如果a和b在同一个连通块中，则输出“Yes”，否则输出“No”。

对于每个询问指令“Q2 a”，输出一个整数表示点a所在连通块中点的数量

每个结果占一行。
数据范围

1≤n,m≤105

输入样例：

5 5
C 1 2
Q1 1 2
Q2 1
C 2 5
Q2 5

输出样例：

Yes
2
3
*/


/*
#include<iostream>
using namespace std;


const int N = 100010;

int n, m; 
int fa[N], Size[N];

int find(int x) {
	
	if (fa[x] != x)
		fa[x] = find(fa[x]);  //函数递归的方法求祖宗节点
	return fa[x];
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		Size[i] = 1;
	}

	//开始读取操作的数量
	char op[2];
	int a, b;
	while (m--) {
		scanf("%s", op);
		if (op[0] == 'C') {   //合并两个集合
			scanf("%d %d", &a, &b);
			if (find(a) != find(b)) {  //两数不在一个集合中
				
				Size[find(b)] += Size[find(a)];  //让a集合根节点的数量+到b集合根节点上  一定要先更新size，再修改集合根节点指向
				fa[find(a)] = find(b);  //让a集合的根节点 变为b集合的祖宗节点
				
			}
		}
		if (op[1] == '1') {  //查询两个数是否在一个集合中
			scanf("%d %d", &a, &b);
			if (find(a) == find(b))
				puts("Yes");
			else
				puts("No");
		}

		if (op[1] == '2') {
			scanf("%d", &a);
			printf("%d\n", Size[find(a)]);
		}
	}		
	return 0;
}
*/
