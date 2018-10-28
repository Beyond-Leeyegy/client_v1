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

	//server->client  //�������������������෴��
	char m_recvBuff[dMAX_SOCK_BUFF];	
	int  m_recvSize;					//����������ݰ��ܳ���
	int  m_recvPos;     

	//client->Server
	char m_sendBuff[dMAX_SOCK_BUFF];	
	int  m_sendSize;					//�����͵����ݰ��ܳ���




	/*
		CLIENT STATE
	*/

	int in_Game = 0; 
	int is_Ready = 0;
	int player_type;    //����client�ṹ���game�е�player����˫��ӳ�� ���� 0��1



	/*
		NETWORK
	*/

	// network communication
	int m_scok;			// ���������׽���
	char m_IP[dIP_LEN] = "127.0.0.1";     // IP  address

	//���һ������ʱ�䣬���ڲ����Ƿ����
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
