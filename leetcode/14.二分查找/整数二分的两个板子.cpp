
//check()判断mid是否满足性质
bool check(int x) {
	
	return false;
}

//当区间[l,r]被划分为[l,mid]和[mid+1,r]时使用

int binary_search1(int l,int r) {
	
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
} 


//当区间[l,r]被划分为[l,mid-1]和[mid,r]时使用
int binary_seacrch(int l, int r) {

	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}

	return l;
}