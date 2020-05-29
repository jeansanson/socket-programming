#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT_ADD 1337

int main(int argc, char *argv[]) {

  int socket_desc;
  struct sockaddr_in server;

  socket_desc = socket(AF_INET, SOCK_STREAM, 0);

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(PORT_ADD);

  printf("trying to bind to socket...\n");
  if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
    printf("error\n");
    return 1;
  }
  printf("sucess\n");

  return 0;
}