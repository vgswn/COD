#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define WAIT 1
int main()
{
    struct sockaddr_in adr;
    int sockfd;
    if((sockfd=socket(AF_INET,SOCK_DGRAM,0))==-1)
    {
        perror("socket");
        exit(-1);
    }
    

    adr.sin_family=AF_INET;
    adr.sin_port=htons(1234);
    struct in_addr sin_addr;
    inet_aton("127.0.0.1",&sin_addr);
    adr.sin_addr=sin_addr;
    int len=sizeof(struct sockaddr_in);
    bzero(&adr.sin_zero, 0);    


    char            name[20] = {0};
    fd_set          input_set;
    struct timeval  timeout;
    int             ready_for_reading = 0;
    int             read_bytes = 0;
    FD_ZERO(&input_set );
    FD_SET(0, &input_set);
    timeout.tv_sec = WAIT;    // WAIT seconds
    timeout.tv_usec = 0;    // 0 milliseconds
    /* Listening for input stream for any activity */





    
    char buffer[1024],s[1024];
    while(1)
    {
            ready_for_reading = select(1, &input_set, NULL, NULL, &timeout);
    if (ready_for_reading == -1) {
        /* Some error has occured in input */
        printf("Unable to read your input\n");
        return -1;
    } 
    if (ready_for_reading) {
        read_bytes = read(0, s, 1024);
        if(s[read_bytes-1]=='\n'){
        --read_bytes;
        s[read_bytes]='\0';
        }
                sendto(sockfd,s,1024,0,(struct sockaddr *)(&adr),len);
        if(strcmp(s,"bye")==0)
        {
            break;
        }
    }

        int rd=recvfrom(sockfd,buffer,1024,0,(struct sockaddr *)(&adr),(socklen_t *)(&len));
        printf("Received from server %s\n",buffer);
    }
    close(sockfd);


    return 0;
}