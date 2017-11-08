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
#include <bits/stdc++.h>
using namespace std;

int arr[24];
int sockfd;
int sz=0;
int flag[24];
string clients[24];
string message;
int plc=0;
void *fun1(void *arg)
{
	while(1)
	{
		int i,x,ns;
		int rd=0;
		int *p=(int*)arg;
		ns=*p;
		char buffer[1024];
		rd=0;
		while(rd==0)
		{

			rd=read(ns,buffer,1024);
		}
		cout<<ns<<endl;

		message=buffer;
		for(i=0;i<sz;i++)
		{
			if(arr[i]==ns)
			{
				x=i;
				break;
			}
		}
		if(flag[x]==0)
		{
			
			clients[x]=message;

		string new_message_=clients[x]+" joined the chat ";
					for(i=0;i<sz;i++)
		{
			send(arr[i],new_message_.c_str(),1024,0);
		}
			flag[x]++;
			continue;
		}
		if(message=="bye")
		{	
			string new_message_;
			new_message_=clients[x]+" left the chat ";
				for(i=0;i<sz;i++)
			{
			send(arr[i],new_message_.c_str(),1024,0);
			}
					plc++;
		}
		if(plc==sz&&plc)
		{
			break;
		}
		string new_message;
		new_message=clients[x];
		new_message=new_message+" : ";
		new_message=new_message + message;

		//printf("%s\n",ts);
		for(i=0;i<sz;i++)
		{
			send(arr[i],new_message.c_str(),1024,0);
		}
	}

}
void *func(void *arg)
{
	while(1)
	{
	struct sockaddr_in clientadr;
	int len=sizeof(clientadr);
	int ns;
	if((ns=accept(sockfd,(struct sockaddr *)(&clientadr),(socklen_t *)(&len)))<0)
	{
		perror("accept");
		exit(-1);
	}
	arr[sz++]=ns;
	pthread_t tid;
	tid=pthread_create(&tid,NULL,fun1,(void *)(&ns)); 
	}
}
int main()
{
	struct sockaddr_in adr;
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket");
		exit(-1);
	}
	

	adr.sin_family=AF_INET;
	adr.sin_port=htons(1238);
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
	
	pthread_t tid;
	pthread_create(&tid,NULL,func,(void *)1); 


	int i,j,flag;
	struct sockaddr_in ca;
	len=sizeof(struct sockaddr);
	
	char s[1024];
	int x;
	int ns;
	while(1)
	{
		if(plc==sz&&plc)
		{
			break;
		}

	}
	close(sockfd);

	return 0;
}