#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
  int client_socket;
  struct sockaddr_in server_addr;
  char buffer[BUFFER_SIZE];
  int bytes_received;

  printf("Starting Chat Client...\n");

  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1) {
    perror("Error: Could not create client socket");
    return 1;
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);

  if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
    perror("Error: Invalid address/ Address not supported");
    close(client_socket);
    return 1;
  }

  if (connect(client_socket, (struct sockaddr *)&server_addr,
              sizeof(server_addr)) == -1) {
    perror("Error: Connection failed. Is the server running?");
    close(client_socket);
    return 1;
  }
  printf("Successfully connected to 127.0.0.1:%d\n", PORT);
  printf("Type 'quit' to exit.\n");

  while (1) {
    printf("You: ");
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
      break;
    }

    send(client_socket, buffer, strlen(buffer), 0);

    if (strcmp(buffer, "quit\n") == 0) {
      break;
    }

    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);

    if (bytes_received <= 0) {
      printf("Server closed connection.\n");
      break;
    }

    buffer[bytes_received] = '\0';
    printf("Server: %s", buffer);
  }

  close(client_socket);
  printf("Client clean exit.\n");
  return 0;
}
