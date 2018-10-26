#include<bits/stdc++.h>

using namespace std;

int minimum(float a, float b){
	if(a > b)return b;
	return a;
}

float prsjf(float arrival[], float burst[], int N){
	float rem[N], completion[N];
	
	for(int i = 0; i < N; i++){
		rem[i] = burst[i];
	}
	
	float min;
	float time = 0, sum, runtime, prevtime = time;
	int i, flag, z;
	while(1){
		min = numeric_limits<float>::max();
		flag = numeric_limits<int>::max();

		for(i = 0; i < N && arrival[i] <= time; i++){
			if(rem[i] < min && rem[i] > 0){
				min = rem[i];
				flag = i;
			}
		}
		if(z == 1 && flag ==  numeric_limits<int>::max() ){time = arrival[i]; continue;}
		//z = 0;
		//cout << flag << "  "<< i<<"  "<<arrival[i]<<"  "<< time << "  "<<min <<endl;
		if( min == numeric_limits<float>::max() ){
			for(int j = 0; j < N; j++)
				sum+=completion[j] - arrival[j];
			return sum/N;
		}
		else{
			if(i < N){
				runtime = arrival[i] - time;
				if(runtime > min) {runtime = min;z = 1;}
				else z = 0;
			}
			else{
				runtime = min;
				z = 0; 
			}
			
			time+= runtime;
			rem[flag] -= runtime;
			if(rem[flag] == 0)completion[flag] = time;
			//if(z == 1)time = arrival[i];
		}
	}
}

float rrobin(float at[],float bt[],int N,float quantum){
	
	queue<int> q;
	int t = 0, i = 1, rem[N];
	q.push(0);
	int sum = 0;

	for(int j = 0; j < N; j++)
		rem[j] = bt[j];

	while(!q.empty()){
		int run = q.front();
		int flag = 0;
		if(rem[q.front()] < quantum){
			t+=rem[q.front()];
			rem[run] = 0;
			sum+=t-at[run];
		}
		else{
			flag = 1;
			t+=quantum;
			rem[run]-=quantum;
		}

		for(; i < N && at[i] < t; i++ ){
			q.push(i);
		}
		q.pop();
		if(flag)q.push(run);
	}

	return sum/N;
}

float frcfs(float arrival[],float burst[],int N){
	
	float completion[N],turnaround[N],sum=0,avg;
	completion[0]=arrival[0]+burst[0];

	for(int i = 1; i < N; i++){
		if(arrival[i] > completion[i-1]){
			completion[i] = arrival[i] + burst[i];
		}
		else{
			completion[i] = completion[i-1] + burst[i];
		}
	}
	for (int j = 0; j < N; j++){
		turnaround[j]=completion[j]-arrival[j];
		sum=sum+turnaround[j];
	}

	avg = sum / N;
	return avg;
}

int main(){
	int N, quantum;
	cout << "Enter number of processes" << endl;
	cin >> N;
	
	srand(time(0));
	float *arrival = new float[N], *burst = new float[N];
	float fcfs[10], rr[10], psjf[10], rr2[10], rr5[10];

	for(int t = 0; t < 10; t++){
		
		
		arrival[0] = 0;
		float R;
		
		//arrival time
		for(int i=1;i<N;i++)
		{
			float r = ((double) rand()/(RAND_MAX));
			float x = ((log(1-r)/(-2))*10);  //lambda=2
			arrival[i] = arrival[i-1]+fmod(x,10);
		}
//		cout<<endl;
		
		//burst time
		for(int j=0;j<N;j++){
			float p=((double) rand()/(RAND_MAX));
			burst[j]=p*20;
		}

		//arrival[0] = 0;arrival[1] = 2;arrival[2] = 4;arrival[3] = 6;arrival[4] = 8;
		//burst[0] = 20;burst[1] = 3;burst[2] = 1;burst[3] = 2;burst[4] = 3;

		fcfs[t] = frcfs(arrival, burst, N);
		rr[t] = rrobin(arrival, burst, N, 1);
		rr2[t] = rrobin(arrival, burst, N, 2);
		rr5[t] = rrobin(arrival, burst, N, 5);
		psjf[t] = prsjf(arrival, burst, N);

	}

	cout << endl;
	cout<<setw(50)<<"Turn around time ( N = "<<N<<" )"<<endl;
	cout<<setw(15)<<"Number of times"<<setw(15)<<"FCFS"<<setw(26)<<"Round-Robin(delta = 1)"<<setw(29)<<"Round-Robin(delta = 2)" <<setw(29)<< "Round-Robin(delta = 5)"<<setw(22)<<"preemptive SJF"<<endl;
	for(int i=0;i<10;i++){
		cout<<setw(11)<<i+1<<setw(20)<<fcfs[i]<<setw(16)<<rr[i]<<setw(29)<<rr2[i]<<setw(29)<<rr5[i]<<setw(29)<<psjf[i]<<endl;
	}

	float avgfcfs = 0, avgrr = 0, avgrr2 = 0, avgrr5 = 0, avgpsjf = 0;

	for(int i = 0; i < 10; i++){
		avgfcfs+=fcfs[i];
		avgrr+= rr[i];
		avgrr2+= rr2[i];
		avgrr5+= rr5[i];
		avgpsjf+= psjf[i];

		//cout << avgrr << endl;
	}

	avgpsjf/=N;
	avgrr5/=N;
	avgrr2/=N;
	avgrr/=N;
	avgfcfs/=N;

	cout<<endl<<setw(11)<<"Avg"<<setw(20)<<avgfcfs<<setw(16)<<avgrr<<setw(29)<<avgrr2<<setw(29)<<avgrr5<<setw(29)<<avgpsjf<<endl;
}
