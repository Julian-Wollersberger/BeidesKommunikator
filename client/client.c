//
// Created by julian on 18.12.17.
// Edited by pi on 18.12.17
// http://www.binarytides.com/server-client-example-c-sockets-linux/
//

#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("cl Socket created");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("cl connect failed. Error\n");
        return 1;
    }

    puts("cl Connected\n");

    //keep communicating with server
    while(1)
    {
        printf("cl Enter message : ");
        scanf("%s" , message);

        //Send some data
        if( send(sock , message , strlen(message) , 0) < 0)
        {
            puts("cl Send failed");
            return 1;
        }

        //Receive a reply from the server
        if( recv(sock , server_reply , 2000 , 0) < 0)
        {
            puts("cl recv failed");
            break;
        }

        puts("cl Server reply :");
        puts(server_reply);
    }

    close(sock);
    return 0;
}