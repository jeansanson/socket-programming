#include "clientCtrl.h"
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MESSAGE_LENGTH 100000
int main(int argc, char *argv[]) {

  char message[MESSAGE_LENGTH];

  int socket_desc;
  struct sockaddr_in server;

  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  defineServer(&server);
  connectSocket(socket_desc, server);

  do {
    printf("Write a message:");
    scanf("%s", message);

    sendMessage(message, socket_desc);

  } while (strcmp(message, "exit")!=0);

  return 0;
}
