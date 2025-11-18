#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
  int server_socket, client_socket;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_size;
  char buffer[BUFFER_SIZE];
  int bytes_received;

  printf("Starting Chat Server on port %d...\n", PORT);

  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("Error: Could not create socket");
    return 1;
  }

  int opt = 1;
  setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

  printf("Socket created successfully!\n");

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(server_socket, (struct sockaddr *)&server_addr,
           sizeof(server_addr)) == -1) {
    perror("Error: Could not bind to port");
    close(server_socket);
    return 1;
  }
  printf("Bind successful. Port %d reserved.\n", PORT);

  if (listen(server_socket, 5) == -1) {
    perror("Error: Listen failed");
    close(server_socket);
    return 1;
  }
  printf("Server is listening...\n");

  addr_size = sizeof(client_addr);
  client_socket =
      accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);

  if (client_socket == -1) {
    perror("Error: Could not accept connection");
    close(server_socket);
    return 1;
  }

  printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr),
         ntohs(client_addr.sin_port));

  while (1) {
    memset(buffer, 0, BUFFER_SIZE);

    bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);

    if (bytes_received <= 0) {
      printf("Client disconnected.\n");
      break;
    }

    buffer[bytes_received] = '\0';
    printf("Client: %s", buffer); // Print message

    char *response = "Server received your message.\n";
    send(client_socket, response, strlen(response), 0);

    if (strcmp(buffer, "quit\n") == 0) {
      printf("Shutting down server conversation...\n");
      break;
    }
  }

  close(client_socket);
  close(server_socket);
  printf("Server clean exit.\n");
  return 0;
}
