/*
	FILE:meta_data.cpp

*/


#include "def.h"
#include "meta_data.h"
#include <cstring>


void PutByte(char *pPacket, BYTE value, int & nPos) {

	*(BYTE *)(pPacket + nPos) = value;
	nPos += sizeof(BYTE);
}

BYTE GetByte(char* pPacket, int& nPos) {
	BYTE value = *(BYTE *)(pPacket + nPos);
	nPos += sizeof(BYTE);
	return value;
}


void PutWord(char *pPacket, WORD value, int & nPos) {
	*(WORD *)(pPacket + nPos) = value;
	nPos += sizeof(WORD);
}

WORD GetWord(char* pPacket, int& nPos) {
	WORD value = *(WORD *)(pPacket + nPos);
	nPos += sizeof(WORD);
	return value;
}

void PutDword(char *pPacket, DWORD value, int & nPos) {
	*(DWORD *)(pPacket + nPos) = value;
	nPos += sizeof(DWORD);
}



DWORD GetDword(char* pPacket, int &nPos) {
	DWORD value = *(DWORD *)(pPacket + nPos);
	nPos += sizeof(DWORD);
	return value;
}


void static PutInteger(char *pPacket, int value, int & nPos) {
	*(int *)(pPacket + nPos) = value;
	nPos += sizeof(int);
}



int  static GetInteger(char* pPacket, int &nPos) {
	int value = *(int*)(pPacket + nPos);
	nPos += sizeof(int);
	return value;
}

void PutShort(char *pPacket, short value, int & nPos) {
	*(short *)(pPacket + nPos) = value;
	nPos += sizeof(short);
}

short GetShort(char* pPacket, int& nPos) {
	short value = *(short*)(pPacket + nPos);
	nPos += sizeof(short);
	return value;
}

void PutString(char *pPacket, char *str, int & nPos) {
	*(WORD*)(pPacket + nPos) = strlen(str);
	nPos += sizeof(WORD);
	memcpy(pPacket + nPos, str, strlen(str));
	nPos += strlen(str);
}

void GetString(char* pPacket, char *pBuffer, int &nPos) {
	WORD length = *(WORD*)(pPacket + nPos);
	nPos += sizeof(WORD);
	memcpy(pBuffer, pPacket + nPos, length);
	*(pBuffer + length) = '\0';
	nPos += length;
}

void PutSize(char *pPacket, WORD nPos) {
	*(WORD *)pPacket = nPos;
}



/*
	write on the end pos
	and after done writing
	return the now end pos
*/
void PutBore(byte* packet,Bore bore,int& end){
	WriteDataToBuffer(packet, bore.m_width, end , 6, end);//width
	WriteDataToBuffer(packet, bore.m_height, end, 6, end);//width
	WriteDataToBuffer(packet, bore.m_hot_row, end, 8, end);//width
	WriteDataToBuffer(packet, bore.m_hot_col, end, 8, end);//width
	WriteDataToBuffer(packet, bore.m_row, end, 10, end);
	WriteDataToBuffer(packet, bore.m_col, end, 10, end);
}

void PutBonus(byte* packet ,Bonus bonus,int & end){
        WriteDataToBuffer(packet, bonus.m_width, end , 6, end);//width
        WriteDataToBuffer(packet, bonus.m_height, end, 6, end);//width
        WriteDataToBuffer(packet, bonus.m_hot_row, end, 8, end);//width
        WriteDataToBuffer(packet, bonus.m_hot_col, end, 8, end);//width
        WriteDataToBuffer(packet, bonus.m_row, end, 10, end);
        WriteDataToBuffer(packet, bonus.m_col, end, 10, end);
	WriteDataToBuffer(packet, (int)bonus.m_type, end , 3, end);//width
}


void PutBullet(byte* packet,Bullet bullet,int& end){
        WriteDataToBuffer(packet, bullet.m_width, end , 6, end);//width
        WriteDataToBuffer(packet, bullet.m_height, end, 6, end);//width
        WriteDataToBuffer(packet, bullet.m_hot_row, end, 8, end);//width
        WriteDataToBuffer(packet, bullet.m_hot_col, end, 8, end);//width
        WriteDataToBuffer(packet, bullet.m_row, end, 10, end);
        WriteDataToBuffer(packet, bullet.m_col, end, 10, end);
        WriteDataToBuffer(packet, (int)bullet.m_dir, end , 2, end);//width
        WriteDataToBuffer(packet, (int)bullet.m_level, end, 2, end);//width
}

