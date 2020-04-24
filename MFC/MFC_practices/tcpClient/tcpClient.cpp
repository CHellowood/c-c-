// tcpClient.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <WinSock2.h>
#include <iostream>

// 编译时加载 ws2_32.lib 库文件
#pragma comment(lib, "ws2_32.lib")

int main()
{
    // 初始化套接字库
    WORD wVersion;
    WSADATA wsaData;
    int err;

    // 套接字库版本
    wVersion = MAKEWORD(1, 1);

    // 初始化套接字库
    err = WSAStartup(wVersion, &wsaData);

    // 检查套接字库是否初始化成功
    if (err != 0) {
        return err;
    }

    // 检查套接字库版本是否正确
    if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1) {
        // 套接字库版本错误, 清理套接字库
        WSACleanup();
        return -1;
    }

    // 创建客户端tcp套接字
    SOCKET sockCli = socket(AF_INET, SOCK_STREAM, 0);

    // 准备连接信息
    SOCKADDR_IN addrCli;
    addrCli.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    addrCli.sin_family = AF_INET;
    addrCli.sin_port = htons(2020);

    // 连接服务器
    connect(sockCli, (SOCKADDR*)&addrCli, sizeof(SOCKADDR));

    char sendBuf[100]; // 用来发送消息的字符串
    char recvBuf[100]; // 用来接收消息的字符串

    // 接收消息
    recv(sockCli, recvBuf, sizeof(recvBuf), 0);
    std::cout << recvBuf << std::endl;

    while (true) {
        std::cin >> sendBuf;
        
        // 发送消息
        send(sockCli, sendBuf, strlen(sendBuf)+1, 0);

        // 断开连接
        if (!strcmp(sendBuf, "/close")) {
            // 接收消息
            recv(sockCli, recvBuf, sizeof(recvBuf), 0);
            std::cout << recvBuf << std::endl;

            break;
        }
    }
    
    // 关闭套接字
    closesocket(sockCli);
    // 清理套接字库
    WSACleanup();

    system("pause");
    return 0;
}
