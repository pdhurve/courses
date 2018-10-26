/* 
 * @author : Pankaj Dhurve
 * udpclient.c - A simple UDP client
 * usage: udpclient <host> <port>
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
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <time.h>
#include <signal.h>
#include <bits/stdc++.h>

#define BUFSIZE 1024
#define SLEEP_VAL 5

using std::deque;

typedef struct{
    char buf[1024];
}packet;

packet p;

/* 
 * error - wrapper for perror
 */
pid_t pid;

char md5checksum[1000] = "md5sum ";  
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

int main(int argc, char **argv) {
    int sockfd, portno, n;
    socklen_t serverlen;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char *hostname;
    char buf[BUFSIZE];
    char chunk[100];
    int baseptr, currptr;
    int flag1, flag2, flag3;
    int timestart, timeend;
    int window = 3, start_timer;
    int success_transfer = 0;
    int threshhold = 1000;
    deque<packet> q;
    int start = 0;
    int end = 0;
    int initbase;
    time(NULL);      
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    /* check command line arguments */
    if (argc != 3) {
       fprintf(stderr,"usage: %s <hostname> <port>\n", argv[0]);
       exit(0);
    }
    hostname = argv[1];
    portno = atoi(argv[2]);

    /* socket: create the socket */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    if (setsockopt (sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,
                    sizeof(tv)) < 0)
            error("setsockopt failed\n");
    /* gethostbyname: get the server's DNS entry */
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host as %s\n", hostname);
        exit(0);
    }

    /* build the server's Internet address */
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
      (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(portno);


    char filename[20];
    /* get a message from the user */
    bzero(buf, BUFSIZE);
    printf("Please enter filename: ");
    scanf("%s", filename);
    //fgets(buf, BUFSIZE, stdin);

    struct stat st;
    stat(filename, &st);
    int size = st.st_size;
    char filesize[20];
    sprintf(filesize, "%d", size);
    //return 0;
    
    int len = size/1016;
    if(size%1016)len++;
    sprintf(chunk, "%d", len);
    
    char message[1000] = "";
    strcat(message, filename);
    strcat(message, " ");
    strcat(message, filesize);
    strcat(message, " ");
    strcat(message, chunk);

    //return 0;
    serverlen = sizeof(serveraddr);
    //send the message to server
    while(1)
    {
        n = sendto(sockfd,(char*) &message, sizeof(message), 0, (struct sockaddr *)&serveraddr, serverlen);
        if (n < 0) 
            error("ERROR in sendto");

        n = recvfrom(sockfd, buf, BUFSIZE, 0, (struct sockaddr *)&serveraddr, &serverlen);
        if (n < 0) 
            error("ERROR in recvfrom");
        if(n>0)
            break;
    }
    //print server's response
    printf("server's response : %s\n", buf);

    
    //return 0;
    int fd = open(filename, O_RDONLY);
    if( fd < 0 )error("error opening file");
    
    int i, m;
    printf("chunks : %d\n", len);
    
    int base = 1;
    int wind_end = base;
    int nextsequencenumber = 1;
    int breakflag = 0;
    pid_t child_pid;
    int iter = window;
    int exitflag = 0;
    int sequence_number = 1;
    int cumulative = 0;

    while(1)
    {
        printf("window size : %d\n", window);
        
        iter = window - q.size();
        
        while(iter-- && sequence_number <= len){
            bzero(p.buf, BUFSIZE);
            n = read(fd, p.buf+8, BUFSIZE-8);
            if (n == 0){
                printf("zero bytes read\n");
                //printf("cumulative : %d\n", cumulative);
                break;
            }
            if (n == -1) 
                error("error reading file");

            ((int*)p.buf)[0]=sequence_number++;
            ((int*)p.buf)[1]=n;

            q.push_back(p);

        }

        for(int i = 0; i < window && i < q.size(); i++){
            p = q[i];
            
            m = sendto(sockfd, p.buf, ((int *)p.buf)[1] + 8, 0, (struct sockaddr *)&serveraddr, serverlen);
            if (m < 0) {
                error("ERROR writing into the socket");
            }
            //printf("\n\npacket start %d\n sent %d\n%s\n\n",((int *)p.buf)[0], m,  p.buf+8);
            if(nextsequencenumber == base){
                //start timer
                alarm(SLEEP_VAL);
                (void) signal(SIGALRM, mysig);
            }
            printf("sent %d\n", ((int *)p.buf)[0] );
            nextsequencenumber++;              
        }


        initbase = base;
        do{
            //printf("for recieve\n");
            n = recvfrom(sockfd, buf, BUFSIZE, 0, (struct sockaddr *)&serveraddr, &serverlen);
            if(n == 0)continue;
            if (n < 0) 
                break;
            if(n>0 && ((int*)buf)[0] < base)continue;
            if(n>0 && ((int*)buf)[0] > len )continue;
            base = ((int*)buf)[0] + 1;
            
            if (base == nextsequencenumber){
                break;
            }
        }while(!alarm_fired);
        
        printf("next packet to send %d\n", base);
        
        while(initbase!=base){
            q.pop_front();
            initbase++;
        }
        
        if(base == len + 1)break;
        else if (base < nextsequencenumber){ 
            threshhold = window/2; 
            window = 1;
            nextsequencenumber = base; 
            alarm(SLEEP_VAL);
            (void) signal(SIGALRM, mysig);
        }     
        else if(window >= threshhold ) window+=1;
        else window = window * 2;

    }
    
    printf("file sent\n");
    close(fd);
    bzero(buf,BUFSIZE);

    //generate MD5 value
    strcat(md5checksum,filename);
    strcat(md5checksum," > file1");
    unsigned int md5;
    system(md5checksum);
    char MD5[1000];
    char text;
    i = 0;
    FILE *md=fopen("file1","r");
    while((fscanf(md,"%c",&text))==1)MD5[i++]=text;
    fclose(md);
    remove("file1");
    printf("md5sum value  at  client : %s\n",MD5 );

    //recieve MD5 value
    printf("before read md5\n");
    bzero(buf, BUFSIZE);
    n = recvfrom(sockfd, buf, 1000, 0, (struct sockaddr *)&serveraddr, &serverlen);
    if (n < 0) 
        error("ERROR in recvfrom");
    
    printf("md5sum value from server : %s\n",buf );
    
    //compare the two MD5 values
    if(strcmp(buf, MD5) == 0)printf("MD5 VALUES MATCHED\n");
    else printf("MD5 VALUES NOT MATCHED\n");

    close(sockfd);
    return 0;

    /* send the message to the server */
    /*serverlen = sizeof(serveraddr);
    n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&serveraddr, serverlen);
    if (n < 0) 
      error("ERROR in sendto");
    */
    /* print the server's reply */
    /*n = recvfrom(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&serveraddr, &serverlen);
    if (n < 0) 
      error("ERROR in recvfrom");
    printf("Echo from server: %s", buf);
    return 0;
    */
}
