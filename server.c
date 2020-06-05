#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT_ADD 1337

int main(int argc, char *argv[]) {

  int socket_desc, new_socket, c;
  char *reply, client_reply[1000];
  struct sockaddr_in server, client;
  reply = "Package received\n";
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(PORT_ADD);

  if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
    printf("Socket Binding: error\n");
    return 1;
  }
  printf("Socket Binding: sucess\n");

  listen(socket_desc, 3);
  c = sizeof(struct sockaddr_in);


  while ((new_socket = accept(socket_desc, (struct sockaddr *)&client,
                              (socklen_t *)&c))) {

    if (recv(new_socket, client_reply, 1000, 0) < 0) {
      printf("Error receiving package");
    }
    printf("Pakcage Content: %s\n", client_reply);
    write(new_socket, reply, strlen(reply));
        bzero(client_reply, sizeof(client_reply));
  }

  return 0;
}