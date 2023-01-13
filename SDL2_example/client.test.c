#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
int main() {
    printf("This is the client.\n");
    WSADATA wsadata;
    int iResult;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsadata);

    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        exit(1);
    }

    struct addrinfo *result, *ptr, hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    //127.0.0.1是特殊地址，指向当前主机，也可写作localhost，端口与服务器端口相对应
    iResult = getaddrinfo("127.0.0.1", "8080", &hints, &result);

    if (iResult != 0) {
        printf("getaddrinfo failed: %d\n", iResult);
        WSACleanup();
        exit(1);
    }

    SOCKET server_socket = INVALID_SOCKET;
    ptr = result;
    server_socket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

    if (server_socket == INVALID_SOCKET) {
        printf("socket() failed: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(server_socket);
        WSACleanup();
        exit(1);
    }

    /*
        MethodName: connect
        @mannual: https://learn.microsoft.com/zh-cn/windows/win32/api/winsock2/nf-winsock2-connect
        connect函数建立与指定套接字的连接
    */
    if (connect(server_socket, ptr->ai_addr, (int)ptr->ai_addrlen) ==
        SOCKET_ERROR) {
        printf("connect() failed.\n");
        system("pause");
        freeaddrinfo(result);
        closesocket(server_socket);
        WSACleanup();
        exit(1);
    }

    freeaddrinfo(result);

    printf("connection established!\n");
    system("pause");
    printf("please input a string.\n");
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    while(scanf("%s", buf)){
        iResult = send(server_socket, buf, strlen(buf), 0);
        if (iResult == SOCKET_ERROR) {
            printf("send failed: %d\n", WSAGetLastError());
            closesocket(server_socket);
            WSACleanup();
            exit(1);
        }
        printf("Bytes send: %d\n", iResult);
        iResult = recv(server_socket, buf, 1000, 0);
        if (iResult > 0) {
            printf("Bytes received: %d\n", iResult);
            printf("%s\n", buf);
        } else if (iResult == 0) {
            printf("Connection closing ...\n");
            system("pause");
        } else {
            printf("recv failed: %d\n", WSAGetLastError());
            closesocket(server_socket);
            WSACleanup();
            exit(1);
        }
        system("pause");
    }
    return 0;
}