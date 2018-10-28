#pragma once
#ifndef __DATA_PTOTOCAL_H__
#define __DATA_PROTOCAL_H__


#include "client_structs.h"
#include "game.hpp"
#define _CLIENT_

/*
data transfer :: server->client
*/
#define KILL_PLAYER_J '1'		
#define CREATE_BONUS  '2'
#define KILL_ENEMY_K '3'
#define REMOVE_PLAYER_BULLET_I_J '4'	//移除玩家i的第j个子弹
#define PLAYER_BULLET_HIT_PLAYER '5'	//
#define PLAYER_BULLET_HIT_PLAYER_BULLET '6'
#define PLAYER_BULLET_HIT_ENEMY_BULLET '7'
#define PLAYER_BULLET_HIT_FENCE '8'
#define ALL_PLAYER_BULLET_MOVE '9'
#define CREATE_ENEMY_BORE 'a'
#define BACK_OFF_CREATE_ENEMY_BORE 'b'
#define BORE_UPDATE_I 'c'
#define CREATE_ENEMY 'd'
#define REMOVE_ENEMY_BORE_I 'e'
#define DEAL_WITH_PLAYER_BORE 'f'
#define REMOVE_ENEMY_BULLET 'g'
/*
others::server->client
*/
#define dPACKET_FRIEND 'h'				//找到了一个友军用户可以与之连接

/*
data transfer::client->server
*/
#define PLAYER_MOVE 'i'
#define SET_PLAYER_DIR 'j'
#define CREATE_PLAYER_BULLET 'k'
/*
others::client->server
*/
#define dPACKET_IS_READY 'm'			//表示用户准备好开始游戏
//#define dPACKET_ALIVE_CHECK '0'
#define FRAME_NO 'n'
/*
new added here
*/
#define CALL_ENEMY_BULLET_HIT_TILE 'o'
#define CALL_ENEMY_BULLET_HIT_FENCE 'p'
#define CALL_ENEMY_BULLET_UPDATE 'q'
#define CALL_PLAYER_BULLET_HIT_TILE 'r'
#define CALL_PLAYER_BULLET_UPDATE 's'
#define CALL_DEAL_WITH_PLAYER 't'
#define CALL_DEAL_WITH_ENEMY_UPDATE_WIN_DELAY_CLICK 'u'
#define CALL_DEAL_WITH_ENEMY_LEFT 'v'
#define CALL_DEAL_WITH_ENEMY_RIGHT 'w'
#define CALL_DEAL_WITH_ENEMY_UP 'x'
#define CALL_DEAL_WITH_ENEMY_DOWN '-'
#define CALL_DEAL_WITH_ENEMY_SET_DIR 'y'
#define CALL_DEAL_WITH_ENEMY_UPDATE_ENEMY_FREEZING 'z'
#define CALL_DEAL_WITH_ENEMY_BORE_UPDATE '+'
#define CALL_DEAL_WITH_BONUS_EXPLODE_MESSAGE_DELAY '*'
#define CALL_PLAYER_BULLET_HIT_TILE  '='
#define CALL_ENEMY_SET_DIR '/'
#define CALL_ENEMY_UPDATE_ATTACK '?'


/*
	new added here
*/ 
#define GAME_RUN_FRAME '`'
#define GAME_WIN_FRAME '.'
#define GAME_OVER_FRAME ']'

void onCache_CALL_ENEMY_BULLET_HIT_TILE(sPCLIENT_DATA, sPCLIENT_DATA);
void onCache_CALL_ENEMY_BULLET_HIT_FENCE(sPCLIENT_DATA, sPCLIENT_DATA);
void onCache_CALL_ENEMY_BULLET_UPDATE(sPCLIENT_DATA, sPCLIENT_DATA);
void onCache_CALL_PLAYER_BULLET_HIT_TILE(sPCLIENT_DATA, sPCLIENT_DATA);
void onCache_CALL_PLAYER_BULLET_UPDATE(sPCLIENT_DATA, sPCLIENT_DATA);
void onCache_CALL_DEAL_WITH_PLAYER(sPCLIENT_DATA, sPCLIENT_DATA);
void onCache_CALL_DEAL_WITH_ENEMY_UPDATE_WIN_DELAY_CLICK(sPCLIENT_DATA, sPCLIENT_DATA);
void onCache_CALL_DEAL_WITH_ENEMY_LEFT(sPCLIENT_DATA, sPCLIENT_DATA, int);
void onCache_CALL_DEAL_WITH_ENEMY_RIGHT(sPCLIENT_DATA, sPCLIENT_DATA, int);
void onCache_CALL_DEAL_WITH_ENEMY_UP(sPCLIENT_DATA, sPCLIENT_DATA, int);
void onCache_CALL_DEAL_WITH_ENEMY_DOWN(sPCLIENT_DATA, sPCLIENT_DATA, int);
void onCache_CALL_DEAL_WITH_ENEMY_SET_DIR(sPCLIENT_DATA, sPCLIENT_DATA, int, int);
void onCache_CALL_DEAL_WITH_ENEMY_UPDATE_ENEMY_FREEZING(sPCLIENT_DATA, sPCLIENT_DATA);
void onCache_CALL_DEAL_WITH_ENEMY_BORE_UPDATE(sPCLIENT_DATA, sPCLIENT_DATA);
void onCache_CALL_DEAL_WITH_BONUS_EXPLODE_MESSAGE_DELAY(sPCLIENT_DATA, sPCLIENT_DATA);
void onCache_CALL_CENTER(sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2, char type);
void onCache_CALL_CENTER_I(sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2, char type, int i);
void onCache_CALL_PLAYER_BULLET_HIT_TILE(sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);
void onCache_CALL_ENEMY_SET_DIR(sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2,int i , int dir);
void onCache_CALL_ENEMY_UPDATE_ATTACK(sPCLIENT_DATA, sPCLIENT_DATA, int);




