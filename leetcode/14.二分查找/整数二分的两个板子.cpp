
//check()�ж�mid�Ƿ���������
bool check(int x) {
	
	return false;
}

//������[l,r]������Ϊ[l,mid]��[mid+1,r]ʱʹ��

int binary_search1(int l,int r) {
	
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
} 


//������[l,r]������Ϊ[l,mid-1]��[mid,r]ʱʹ��
int binary_seacrch(int l, int r) {

	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}

	return l;
}