void PutTile(byte* packet,Tile tile,int& end){
        WriteDataToBuffer(packet, (int)tile.m_data[0], end , 4, end);//width
        WriteDataToBuffer(packet, (int)tile.m_data[1], end , 4, end);
        WriteDataToBuffer(packet, (int)tile.m_data[2], end , 4, end);
        WriteDataToBuffer(packet, (int)tile.m_data[3], end , 4, end);
        WriteDataToBuffer(packet, (int)tile.m_data[4], end , 4, end);
}


void PutFrame_No(byte* packet ,int & frame_size,int frame_num,char type){
	//deal with lastly
	//end : the total bits we used in this frame including the FRAME_NO
	int end = 0;
        WriteDataToBuffer(packet,(int)((frame_size/8)+1), 0, 10, end);
        WriteDataToBuffer(packet,type, end, 8, end);
        WriteDataToBuffer(packet, frame_num, end, 16, end);
}

void PutPlayer(byte* packet,Player player,int& end){
        WriteDataToBuffer(packet, player.m_width, end , 6, end);//width
        WriteDataToBuffer(packet, player.m_height, end, 6, end);//width
        WriteDataToBuffer(packet, player.m_hot_row, end, 8, end);//width
        WriteDataToBuffer(packet, player.m_hot_col, end, 8, end);//width
        WriteDataToBuffer(packet, (int)player.m_level, end, 2, end);
        WriteDataToBuffer(packet, player.m_life_left, end, 8, end);
        WriteDataToBuffer(packet, player.m_row, end, 10, end);
        WriteDataToBuffer(packet, player.m_col, end, 10, end);
        WriteDataToBuffer(packet, (int)player.m_dir, end , 2, end);//width
        WriteDataToBuffer(packet, (int)player.m_shield, end, 1, end);//width
}


void PutEnemy(byte* packet,Enemy enemy,int& end){
        WriteDataToBuffer(packet, enemy.m_width, end , 6, end);//width
        WriteDataToBuffer(packet, enemy.m_height, end, 6, end);//width
        WriteDataToBuffer(packet, enemy.m_hot_row, end, 8, end);//width
        WriteDataToBuffer(packet, enemy.m_hot_col, end, 8, end);//width
        WriteDataToBuffer(packet, (int)enemy.m_level, end, 2, end);
        WriteDataToBuffer(packet, enemy.m_life_left, end, 8, end);
        WriteDataToBuffer(packet, enemy.m_row, end, 10, end);
        WriteDataToBuffer(packet, enemy.m_col, end, 10, end);
        WriteDataToBuffer(packet, (int)enemy.m_dir, end , 2, end);//width
        WriteDataToBuffer(packet, (int)enemy.m_shield, end, 1, end);//width
        WriteDataToBuffer(packet, (int)enemy.m_type, end , 2, end);//width
        WriteDataToBuffer(packet, (int)enemy.m_flash, end, 1, end);//width
}

void PutExplode(byte* packet,Explode explode,int& end){
        WriteDataToBuffer(packet, explode.m_width, end , 6, end);//width
        WriteDataToBuffer(packet, explode.m_height, end, 6, end);//width
        WriteDataToBuffer(packet, explode.m_hot_row, end, 8, end);//width
        WriteDataToBuffer(packet, explode.m_hot_col, end, 8, end);//width
        WriteDataToBuffer(packet, explode.m_row, end, 10, end);
        WriteDataToBuffer(packet, explode.m_col, end, 10, end);
        WriteDataToBuffer(packet, explode.m_type,end,2,end);
}

