/* 
 * tcpserver.c - A simple TCP echo server 
 * usage: tcpserver <port>
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
#include <sys/select.h>

#define BUFSIZE 1024

struct timeval {
  int tv_sec;
  int tv_usec;
}tv;

struct connect {
  char name[20];
  char ip[32];
  cha
}

fd_set readfds, mainfds;

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
  int maxfd;
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
  
  tv.tv_sec = 10;
  tv.tv_usec = 500000;
  
  FD_ZERO(&mainfds);
  FD_ZERO(&readfds);
  FD_SET(parentfd, &readfds);
  FD_SET(parentfd, &mainfds);
  int fd;
  maxfd = parentfd + 1;

  while (1) {
    

    fd = select(maxfd, &readfds, NULL, NULL, &tv);

    if (fd == -1) {
      perror("select"); 
    } else if (fd == 0) {
      printf("Timeout occurred!  No data after 10.5 seconds.\n");
    }else {
      for(int i = 0; i < maxfd; i++){
        
        if(!FD_ISSET(i, &readfds))continue;

        if(i == parentfd){
          clientlen = sizeof(clientaddr);
          childfd = accept(parentfd, (struct sockaddr *) &clientaddr, &clientlen);
          if (childfd < 0)
            error("ERROR on accept");
          else{
            FD_SET(childfd,&master);
            if(childfd > fd_max)
              fd_max = childfd;
          }
        }
        else if(i == STDIN){
          bzero(buf, BUFSIZE);
          fgets(buf, BUFSIZE, stdin);
          j=0;
          while(buf[j]!='/')
          {
            frnd_name[j] = buf[j];
            j++;
          }

          FILE *fp = fopen("user_info.txt", "r");
          char name[10], ip[32];
          int port;
          int found = 0;
          while(fscanf(fp, "%s %s %s", name, ip, port) == 3)
            if(strcmp(frnd_name, name) == 0){found = 1;break;}

          if(found == 0)continue;
          found = 0;
          for(int i =0; i < 5; i++)
            if(strcmp(arr[i].name,frnd_name) == 0){
              found = 1;
              //send

            }

          //if required connect to peer
          if(found == 0){

          }
          

        }
        else{

          n = read(i, buf, BUFSIZE);
          if (n <= 0)
          {
            if(n==0)
              printf("\nsocket %d hung up\n",i);
            else
              error("ERROR reading from socket");
        
            close(i);
            FD_CLR(i,&master);
          }
          else
          {
            printf("\nMessage recieved from socket %d ---> %s\n",i,buf);
          }
        }

  }

  
  }
}

