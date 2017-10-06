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
	int sock_id_server;
	struct sockaddr_in server;


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




size_t l = 0;

	printf("conneced\n");
	FILE *fp;
	char s[1024];
	printf("Enter File Namw\n");
	scanf("%s",s);
	sendto(sock_id_server,s,1024,0,(struct sockaddr*)(&server),len);
	fp=fopen(s,"r");
	char * c = NULL;
		int r;


    while ((r = getline(&c, &l, fp)) != -1) {
	sendto(sock_id_server,c,1024,0,(struct sockaddr*)(&server),len);
	//printf("%s",c );
        
    }
	/*while(1)
	{
		//c=fgetc(fp);
		scanf("%s",c);
		send(sock_id_server,c,1024,0);
		//if(c==EOF)
		//	break;
				if(strcmp("bye",c)==0)


				break;

	}*/

	fclose(fp);
	sendto(sock_id_server,"###",1024,0,(struct sockaddr*)(&server),len);




}