/*
	for double

*/

void onCache_GAME_RUN_FRAME(Game& game,sPCLIENT_DATA pClient1,sPCLIENT_DATA pClient2,int frame_num);

void onCache_GAME_WIN_FRAME(Game& game,sPCLIENT_DATA pClient1,sPCLIENT_DATA pClient2,int frame_num);

void onCache_GAME_OVER_FRAME(Game& game,sPCLIENT_DATA pClient1,sPCLIENT_DATA pClient2,int frame_num);





#ifdef _CLIENT_
void onHandle_CALL_ENEMY_BULLET_HIT_TILE(Game& game);
void onHandle_CALL_ENEMY_BULLET_HIT_FENCE(Game& game);
void onHandle_CALL_ENEMY_BULLET_UPDATE(Game& game);
void onHandle_CALL_PLAYER_BULLET_HIT_TILE(Game& game);
void onHandle_CALL_PLAYER_BULLET_UPDATE(Game& game);
void onHandle_CALL_DEAL_WITH_PLAYER(Game& game);
void onHandle_CALL_DEAL_WITH_ENEMY_UPDATE_WIN_DELAY_CLICK(Game& game);
void onHandle_CALL_DEAL_WITH_ENEMY_LEFT(Game& game, sPCLIENT_DATA client);
void onHandle_CALL_DEAL_WITH_ENEMY_RIGHT(Game& game, sPCLIENT_DATA client);
void onHandle_CALL_DEAL_WITH_ENEMY_UP(Game& game, sPCLIENT_DATA client);
void onHandle_CALL_DEAL_WITH_ENEMY_DOWN(Game& game, sPCLIENT_DATA client);
void onHandle_CALL_DEAL_WITH_ENEMY_SET_DIR(Game& game, sPCLIENT_DATA client);
void onHandle_CALL_DEAL_WITH_ENEMY_UPDATE_ENEMY_FREEZING(Game& game);
void onHandle_CALL_DEAL_WITH_ENEMY_BORE_UPDATE(Game& game);
void onHandle_CALL_DEAL_WITH_BONUS_EXPLODE_MESSAGE_DELAY(Game& game);
void onHandle_CALL_PLAYER_BULLET_HIT_TILE(Game& game);
void onHandle_CALL_ENEMY_SET_DIR(Game& game,sPCLIENT_DATA client);
void onHandle_CALL_ENEMY_UPDATE_ATTACK(Game& game,sPCLIENT_DATA);
#endif // CLIENT



void  onHandle_GAME_RUN_FRAME(Game& game,sPCLIENT_DATA pClient1);

void onHandle_GAME_WIN_FRAME(Game& game,sPCLIENT_DATA pClient1);

void onHandle_GAME_OVER_FRAME(Game& game,sPCLIENT_DATA pClient1);

/*
SERVER SOURCE
*/

/*
DATA_TRANSFER
*/
void onCache_KILL_PLAYER_J(int player_type, sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);
void onCache_CREATE_BONUS(int, int, int, sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);
void onCache_KILL_ENEMY_K(int i, int k, sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);
void onCache_REMOVE_PLAYER_BULLET_I_J(int i, int j, sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);
void onCache_PLAYER_BULLET_HIT_PLAYER(int i, int j, sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);
void onCache_PLAYER_BULLET_HIT_PLAYER_BULLET(int i, int j, sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);
void onCache_PLAYER_BULLET_HIT_ENEMY_BULLET(int i, int j, int k, sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);
void onCache_PLAYER_BULLET_HIT_FENCE(int i, int j, sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);
void onCache_ALL_PLAYER_BULLET_MOVE(sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);
void onCache_CREATE_ENEMY_BORE(int i, sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);
void onCache_BACK_OFF_CREATE_ENEMY_BORE(int tmp, sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);
void onCache_BORE_UPDATE_I(int i, sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);
void onCache_CREATE_ENEMY(int row, int col, int type, bool flash, sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);
void onCache_REMOVE_ENEMY_BORE_I(int i, sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);
void onCache_DEAL_WITH_PLAYER_BORE(sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);
void onCache_REMOVE_ENEMY_BULLET(int, sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);


