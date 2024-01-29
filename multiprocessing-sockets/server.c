/* The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void server_init(void);
void handle_client(int client_socket) 
{
    const char *response = "HTTP/1.1 200 OK\r\n"
                           "Content-Type: text/html\r\n\r\n"
                           "<html><body><h1>Hello, this is a simple web server!</h1></body></html>";

    // Send the HTTP response to the client
    if (send(client_socket, response, strlen(response), 0) < 0) {
        perror("ERROR writing to socket");
    }
}
int main(int argc, char **argv)
{
    if(argc < 2)
    {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }

    int sock_fd, new_sock_fd, port_no;
    socklen_t client_len;
    struct sockaddr_in server_addr, client_addr;
    int n;
    char buffer[256];

    /* Create socket */
    /*socket(int domain, int type, int protocol);*/

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd < 0)
    {
        perror("ERROR opening socket");
        exit(0);
    }

    /* Clear address structure */
    memset(&server_addr, 0, sizeof(server_addr));

    port_no = atoi(argv[1]);

    /* setup the host_addrs structure for use in bind call */
    server_addr.sin_family = AF_INET;

    /* Automatically be filled with current host's IP address*/
    server_addr.sin_addr.s_addr = INADDR_ANY;

    /* Convert short integer value for port must be converted into network byte order */
    server_addr.sin_port = htons(port_no);

    /*
        bind(int fd, struct sockaddr *local_addr, socklen_t addr_length)
        bind() passes file descriptor, the address structure, 
        and the length of the address structure
        This bind() call will bind  the socket to the current IP address on port, portno
    */

   if(bind(sock_fd,
        (struct sockaddr *) &server_addr, 
        sizeof(server_addr)) < 0)
    {
        perror("Error on binding");
        exit(0);
    }

    /*
        This listen() call tells the socket to listen to the incoming connections.
        The listen() function places all incoming connection into a backlog queue
        until accept() call accepts the connection.
        Here, we set the maximum size for the backlog queue to 5.
    */
    listen(sock_fd, 5);

     /* The accept() call accepts an incoming connection */
    client_len = sizeof(client_addr);

    /*
        This accept() function will write the connecting client's address info 
        into the the address structure and the size of that structure is clilen.
        The accept() returns a new socket file descriptor for the accepted connection.
        So, the original socket file descriptor can continue to be used 
        for accepting new connections while the new socker file descriptor is used for
        communicating with the connected client.
    */
   new_sock_fd = accept(sock_fd, (struct sockaddr *) &client_addr, &client_len);
   if(new_sock_fd < 0)
   {
        perror("ERROR on accept");
        exit(0);
   }
   printf("server: got connection from %s port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    
//    send(new_sock_fd, "Hello, world!\n", 13, 0);

    memset(buffer, 0, sizeof(buffer) / sizeof(buffer[0]));

    n = read(new_sock_fd, buffer, 255);
    if(n < 0)
    {
        perror("ERROR reading from socket");
    }
    if(n > 0)
    {
        FILE *file = fopen("server_output.txt", "w");
        if(file == NULL)
        {
            perror("Error opening file");
            exit(1);
        }
        fprintf(file,"Client request: %s\n", buffer);
        fclose(file);
    }
   
    close(new_sock_fd);
    close(sock_fd);
    return 0;
}

void server_init(void)
{

}