#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#include<time.h>

int main(){
	while(1){
		char command[1000];
		char *tokens[100];
		gets(command);
		if(strcmp("quit", command) == 0)break;
		int i = 0, j = 0;
		// Tokenize
		while (command[i] != '\0') {       
          while (command[i] == ' ' || command[i] == '\t' || command[i] == '\n')
               command[i++] = '\0';     
          	tokens[j++] = &command[i];          
          while (command[i] != '\0' && command[i] != ' ' && 
                 command[i] != '\t' && command[i] != '\n') 
               command[i++];           
     	}
     	tokens[j] = '\0';

     	int status;
     	pid_t pid ;
     	pid = fork();

     	if (pid == 0) {          
          if (execvp(*tokens, tokens) < 0) {    
               printf("ERROR: Invalid Command\n");
               exit(1);
          }
     	}
     	else {                                  
          while (wait(&status) != pid); 
     	}
	}
	
}