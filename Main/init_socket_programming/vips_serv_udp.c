#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
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

	if((bind(sockfd,(struct sockaddr *)(&adr),len))==-1)
	{
		perror("Bind");
		exit(-1);
	}

	struct sockaddr_in ca;
	len=sizeof(struct sockaddr);

	char buffer[1024],s[1024];
	while(1)
	{
		int rd=recvfrom(sockfd,buffer,1024,0,(struct sockaddr *)(&ca),(socklen_t *)(&len));
		printf("Received from client %s\n",buffer);
		if(strcmp(buffer,"bye")==0)
		{
			break;
		}
		scanf("%s",s);
		sendto(sockfd,s,1024,0,(struct sockaddr *)(&ca),len);
	}
	close(sockfd);

	return 0;
}