void PutGame(byte* packet,Game game ,int & end){
        //setting
        WriteDataToBuffer(packet,(int)game.m_game_state, end , 3, end);//width
        WriteDataToBuffer(packet, game.m_level, end, 4, end);//width
        WriteDataToBuffer(packet, game.m_enemy_level, end, 4, end);//width
        WriteDataToBuffer(packet, game.m_player_level[0], end, 4, end);//width
        WriteDataToBuffer(packet, game.m_player_level[1], end, 4, end);

        for(int i = 0;i<2;i++){
                for(int j = 0;j<4;j++){
                   WriteDataToBuffer(packet, game.m_count[i][j], end, 5, end);
                }
        }

        //player
        WriteDataToBuffer(packet, (int)game.m_player_freezing, end, 1, end);
        PutPlayer(packet,game.m_player[0],end);
        PutPlayer(packet,game.m_player[1],end);
        WriteDataToBuffer(packet, (int)game.m_player_living[0], end, 1, end);
        WriteDataToBuffer(packet, (int)game.m_player_living[1], end, 1, end);
        WriteDataToBuffer(packet, game.m_player_life_left[0], end, 8, end);
        WriteDataToBuffer(packet, game.m_player_life_left[1], end, 8, end);


        //enemy
        WriteDataToBuffer(packet, (int)game.m_enemy_freezing, end, 1, end);
        WriteDataToBuffer(packet, game.m_enemy_living, end, 5, end);
        for(int i = 0 ;i<game.m_enemy_living;i++){
                PutEnemy(packet,game.m_enemy[i],end);
        }
        WriteDataToBuffer(packet, game.m_enemy_left, end, 5, end);

        //Player Bullet
        WriteDataToBuffer(packet, (int)game.m_player_bullet_living[0], end, 3, end);
        for(int i = 0 ;i<game.m_player_bullet_living[0];i++){
                PutBullet(packet,game.m_player_bullet[0][i],end);
        }

        WriteDataToBuffer(packet, (int)game.m_player_bullet_living[1], end, 3, end);
        for(int i = 0 ;i<game.m_player_bullet_living[1];i++){
                PutBullet(packet,game.m_player_bullet[1][i],end);
        }

        //Enemy Bullet
        WriteDataToBuffer(packet, (int)game.m_enemy_bullet_living, end, 6, end);
        for(int i = 0 ;i<game.m_enemy_bullet_living;i++){
                PutBullet(packet,game.m_enemy_bullet[i],end);
        }

        //Player Bore
        WriteDataToBuffer(packet, (int)game.m_player_bore_living[0], end, 1, end);
        WriteDataToBuffer(packet, (int)game.m_player_bore_living[1], end, 1, end);
        PutBore(packet,game.m_player_bore[0],end);
        PutBore(packet,game.m_player_bore[1],end);

        //Enemy Bore
        WriteDataToBuffer(packet, (int)game.m_enemy_bore_living, end, 2, end);
        for(int i = 0;i<game.m_enemy_bore_living;i++){
                PutBore(packet,game.m_enemy_bore[i],end);
        }

        //big explode
        WriteDataToBuffer(packet, (int)game.m_big_explode_living, end, 5, end);
        for(int i = 0;i<game.m_big_explode_living;i++){
               PutExplode(packet,game.m_big_explode[i],end);
        }

        //small explode
        WriteDataToBuffer(packet, (int)game.m_small_explode_living, end,5, end);       for(int i = 0;i<game.m_small_explode_living;i++){
                PutExplode(packet,game.m_small_explode[i],end);
        }

        //hawk explode
        WriteDataToBuffer(packet, (int)game.m_hawk_explode_living, end, 1, end);
        PutExplode(packet,game.m_hawk_explode,end);

         //bonus
        WriteDataToBuffer(packet, (int)game.m_bonus_living, end, 1, end);
        PutBonus(packet,game.m_bonus,end);
}


void PutMap(byte* packet,Game game,int & end){
        WriteDataToBuffer(packet, (int)game.m_map.m_protected, end, 1, end);
        WriteDataToBuffer(packet, (int)game.m_map.m_bare, end, 1, end);

        //Tile[13*13]
        for(int i =  0;i<13*13;i++){
                PutTile(packet,game.m_map.m_tile_array[i],end);
        }
}

//return the bytes this frame use
int PutGameRunFrame(byte* packet,Game game,int frame_num){
        int frame_size;
        int end = 34;
        //map
        PutMap(packet,game,end);

        //game 
        PutGame(packet,game ,end);

        frame_size =(int)((end/8)+1);
        //FRAME_NO
        PutFrame_No(packet,end,frame_num,GAME_RUN_FRAME);

        return frame_size;

}

int PutGameWinFrame(byte * packet,Game game,int frame_num){
        int frame_size;
        int end = 34;

        WriteDataToBuffer(packet, (int)game.m_game_state, end, 3, end);
        WriteDataToBuffer(packet, (int)game.m_win_click, end, 9, end);

        frame_size = (int)((end/8)+1);

        //FRAME_NO
        PutFrame_No(packet,end,frame_num,GAME_WIN_FRAME);

        return frame_size;

}

