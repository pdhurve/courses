//does not support matrix initialisation
int main(){
int a;
Matrix m[2][3];
// unary assignments
m[1][2]++;
m[1][2]--;
++m[1][1];
--m[1][1];
+m[1][1];
-m[1][1];
&m[1][1];
*m[1][1];
m[1][1].';
// assignment expressions
a = m[1][1];
m[1][1] = 1;
m[2][2] = m[1][1];
m[1][1]*=m[1][1];
m[1][1]/=1;
m[1][1]+=1;
m[1][1]-=1;
m[1][1]|=m[1][1];
m[1][1]<<=m[1][1];
m[1][1]>>=m[1][1];
m[1][1]&=m[1][1];
m[1][1]^=m[1][1];
// relational expressions
if(a == m[1][1]);
if(a != m[1][1]);
if(m[1][1] == a);
if(m[1][1] == m[1][1]);
if(a != 1);
if(m[1][1]!=1);
if(m[1][1] > 1);
if(m[1][1] < 1);
if(m[1][1] >=1 );
if(m[1][1] <= 1);
//logical operators
a&1;
m[1][1]&1;
a|1;
m[1][1]|1;
// shift operators
a<<1;
m[1][1]<<1;
a>>1;
m[1][1]>>1;

return 1;
}

