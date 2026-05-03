# Simple C Chat Application

A basic TCP chat application in C demonstrating socket programming. Single client connection over TCP.

## Project Structure

| File | Description |
|------|-------------|
| `server.c` | Listens on port 8080, accepts one client, echoes messages |
| `client.c` | Connects to 127.0.0.1:8080, sends messages, displays acknowledgments |

## Build

```bash
gcc -o server server.c
gcc -o client client.c
```

## Usage

Start the server first, then the client in a separate terminal:

```bash
./server
./client
```

Type messages in the client window. Type `quit` to close the connection.

## Limitations

- Single client connection only
- No concurrent users
- Basic message echoing only
