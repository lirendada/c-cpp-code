#define  _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

uint16_t server_port = 8080;
string server_ip = "119.29.17.38";

int main() 
{
	WSADATA wsaData;
	// 初始化套接字环境WSAStartup   
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cout << "WSAStartup failed with error: " << WSAGetLastError() << endl;
		return 1;
	}
	else
	{
		cout << "WSAStartup Success" << endl;
	}

	// 创建套接字，初始化地址和端口
	SOCKET csock = socket(AF_INET, SOCK_DGRAM, 0);
	if (csock == SOCKET_ERROR)
	{
		cout << "socket failed with error: " << WSAGetLastError() << endl;
		closesocket(csock);
		WSACleanup();
		return 1;
	}
	else
	{
		cout << "socket success" << endl;
	}
	struct sockaddr_in server;
	memset(&server, 0, sizeof server);
	server.sin_family = AF_INET;
	server.sin_port = htons(server_port);
	server.sin_addr.s_addr = inet_addr(server_ip.c_str());

	char inbuffer[1024];
	string send_message;
	while (true)
	{
		// 发送信息
		cout << "Please Enter# ";
		getline(cin, send_message);
		int s = sendto(csock, send_message.c_str(), (int)send_message.size(), 0, (struct sockaddr*)&server, (int)sizeof(server));
		if (s == -1)
		{
			cout << "send failed" << endl;
			break;
		}

		// 接收信息
		struct sockaddr_in peer;
		int peerlen = sizeof peer;
		inbuffer[0] = 0; // C语言风格的清零
		int n = recvfrom(csock, inbuffer, sizeof(inbuffer) - 1, 0, (struct sockaddr*)&peer, &peerlen);
		if (n > 0)
		{
			inbuffer[n] = 0;
			cout << "Server返回的信息是# " << inbuffer << endl;
		}
		else
			break;
	}

	closesocket(csock);
	WSACleanup();
	return 0;
}