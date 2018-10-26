// sum upto n
int test = 4;
void main () {
	int n = 6;
	int sm;
	sm = sumupton(n,1);
	return;
}
int sumupton (int n,int flag) {
	int m = n-1;
	int r = 1;
	Matrix a[5][5];
	if (m) {
		int fn = sumupton(m-1);
		r = n+fn;
	}
	return r;
}
