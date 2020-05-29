#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define REPLY_LENGTH 1000000

int main(int argc, char *argv[]) {

  int socket_desc;
  struct sockaddr_in server;
  char *message, server_reply[REPLY_LENGTH];

  // AF_INET - IPv4, SOCK_STREAM - tcp, 0 - IP
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  server.sin_addr.s_addr = inet_addr("172.217.28.132");
  server.sin_family = AF_INET;
  server.sin_port = htons(80);
  message = "GET / HTTP/1.1\r\n\r\n";

  printf("opening connection...\n");
  if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
    printf("error\n");
    return 1;
  }
  printf("sucess\n");

  printf("sending package...\n");
  if (send(socket_desc, message, strlen(message), 0) < 0) {
    printf("error...\n");
    return 1;
  }
  printf("sucess\n");

  printf("receiving package...\n");
  if (recv(socket_desc, server_reply, REPLY_LENGTH, 0) < 0) {
    printf("error...\n");
    return 1;
  }
  printf("sucess\n");
  printf("%s\n", server_reply);
  close(socket_desc);

  return 0;
}