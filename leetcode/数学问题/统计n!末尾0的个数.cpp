/*
����һ������N����ôN�Ľ׳�N��ĩβ�ж��ٸ�0�� ���磺N=10��N��=3628800,N����ĩβ��2��0
*/

//ͳ�Ʊ�5���������ָ��� 25����6��5
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