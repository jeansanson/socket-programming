#include "clientctrl.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define REPLY_LENGTH 100000
#define SERVER_PORT 1337

int sendMessage(char *message, int socket_desc) {
  if (send(socket_desc, message, strlen(message), 0) < 0) {
    printf("Package: error\n");
    return 1;
  }
  printf("Package: sent\n");

  char server_reply[REPLY_LENGTH];

  if (recv(socket_desc, server_reply, REPLY_LENGTH, 0) < 0) {
    printf("Reply: error\n");
    return 1;
  }
  printf("Reply: %s\n", server_reply);
  return 0;
}

int defineServer(struct sockaddr_in *server) {
  server->sin_addr.s_addr = inet_addr("127.0.0.1");
  server->sin_family = AF_INET;
  server->sin_port = htons(SERVER_PORT);
  return 1;
}

int connectSocket(int socket_desc, struct sockaddr_in server) {
  if (connect(socket_desc, (struct sockaddr *)(&server), sizeof(server)) < 0) {
    printf("Connect: error\n");
    return 1;
  }
  printf("Connect: sucess\n");
  return 0;
}
