#pragma once
/*
	FILE:network.h

	套接字处理函数的头文件

*/
#ifndef __NETWORK_H__
#define __NETWORK_H__

#include "def.h"
#include "client_structs.h"
#define IP "127.0.0.1"
#define PORT "7000"

bool ConnectToServer(sPCLIENT_DATA network);
void DisconnectNetWork(sPCLIENT_DATA network);
void NonBlock(SOCKET sock);


//send
int FlushSendBuff(sPCLIENT_DATA network);

//recv
bool RecvFromClient(sPCLIENT_DATA network);

#endif // !__NETWORK_H__

