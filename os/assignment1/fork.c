#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#include<time.h>

int main(){
	int x,y,z;
	
	srand(time(NULL));
	
	int pd[2];
	pipe(pd);
	int a = rand()%500, b = rand()%500, c = rand()%500;
	x = fork();
	if(x == 0){
		//child
		printf("\n\nB: ");
		int i, j, arr[100];
		for( i = 0; i < 100; i++){
			arr[i] = 1 + a + rand()%1000;
		}

		for(i = 0; i < 100; i++){
			for( j = 0; j < 100 - 1 - i; j++ ){
				if(arr[j] > arr[j+1]){
					int temp;
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
		for(i = 0; i < 100; i++)
			printf("%d ",arr[i]);
		printf("\n");
		//close(pd[0]);
		write(pd[1], arr, 100*sizeof(int) );
	}
	else{
		y = fork();
		if(y == 0){
			//child
			printf("\n\nC: ");
			int i, j, arr[100];
			for( i = 0; i < 100; i++){
				arr[i] = 1 + b + rand()%1000;
			}

			for(i = 0; i < 100; i++){
				for( j = 0; j < 100 - 1 - i; j++ ){
					if(arr[j] > arr[j+1]){
						int temp;
						temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp;
					}
				}
			}
			for(i = 0; i < 100; i++)
				printf("%d ",arr[i]);
			printf("\n");
			//close(pd[0]);
			write(pd[1], arr, 100*sizeof(int) );

		}
		else{
			z = fork();
			if(z == 0){
				printf("\n\nD: ");
				int arr[300];

				//close(pd[1]);
				read(pd[0], arr, 100*sizeof(int));
				read(pd[0], arr+100, 100*sizeof(int));
				read(pd[0], arr+200, 100*sizeof(int));
				int k, j;
				int i;
				for(i = 0; i < 300; i++){
					for( j = 0; j < 300 - 1 - i; j++ ){
						if(arr[j] > arr[j+1]){
							int temp;
							temp = arr[j];
							arr[j] = arr[j+1];
							arr[j+1] = temp;
						}
					}
				}
				for( i = 0; i < 300; i++)
					printf("%d ", arr[i]);
				printf("\n");

				printf("\n The Minimum Number is : %d\n", arr[0]);
				exit(0);
			}
			else{
				printf("\n\nA: ");
				int i, j, arr[100];
				for( i = 0; i < 100; i++) {
					arr[i] = 1 + c + rand()%1000;
				}

				for(i = 0; i < 100; i++){
					for( j = 0; j < 100 - 1 - i; j++ ){
						if(arr[j] > arr[j+1]){
							int temp;
							temp = arr[j];
							arr[j] = arr[j+1];
							arr[j+1] = temp;
						}
					}
				}
				for(i = 0; i < 100; i++)
					printf("%d ",arr[i]);

				printf("\n");
				//close(pd[0]);
				write(pd[1], arr, 100*sizeof(int));
				close(pd[0]);
				close(pd[1]);
				exit(0);
			}
		}
		
	}

}