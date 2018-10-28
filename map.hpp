#ifndef map_h
#define map_h

#include "hsl/hsl.hpp"
typedef enum {
	BlockNull = 0,
	BlockBrick,    //砖
	BlockConcrete, //钢板
	BlockTree,
	BlockRiver1,
	BlockRiver2,
	BlockHawk,
	BlockStone,    //死掉的老王
	BlockMix,		//杂和板（因为一个Tile由四个Block组成，当四个Block的类型不一致的时候，那么该Tile的类型就是BlcokMix）
}BlockType;



class Tile{
	public:
		//BlockType:枚举体
		BlockType type();
		BlockType type(int);		//返回m_data在i+1出元素值
		void set_type(BlockType);	//设置m_data[0]
		void set_type(int,BlockType);//设置m_data[i+1]
	public:
		BlockType m_data[5];		//保存地图上砖块的类型？
};



class Map {
	public:
		Map();
		virtual ~Map();


	public:
		bool  load(const char*);


		Tile& tile(int,int);
		Tile& pixel_tile(int,int);


		// 当前点的绝对属性
		BlockType  pixel_type(int,int);

		void blit_tile (HSL::Image&,int,int);
		void blit_floor(HSL::Image&,int,int);
		void blit_cover(HSL::Image&,int,int);


	public:

		void    set_tile(int,int,BlockType);
		void    set_tile(int,int,int,BlockType);

		void    set_hawk_protected();
		void	set_hawk_bare();//老王被脱光
		void    set_hawk_normal();
		void    update();
		void    update_river();

		int 	pixel_width();
		int 	pixel_height();
		int 	tile_width();
		int 	tile_height();





//	private:
//		#define m_width 13
//		#define m_height 13
	public:
		bool 	m_protected;
		bool    m_bare;
		int	m_protect_click;
		int 	m_bare_click;
		Tile	m_tile_array[13*13];
		static  HSL::Image s_img_tile;
	
};


#endif
