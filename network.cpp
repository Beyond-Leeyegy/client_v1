/*
	
	FILE:network.cpp
	
	用于套接字处理的源程序文件

*/

#include "def.h"
#include "client_structs.h"
#include "network.h"
#include "meta_data.h"
#include "linked_list.h"
#include "utils.h"
#include "data_protocal.h"

#include <string.h>
#include <stdio.h>



extern sPCLIENT_DATA g_ClientList;
extern int g_TotalClient;

/*
断开连接
*/
void DisconnectNetWork(sPCLIENT_DATA network) {
	closesocket(network->m_scok);
	//设置not_in_game and not_ready
	network->in_Game = 0;
	network->is_Ready = 0;
		

}

bool ConnectToServer(sPCLIENT_DATA network) {
	struct sockaddr_in addr;
	network->m_scok = socket(AF_INET, SOCK_STREAM, 0);


	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(PORT));
	addr.sin_addr.s_addr = inet_addr(IP);

	if (connect(network->m_scok, (const struct sockaddr *)&addr, sizeof(addr)) == -1) {
		log("[WARNING::BAD_NETWORK]in ConnectToServer \r\n\r\n");
		return false;
	}

	//NonBlock(network->m_scok);
	return true;

}

/*
将套接字设置成NonBlocking模式
*/
void NonBlock(SOCKET sock) {

#ifdef  WIN32
	u_long u10n;
	u10n = 1L;
	ioctlsocket(sock, FIONBIO, (unsigned long*)&u10n);
#else
	/*
	LINUX
	*/
	int flags;
	flags = fcntl(sock, F_GETFL, 0);
	flags |= O_NONBLOCK;
	if (fcntl(sock, F_SETFL, flags) < 0)
		return; //fail
#endif // ! WIN32
}


int FlushSendBuff(sPCLIENT_DATA pClient) {

	int sendSize;   //记录真正发送出去的数据的长度；单位字节（服务器-》客户）
	sendSize = send(pClient->m_scok, pClient->m_sendBuff, pClient->m_sendSize, 0);
	
//        sendSize = write(pClient->m_scok, pClient->m_sendBuff, pClient->m_sendSize);


	/*
		Error: caused by send function
	*/
	if (sendSize <= 0) {
		log("Error:client[%d] call send function but failed...", pClient->m_scok);
		return -1;
	}


	/*
		if some data sent failed
	*/
	if (sendSize < pClient->m_sendSize) {
		memmove(&pClient->m_sendBuff[0], &pClient->m_sendBuff[sendSize], pClient->m_sendSize - sendSize);
		pClient->m_sendSize -= sendSize;
	}
	else
	{
		*pClient->m_sendBuff = '\0';
		pClient->m_sendSize = 0;
	}


	log("[SEND::%d::%s]send:%d bytes left:%d bytes\r\n\r\n", pClient->m_scok, pClient->m_IP, sendSize, pClient->m_sendSize);

	return sendSize;
	

}

bool RecvFromClient(sPCLIENT_DATA pClient) {
	int recvSize;
	char recvBuff[dMAX_SOCK_BUFF];

	recvSize = recv(pClient->m_scok, recvBuff, 1024, 0);
	if (recvSize == 0) {
		log("[Error reading::disconnct]:%s try to read socket while no data\r\n", pClient->m_IP);
		return false;
	}
	if (recvSize < 0) {
#if defined(Win32)
	/*
		WIN32
	*/
		if (WSAGetLastError() != WSAEWOULDBLOCK) {
			log("[Error handling::disconnct]:%s unknown error while read socket\r\n", pClient->m_IP);
			return false;
		}
#else
		/*
			LINUX
		*/
		if (errno != EWOULDBLOCK) {
			log("[Error handling::disconnct]:%s unknown error while read socket\r\n", pClient->m_IP);
			return false;
		}
#endif
		else
		{
			//pClient->m_scok
			return true; //假的错误——由nonBlocking机制引发
		}
	}
	/*
		Buffer Overflow
	*/
	if ((pClient->m_recvSize + recvSize) >= dMAX_SOCK_BUFF) {
		log("[reading buffer overflow::disconnct]:%s try to read which resulting in overflow \r\n", pClient->m_IP);
		return false;
	}

	// record time 
	pClient->m_lastRecvTime = timeGetTime();

	memcpy(&pClient->m_recvBuff[pClient->m_recvSize], recvBuff, recvSize);
	pClient->m_recvSize += recvSize;

	return true;		// 一切正常
}
