#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char **argv)
{
    int sock_fd, port_no, n;
    struct sockaddr_in server_addr;
    struct hostent *server;

    char buffer[256];
    if(argc < 3)
    {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }
    port_no = atoi(argv[2]);
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd < 0)
    {
        perror("ERROR opening socket");
        exit(0);
    }
    
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(server->h_addr_list[0], (char *) &server_addr.sin_addr.s_addr , server->h_length);
    server_addr.sin_port = htons(port_no);
    if(connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(0);
    }

    printf("Please enter the message..");
    memset(buffer, 0, 256);
    fgets(buffer, 255, stdin);

    if(write(sock_fd, buffer, strlen(buffer)) < 0)
    {
        perror("ERROR writting to socket");
    }
    if(read(sock_fd, buffer, 255) < 0)
    {
        perror("ERROR reading from socket");
    }


    printf("%s\n", buffer);
    close(sock_fd);
    return 0;
}