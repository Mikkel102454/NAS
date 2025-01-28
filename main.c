#include <stdio.h>
#include <winsock2.h>

#define PORT 8080
#define BUFFER_SIZE 4096

int main(void) {
    int server_fd;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1){
        perror("Failed to create socket");
        exit(-1);
    }

    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // this will bind the socket to an ip and a port
    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))){
        perror("Failed to bind");
        exit(-1);
    }

    if(listen(server_fd, 10) < 0){
        perror("Failed to listen");
        exit(-1);
    }
    printf("Server running on port %d...\n", PORT);

    return 0;
}