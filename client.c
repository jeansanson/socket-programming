#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {

  int socket_desc;
  struct sockaddr_in server;

  // AF_INET - IPv4, SOCK_STREAM - tcp, 0 - IP
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  server.sin_addr.s_addr = inet_addr("172.217.28.132");
  server.sin_family = AF_INET;
  server.sin_port = htons(80);

  printf("opening connection...\n");

  // connect
  if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
    printf("error\n");
    return 1;
  }
  printf("sucess\n");

  return 0;
}