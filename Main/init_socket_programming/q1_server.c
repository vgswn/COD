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
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket");
		exit(-1);
	}
	

	adr.sin_family=AF_INET;
	adr.sin_port=htons(1231);
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

	if((listen(sockfd,2))==-1)
	{
		perror("listen");
		exit(-1);
	}

	struct sockaddr_in clientadr;
	len=sizeof(clientadr);
	int ns;
	if((ns=accept(sockfd,(struct sockaddr *)(&clientadr),(socklen_t *)(&len)))<0)
	{
		perror("accept");
		exit(-1);
	}

	while(1)
	{
		char buffer[1024]={0},s[1024]={0};
		int j=0;
		while(1)
		{
			int rd=read(ns,buffer,1024);
			int c=0;
			if(strcmp(buffer,"*")==0)
			{
				break;
			}
			for(c=0;c<strlen(buffer);c++)
			{
				s[j++]=buffer[c];
			}
		}
		s[j]='\0';
		printf("Received from client %s\n",s);
		if(strcmp(s,"bye")==0)
		{
			break;
		}
	}
	close(sockfd);

	return 0;
}