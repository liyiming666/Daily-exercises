#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <string>
#define MAX_BUF_SIZE 1024
#define PORT 8888
int main()
{ 
    int sockfd, addrlen, n; 
    char buffer[MAX_BUF_SIZE];
    struct sockaddr_in addr;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) 
    {  
        fprintf(stderr, "socket falied\n");   
        exit(EXIT_FAILURE);
    }  
    addrlen = sizeof(struct sockaddr_in); 
//    bzero(&addr, addrlen);
    addr.sin_family = AF_INET;  
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY); 
    puts("socket success");
  //  bzero(buffer, MAX_BUF_SIZE);
    string s= "{ID:ZSN00117A1800000,SIM:89860317452045302355,Size:9,Data:8040ff00641800003b}";
    fgets(buffer, MAX_BUF_SIZE, s.c_str());
    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)(&addr), addrlen);     
    printf("client send msg is %s\n", buffer);   
    n = recvfrom(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)(&addr), &addrlen);    
    fprintf(stdout, "clinet Receive message from server is %s\n", buffer); 
    close(sockfd);  
    exit(0); 
    return 0;
}
