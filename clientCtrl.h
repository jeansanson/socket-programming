#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int sendMessage(char *message, int socket_desc);

int defineServer(struct sockaddr_in *server);

int connectSocket(int socket_desc, struct sockaddr_in server);