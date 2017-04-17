#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	//int sfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);	
	int sfd = socket(AF_INET, SOCK_DGRAM, 0);	
	if(sfd < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	
	struct sockaddr_in mysock;

	mysock.sin_family = AF_INET;
	mysock.sin_port = htons(0x7788);
	mysock.sin_addr.s_addr = inet_addr("172.25.254.123");

	printf("port 0x%x\n", mysock.sin_port);
	char *buff = "hello westos";
	int ret = sendto(sfd, buff, strlen(buff)+1, 0, 
		(struct sockaddr *)&mysock, sizeof(mysock));
	if(ret < 0){
		perror("sendto");
		exit(EXIT_FAILURE);
	}
	
	close(sfd);
}















