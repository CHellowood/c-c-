// tcpServer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <WinSock2.h>
#include <iostream>

// 编译时加载 ws2_32.lib 库文件
#pragma comment(lib, "ws2_32.lib")

int main()
{
	//初始化套接字库
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

	// 创建服务端tcp套接字
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);

	//准备绑定信息
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	// 端口: 0-65535, 1024以下的端口是系统保留的
	addrSrv.sin_port = htons(2020);

	// 绑定到本机(IP)
	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	// 监听
	listen(sockSrv, 10);

	std::cout << "Server port: 2020" << std::endl;

	SOCKADDR addrCli;
	int len = sizeof(SOCKADDR);

	char recvBuf[100]; // 用来接收消息的字符串
	char sendBuf[100] = "服务端连接成功!(关闭客户端时,请先断开与服务端的连接(输入 /close))"; // 用来发送消息的字符串
	
	// 接收连接请求, 返回针对客户端的套接字
	SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrCli, &len);

	// 发送消息
	send(sockConn, sendBuf, strlen(sendBuf) + 1, 0);

	while (true) {
		// 接收连接请求, 返回针对客户端的套接字
		//SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrCli, &len);

		//sprintf_s(sendBuf, sizeof(sendBuf), "服务端连接成功!");
		// 发送消息
		//send(sockConn, sendBuf, strlen(sendBuf)+1, 0);

		// 接收消息
		recv(sockConn, recvBuf, sizeof(recvBuf), 0);

		if (!strcmp(recvBuf, "/close")) {
			char temp[24] = "已断开与服务端的连接!";

			// 发送消息
			send(sockConn, temp, strlen(temp)+1, 0);
			
			// 关闭套接字
			closesocket(sockConn);
			
			break;
		}

		// 打印接收到的消息
		std::cout << recvBuf << std::endl;

		// 关闭套接字
		//closesocket(sockConn);
	}

	// 关闭套接字
	closesocket(sockSrv);

	// 清理套接字库
	WSACleanup();

	system("pause");
	return 0;
}
