# Simple C Chat Application (Client/Server)

A basic, single-connection TCP chat application implemented in C that demonstrates fundamental socket programming concepts including creation, binding, listening, connecting, and sending/receiving data using the standard BSD socket API.

## 📁 Project Structure

| File | Description |
|------|-------------|
| `server.c` | Listens on a specified port (8080), accepts a single incoming client connection, and echoes messages from the client |
| `client.c` | Connects to the server (on 127.0.0.1:8080) and allows the user to send messages to the server, displaying the server's acknowledgment |

## ⚙️ Compilation

This project is intended for Linux/Unix-like environments. Compile both files using the GCC compiler:

```bash
gcc -o server server.c
gcc -o client client.c
```

## 🚀 Usage

The server must be started before the client. Both executables require a separate terminal window.

### Starting the Server
```bash
./server
```
The server will wait for a connection on port 8080.

### Starting the Client
```bash
./client
```
The client will attempt to connect to 127.0.0.1:8080.

### Chatting
Once connected, type messages in the client window. The client sends the message, and the server responds with a simple acknowledgment.

### Exiting
Type `quit` in the client window to gracefully close the connection and shut down both applications.

## 📝 Features

- **Protocol**: Uses TCP sockets for reliable, stream-based communication
- **Port**: Runs on port 8080 by default
- **Connection**: Supports a single, synchronous client connection
- **Simple Interface**: Basic command-line interaction for testing socket communication

## 🎯 Limitations

- Single client connection only (no concurrent users)
- No advanced error handling or recovery
- Basic message echoing functionality only

## 🛠️ Requirements

- Linux/Unix-like environment
- GCC compiler
- Basic knowledge of terminal usage
