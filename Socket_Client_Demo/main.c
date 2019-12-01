//
//  main.c
//  Socket_Client_Demo
//
//  Created by zhangtalent on 2019/11/24.
//  Copyright © 2019 zhangtalent. All rights reserved.
//  Client

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    //create a socket , it returns a integer.
    
    /*Day01----Study
     与服务器读写 line 20 to 44
     */
    /**int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    char buff[1024];
    struct sockaddr_in sd;
    char *htmldata = "Nice to meet u,too";
    sd.sin_family = AF_INET;
    sd.sin_port = htons(8088);
    char *addr = "127.0.0.1";
    //generate addr
    int convertaddr_result = inet_pton(AF_INET,addr,&sd.sin_addr);
    printf("convert:%i",convertaddr_result);
    int conn_result = connect(client_socket, (struct sockaddr *)&sd, sizeof(sd));
    printf("conn:%i",conn_result);
    while (1) {
        if(write(client_socket, htmldata, 1024)>0){
            
        }
        while (read(client_socket,buff, sizeof(buff))) {
            fputs(buff, stdout);
            printf("---no over%c",buff[1023]);
            if(strlen(buff)<1024)break;
            bzero(buff,sizeof(buff));
            //printf("---no over%c",buff[1023]);
        }
        sleep(5);
    }********/
    
    
    
    /*---------------------------------*/
    
    
    /*
     Day 2
     */
    int i,clientfds[5];
    struct sockaddr_in    servaddr;


    for (i = 0; i < 5; i++) {
        clientfds[i] = socket(AF_INET, SOCK_STREAM, 0);
        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(8088);
        inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
        connect(clientfds[i],  (struct sockaddr *)&servaddr, sizeof(servaddr));
    }

    //str_cli(stdin, sockfd[0]);        /* do it all */

    exit(0);
    
    
    
    
    return 0;
}
