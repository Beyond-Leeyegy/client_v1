#ifndef game_hpp
#define game_hpp

#include "hsl/hsl.hpp"
#include "sprite.hpp"
#include "map.hpp"
#include <pthread.h>
#include <iostream>
#include <string>
#include "client_structs.h"

#define maxFrameNum 60000; 


int click(int);
typedef enum {
	GameWin = 0,
	GameStart,		//1  表示游戏开始，在Game::init函数中使用
	GameSplash,    //2
	GameRun,       //3
	GameSelect,     //4
	GameOver,      //5
	GameEnd, //彻底的结束，用在外层while(state != GameEnd ) 中
}GameState;

typedef enum {
	SplashJalousie = 0,   //百叶窗的展示效果
	SplashWindow,
	SplashBlock,
	SplashOther,
}SplashStyle;

#define g_max_enemy_count 20
#define g_fps 40		//播放帧率(帧数/秒)，可以依次调整游戏的速度

int game_random(int, int);

class Game {
public:
	Game();
	~Game();

public:
	//		void lock_game();
	//		bool try_lock_game();
	//		void unlock_game();

	void init();
	void run();
	void over();
	void delay();
	void mark_time();


	void process_input();
	void set_timer(int, TimerHandler, void*);
	void set_event_handler(HSL::EventHandler, void*);


	void init_map();



	bool single_player();
	void set_single_player(bool);
	Direction player_dir(int);
	void set_player_dir(int, Direction);
	bool player_freezing();
	void player_move(int);    //go if can 


	void enemy_try_attack(int);
	bool enemy_try_go_ahead(int);

	void player_try_attack(int);
	void player_get_bonus(int);
	void enemy_get_bonus(int);



	GameState state();
	void      set_state(GameState);
	void	  set_enemy_freezing();
	void	  set_hawk_protected();
	void      kill_enemy();
	void      show_message(const std::string&, int ms);





	void create_bonus();
	void create_player(int);
	void create_player_bore(int);
	void create_player_bullet(int);
	void create_enemy(int, int);
	void create_enemy_bore(int);
	void create_enemy_bullet(int);
	void create_hawk_explode();
	void create_small_explode(int, int);
	void create_big_explode(int, int);


	void remove_player(int);
	void remove_enemy(int);
	void remove_player_bore(int);
	void remove_player_bullet(int, int);
	void remove_enemy_bore(int);
	void remove_enemy_bullet(int);
	void remove_big_explode(int);
	void remove_small_explode(int);
	void remove_hawk_explode();
	void remove_bonus();

	void enemy_attack(int);
	void get_info_of_hit(Tile**, int*, Tile**, int*, int, int, Direction);
	void destroy_tile_block(Tile*, int);



	void try_create_enemy_bore();
	void try_create_player_bore();

	void deal_with_enemy_bullet();
	void deal_with_player_bullet();
	void deal_with_player();
	void deal_with_enemy();
	void deal_with_player_bore();
	void deal_with_enemy_bore();
	void deal_with_bonus();
	void deal_with_explode();

	void deal_with_message();
	void deal_with_delay();

	void enemy_bullet_hit_tile();
	void enemy_bullet_hit_player();
	void enemy_bullet_hit_fence();

	void player_bullet_hit_tile();
	void player_bullet_hit_enemy();
	void player_bullet_hit_player();
	void player_bullet_hit_player_bullet();
	void player_bullet_hit_enemy_bullet();
	void player_bullet_hit_fence();


	void enemy_bullet_update();
	void player_bullet_update();

	void update_screen();
	void update_auto_data();

	void draw_world();
	void draw_periphery();
	void draw_tiles();
	void draw_sprite();

	void draw_screen_on_run();
	void draw_screen_on_start();
	void draw_screen_on_over();
	void draw_screen_on_splash();
	void draw_screen_on_select();
	void draw_screen_on_win();

	void draw_enemy_left();
	void draw_player_life_left();
	void draw_player_level();
	void draw_game_level();

	void update_auto_data_on_run();
	void update_auto_data_on_start();
	void update_auto_data_on_over();
	void update_auto_data_on_splash();
	void update_auto_data_on_win();
	void update_auto_data_on_select();

public:
	//time control

	struct timespec m_time;
	struct timespec m_old_time;
	//state val
	GameState m_game_state;
	SplashStyle m_splash_style;
	bool m_full_screen;
	bool m_single_player;
	int  m_level;
	int  m_enemy_level;
	int  m_player_level[2];
	int  m_count[2][4];
	int  m_score[2];

	int  m_start_click;
	int  m_select_click;

	std::string m_msg;
	int  m_msg_click;

public:
	bool   m_player_freezing;
	int    m_player_freezing_click;

	Enemy  m_enemy[g_max_enemy_count];
	int    m_enemy_living;
	int    m_enemy_left;
	bool   m_enemy_freezing;
	int	   m_enemy_freezing_click;

	Player m_player[2];
	bool   m_player_living[2];
	int	   m_player_life_left[2];

	Bullet m_player_bullet[2][20];
	int    m_player_bullet_living[2];

	Bullet m_enemy_bullet[40];
	int	   m_enemy_bullet_living;

	Bore  m_player_bore[2];
	int	        m_player_bore_living[2];
	int	   	    m_player_bore_click[2];

	Bore   		m_enemy_bore[3];
	int	        m_enemy_bore_living;
	int	        m_last_enemy_bore_click;


	Explode   m_big_explode[20];
	int		  m_big_explode_living;

	Explode   m_small_explode[30];
	int		  m_small_explode_living;

	Explode   m_hawk_explode;
	bool       m_hawk_explode_living;

	Bonus     m_bonus;
	bool      m_bonus_living;


	int 	  m_win_click;//表示胜利画面的时间
	int 	  m_over_click;//表示"game over"画面的时间
	int 	  m_run_click;
	int       m_splash_click;

	int 	  m_win_delay_click;
	int 	  m_over_delay_click;

	pthread_mutex_t m_mutex;     //lock
public:
	//HSL classes

	HSL::Window m_win;
	HSL::Image  m_buffer;
	HSL::Image  m_img_select_single;
	HSL::Image  m_img_select_double;
	HSL::Image  m_img_world;
	HSL::Image  m_img_win;
	HSL::Image  m_img_over;
	HSL::Image  m_img_tiles;

	HSL::Audio  m_audio;
	HSL::Font   m_pen;
public:
	Map 			m_map;


public:
	sPCLIENT_DATA network;
	bool got_friend = false;

	friend void handle_event(HSL::Event*, void*);
	friend void handle_timer(HSL::Event*, void*);

public:
	bool connectToNetwork();			//尝试连接网络
										//void initClient();					//如果网络连接成功，分配指针空间，初始化指针内容，连接网络
	void disconnectFromNetwork();		//断开网络
	void freeClient();					//如果网络已经断开，那么就置sock为-1，并且重置缓存区
	void try_got_friend();
	void try_flush_client_order();
	void update_auto_data_on_run_onLine();

public:
	void deal_with_enemy_update_win_delay_click();
	void deal_with_enemy_left(int i);
	void deal_with_enemy_down(int i);
	void deal_with_enemy_right(int i);
	void deal_with_enemy_up(int i);
	void deal_with_enemy_set_dir(int i, int dir);
	void deal_with_enemy_update_enemy_freezing();
	void deal_with_enemy_bore_update();
	void deal_with_bonus_explode_message_delay();


public:
	int valid_input_count = 0;
	WORD frame_no = 0;
};

#define SoundTankHitted 1
#define SoundHawkHitted 1
#define SoundPlayerGetBonus 3
#define SoundEnemyGetBonus 4
#endif
