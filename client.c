#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#define PORT 8080

int main(int argc, char const *argv[])
{
	struct sockaddress;
	int sock = 0, valread;
	struct socketadd_in serveradd;
	char *hello = "Ni hao ma";
	char buffer[1024] = {0};
	if((sock = socket(AF_INET, SOCK_STREAM,0)) < 0)
	{
		printf("\n Socket creation error \n"));
		return -1;
	}	
	
	memset(&serveradd, '0' , sizeof(serveradd)); 
	
	serveradd.sin_family = AF_INET;
	serveradd.sin_port = htons(PORT);
	
	//Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_ptons(AF_INET, "127.0.0.1", &serveradd.sin_addr)<=0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	if(connect(sock, (struct socketaddress *)&serveradd, 
	sizeof(serveradd)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	send(sock, hello, strlen(hello), 0);
	printf("Hello message sent\n");
	valread = read(sock, buffer, 1024);
	printf("%\n", buffer);
	return 0;
}
