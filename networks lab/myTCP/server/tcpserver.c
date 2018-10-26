/* 
 * tcpserver.c - A simple TCP echo server 
 * usage: tcpserver <port>
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
#include <arpa/inet.h>
#include <fcntl.h>
#include <openssl/md5.h>
#include <openssl/sha.h>

#define BUFSIZE 1024
#define MAX_FILENAME_SIZE 100

#if 0
/* 
 * Structs exported from in.h
 */

/* Internet address */
struct in_addr {
  unsigned int s_addr; 
};

/* Internet style socket address */
struct sockaddr_in  {
  unsigned short int sin_family; /* Address family */
  unsigned short int sin_port;   /* Port number */
  struct in_addr sin_addr;	 /* IP address */
  unsigned char sin_zero[...];   /* Pad to size of 'struct sockaddr' */
};

/*
 * Struct exported from netdb.h
 */

/* Domain name service (DNS) host entry */
struct hostent {
  char    *h_name;        /* official name of host */
  char    **h_aliases;    /* alias list */
  int     h_addrtype;     /* host address type */
  int     h_length;       /* length of address */
  char    **h_addr_list;  /* list of addresses */
}
#endif

/*
 * error - wrapper for perror
 */
void error(char *msg) {
  perror(msg);
  exit(1);
}

char* extractMessage (char* s) {
  int i;
  char* res = (char *) malloc ((100) * sizeof (char ));
  for (i = 0; i < strlen (s) && s[i]!= ' '; i++) {
    res[i] = s[i];
  }
  res[i] = '\0';
  return res;
}

long long int getsize(char* s) {
  int i, size = 0;
  for (i = 0; i < strlen (s) && s[i]!= ' '; i++);
  i++;
  for(; i < strlen(s); i++){
    size = size*10 + s[i] - '0';      
  }
  return size;
}

int main(int argc, char **argv) {
  int parentfd; /* parent socket */
  int childfd; /* child socket */
  int portno; /* port to listen on */
  int clientlen; /* byte size of client's address */
  struct sockaddr_in serveraddr; /* server's addr */
  struct sockaddr_in clientaddr; /* client addr */
  struct hostent *hostp; /* client host info */
  char buf[BUFSIZE]; /* message buffer */
  char *hostaddrp; /* dotted decimal host addr string */
  int optval; /* flag value for setsockopt */
  int n; /* message byte size */

  /* 
   * check command line arguments 
   */
  if (argc != 2) {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(1);
  }
  portno = atoi(argv[1]);

  /* 
   * socket: create the parent socket 
   */
  parentfd = socket(AF_INET, SOCK_STREAM, 0);
  if (parentfd < 0) 
    error("ERROR opening socket");

  /* setsockopt: Handy debugging trick that lets 
   * us rerun the server immediately after we kill it; 
   * otherwise we have to wait about 20 secs. 
   * Eliminates "ERROR on binding: Address already in use" error. 
   */
  optval = 1;
  setsockopt(parentfd, SOL_SOCKET, SO_REUSEADDR, 
	     (const void *)&optval , sizeof(int));

  /*
   * build the server's Internet address
   */
  bzero((char *) &serveraddr, sizeof(serveraddr));

  /* this is an Internet address */
  serveraddr.sin_family = AF_INET;

  /* let the system figure out our IP address */
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

  /* this is the port we will listen on */
  serveraddr.sin_port = htons((unsigned short)portno);

  /* 
   * bind: associate the parent socket with a port 
   */
  if (bind(parentfd, (struct sockaddr *) &serveraddr, 
	   sizeof(serveraddr)) < 0) 
    error("ERROR on binding");

  /* 
   * listen: make this socket ready to accept connection requests 
   */
  if (listen(parentfd, 5) < 0) /* allow 5 requests to queue up */ 
    error("ERROR on listen");
  printf("Server Running ....\n");
  /* 
   * main loop: wait for a connection request, echo input line, 
   * then close connection.
   */
  clientlen = sizeof(clientaddr);
  while (1) {

    /* 
     * accept: wait for a connection request 
     */
    childfd = accept(parentfd, (struct sockaddr *) &clientaddr, &clientlen);
    if (childfd < 0) 
      error("ERROR on accept");
    
    /* 
     * gethostbyaddr: determine who sent the message 
     */
    /*hostp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr, 
			  sizeof(clientaddr.sin_addr.s_addr), AF_INET);
    if (hostp == NULL)
      error("ERROR on gethostbyaddr");
    hostaddrp = inet_ntoa(clientaddr.sin_addr);
    if (hostaddrp == NULL)
      error("ERROR on inet_ntoa\n");
    printf("server established connection with %s (%s)\n", 
	   hostp->h_name, hostaddrp);*/
    
    /* 
     * read: read input string from the client
     */
    bzero(buf, BUFSIZE);
    n = read(childfd, buf, BUFSIZE);
    if (n < 0) 
      error("ERROR reading from socket");
    printf("server received %d bytes: %s\n", n, buf);

    
    char* filename = extractMessage (buf);
    long long int file_size =  getsize(buf);
    

    printf ("Filename : %s\n", filename);
    printf ("Size : %lld\n", file_size);

    n = write(childfd, buf, strlen(buf));
    if(n<0) error("Error writing to socket");
    
    int filefd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        if (filefd == -1)
            error("open");
          int acquired = 0;
    while(1) {
            n = read(childfd, buf, BUFSIZE);
            if(n == 0)break;
            if (n == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }
            if (write(filefd, buf, n) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }
            acquired += n;
            if (acquired == file_size) {
              break;
            }
    }
    close(filefd);
    
    char md5checksum[8]="md5sum ";
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
    printf("%s\n",MD5 );
    
    n = write(childfd, MD5, strlen(MD5));
    if (n < 0)error("ERROR writing to socket");

    close(childfd);
  }
}
