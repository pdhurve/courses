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

#define BUFSIZE 1024

/* 
 * error - wrapper for perror
 */
char md5checksum[1000] = "md5sum ";  

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char **argv) {
    int sockfd, portno, n;
    int serverlen;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char *hostname;
    char buf[BUFSIZE];

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

    char message[1000] = "";
    strcat(message, filename);
    strcat(message, " ");
    strcat(message, filesize);

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

    int len = size/1016;
    if(size%1016)len++;
    //return 0;
    int fd = open(filename, O_RDONLY);
    if( fd < 0 )error("error opening file");
    
    int i, m;
    //printf("%d\n", len);
    for(i = 1; i <= len; i++)
    {

        bzero(buf, BUFSIZE);
        n = read(fd, buf+8, BUFSIZE-8);
            if (n == 0)
                break;
            if (n == -1) 
                error("error reading file");

            ((int*)buf)[0]=i;
            ((int*)buf)[1]=n;
            
        while (1) {
            
            m = sendto(sockfd, buf, n+8, 0, (struct sockaddr *)&serveraddr, serverlen);
            if (m < 0) {
                error("ERROR writing into the socket");
            }
            n = recvfrom(sockfd, buf, BUFSIZE, 0, (struct sockaddr *)&serveraddr, &serverlen);
            if (n < 0) 
                error("ERROR in recvfrom");
            if(n>0 && ((int*)buf)[0] == i )
                break;
        
        }
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
