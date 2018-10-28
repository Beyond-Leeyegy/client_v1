#pragma once
#ifndef __CLIENT_STRUCTS_H__
#define __CLIENT_STRUCTS_H__
#include "def.h"

#define dMAX_SOCK_BUFF 10240	// buffer length
#define dNAME_LEN 50		// name length 
#define dIP_LEN 20			// IP length


struct client_data
{
	/*
		DATA
	*/

	//server->client  //这里的设置与服务器是相反的
	char m_recvBuff[dMAX_SOCK_BUFF];	
	int  m_recvSize;					//待处理的数据包总长度
	int  m_recvPos;     

	//client->Server
	char m_sendBuff[dMAX_SOCK_BUFF];	
	int  m_sendSize;					//待发送的数据包总长度




	/*
		CLIENT STATE
	*/

	int in_Game = 0; 
	int is_Ready = 0;
	int player_type;    //用于client结构体和game中的player进行双向映射 ；； 0，1



	/*
		NETWORK
	*/

	// network communication
	int m_scok;			// 网络连接套接字
	char m_IP[dIP_LEN] = "127.0.0.1";     // IP  address

	//最后一次连接时间，用于测试是否掉线
	unsigned long m_lastRecvTime;

	int frame_num;

	/*
		LIST
	*/
	struct client_data *m_prev;
	struct client_data *m_next;

};


typedef struct client_data sCLIENT_DATA, *sPCLIENT_DATA;




#endif
