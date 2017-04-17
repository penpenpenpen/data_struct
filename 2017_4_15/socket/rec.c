#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
	//int sfd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	int sfd = socket(PF_INET, SOCK_DGRAM, 0);
	if(sfd < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in my;
	my.sin_family = PF_INET;
	my.sin_port = htons(0x8888);
	my.sin_addr.s_addr = htonl(INADDR_ANY);

	int ret = bind(sfd, (struct sockaddr *)&my, sizeof(my));
	if(ret < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}
	
	char buff[1024] = {0};
	struct sockaddr_in  snd;
	int len;
	
	while(1){
		ret = recvfrom(sfd, buff, 1024, 0, 
				(struct sockaddr *)&snd, &len);
		if(ret < 0){
			perror("recvfrom");
			exit(EXIT_FAILURE);
		}
		
		printf("src ip: %s\n", inet_ntoa(snd.sin_addr));
		printf("data len: %d\n", len);
		printf("data is: %s\n", buff);
		printf("not port is: 0x%x\n",snd.sin_port );
		printf("port is: 0x%x\n", ntohs(snd.sin_port));
	}
	
	
	close(sfd);
	
}