int PutGameOverFrame(byte * packet,Game game,int frame_num){
        int frame_size;
        int end = 34;

        WriteDataToBuffer(packet, (int)game.m_game_state, end, 3, end);

        frame_size = (int)((end/8)+1);

        //FRAME_NO
        PutFrame_No(packet,end,frame_num,GAME_OVER_FRAME);

        return frame_size;

}



void GetBore(byte* packet,Bore& bore,int& end){
	ReadDataFromBuffer(packet,end,6,end, bore.m_width);//width
	ReadDataFromBuffer(packet,end,6,end, bore.m_height);//width
	ReadDataFromBuffer(packet,end,8,end, bore.m_hot_row);
	ReadDataFromBuffer(packet,end,8,end, bore.m_hot_col);
	ReadDataFromBuffer(packet,end,10,end, bore.m_row);
	ReadDataFromBuffer(packet,end,10,end, bore.m_col);
}

void GetBonus(byte* packet ,Bonus& bonus,int & end){
        ReadDataFromBuffer(packet,end,6 ,end, bonus.m_width);
        ReadDataFromBuffer(packet,end,6,end, bonus.m_height);
        ReadDataFromBuffer(packet, end,8,end,bonus.m_hot_row);
        ReadDataFromBuffer(packet,end,8,end, bonus.m_hot_col);
        ReadDataFromBuffer(packet,end,10,end, bonus.m_row);
        ReadDataFromBuffer(packet,end,10,end, bonus.m_col);
	
	int bonus_type = 0;
	
	ReadDataFromBuffer(packet,end , 3, end, bonus_type);//width
	bonus.m_type =(BonusType) bonus_type;
}


void GetBullet(byte* packet,Bullet& bullet,int& end){
        ReadDataFromBuffer(packet, end , 6, end, bullet.m_width);//width
        ReadDataFromBuffer(packet, end , 6, end, bullet.m_height);//width
        ReadDataFromBuffer(packet, end, 8, end, bullet.m_hot_row);//width
        ReadDataFromBuffer(packet, end, 8, end, bullet.m_hot_col);//width
        ReadDataFromBuffer(packet, end, 10, end, bullet.m_row);
        ReadDataFromBuffer(packet, end, 10, end, bullet.m_col);
        
	
	int dir = 0;
	int level = 0;
	
	ReadDataFromBuffer(packet, end , 2, end, dir);//width
        ReadDataFromBuffer(packet, end , 2, end, level);//width

	bullet.m_dir = (Direction)dir;
	bullet.m_level = (BulletLevel)level;
}

void GetTile(byte* packet,Tile& tile,int& end){
	int a,b,c,d,e;

        ReadDataFromBuffer(packet, end , 4, end, a);//width
        ReadDataFromBuffer(packet, end , 4, end, b) ;
        ReadDataFromBuffer(packet, end , 4, end, c) ;
        ReadDataFromBuffer(packet, end , 4, end, d) ;
        ReadDataFromBuffer(packet, end , 4, end, e) ;


	tile.m_data[0] = (BlockType)a;
	tile.m_data[1] = (BlockType)b;
	tile.m_data[2] = (BlockType) c;

	tile.m_data[3] =  (BlockType)d;
	tile.m_data[4] =  (BlockType)e;

}

//frame_size: here the unit is byte
//get frame_size , frame_type,frame_num

void GetFrame_No(byte* packet ,int & frame_size,int& frame_num,char& type){
	//deal with lastly
	//end : the total bits we used in this frame including the FRAME_NO
	int end = 0;
	int m_type ;

        ReadDataFromBuffer(packet, 0, 10, end,frame_size);
        ReadDataFromBuffer(packet, end, 8, end,m_type);
        ReadDataFromBuffer(packet, end, 16, end, frame_num);

	type = (char)m_type;
}

