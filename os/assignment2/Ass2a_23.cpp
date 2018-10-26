#include <bits/stdc++.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
using namespace std;

int isPrime(){
  int randomprime, flag;
  srand(-getpid());
  while(1){
          randomprime = rand(); flag = 0;
          int j;
          for( j = 2; j < randomprime; j++)
            if(randomprime % j == 0) {break;}
          if(j == randomprime)break;
        }
}

int main(){
  
  time(0);
	int prod, cons;

	cin >> prod >> cons;
	
	key_t key = ftok("shmfile",65);

	// shmget returns an identifier in shmid
	int shmid = shmget(key,7*sizeof(int),0666|IPC_CREAT);
	
	// shmat to attach to shared memory
	int *shm = (int*)shmat(shmid,(void*)0,0);
	
	shm[5] = 0;	//producer
	shm[6] = 0;	//consumer
	
	
	for(int i = 0; i < prod; i++){
		int pid = fork();
		if(pid == 0){
		 // srand(-getpid());
			while(1){
			  
			  //Sleep for 5 sec or less
				int wt = rand()%6;
				sleep(wt);
				int randomprime, flag;
				
				// Generate Random Prime Number
				randomprime = isPrime();
				/*while(1){
          randomprime = rand(); flag = 0;
          int j;
          for( j = 2; j < randomprime; j++)
            if(randomprime % j == 0) {break;}
          if(j == randomprime)break;
        }*/
        
       
        //Check if a Positiion is empty
				if(shm[5] - shm[6] < 5){
					shm[shm[5]%5] = randomprime;
					shm[5]++;
					cout<< "producer " << i+1 << " : "<< randomprime << " , time : " << time(0)  << endl;		
				}
			}
		}
		else{
			//do nothing
		}
	}
	
	for(int i = 0; i < cons; i++){
		//Fork to create child
		int pid = fork();
		if(pid == 0){
			while(1){
			  
			  // wait for 5 sec or less
				int wt = rand()%6;
				sleep(wt);
				
        
        // Check if there is somthing left to consume
				if(shm[5] > shm[6]){
					int x = shm[shm[6]%5];
					shm[6]++;
					cout  <<"consumer " << i+1 << " : "<< x << " , time :  "<<time(0)<< endl;		
				}											
			}		
		}
		else{
			//do nothing		
		}			
	
	}

	sleep(30);
	kill(-getpid(), SIGKILL);

}
