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
#include <pthread.h>
#include <sys/sem.h>
#include <semaphore.h>
sem_t mutex,mutex1;
    char buffer[1024],s[1024];
    int f,f1;
    struct sockaddr_in adr;
   int sockfd;
       int len=sizeof(struct sockaddr_in);
void *f_read(void *a)
{

	while(1)
    {
        if(f==0){
        sem_wait (&mutex);	
    	
    	scanf("%s",s);
    	f=1;
    	sem_post (&mutex);	
    }

        
    }

}
void *f_write(void *b)
{

	while(1)
	{
		        if(f1==0){
		        sem_wait (&mutex1);	
    
    	        int rd=recvfrom(sockfd,buffer,1024,0,(struct sockaddr *)(&adr),(socklen_t *)(&len));
    	f1=1;
    	sem_post (&mutex1);
    }

	}
}



int main()
{
    
 
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

    bzero(&adr.sin_zero, 0);    


 

 sem_init(&mutex, 0, 1);
 sem_init(&mutex1, 0, 1);
f=0;f1=0;



    pthread_t tid1,tid2;
    char name[1024];
    printf("Enter your Name \n");
scanf("%s",name);
sendto(sockfd,name,1024,0,(struct sockaddr *)(&adr),len);
    pthread_create(&tid1, NULL, f_read, (void *)0);
    pthread_create(&tid2, NULL, f_write, (void *)1);
    
    

    while(1)
    {
    	
    	if(f==1)
    	{	sem_wait (&mutex);

    		sendto(sockfd,s,1024,0,(struct sockaddr *)(&adr),len);
    		    		if(strcmp(s,"bye")==0)
    			break;
    		f=0;
    		sem_post (&mutex);

    	}
    	if(f1==1)
    	{	sem_wait (&mutex1);
    		printf("%s\n",buffer);
    		f1=0;
    		sem_post (&mutex1);
    	}


    }
    close(sockfd);


    	

    



    return 0;
}