/*
OTHERS
*/
void onCache_dPACKET_FRIEND(sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);
void onCache_FRAME_NO(WORD frame_num, sPCLIENT_DATA pClient1, sPCLIENT_DATA pClient2);	//server
void onCache_FRAME_NO(WORD frame_num, sPCLIENT_DATA network);			//server转发client的帧数据包
																		/*
																		CLIENT SOURCE
																		*/
void onCache_PLAYER_MOVE(sPCLIENT_DATA toClient);
void onCache_SET_PLAYER_DIR(sPCLIENT_DATA toClient, int dir);
void onCache_CREATE_PLAYER_BULLET(sPCLIENT_DATA toClient);

void onCache_dPACKET_IS_READY(sPCLIENT_DATA pClient);




/*
SERVER MORE
*/

/*
DATA_TRANSFER
*/
void onHandle_PLAYER_MOVE(Game& game, sPCLIENT_DATA pClient);
void onHandle_SET_PLAYER_DIR(Game& game, sPCLIENT_DATA pClient);
void onHandle_CREATE_PLAYER_BULLET(Game& game, sPCLIENT_DATA pClient);

/*
OTHERS
*/
void onHandle_dPACKET_IS_READY(sPCLIENT_DATA pClient);


/*
CLIENT MORE
*/

void onHandle_KILL_PLAYER_J(Game& game, sPCLIENT_DATA client);
void onHandle_CREATE_BONUS(Game& game, sPCLIENT_DATA client);
void onHandle_KILL_ENEMY_K(Game& game, sPCLIENT_DATA client);
void onHandle_REMOVE_PLAYER_BULLET_I_J(Game& game, sPCLIENT_DATA client);
void onHandle_PLAYER_BULLET_HIT_PLAYER(Game& game, sPCLIENT_DATA client);
void onHandle_PLAYER_BULLET_HIT_PLAYER_BULLET(Game& game, sPCLIENT_DATA client);
void onHandle_PLAYER_BULLET_HIT_ENEMY_BULLET(Game& game, sPCLIENT_DATA client);
void onHandle_PLAYER_BULLET_HIT_FENCE(Game& game, sPCLIENT_DATA client);
void onHandle_ALL_PLAYER_BULLET_MOVE(Game& game, sPCLIENT_DATA client);
void onHandle_CREATE_ENEMY_BORE(Game& game, sPCLIENT_DATA client);
void onHandle_BACK_OFF_CREATE_ENEMY_BORE(Game& game, sPCLIENT_DATA client);
void onHandle_BORE_UPDATE_I(Game& game, sPCLIENT_DATA client);
void onHandle_CREATE_ENEMY(Game& game, sPCLIENT_DATA client);
void onHandle_REMOVE_ENEMY_BORE_I(Game& game, sPCLIENT_DATA client);
void onHandle_DEAL_WITH_PLAYER_BORE(Game& game, sPCLIENT_DATA client);
void onHandle_REMOVE_ENEMY_BULLET(Game& game, sPCLIENT_DATA client);

void onHandle_FRAME_NO(sPCLIENT_DATA fromClient);
void onHandle_dPACKET_FRIEND(Game& game);

#ifdef _CLIENT_
bool onHandle_CONTROL_CENTER(Game& game, sPCLIENT_DATA pClient);
#endif

bool onHandle_CONTROL_CENTER(Game& game, sPCLIENT_DATA pClient, sPCLIENT_DATA to_client);
bool onHandle_CONTROL_CENTER_FOR_IS_READY(sPCLIENT_DATA);
bool onHandle_CONTROL_CENTER_SYN(Game&,sPCLIENT_DATA);








             
           
          



//void onCached_PACKET_ALIVE_CHECK();



#endif // !__DATA_PTOTOCAL_H__


/*
数据包结构说明
*/
/*
KILL_PLAYER_J
BYTE==unsigned char
size:WORD->tag:BYTE->j:WORD
总占字节：5
*/
/*
REMOVE_ENEMY_BULLET
size:WORD->tag:BYTE->i:WORD
all： 5
*/

/*
CREATE_BONUS
size:WORD->tag:BYTE->type:WORD,row :WORD,col:WORD
all: 9
*/
