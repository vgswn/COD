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
int client_socket;
string message_in,message_out;
int flag_in,flag_out;
int len;
string myname;
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
	{
		int gb=0;
		if(flag_out==0)
		{
			string file_name;
			char buffer[1024];
			struct sockaddr_in ca;
			int len=sizeof(struct sockaddr);
			int rd=recvfrom(client_socket,buffer,1024,0,(struct sockaddr *)(&server_address),(socklen_t *)(&len));

			message_in=buffer;
			//cout<<message_in<<endl;
			int i,l=strlen(buffer),fld=0;
			char fn[1024];
			int in=message_in.find("File_");
			//cout<<in<<endl;

			if(in>=0 && in<message_in.size())
			{
					  
					 
					int index=message_in.find(":");



					file_name=message_in.substr(0,index)+"->"+message_in.substr(index+1,message_in.size());


					FILE *fptr;
					fptr=fopen(file_name.c_str(),"w+");
					
					while(1)
					{
						recvfrom(client_socket,buffer,1024,0,(struct sockaddr *)(&ca),(socklen_t *)(&len));
						message_in=buffer;
						index=message_in.find(":");

					  message_in=message_in.substr(index+1,message_in.size());


					  		if(message_in==" Closing File")
					  		{
					  			break;
					  		}
							fprintf(fptr,"%s\n",message_in.c_str());
						
					}
						fclose(fptr);
						message_in="File Received As "+ file_name;
						flag_out=1;

			}
			else
			{
						flag_out=1;


			}
		}
	}
}
int main()
{

	if((client_socket=socket(AF_INET,SOCK_DGRAM,0))==-1)
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
	getline(cin,myname);
	cin.clear();
	sendto(client_socket,myname.c_str(),1024,0,(struct sockaddr *)(&server_address),len);
		//sendto(client_socket,myname.c_str(),1024,0,(struct sockaddr *)(&server_address),len);

	
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,func1,(void *)1);
	pthread_create(&tid2,NULL,func2,(void *)1);

	while(1)
	{
		if(flag_in==1)
		{
			

			if(message_out.find("File_")!=string :: npos)

			{
				string file_name=message_out.substr(5,message_out.size());

				FILE *fptr;
				fptr=fopen(file_name.c_str(),"r+");
				//s="Sending File ";
				char buffer[1024];
				sendto(client_socket,message_out.c_str(),1024,0,(struct sockaddr *)(&server_address),len);
				while(fscanf(fptr," %[^\n]s",buffer)>0)
				{
					message_out=buffer;
					sendto(client_socket,message_out.c_str(),1024,0,(struct sockaddr *)(&server_address),len);

				}
				fclose(fptr);
				message_out="Closing File";
				sendto(client_socket,message_out.c_str(),1024,0,(struct sockaddr *)(&server_address),len);
			}
			else
			{
				sendto(client_socket,message_out.c_str(),1024,0,(struct sockaddr *)(&server_address),len);
				if(message_out=="bye")
				{
					break;
				}
			}
			flag_in=0;
		}
		if(flag_out==1)
		{
				cout<<message_in<<endl;
				flag_out=0;
		}
	}
	close(client_socket);


	return 0;
}