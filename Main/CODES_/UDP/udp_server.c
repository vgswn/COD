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

int main()
{
	int sock_id_server,sock_id_client;
	struct sockaddr_in server,client;


	if((sock_id_server=socket(AF_INET,SOCK_DGRAM,0))<0)
	{
		perror("socket");
		exit(-1);
	}
	server.sin_family=AF_INET;
	server.sin_port=htons(1536);

	struct in_addr new;
	inet_aton("127.0.0.1",&new);
	server.sin_addr=new;
	bzero(&server.sin_zero,0);

	int len=sizeof(server);

	if((bind(sock_id_server,(struct sockaddr *)(&server),len))==-1)
	{
		perror("Bind");
		exit(-1);
	}
	






	printf("conneced\n");

	char c[1024];
	char s[1024];
		recvfrom(sock_id_server,c,1024,0,(struct sockaddr *)(&client),(socklen_t *)(&len));

	strcpy(s,"new");
	int des=strlen(s);
	int j=des;
	int i;;
	for(i=0;i<strlen(c);i++)
		s[j++]=c[i];
	s[j]='\0';
	printf("%s\n",s );
	FILE *fp;
	fp=fopen(s,"w+");
	
	

	while(1)
	{
		recvfrom(sock_id_server,c,1024,0,(struct sockaddr *)(&client),(socklen_t *)(&len));
		//fputc(c,fp);
		//if(c==EOF)
		//	break;
		if(strcmp("###",c)==0)
			break;
		fprintf(fp,"%s",c);
		
	}
	fclose(fp);
	




}