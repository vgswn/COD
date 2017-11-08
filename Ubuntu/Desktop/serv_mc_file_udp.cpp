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
using namespace std ;
int main()
{
	struct sockaddr_in server_address;
	int socket_server;
	if((socket_server=socket(AF_INET,SOCK_DGRAM,0))==-1)
	{
		perror("socket");
		exit(-1);
	}
	

	server_address.sin_family=AF_INET;
	server_address.sin_port=htons(5555);
	struct in_addr sin_addr;
	inet_aton("127.0.0.1",&sin_addr);
	server_address.sin_addr=sin_addr;
	int len=sizeof(struct sockaddr_in);
	bzero(&server_address.sin_zero, 0);	

	if((bind(socket_server,(struct sockaddr *)(&server_address),len))==-1)
	{
		perror("Bind");
		exit(-1);
	}


	struct sockaddr_in clients_address[24];
	int clients_size=0,i,j,flag;
	struct sockaddr_in client_address;
	len=sizeof(struct sockaddr);

	
	int x;
	int closed_clients=0;
	string message;
	string clients[24];
	while(1)
	{
		flag=0;
		char buffer[1024];
		int rd=recvfrom(socket_server,buffer,1024,0,(struct sockaddr *)(&client_address),(socklen_t *)(&len));
		message=buffer;
		for(i=0;i<clients_size;i++)
		{
			if(clients_address[i].sin_port==client_address.sin_port&&clients_address[i].sin_addr.s_addr==client_address.sin_addr.s_addr)
			{
				x=i;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			x=clients_size;
			clients[clients_size]=message;
			clients_address[clients_size++]=client_address;
			cout<<clients[clients_size-1]<<" joined the chat"<<endl;
			
			continue;
		}

		if(message=="bye")
		{
				cout<<clients[x]<<" left the chat"<<endl;
				closed_clients++;
		}
		if(closed_clients==clients_size&&closed_clients)
		{
			break;
		}
		string new_message;
		new_message=clients[x]+" : "+message;

		for(i=0;i<clients_size;i++)
		{
			sendto(socket_server,new_message.c_str(),1024,0,(struct sockaddr *)(&clients_address[i]),len);
		}
	}
	close(socket_server);

	return 0;
}