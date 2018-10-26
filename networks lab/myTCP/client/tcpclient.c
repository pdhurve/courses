/* 
 * tcpclient.c - A simple TCP client
 * usage: tcpclient <host> <port>
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
#define MAX_FILENAME_SIZE 100
/* 
 * error - wrapper for perror
 */
void error(char *msg) {
    perror(msg);
    exit(0);
}

char md5checksum[1000] = "md5sum ";         

int main(int argc, char **argv) {
    int sockfd, portno, n;
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
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
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

    /* connect: create a connection with the server */
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) 
      error("ERROR connecting");

    char *filename = (char *)malloc(MAX_FILENAME_SIZE*sizeof(char));
    printf( "Enter the name of the file\n");
    scanf("%s", filename);
    //int i;
    //for(i = 0; i < strlen(filename); i++);
    struct stat st;
    stat(filename, &st);
    int size = st.st_size;
    char *filesize;
    sprintf(filesize, "%d", size);

    char message[100] = "";
    strcat(message, filename);
    strcat(message, " ");
    strcat(message, filesize);

    n = write(sockfd, message, strlen(message));
    if (n < 0) 
      error("ERROR writing to socket");

    //read from server
    bzero(buf, BUFSIZE);
    n = read(sockfd, buf, BUFSIZE);
    if (n < 0) 
      error("ERROR reading from socket");
    printf("Echo from server: %s\n", buf);
   
    //open file
    int fileid =  open(filename, O_RDONLY);
    if(fileid == -1)    error((char *) "ERROR opening file......");

    bzero(buf,BUFSIZE);
    //send file
    while (1) {
        n = read(fileid, buf, BUFSIZE);
        if (n == 0)
            break;
        if (n == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        if (write(sockfd, buf, n) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }
    bzero(buf,BUFSIZE);
    close(fileid);

    //calculate md5sum
    strcat(md5checksum,filename);
    strcat(md5checksum," > file1");
    unsigned int md5;
    system(md5checksum);
    char MD5[1000];
    char text;
    int i = 0;
    FILE *md=fopen("file1","r");
    while((fscanf(md,"%c",&text))==1)MD5[i++]=text;
    fclose(md);
    remove("file1");
    printf("md5sum value from client : %s\n",MD5 );
    

    // read md5sum from server
    n = read(sockfd, buf, BUFSIZE);
    if(n < 0) printf("Error reading from server\n");
    printf("md5sum value from server : %s\n", buf);
    
    //compare the two md5sum values
    if(strcmp(buf, MD5) == 0)printf("MD5 VALUES MATCHED\n");
    else printf("MD5 VALUES NOT MATCHED\n");
    
    close(sockfd);
    return 0;
}
