#include <bits/stdc++.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <termios.h>
#include <string.h>
#include <stdio.h>

using namespace std;

#define msize 100
#define LIMIT 256 
#define MAX_LINE 1024

void repair(char *s){

	int j = 0;
	while(s[j] ==' ' || s[j] == '\t' || s[j] =='\n')j++;
	int i = 0;
	while(s[j] != '\0'){
		if(s[j] == ' ' && j-1 > 0 && s[j-1] != ' ') s[i++] = ' ';
		else if(s[j] == '\t' && j-1 > 0 && s[j-1] != '\t')s[i++] = ' ';
		else if(s[j] == '\n' && j-1 > 0 && s[j-1] != '\n')s[i++] = ' ';
		else if(s[j]!= ' ' && s[j] != '\t' && s[j] != '\n')s[i++] = s[j];
		j++;
	}
	if(s[i-1] == ' ')s[i-1] = '\0';
	else s[i] = '\0';

}

int main(){
	while(1){
		int choice;
		cout<<""<<endl;
		cout<<"1.Run an internal command "<<endl;
		cout<<"2.Run an external command "<<endl;
		cout<<"3.Run an external command by redirecting standard input from a file "<<endl;
		cout<<"4.Run an external command by redirecting standard output to a file"<<endl;
		cout<<"5.Run an external command in the background "<<endl;
		cout<<"6.Run several external commands in the pipe mode(give space after each '|') "<<endl;
		cout<<"7.Run an external command by redirecting standard output and standard input to a file "<<endl;
		cout<<"8.Pipe with redirection "<< endl;
		cout<<"9.Quit the shell "<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		cin.clear();
		cin.ignore(1000, '\n');

		switch(choice){
			case 1:{
				string command;
				cout<<endl<<"Now Enter an internal command"<<endl;
				getline(cin, command);
				char *str = new char[command.length() + 1];
				strcpy(str, command.c_str());
				repair(str);

				char *argc[10];
				argc[0]=strtok(str," ");
	            int i = 1;
	            
	            while(argc[i++]=strtok(NULL," "));
	            argc[i]=NULL;
				
				if(strcmp(argc[0],"mkdir")==0){
					if(mkdir(argc[1],0777))
					{
						cout<<"Error: "<<strerror(errno)<<endl;
					}
				}
				else if(strcmp(argc[0],"cd")==0){
	                if(chdir(argc[1]))
	    			{
	                   cout<<"Error: "<<strerror(errno)<<endl;
	                }

	            }
	            else if(strcmp(argc[0],"rmdir")==0){
	                if(rmdir(argc[1]))
	                {
	                    cout<<"Error: "<<strerror(errno)<<endl;
	                }
	            }
				break;

			}

			case 2:{
				string command;
				cout<<endl<<"Now Enter an external command"<<endl;
				getline(cin, command);
				char *str = new char[command.length() + 1];
				strcpy(str, command.c_str());
				repair(str);
				
				char *argc[10];
				argc[0]=strtok(str," ");
	            int i = 1;
	            while( argc[i++]=strtok(NULL," ") );
	            argc[i]=NULL;

	            int x, status;
	            x = fork();
	            if(x == 0){
	            	if(execvp(argc[0], argc) < 0){
	            		cout << "ERROR" << endl;
	            		exit(1);
	            	}
	            }
	            else{
	            	while(wait(&status)!= x);
				}

				break;
			}

			case 3:{
				string command, file, exec;
				cout<<endl<<"Now Enter an external command, redirecting standard input from a file"<<endl;
				getline(cin, command);
				for(int i=0;i<command.length();i++){
					if(command[i] == '<'){
						int len = command.length()-i-1;
						file = command.substr(i+1,len);
						exec = command.substr(0,i);
						break;
					}
				}

				char *inpfile = new char[file.length() + 1];
				strcpy(inpfile, file.c_str());
				
				char *str = new char[exec.length() + 1];
				strcpy(str, exec.c_str());

				repair(inpfile);
				repair(str);

				int x = fork();

				if(x == 0){
					int ifd = open(inpfile, O_RDONLY);
                    if(ifd < 0)
                        fprintf(stderr, "Unable to open file\n");

                    close(0);
                    dup(ifd);
                    close(ifd);

	                char *argc[msize];
	                argc[0]=strtok(str," ");
	                int ind=0;
	                while(argc[++ind]=strtok(NULL," "));
	                argc[ind]=NULL;
	                execvp(argc[0],argc);
	                perror("Error!!\n");
				}
				else{
					if( command[command.length()-1] != '&') {
                        wait(NULL);
                    }
                    else{
                        printf("Process is running in the background!!\n");
                    }
				}

				break;
			}
			case 4:{
				string command, file, exec;
				cout << endl << "Enter an external command, redirecting standard output to a file" << endl;
				getline(cin, command);

				for(int i=0;i<command.length();i++){
					if(command[i] == '>'){
						int len = command.length()-i-1;
						file = command.substr(i+1,len);
						exec = command.substr(0,i);
						break;
					}
				}

				char *outfile = new char[file.length() + 1];
				strcpy(outfile, file.c_str());
				
				char *str = new char[exec.length() + 1];
				strcpy(str, exec.c_str());

				repair(outfile);
				repair(str);

				int x = fork();

				if(x == 0){
					int ifd = open(outfile, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
                    if(ifd < 0)
                        fprintf(stderr, "Unable to open file\n");

                    close(1);
                    dup(ifd);
                    close(ifd);

	                char *argc[msize];
	                argc[0]=strtok(str," ");
	                int ind=0;
	                while(argc[++ind]=strtok(NULL," "));
	                argc[ind]=NULL;
	                execvp(argc[0],argc);
	                perror("Error!!\n");
				}
				else{
					if( command[command.length()-1] != '&') {
                        wait(NULL);
                    }
                    else{
                        printf("Process is running in the background!!\n");
                    }
				}

			}

			case 5:{
				string command, file, exec;
				cout<<"\nNow Enter an external command to run in background"<<endl;
				//string command;
				getline(cin, command);
				char *str = new char[command.length() + 1];
				strcpy(str, command.c_str());
				repair(str);
				
				char *argc[10];
				argc[0]=strtok(str," ");
	            int i = 1;
	            while( argc[i++]=strtok(NULL," ") );
	            argc[i]=NULL;

	            int x, status;
	            x = fork();
	            if(x == 0){
	            	if(execvp(argc[0], argc) < 0){
	            		cout << "ERROR" << endl;
	            		exit(1);
	            	}
	            }
	            else{
	            	while(wait(&status)!= x);
				}
			}

			case 6:{
				string cmd_input_str;int count=0;
				int fd1[2],fd2[2];
				int j=0,i=0,k=0,l=0;
				int errr = -1;int p_id;
				int end_index = 0;
				char *arguments[256];
				char * tokens[msize];
				char line[MAX_LINE]; 
				int numTokens;

				cout<<""<<endl;
				cout<<"Now Enter a command to run several external commands in the pipe mode"<<endl;
	
				memset (line,'\0',MAX_LINE);
				fgets(line, MAX_LINE, stdin);

				if((tokens[0] = strtok(line," \n\t")) == NULL) continue;

				numTokens = 1;
				while((tokens[numTokens] = strtok(NULL," \n\t")) != NULL) numTokens++;

				while (tokens[l] != NULL){
						if (strcmp(tokens[l],"|") == 0){
							count++;
						}
						l++;
				}
				count+=1;	// no. of commands


				while(tokens[i] != NULL  && end_index != 1){
					k = 0;
					while (strcmp(tokens[j],"|") != 0){
						arguments[k] = tokens[j];
						j++;	
						if (tokens[j] == NULL){
							end_index = 1;
							k++;
							break;
						}
						k++;
					}

					arguments[k] = NULL;
					j++;
					
					for(int rd=0;rd<k;rd++){
						repair(arguments[rd]);
					}

					if (i % 2 != 0){
						pipe(fd1); // for odd i
					}else{
						pipe(fd2); // for even i
					}

					int x = fork();

					if(x == 0){
						if (i == 0){
							dup2(fd2[1], STDOUT_FILENO);
						}
						else if (i == count - 1){
							if (count % 2 == 0){ // for odd number of commands
								dup2(fd2[0],STDIN_FILENO);
							}else{ // for even number of commands
								dup2(fd1[0],STDIN_FILENO);
							}
						}
						else{ // for odd i
							if (i % 2 == 0){
								dup2(fd1[0],STDIN_FILENO); 
								dup2(fd2[1],STDOUT_FILENO);	
							}else{ // for even i
								dup2(fd2[0],STDIN_FILENO); 
								dup2(fd1[1],STDOUT_FILENO);			
							} 
						}
						if (execvp(arguments[0],arguments)==errr){
							kill(getpid(),SIGTERM);
						}	
					}
					if (i == 0){
						close(fd2[1]);
					}else if (i == count - 1){
						if (count % 2 != 0){					
							close(fd1[0]);
						}else{					
							close(fd2[0]);
						}
					}else{
						if (i % 2 != 0){					
							close(fd2[0]);
							close(fd1[1]);
						}else{					
							close(fd1[0]);
							close(fd2[1]);
						}
					}
					waitpid(x,NULL,0);			
					i++;
				}
				break;
			}
			case 7: {

				string command, file, exec, fileout, filein;
				cout<<endl<<"Now Enter an external command, redirecting standard output and standard input to a file"<<endl;
				getline(cin, command);
				
				for(int i=0;i<command.length();i++){
					if(command[i] == '<'){
						int len = command.length()-i-1;
						file = command.substr(i+1,len);
						exec = command.substr(0,i);
						break;
					}
				}

				for(int i=0;i<file.length();i++){
					if(file[i] == '>'){
						int len = file.length()-i-1;
						fileout = file.substr(i+1,len);
						filein =  file.substr(0,i);
						break;
					}
				}
				char *outfile = new char[fileout.length() + 1];
				strcpy(outfile, fileout.c_str());

				char *inpfile = new char[filein.length() + 1];
				strcpy(inpfile, filein.c_str());
				
				char *str = new char[exec.length() + 1];
				strcpy(str, exec.c_str());

				repair(outfile);
				repair(inpfile);
				repair(str);

				int x = fork();

				if(x == 0){

					int ifd = open(inpfile, O_RDONLY);
                    if(ifd < 0)
                        fprintf(stderr, "Unable to open input file\n");

                    close(0);
                    dup(ifd);
                    close(ifd);

                    int ifd2 = open(outfile, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
                    if(ifd2 < 0)
                        fprintf(stderr, "Unable to open output file\n");

                    close(1);
                    dup(ifd2);
                    close(ifd2);

                    char *argc[msize];
	                argc[0]=strtok(str," ");
	                int ind=0;
	                while(argc[++ind]=strtok(NULL," "));
	                argc[ind]=NULL;
	                execvp(argc[0],argc);
	                perror("Error!!\n");
				}
				else{
					if( command[command.length()-1] != '&') {
                        wait(NULL);
                    }
                    else{
                        printf("Process is running in the background!!\n");
                    }
				}

				break;
			}
			case 8:{

					
				break;
			}
			case 9:{
				cout << "Do you reall want to exit" << endl;
				char c;
				cin >> c;
				if(c == 'Y' || c == 'y')exit(1);
				else if(c == 'n' || c == 'N');
				else cout << "INVALID ENTRY\n";

				break;

			}
			default : cout << "INCORRECT CHOICE" << endl;
		}
	}

	return 0;
}