#include "./cliente.h"
struct sockaddr_in sa;
void set(const char *y,int z)
{
	bzero(&(sa.sin_zero),8);
 	sa.sin_family =	AF_INET;
 	sa.sin_port	=	htons(z);
	sa.sin_addr.s_addr=	inet_addr(y);
};
int main(int argc, char *argv[])
{
	int x;
	char buffer[TAM_BUF];
	if((x=socket(AF_INET,SOCK_STREAM,0))==-1)	
		return 1;
	set(IP,PORT);
  	if(connect(x,(struct sockaddr *) &sa,sizeof(sa))==-1)	
		return 1;
	bzero(buffer,TAM_BUF);
	recv(x,buffer,TAM_BUF,0);
	printf("MSG SERVER: %s\n",buffer);
	printf("MSG SEND:");
	scanf("%s",buffer);
    send(x,buffer,strlen(buffer),0);
	bzero(buffer,TAM_BUF);
	recv(x,buffer,TAM_BUF,0);
  	printf("%s",buffer);
 	close(x);
 	return 0;
}