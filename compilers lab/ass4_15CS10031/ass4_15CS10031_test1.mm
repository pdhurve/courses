
int test = 5;
double d = 2.3;
int i;
int a = 4, *p, b;
void func(int i, double d);
char c;
int main () {
  int ae=1, be=2, ce;
	ce = ae + be;
	ce = ae- be;
	ae++;
	ae--;
	ae = ae + 1;
	ae = ae>>2;
	be = ae / be;
	double d;
	d = ae+d;
	ae = be > ae ? be : ae;
	int cehecek = ae+be*ce;
	if (cehecek < ce) 
		ce = ae|be;
	int ke;
	ke = ++ae + be++;
	
	a = 10;
	int *x, y;
	x = &y;
	*x = y;
	y = *x;
	int k = 5;
	int fn = sumupton(k);
	int a=1, b=2, c;
	c = a + b;
	a--;
	
	int check = a+b*c;
	if (check < c) 
		c = a|b;
	i = ++a;
	
	int i, v = 5;
	double d;
	i = 1;
	
	//do i = i - 1; while (a[i] < v);
	i = 2;
	if (i&&v) i = 1;
	return;
}
int sumupton (int n) {
	int m = n-1;
	int r = 1;
	if (m) {
		int fn = factorial(m-1);
		r = n+fn;
	}
	return r;
}
int add (int a, int b) {
	a = 10;
	int b = 5;
	
	c = a+ b;
	
	return c;
}
