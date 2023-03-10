#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
int main() {
    printf("This is the server.\n");
    WSADATA wsaData;
    int iResult;
    /*
        MethodName: WSAStartup
        @mannual: https://learn.microsoft.com/zh-cn/windows/win32/api/winsock/nf-winsock-wsastartup
        网络服务初始化(Web Server API)，第一个参数为需求的最低socket版本号，示例使用的是2.2版本
    */
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

    //如果初始化失败则报错并打印错误信息（iResult），网络编程中需要时刻注意中途可能出现的错误并给予返回信息
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        //自带收尾工作的return 1，返回值为1表示程序未正常结束
        exit(1);
    }
    struct addrinfo *result, *ptr, hints;
    //为getaddrinfo函数做准备
    memset(&hints, 0, sizeof(struct addrinfo));
    //IPV4地址
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    //TCP协议
    hints.ai_protocol = IPPROTO_TCP;
    //服务端被动绑定
    hints.ai_flags = AI_PASSIVE;

    /*
        MethodName: getaddrinfo
        @mannual: https://learn.microsoft.com/zh-cn/windows/win32/api/ws2tcpip/nf-ws2tcpip-getaddrinfo
        8080表示端口号，取值范围为0~65535，但有些端口为保留端口，使用前请先查询目标端口是否被占用
        getaddrinfo函数提供从主机名到地址的独立于协议的转换，结果记录在result中
    */
    iResult = getaddrinfo(NULL, "8080", &hints, &result);

    if (iResult != 0) {
        printf("getaddrinfo failed: %d\n", iResult);
        WSACleanup();
        exit(1);
    }

    SOCKET listen_socket = INVALID_SOCKET;
    /*
        MethodName: socket
        @mannual: https://learn.microsoft.com/zh-cn/windows/win32/api/winsock2/nf-winsock2-socket
        socket函数根据getaddrinfo函数返回的信息创建一个绑定到相应端口的套接字
    */
    listen_socket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

    if (listen_socket == INVALID_SOCKET) {
        printf("socket() failed: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        exit(1);
    }

    /*
        MethodName: bind
        @mannual: https://learn.microsoft.com/zh-cn/windows/win32/api/winsock/nf-winsock-bind
        绑定函数将本地地址与套接字相关联
    */
    iResult = bind(listen_socket, result->ai_addr, (int)result->ai_addrlen);

    //绑定完成后，释放不再使用的内存空间
    freeaddrinfo(result);

    if (iResult == SOCKET_ERROR) {
        printf("bind() failed: %d\n", WSAGetLastError());
        closesocket(listen_socket);
        WSACleanup();
        exit(1);
    }

    /*
        MethodName: listen
        @mannual: https://learn.microsoft.com/zh-cn/windows/win32/api/winsock2/nf-winsock2-listen
        侦听函数将套接字置于侦听传入连接的状态
    */
    if (listen(listen_socket, SOMAXCONN) == SOCKET_ERROR) {
        printf("listen() failed: %d\n", WSAGetLastError());
        closesocket(listen_socket);
        WSACleanup();
        return 1;
    }

    //预备用户套接字
    SOCKET client_socket[2] = {INVALID_SOCKET};
    for (int i = 0; i <= 1; i++) {
        /*
            MethodName: accept
            @mannual: https://learn.microsoft.com/zh-cn/windows/win32/api/winsock2/nf-winsock2-accept
            accept函数允许在套接字上尝试传入连接
        */
        client_socket[i] = accept(listen_socket, NULL, NULL);

        if (client_socket[i] == INVALID_SOCKET) {
            printf("accept() failed: %d\n", WSAGetLastError());
            closesocket(listen_socket);
            WSACleanup();
            exit(1);
        }
    }

    //连接成功建立
    printf("connection established!\n");

    //信息接收数组以及初始化
    char buf[1024];
    memset(buf, 0, sizeof(buf));

    //服务端程序需要在开机时持续执行
    while(1){
        /*
            MethodName: recv
            @mannual: https://learn.microsoft.com/zh-cn/windows/win32/api/winsock/nf-winsock-recv
            recv函数从连接的套接字或绑定的无连接套接字接收数据，返回值是接收到的字符数
        */
        iResult = recv(client_socket[0], buf, 1000, 0);

        if (iResult > 0) {
            printf("Bytes received: %d\n", iResult);
            printf("%s\n", buf);
            for (int i = 0; i < iResult; i++) {
                if (buf[i] >= 'a' && buf[i] <= 'z')
                    buf[i] -= 32;
                else if (buf[i] == 0)
                    break;
            }
            /*
                MethodName: send
                @mannual: https://learn.microsoft.com/zh-cn/windows/win32/api/winsock2/nf-winsock2-send
                send函数在连接的套接字上发送数据
            */
            int iSendResult = send(client_socket[0], buf, iResult, 0);
            if (iSendResult == SOCKET_ERROR) {
                printf("send failed: %d\n", WSAGetLastError());
                closesocket(client_socket[0]);
                closesocket(client_socket[1]);
                WSACleanup();
                exit(1);
            }
        } else if (iResult == 0) {
            printf("Connection closing ...\n");
            system("pause");
        } else {
            printf("recv failed: %d\n", WSAGetLastError());
            closesocket(client_socket[0]);
            closesocket(client_socket[1]);
            WSACleanup();
            exit(1);
        }

        //第二个客户端，更多客户端应该使用for循环进行，但是如果这么处理存在怎样的问题？
        iResult = recv(client_socket[1], buf, 1000, 0);
        if (iResult > 0) {
            printf("Bytes received: %d\n", iResult);
            printf("%s\n", buf);
            for (int i = 0; i <= 1000; i++) {
                if (buf[i] >= 'a' && buf[i] <= 'z')
                    buf[i] -= 32;
                else if (buf[i] == 0)
                    break;
            }
            int iSendResult = send(client_socket[1], buf, iResult, 0);
            if (iSendResult == SOCKET_ERROR) {
                printf("send failed: %d\n", WSAGetLastError());
                closesocket(client_socket[0]);
                closesocket(client_socket[1]);
                WSACleanup();
                exit(1);
            }
        } else if (iResult == 0) {
            printf("Connection closing ...\n");
            system("pause");
        } else {
            printf("recv failed: %d\n", WSAGetLastError());
            closesocket(client_socket[0]);
            closesocket(client_socket[1]);
            WSACleanup();
            exit(1);
        }
    }
    return 0;
}