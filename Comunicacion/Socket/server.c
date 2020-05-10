#include "./server.h"
struct sockaddr_in sa;
void setServer(int socket_id,int port,int max_queue)
{
	bzero((char *) &sa, sizeof(struct sockaddr_in));
 	sa.sin_family = AF_INET;
 	sa.sin_port = htons(port);
	sa.sin_addr.s_addr = INADDR_ANY;
 	bind(socket_id,(struct sockaddr *)&sa,sizeof(struct sockaddr_in));    
 	listen(socket_id,max_queue);
};
int main(int argc, char *argv[])
{
	int habilitar = 1;
	socklen_t cl=sizeof(struct sockaddr_in);
	struct sockaddr_in ca;
 	int server_socket;
	int client_socket;
	char buffer[TAM_BUF];
	if((server_socket=socket(AF_INET,SOCK_STREAM,0)) ==-1)	
		return 1;
	if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &habilitar, sizeof(int)) < 0)
        return 1;
	setServer(server_socket,PORT,MAX_QUEUE);
 	client_socket=accept(server_socket,(struct sockaddr *) &ca, &cl);
	send(client_socket,"BIENVENIDO",10,0);
	bzero(buffer,TAM_BUF);
	recv(client_socket,buffer,TAM_BUF,0);
	printf("MSG RECV: %s\n",buffer);
	sprintf(buffer,"chau");
	send(client_socket, buffer, strlen(buffer), 0);	
 	close(client_socket);
 	close(server_socket);
 	return 0; 
};

