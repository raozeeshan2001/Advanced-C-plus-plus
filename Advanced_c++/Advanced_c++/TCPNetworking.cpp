#include "TCPNetworking.h"
#include <memory>
#include "iostream"
#include <string>

#include <winsock2.h>
#include <ws2tcpip.h>
using namespace std;
#pragma comment(lib, "ws2_32.lib")

void TCPNetworking::TCPServer() {

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cout << "WSAStartup failed\n";
        return;
    }
    // 2. Create socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket == INVALID_SOCKET)
    {
        std::cout << "Socket creation failed: " << WSAGetLastError() << endl;
        WSACleanup();
        return;
    }

    // Create server address

    sockaddr_in serverAdress{};
    serverAdress.sin_family = AF_INET;
    serverAdress.sin_addr.s_addr = INADDR_ANY;//Accept connections on any local network interface."e.g wifi,ethernet.
    serverAdress.sin_port = htons(8080);//convert port number to network byte order

    if (bind(serverSocket,//Bind this socket to this address. or Attach this socket to this IP address and port.
        (sockaddr*)&serverAdress,
        sizeof(serverAdress)
    ) == SOCKET_ERROR)
    {
        std::cout << "Bind failed: " << WSAGetLastError() << endl;

        closesocket(serverSocket);
        WSACleanup();

        return;
    }
    if (listen(serverSocket, 5) == SOCKET_ERROR) {//This socket is now a listening socket. Wait for incoming connections.
        std::cout << "Listen failed: " << WSAGetLastError() << endl;

        closesocket(serverSocket);
        WSACleanup();

        return;
    }
    std::cout << "Server waiting for client...\n";
    SOCKET clientsocket = accept(serverSocket, nullptr, nullptr);//It communicates with the connected client
    if (clientsocket == INVALID_SOCKET) {
        std::cout << "Accept failed: " << WSAGetLastError() << endl;

        closesocket(serverSocket);
        WSACleanup();

        return;
    }
    std::cout << "Client connected!\n";
    // 7. Receive data
    char buffer[1024]{};
    while (true) {//use loop to Keep receiving instead of reading only once
    int bytesReceived = recv(//Because recv() returns the number of bytes received. We need that number to know how much valid data is in the buffer.
        clientsocket,
        buffer,
        sizeof(buffer) - 1,
        0);

    if (bytesReceived > 0)
    {
        buffer[bytesReceived] = '\0';//Print received bytes safely as a C string
        cout << "Received from client: "
            << buffer << endl;
        /*std::cout << "Client says: "
            << buffer << '\n';*/
    }
    else if (bytesReceived == 0)
    {
        cout << "Client shut down its sending direction.\n";
    }
    else
    {
        cout << "Receive failed: "
            << WSAGetLastError() << endl;
    }
}
    // 8. Send response
    std::string response = "Hello from server!";

    send(
        clientsocket,
        response.c_str(),
        response.size(),
        0);
    // 9. Close
    closesocket(clientsocket);
    closesocket(serverSocket);

    // 10. Cleanup Winsock
    WSACleanup();

    return ;





}
