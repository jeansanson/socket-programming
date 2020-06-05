#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT_ADD 1337

int main(int argc, char *argv[]) {

  int socket_desc, new_socket, c;
  char *reply;
  struct sockaddr_in server, client;

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

    // Reply to the client
    
    reply = "package received\n";
    write(new_socket, reply, strlen(reply));
  }

  return 0;
}