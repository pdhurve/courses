/* 
 * @author : Pankaj Dhurve
 * udpserver.c - A UDP echo server 
 * usage: udpserver <port_for_server>
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <openssl/md5.h>
#include <openssl/sha.h>

#define BUFSIZE 1024

/*
 * error - wrapper for perror
 */

void error(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char **argv) {
  int sockfd; /* socket file descriptor - an ID to uniquely identify a socket by the application program */
  int portno; /* port to listen on */
  int clientlen; /* byte size of client's address */
  struct sockaddr_in serveraddr; /* server's addr */
  struct sockaddr_in clientaddr; /* client addr */
  struct hostent *hostp; /* client host info */
  char buf[BUFSIZE]; /* message buf */
  char *hostaddrp; /* dotted decimal host addr string */
  int optval; /* flag value for setsockopt */
  int n; /* message byte size */
  char filename[100];
  int fd, j, i;
  /* 
   * check command line arguments 
   */
  if (argc != 2) {
    fprintf(stderr, "usage: %s <port_for_server>\n", argv[0]);
    exit(1);
  }
  portno = atoi(argv[1]);

  /* 
   * socket: create the socket 
   */
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) 
    error("ERROR opening socket");

  /* setsockopt: Handy debugging trick that lets 
   * us rerun the server immediately after we kill it; 
   * otherwise we have to wait about 20 secs. 
   * Eliminates "ERROR on binding: Address already in use" error. 
   */
  optval = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, 
       (const void *)&optval , sizeof(int));

  /*
   * build the server's Internet address
   */
  bzero((char *) &serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serveraddr.sin_port = htons((unsigned short)portno);

  /* 
   * bind: associate the parent socket with a port 
   */
  if (bind(sockfd, (struct sockaddr *) &serveraddr, 
     sizeof(serveraddr)) < 0) 
    error("ERROR on binding");

  /* 
   * main loop: wait for a datagram, then echo it
   */
  clientlen = sizeof(clientaddr);
  while (1) {

    /*
     * recvfrom: receive a UDP datagram from a client
     */
    //printf("Here\n");
    //fflush(stdout);
    bzero(buf, BUFSIZE);
    n = recvfrom(sockfd, buf, BUFSIZE, 0,
     (struct sockaddr *) &clientaddr, &clientlen);
    if (n < 0)
      error("ERROR in recvfrom");

    /* 
     * gethostbyaddr: determine who sent the datagram
     */
    /*hostp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr, 
        sizeof(clientaddr.sin_addr.s_addr), AF_INET);
    if (hostp == NULL)
      error("ERROR on gethostbyaddr");
    hostaddrp = inet_ntoa(clientaddr.sin_addr);
    if (hostaddrp == NULL)
      error("ERROR on inet_ntoa\n");
    printf("server received datagram from %s (%s)\n", 
     hostp->h_name, hostaddrp);*/
    printf("server received %d/%d bytes: %s\n", (int)strlen(buf), n, buf);

    //print the received string
    //printf("%s\n",buf );

    n = sendto(sockfd, buf, strlen(buf)+1, 0,(struct sockaddr *) &clientaddr, clientlen);
    if (n < 0) 
      error("ERROR in sendto");
    //printf("came here\n");
    
    //extract filename
    for(j=0;buf[j]!=' ';j++)
        filename[j]=buf[j];
    filename[j]='\0';

    //printf("came here 2\n");
    int size = 0;
    //extract filesize
    j++;
    for(; buf[j] != '\0'; j++){
      //printf("%d %c\n",size,buf[j] );
      size = size * 10 + (int)(buf[j] - '0');
    }
    //printf("came here\n");
    printf("filename : %s\n", filename);
    printf("size : %d\n", size);
    int iter = size/1016;
    if(size%1016)iter++;
    bzero(buf,BUFSIZE);
    //printf("%d\n", iter);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    for(i = 1; i <= iter; )
    {
        //printf("loop started: %d: %d:\n",i, nframes);
        n = recvfrom(sockfd, buf, BUFSIZE, 0,(struct sockaddr*) &clientaddr, &clientlen);
        if (n < 0)
          error("ERROR in recvfrom");

        if(((int*)buf)[0]==i)
        {
            sendto(sockfd, buf, sizeof(int), 0,(struct sockaddr *) &clientaddr, clientlen);
            
            i++;
            if (write(fd, buf+8, n-8) == -1) {
              error("write");
            }

        }
        else{
            n = sendto(sockfd, buf, sizeof(int), 0,(struct sockaddr *) &clientaddr, clientlen);
            if (n < 0) 
              error("ERROR in sendto");
        }
    }
    
    printf("file received\n");
    close(fd);

    char md5checksum[80]="md5sum ";
    strcat(md5checksum,filename);
    strcat(md5checksum," > file1");
    unsigned int md5;
    system(md5checksum);
    char MD5[1000];
    bzero(MD5, sizeof(MD5));
    char text;
    int i = 0;
    FILE *md=fopen("file1","r");
    while((fscanf(md,"%c",&text))==1)MD5[i++]=text;
    fclose(md);
    remove("file1");
    printf("md5sum generated at server : %s ",MD5 );

    n = sendto(sockfd, MD5, strlen(MD5), 0,(struct sockaddr *) &clientaddr, clientlen);
      if (n < 0) 
        error("ERROR in sendto");

    /* 
     * sendto: echo the input back to the client 
     */
    /*  
    n = sendto(sockfd, buf, strlen(buf), 0, 
         (struct sockaddr *) &clientaddr, clientlen);
    if (n < 0) 
      error("ERROR in sendto");*/
  }
  close(sockfd);
  return 0;
}
