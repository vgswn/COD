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
	struct sockaddr_in arr[10];
	int c=0,i,c1=0;
	char buffer[1024],s[1024];
	char name[1024][1024];
	int x;
	while(1)
	{
		int rd=recvfrom(sockfd,buffer,1024,0,(struct sockaddr *)(&ca),(socklen_t *)(&len));
		int f=0;
		for (i = 0; i < c; ++i)
		{	
			if(arr[i].sin_port==ca.sin_port && arr[i].sin_addr.s_addr==ca.sin_addr.s_addr)
			{
				
				f=1;
				x=i;

				break;
			}
			
		}
		if(f==0)
		{
			strcpy(name[c],buffer);
			arr[c++]=ca;
			printf("%s aaya\n",name[c-1]);
			continue;
		}
		for (i = 0; i < c; ++i)
		{
			int j=0;
			char fg[1024];
			
			int ll=0;

			for(ll=0;ll<strlen(name[x]);ll++)
			{
				fg[j++]=name[x][ll];
			}
			fg[j++]=':';
			for(ll=0;ll<strlen(buffer);ll++)
			{
				fg[j++]=buffer[ll];
			}
			fg[j]='\0';
			sendto(sockfd,fg,1024,0,(struct sockaddr *)(&arr[i]),len);
		}
		printf("%s\n",buffer);
		if(strcmp(buffer,"bye")==0)
		{
			c1++;
		}
		if(c==c1)
			break;
		//scanf("%s",s);
		
	}
	close(sockfd);

	return 0;
}