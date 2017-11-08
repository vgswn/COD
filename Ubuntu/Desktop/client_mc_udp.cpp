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
#include <pthread.h>
#include <bits/stdc++.h>
using namespace std ;
struct sockaddr_in server_address;
int socket_client;


string message_in,message_out;
int flag_in,flag_out;
int len;
void *func1(void *arg)
{
	while(1)
	{
		if(flag_in==0)
		{
				getline(cin,message_out);
				cin.clear();

				flag_in=1;
		}
	}
}
void *func2(void *arg)
{
	while(1)
	{	char buffer[1024];
		if(flag_out==0)
		{
			recvfrom(socket_client,buffer,1024,0,(struct sockaddr *)(&server_address),(socklen_t *)(&len));
			message_in=buffer;

			flag_out=1;
		}
	}
}
int main()
{

	if((socket_client=socket(AF_INET,SOCK_DGRAM,0))==-1)
	{
		perror("socket");
		exit(-1);
	}
	

	server_address.sin_family=AF_INET;
	server_address.sin_port=htons(5555);
	struct in_addr sin_addr;
	inet_aton("127.0.0.1",&sin_addr);
	server_address.sin_addr=sin_addr;
	len=sizeof(struct sockaddr_in);
	bzero(&server_address.sin_zero, 0);	

	getline(cin,message_out);
	cin.clear();

	sendto(socket_client,message_out.c_str(),1024,0,(struct sockaddr *)(&server_address),len);
	
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,func1,(void *)1);
	pthread_create(&tid2,NULL,func2,(void *)1);

	while(1)
	{
		if(flag_in==1)
		{
			sendto(socket_client,message_out.c_str(),1024,0,(struct sockaddr *)(&server_address),len);
			if(message_out=="bye")
			{
				break;
			}
			flag_in=0;
		}
		if(flag_out==1)
		{
				cout<<message_in<<endl;
				flag_out=0;
		}
	}
	close(socket_client);


	return 0;
}