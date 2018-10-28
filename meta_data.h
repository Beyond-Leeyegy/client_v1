#pragma once
/*
	FILE meta_data.h
	定义数据包封装与解封的基本格式
	size(WORD:2)-tag(BYTE:1)-data

*/
#ifndef  __META_DATA_H__
#define  __META_DATA_H__

#include "def.h"
#include "sprite.hpp"
#include "read_write_on_bit.h"
#include "data_protocal.h"
//BYTE == unsigned char

void PutByte(char *pPacket, BYTE value, int & nPos);
BYTE GetByte(char* pPacket, int& nPos);

void PutWord(char *pPacket, WORD value, int & nPos);
WORD GetWord(char* pPacket, int& nPos);

void PutDword(char *pPacket, DWORD value, int & nPos);
DWORD GetDword(char* pPacket, int& nPos);


void static PutInteger(char *pPacket, int value, int & nPos);
int static GetInteger(char* pPacket, int& nPos);


void PutShort(char *pPacket, short value, int & nPos);
short GetShort(char* pPacket, int &nPos);

void PutString(char *pPacket, char *str, int & nPos);
void GetString(char* pPacket, char *pBuffer, int& nPos);

void PutSize(char *pPacket, WORD nPos);


/*
	write on the end pos
	and after done writing
	return the now end pos
*/
void PutBore(byte* packet,Bore bore,int& end);

void PutBonus(byte* packet ,Bonus bonus,int & end);


void PutBullet(byte* packet,Bullet bullet,int& end);

void PutTile(byte* packet,Tile tile,int& end);


void PutFrame_No(byte* packet ,int & frame_size,int frame_num,char type);

void PutPlayer(byte* packet,Player player,int& end);


void PutEnemy(byte* packet,Enemy enemy,int& end);

void PutExplode(byte* packet,Explode explode,int& end);

void PutGame(byte* packet,Game game ,int & end);


void PutMap(byte* packet,Game game,int & end);

//return the bytes this frame use
int PutGameRunFrame(byte* packet,Game game,int frame_num);

int PutGameWinFrame(byte * packet,Game game,int frame_num);

int PutGameOverFrame(byte * packet,Game game,int frame_num);





//get and set data

void GetBore(byte* packet,Bore& bore,int& end);

void GetBonus(byte* packet ,Bonus& bonus,int & end);


void GetBullet(byte* packet,Bullet& bullet,int& end);

void GetTile(byte* packet,Tile& tile,int& end);


void GetFrame_No(byte* packet ,int & frame_size,int& frame_num,char& type);

void GetPlayer(byte* packet,Player& player,int& end);


void GetEnemy(byte* packet,Enemy& enemy,int& end);

void GetExplode(byte* packet,Explode& explode,int& end);

void GetGame(byte* packet,Game& game ,int & end);


void GetMap(byte* packet,Game& game,int & end);

//return the bytes this frame use
void GetGameRunFrameBody(byte* packet,Game& game);

void GetGameWinFrameBody(byte * packet,Game& game);

void GetGameOverFrameBody(byte* packet,Game& game);


#endif


