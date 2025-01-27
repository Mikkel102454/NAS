#include <stdio.h>
#include <winsock2.h>

int main(void) {
    int server_fd;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1){
        perror("Failed to create socket");
        exit(-1);
    }

    return 0;
}