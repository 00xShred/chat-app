Simple C Chat Application (Client/Server)

This is a basic, single-connection TCP chat application implemented in C. It demonstrates fundamental concepts of socket programming, including creation, binding, listening, connecting, and sending/receiving data using the standard BSD socket API.

📁 Project Structure

File

Description

server.c

Listens on a specified port (8080), accepts a single incoming client connection, and echoes messages from the client.

client.c

Connects to the server (on 127.0.0.1:8080) and allows the user to send messages to the server, displaying the server's acknowledgment.

⚙️ Compilation

This project is intended for Linux/Unix-like environments. Compile both files using the GCC compiler:

gcc -o server server.c
gcc -o client client.c

🚀 How to Run

The server must be started before the client. Both executables require a separate terminal window.

Start the Server:

./server

(The server will wait for a connection.)

Start the Client:

./client

(The client will attempt to connect.)

Chat: Once connected, type messages in the client window. The client sends the message, and the server responds with a simple acknowledgment.

Exit: Type quit in the client window to gracefully close the connection and shut down both applications.

📝 Features

Protocol: Uses TCP sockets for reliable, stream-based communication.

Port: Runs on port 8080.

Connection: Supports a single, synchronous client connection.
