/*
> 有N件物品和一个容量为V的背包，每件物品只能使用一次。
  第i件物品的体积为vi，价值为wi。求解将哪些物品装入背包，可使得这些物品的总体积不超过背包容量，
  且总价值最大。输出字典序最小的方案。这里的字典序是指：所选物品的编号所构成的序列。物品的编号范围是 1…N
*/

/*
#include<iostream>
#include<algorithm>

using namespace std;


const int N = 1010;
int n, m;
int c[N]; //物品体积
int w[N]; //物品价值
int f[N][N];  //当考虑前i物品，体积最多j的的最大价值

*/