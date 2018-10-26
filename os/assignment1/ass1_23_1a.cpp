            #include <iostream>
            #include <stdio.h>
            #include <stdlib.h>
            #include <unistd.h>
            #include <time.h>
            #include <stdlib.h>
            #include <string.h>
            #include <bits/stdc++.h>
            using namespace std;


            int main()
            {
                int PA[2];
                int PB[2];
                int PC[2];
                int PD[2];
                if(pipe(PA)<0)
                exit(1);
                if(pipe(PB)<0)
                exit(1);
                if(pipe(PC)<0)
                exit(1);
                if(pipe(PD)<0)
                exit(1);
                srand(time(0));
                int val=fork();
                if(val)
                {
                    int val2 = fork();
                    if(val2) {
                    int A[100];
                    for(int i=0;i<100;i++)
                    {
                        A[i]=abs(rand())%1000;            }
                        sort(A,A+100);
                        for(int i=0;i<100;i++)
                        write(PA[1],(A+i),4);
                    }
                    else {
            //b         
                    int B[100];
                    for(int i=0;i<100;i++)
                    {
                        B[i]=abs(rand())%1000;
                    }
                        sort(B,B+100);
                        for(int i=0;i<100;i++)
                        write(PB[1],(B+i),4);

                    }
                }
                else
                {   
                int val3 = fork();
                if(val3) {
                    int C[100];
                    for(int i=0;i<100;i++)
                    {
                        C[i]=abs(rand())%1000;
                    }
                        sort(C,C+100);
                        for(int i=0;i<100;i++)
                        write(PC[1],C+i,4);

            //c
                }   
                else 
                {
                    int a,b,c;
                    int A1[100];
                    int B1[100];
                    int C1[100];
                    int D[300];
                    for(int i=0;i<100;i++)
                    {
                        read(PA[0],(A1 + i),4);
                    }

                    for(int i=0;i<100;i++)
                    {
                        read(PB[0],(B1 + i),4);
                    }

                    for(int i=0;i<100;i++)
                    {
                        read(PC[0],(C1 + i),4);
                    }
                    // Merging 

                    int i,j,k,counter;
                    i = j = k = counter = 0;
                    int m,n,o;
                    m=n=o=100;
            while (i < m && j < n && k < o) {
        
                // Get minimum of a, b, c
                int m = min(min(A1[i], B1[j]), C1[k]);
        
                // Put m in D
                D[counter]=m;
                counter++;
        
                // Increment i, j, k
                if (m == A1[i])
                    i++;
                else if (m == B1[j])
                    j++;
                else
                    k++;
            }
        
            // C has exhausted
            while (i < m && j < n) {
                if (A1[i] <= B1[j]) {
                    D[counter]=A1[i];
                    i++;
                    counter++;
                }
                else {
                    D[counter]=B1[j];
                    counter++;
                    j++;
                }
            }
        
            // B has exhausted
            while (i < m && k < o) {
                if (A1[i] <= C1[j]) {
                    D[counter]=A1[i];
                    i++;
                    counter++;
                }
                else {
                    D[counter]=C1[k];
                    k++;
                    counter++;
                }
            }
        
            // A has exhausted
            while (j < n && k < o) {
                if (B1[j] <= C1[k]) {
                    D[counter]=B1[j];
                    counter++;
                    j++;            
                }
                else {
                    D[counter]=C1[k];
                    k++;
                    counter++;
                }
            }
        
            // A and B have exhausted
            while (k < o)
                {
                D[counter]=C1[k];
                k++;
                counter++;
                }
            // B and C have exhausted
            while (i < m)
               {
                    D[counter]=A1[i];
                    i++;
                    counter++;
               }
            // A and C have exhausted
            while (j < n)
            {
                D[counter]=B1[j];
                    counter++;
                    j++;
            }
            for(int x=0;x<300;x++)
                    cout<<D[x]<<endl;


                        

            
                }  

                }

            }
