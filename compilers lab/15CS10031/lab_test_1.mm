
int fib(int n){
	if(n<=1)
		return 0;
	return fib(n-1) + fib(n-2);
}




int mul(int a,int b){
 	return a*b;
}





int main(){
	
	int c = 3,a = 4;
	int b = mul(c,(mul(a,1)));
        double d = fib(b-1) + fib(fib(b-1));
	char e = fib(d);
	return 0;
}