void GetPlayer(byte* packet,Player& player,int& end){
	int level,shield,dir;


        ReadDataFromBuffer(packet, end , 6, end, player.m_width) ;//width
        ReadDataFromBuffer(packet, end , 6, end, player.m_height) ;//width
        ReadDataFromBuffer(packet, end , 8, end, player.m_hot_row) ;//width
        ReadDataFromBuffer(packet, end , 8, end, player.m_hot_col) ;//width
        ReadDataFromBuffer(packet, end , 2, end, level) ;
        ReadDataFromBuffer(packet, end , 8, end, player.m_life_left) ;
        ReadDataFromBuffer(packet, end , 10, end, player.m_row) ;
        ReadDataFromBuffer(packet, end , 10, end, player.m_col) ;
        ReadDataFromBuffer(packet, end , 2, end, dir) ;//width
        ReadDataFromBuffer(packet, end , 1, end, shield) ;//width


	player.m_dir = (Direction)dir;
	player.m_level = (TankLevel)level;
	player.m_shield =(bool)shield;

}


void GetEnemy(byte* packet,Enemy& enemy,int& end){
	int shield,dir,level,flash,type;


        ReadDataFromBuffer(packet, end , 6, end, enemy.m_width) ;//width
        ReadDataFromBuffer(packet, end , 6, end, enemy.m_height) ;//width
        ReadDataFromBuffer(packet, end , 8, end, enemy.m_hot_row) ;//width
        ReadDataFromBuffer(packet, end , 8, end, enemy.m_hot_col) ;//width
        ReadDataFromBuffer(packet, end , 2, end, level) ;
        ReadDataFromBuffer(packet, end , 8, end, enemy.m_life_left) ;
        ReadDataFromBuffer(packet, end , 10, end, enemy.m_row) ;
        ReadDataFromBuffer(packet, end , 10, end, enemy.m_col) ;
        ReadDataFromBuffer(packet, end , 2, end, dir) ;//width
        ReadDataFromBuffer(packet, end , 1, end, shield) ;//width
        ReadDataFromBuffer(packet, end , 2, end, type) ;//width
        ReadDataFromBuffer(packet, end , 1, end, flash) ;//width

	enemy.m_shield = (bool)shield;
	enemy.m_type = (EnemyType)type;
	enemy.m_flash = (bool)flash;
	enemy.m_level = (TankLevel)level;
	enemy.m_dir = (Direction)dir;
}

void GetExplode(byte* packet,Explode& explode,int& end){
        	
	int type;

	ReadDataFromBuffer(packet, end , 6, end, explode.m_width) ;//width
        ReadDataFromBuffer(packet, end , 6, end, explode.m_height) ;//width
        ReadDataFromBuffer(packet, end , 8, end, explode.m_hot_row) ;//width
        ReadDataFromBuffer(packet, end , 8, end, explode.m_hot_col) ;//width
        ReadDataFromBuffer(packet, end , 10, end, explode.m_row) ;
        ReadDataFromBuffer(packet, end , 10, end, explode.m_col) ;
        ReadDataFromBuffer(packet, end , 2, end, type) ;

	explode.m_type = (ExplodeType)type;
}

