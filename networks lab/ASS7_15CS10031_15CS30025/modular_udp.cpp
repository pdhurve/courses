/* 
 * @author : Pankaj Dhurve
 * modular_udp.c - A simple UDP Application
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <pthread.h>
#include <signal.h>
#include <bits/stdc++.h>

#define MSS 1024
#define MAX_BUFFER 100
#define SLEEP_VAL 5

using namespace std;
int alarm_fired = 0;
void mysig(int sig)
{
    pid_t pid;
    printf("PARENT : Received signal %d \n", sig);
    if (sig == SIGALRM)
    {
        alarm_fired = 1;
    }
}

void error(char *msg) {
    perror(msg);
    exit(0);
}

struct packet{
	char data[MSS];
};

int port;
char *ip;
int sockfd;
socklen_t serverlen;
socklen_t clientlen; /* byte size of client's address */
struct sockaddr_in serveraddr; /* server's addr */
struct sockaddr_in clientaddr; /* client addr */
int sequence_number = 0;
deque<packet> Q;
int len;
int fd;
int BUFSIZE = 1024;
char buf[MSS];
struct hostent *server;

//seperate thread
void *congestion_and_flow_control(void *s){

	struct packet p;
	int nextsequencenumber = 1;
	int receiver_window = 0;
	int pops = 0;
	int sender_window = 3;
	int m;
	int n;
	int i;
	int base;
	int window, threshhold, congestion_window;

	while(1){

		while(Q.size() == 0);
		base  = ((int *)(Q[0].data))[0];
		for( i = 0; i < sender_window; i++){
			p = Q[i];
			// send q[i]
			m = sendto(sockfd, p.data, ((int *)p.data)[1], 0, (struct sockaddr *)&serveraddr, serverlen);
			alarm(SLEEP_VAL);
			(void) signal(SIGALRM, mysig);
		}

		nextsequencenumber = ((int *)Q[i].data)[0];
		do{
			n = recvfrom(sockfd, buf, BUFSIZE, 0, (struct sockaddr *)&serveraddr, &serverlen);
			if(n == 0)continue;
			if (n < 0) 
			    break;
			if(n>0 && ((int*)buf)[0] < base)continue;
			if(n>0 && ((int*)buf)[0] > len )continue;

			base = ((int*)buf)[0] + 1;
			receiver_window = ((int *)buf)[1];

			if (base == nextsequencenumber){
			    break;
			}
		}while(!alarm_fired);
		// pop
		pops = base - ((int *)Q[0].data)[0];

		while(pops--)Q.pop_back();

		if(base == len + 1)break;
        else if (base < nextsequencenumber){ 
            threshhold = window/2; 
            congestion_window = 1;
            nextsequencenumber = base + 1; 
            alarm(SLEEP_VAL);
            (void) signal(SIGALRM, mysig);
        }     
        else if(window >= threshhold ) congestion_window+=1;
        else congestion_window = congestion_window * 2;

        if(receiver_window < congestion_window)sender_window = receiver_window;
        else sender_window = congestion_window;
	}


}

int Buffer_handler(char *buf, size_t len){
	
	struct packet p;
	int track = 0;
	int i = 0;
	while(i!=len){
		// Blocking Call, Blocked if space not available
		while(Q.size() == MAX_BUFFER);

		for(i = track; i < len && i < track + 1016; i++)
			p.data[i-track + 8] = buf[i];
		((int *)p.data)[0] = sequence_number++;
		((int *)p.data)[1] = i - track + 8;
		Q.push_back(p);
		track = i;

	}

	return 0;
}

int Buffer_handler_reciever(char buf[], size_t len){
	
	while(Q.size() == MAX_BUFFER);
	struct packet p;
	strcpy(p.data, buf);
	Q.push_back(p);
	((int *)buf)[1] = MAX_BUFFER - Q.size();
	sendto(sockfd, buf, sizeof(int), 0,(struct sockaddr *) &clientaddr, clientlen);
}

int appSend(char* buff, size_t len){
	
	// congestion control meanwhile sends data
	// write data in buffer
	int flag = 0;
	alarm(SLEEP_VAL);
	(void) signal(SIGALRM, mysig);
	while(!alarm_fired){
		Buffer_handler(buff, len);
		flag = 1;
	}

	if(flag)return 1;
}
//seperate thread
void *appRecv(void *s){

	
	// read data from buffer

	while(Q.size() == 0);
	struct packet p;
	
	while(!Q.empty()){
		p = Q.front();

		if(write(fd, p.data+8, ((int *)p.data)[1]-8) == -1) {
            error("write");
        }
	}
}

