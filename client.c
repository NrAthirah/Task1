#include<unistd.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#define PORT 8080

int main()
	{
		char cclient_msg[256] = "Ni hao ma" ;
		char cclient_respond[256] ;
		char server_msg[256] = "Ni hao ma" ;
		char server_respond[256] ;
		int network_socket ;
		network_socket = socket(AF_INET, SOCK_STREAM, 0) ;
	
		struct sockaddr_in cclient_address ;
		cclient_address.sin_family = AF_INET ;
		cclient_address.sin_port = htons(10000) ;
		cclient_address.sin_addr.s_addr = inet_addr("ipaddr") ;
		struct sockaddr_in server_address ;
		server_address.sin_family = AF_INET ;
		server_address.sin_port = htons(10000) ;
		server_address.sin_addr.s_addr = inet_addr("192.168.203.130") ;
	
		int status = connect(network_socket, (struct sockaddr *) 
	&cclient_address, sizeof(cclient_address)) ;
	&server_address, sizeof(server_address)) ;
	
		if(status == -1)
		{
			printf("Error\n") ;
		}
	
		send (network_socket, cclient_msg, sizeof(cclient_msg) ,0) ;
		send (network_socket, server_msg, sizeof(server_msg) ,0) ;
	
		recv(network_socket, cclient_respond, sizeof(cclient_respond) , 
		recv(network_socket, server_respond, sizeof(server_respond),0) ;
	
		printf("Client message : %s\n" , cclient_respond) ;
		printf("Client message : %s\n" , server_respond) ;
		close(network_socket) ;
	
		return 0 ;
}
		     