void GetGame(byte* packet,Game& game ,int & end){
        
	int state,player_freezing,player_living_1,player_living_2,enemy_freezing;	

	//setting
        ReadDataFromBuffer(packet, end , 3, end,state) ;//width
        ReadDataFromBuffer(packet, end , 4, end, game.m_level) ;//width
        ReadDataFromBuffer(packet, end , 4, end, game.m_enemy_level) ;//width
        ReadDataFromBuffer(packet, end , 4, end, game.m_player_level[0]) ;//width
        ReadDataFromBuffer(packet, end , 4, end, game.m_player_level[1]) ;

	game.m_game_state =(GameState) state;
	

        for(int i = 0;i<2;i++){
                for(int j = 0;j<4;j++){
                   ReadDataFromBuffer(packet, end , 5, end, game.m_count[i][j]) ;
                }
        }

        //player
        ReadDataFromBuffer(packet, end , 1, end, player_freezing) ;
        GetPlayer(packet,game.m_player[0],end);
        GetPlayer(packet,game.m_player[1],end);
        ReadDataFromBuffer(packet, end , 1, end, player_living_1) ;
        ReadDataFromBuffer(packet, end , 1, end, player_living_2) ;
        ReadDataFromBuffer(packet, end , 8, end, game.m_player_life_left[0]) ;
        ReadDataFromBuffer(packet, end , 8, end, game.m_player_life_left[1]) ;

	game.m_player_freezing = (bool)player_freezing;	

	game.m_player_living[0] = player_living_1;
	game.m_player_living[1] = player_living_2;
	
	


        //enemy
        ReadDataFromBuffer(packet, end , 1, end, enemy_freezing) ;
        ReadDataFromBuffer(packet, end , 5, end, game.m_enemy_living) ;
        for(int i = 0 ;i<game.m_enemy_living;i++){
                GetEnemy(packet,game.m_enemy[i],end);
        }


	game.m_enemy_freezing = (bool)enemy_freezing;


        ReadDataFromBuffer(packet, end , 5, end, game.m_enemy_left) ;

        //Player Bullet
        ReadDataFromBuffer(packet, end , 3, end, game.m_player_bullet_living[0]) ;
        for(int i = 0 ;i<game.m_player_bullet_living[0];i++){
                GetBullet(packet,game.m_player_bullet[0][i],end);
        }

        ReadDataFromBuffer(packet, end , 3, end, game.m_player_bullet_living[1]) ;
        for(int i = 0 ;i<game.m_player_bullet_living[1];i++){
                GetBullet(packet,game.m_player_bullet[1][i],end);
        }

        //Enemy Bullet
        ReadDataFromBuffer(packet, end , 6, end, game.m_enemy_bullet_living) ;
        for(int i = 0 ;i<game.m_enemy_bullet_living;i++){
                GetBullet(packet,game.m_enemy_bullet[i],end);
        }

        //Player Bore
        ReadDataFromBuffer(packet, end , 1, end, game.m_player_bore_living[0]) ;
        ReadDataFromBuffer(packet, end , 1, end, game.m_player_bore_living[1]) ;
        GetBore(packet,game.m_player_bore[0],end);
        GetBore(packet,game.m_player_bore[1],end);

        //Enemy Bore
        ReadDataFromBuffer(packet, end , 2, end, game.m_enemy_bore_living) ;
        for(int i = 0;i<game.m_enemy_bore_living;i++){
                GetBore(packet,game.m_enemy_bore[i],end);
        }

        //big explode
        ReadDataFromBuffer(packet, end , 5, end, game.m_big_explode_living) ;
        for(int i = 0;i<game.m_big_explode_living;i++){
               GetExplode(packet,game.m_big_explode[i],end);
        }

        //small explode
        ReadDataFromBuffer(packet, end , 5, end, game.m_small_explode_living) ; 
        for(int i = 0;i<game.m_small_explode_living;i++){
                GetExplode(packet,game.m_small_explode[i],end);
        }

	int hawk_explode_living;

        //hawk explode
        ReadDataFromBuffer(packet, end , 1, end, hawk_explode_living) ;
        game.m_hawk_explode_living = (bool)hawk_explode_living;
	
	GetExplode(packet,game.m_hawk_explode,end);

	int bonus_living;	
         //bonus
        ReadDataFromBuffer(packet, end , 1, end,bonus_living) ;
	game.m_bonus_living = (bool)bonus_living;	

        GetBonus(packet,game.m_bonus,end);
}


void GetMap(byte* packet,Game& game,int & end){
        int pro,bare;

	ReadDataFromBuffer(packet, end , 1, end,pro);
        ReadDataFromBuffer(packet, end , 1, end,bare);

	game.m_map.m_protected = (bool)pro;
	game.m_map.m_bare = (bool)bare;

        //Tile[13*13]
        for(int i =  0;i<13*13;i++){
               GetTile(packet,game.m_map.m_tile_array[i],end);
        }
}

//return the bytes this frame use
void GetGameRunFrameBody(byte* packet,Game& game){
        int end = 34;
        //map
        GetMap(packet,game,end);

        //game 
        GetGame(packet,game ,end);

//GetFrame_no will be called outside this function
//	GetFrame_no(packet,frame_size,frame_num,);
	
}

void GetGameWinFrameBody(byte * packet,Game& game){
        int end = 34;
	
	int state;	

        ReadDataFromBuffer(packet, end, 3, end, state);
	game.m_game_state = (GameState)state;

        ReadDataFromBuffer(packet, end, 9, end, game.m_win_click);
	if(game.m_win_click == 0){game.set_state(GameWin);}
}

void GetGameOverFrameBody(byte* packet,Game& game){
        int end = 34;
        
	int state ;

	ReadDataFromBuffer(packet, end, 3, end, state);
	//log("debug info ::deal with GameOverFrame\r\n");
	game.m_game_state = (GameState)state;
	game.set_state(GameOver);
	game.disconnectFromNetwork();
	//log("debug info::done deal with GameOverFrame\r\n");
}