int main(int argc, char **argv){
	// cout << "UDP Application Starts................................................" << endl;

	struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    char chunk[100];
    int optval;
    int n;
    int i;
    int j;
    char filename[20];

	/* socket: create the socket */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");



	/* check command line arguments */
    if(argc == 3){

    	//sender
    	ip = argv[1];
    	port = atoi(argv[2]);

    	/* gethostbyname: get the server's DNS entry */
	    server = gethostbyname(ip);
	    if (server == NULL) {
	        fprintf(stderr,"ERROR, no such host as %s\n", ip);
	        exit(0);
	    }

		if (setsockopt (sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0)
			error("setsockopt failed\n");

	    /* build the server's Internet address */
	    bzero((char *) &serveraddr, sizeof(serveraddr));
	    serveraddr.sin_family = AF_INET;
	    bcopy((char *)server->h_addr, 
	      (char *)&serveraddr.sin_addr.s_addr, server->h_length);
	    serveraddr.sin_port = htons(port);

	    /* get a message from the user */
	    char filename[20];
	    bzero(buf, BUFSIZE);
	    printf("Please enter filename: ");
	    scanf("%s", filename);

	    struct stat st;
	    stat(filename, &st);
	    int size = st.st_size;
	    char filesize[20];
	    sprintf(filesize, "%d", size);
	    
	    len = size/1016;
	    if(size%1016)len++;
	    sprintf(chunk, "%d", len);
	    
	    char *message = new char[1000];
	    strcat(message, filename);
	    strcat(message, " ");
	    strcat(message, filesize);
	    strcat(message, " ");
	    strcat(message, chunk);

	    serverlen = sizeof(serveraddr);

	    int fd = open(filename, O_RDONLY);
    	if( fd < 0 )error("error opening file");
    	
    	//seperate thread for congestion and flow control
    	pthread_t tid;
    	pthread_create(&tid, NULL, congestion_and_flow_control, (void *)NULL);
		
		appSend(message, sizeof(message));
	    printf("server's response : %s\n", buf);
	    printf("chunks : %d\n", len);

	    while (1) {
	        n = read(fd, buf, BUFSIZE);
	        if (n == 0)
	            break;
	        if (n == -1) {
	            perror("read");
	            exit(EXIT_FAILURE);
	        }
	        if (appSend(buf, n)) {
	            perror("write");
	            exit(EXIT_FAILURE);
	        }
    	}
    	pthread_join(tid, NULL);
		// while(Q.size() != 0);

    }
    else if(argc == 2){
    	//reciever

    	port = atoi(argv[1]);
	    optval = 1;
	    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval , sizeof(int));

	    bzero((char *) &serveraddr, sizeof(serveraddr));
	    serveraddr.sin_family = AF_INET;
	    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	    serveraddr.sin_port = htons((unsigned short)port);

	    if (bind(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) 
	    	error("ERROR on binding");
	  	clientlen = sizeof(clientaddr);

	  	pthread_t tid;
	  	pthread_create(&tid, NULL, appRecv, NULL);

	  	while (1) {
			
			bzero(buf, BUFSIZE);
			//reciever
		    n = recvfrom(sockfd, buf, BUFSIZE, 0, (struct sockaddr *) &clientaddr, &clientlen);
		    if (n < 0)
		      error("ERROR in recvfrom");

		  
		    printf("server received %d/%d bytes: %s\n", (int)strlen(buf), n, buf);
		    //sender
		    ((int *)buf)[1] = MAX_BUFFER;
			n = sendto(sockfd, buf, strlen(buf)+1, 0,(struct sockaddr *) &clientaddr, clientlen);
		    if (n < 0) 
		      error("ERROR in sendto");

		    for(j=0;buf[j]!=' ';j++)
		        filename[j]=buf[j];
		    filename[j]='\0';

		    int size = 0;

		    j++;
		    for(; buf[j] != ' '; j++){
		      size = size * 10 + (int)(buf[j] - '0');
		    }
		    
		    printf("filename : %s\n", filename);
		    printf("size : %d\n", size);
		    int iter = size/1016;
		    if(size%1016)iter++;
		    bzero(buf,BUFSIZE);
		    printf("chunks : %d\n", iter);
		    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

		    for(i = 1; i <= iter; )
		    {
		        bzero(buf, BUFSIZE);
		        n = recvfrom(sockfd, buf, BUFSIZE, 0,(struct sockaddr*) &clientaddr, &clientlen);
		        if (n < 0)
		          error("ERROR in recvfrom");


		        if(((int*)buf)[0]==i)
		        {
		            if(Buffer_handler_reciever(buf, n) == -1) {
		              error("write");
		            }

					printf("ack %d\n", i);
		            i++;

		        }

		        else if(((int *)buf)[0] < i ){
		        	((int *)buf)[1] = MAX_BUFFER - Q.size();
		            n = sendto(sockfd, buf, sizeof(int), 0,(struct sockaddr *) &clientaddr, clientlen);
		            if (n < 0) 
		              error("ERROR in sendto");
		        }
		    }

		    pthread_join(tid, NULL);

		}
	}
    else {
       fprintf(stderr,"usage: sender <ip> <port> or usage : receiver <port_for_server> \n");
       exit(0);
    }
	
    close(sockfd);
  	return 0;
}
