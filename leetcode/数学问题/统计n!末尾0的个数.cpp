/*
给定一个整数N，那么N的阶乘N！末尾有多少个0？ 比如：N=10，N！=3628800,N！的末尾有2个0
*/

//统计被5整除的数字个数 25中有6个5
long func1(int N) {
	int res = 0; 
	int j = 0;
	for (int i = 1; i <= N; i++) {
		j = i;
		if (j % 5 == 0) {
			res++;
			j /= 5;
		}
	}
	return res;
}


int func2(int N) {
	int ret = 0;
	while (N) {
		ret += N / 5;
		N /= 5;
	}
	return ret;
}