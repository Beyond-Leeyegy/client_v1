#include <iostream>
#include <stdio.h>
#include "font.hpp"

HSL::Font::Font():
HSL::Image()
{
}

HSL::Font::~Font()
{
}


//int HSL::Font::put_char(HSL::Image& dst,char ch,int row,int col){
//
//	if( ch >= '0' && ch <= '9'){
//		dst.draw(*this,
//				  ((ch-'0')*39.834),0,
//				  18,25,
//				  row,col,
//				  RGB(0,0,0));
//		return 16-(3*(ch=='1'));
//	}else if(ch >='a' && ch <='m'){
//		dst.draw(*this,
//				  1+((ch-'a')*39.834),35,
//				  18,25,
//				  row,col,
//				  RGB(0,0,0));
//		return 16-(7*(ch == 'i' || ch == 'l')) + (2*(ch =='m'));
//	}else if(ch >='n' && ch <= 'z'){
//		dst.draw(*this,
//				  (ch-'n')*39.834,62,
//				  22,24,
//				  row,col,
//				  RGB(0,0,0));
//		return 17;
//
//	}else if(ch >='A' && ch <= 'M'){
//		dst.draw(*this,
//				  (ch-'A')*39.834,90,
//				  22,26,
//				  row,col,
//				  RGB(0,0,0));
//		return 20-(2*(ch=='I'));
//	}else if(ch >='N' && ch <= 'Z'){
//		dst.draw(*this,
//				  (ch-'N')*39.834,124,
//				  22,26,
//				  row,col,
//				  RGB(0,0,0));
//		return 20;
//	}else if(ch =='.' || ch == ',' || ch == '!'){
//		dst.draw(*this,
//				  394+40.85*((ch==',')+2*(ch=='!')),0,
//				  22,26,
//				  row,col,
//				  RGB(0,0,0));
//		return 13;
//	}else{
//		return 9;
//	}
//
//}
//
int HSL::Font::put_char(HSL::Image& dst,char ch,int row,int col){

	if( ch >= '0' && ch <= '9'){
		dst.draw(*this,
				  ((ch-'0')*31.55),0,
				  15,19,
				  row,col,
				  RGB(0,0,0));
		return 13-(3*(ch=='1'));
	}else if(ch >='a' && ch <='m'){
		dst.draw(*this,
				  -1+((ch-'a')*31.55),26,
				  18,20+3*(ch == 'j' || ch == 'g'),
				  row,col,
				  RGB(0,0,0));
		return 13-(6*(ch == 'i' || ch == 'l')) + (3*(ch =='m'));
	}else if(ch >='n' && ch <= 'z'){
		dst.draw(*this,
				  (ch-'n')*31.55,49,
				  18,20,
				  row,col,
				  RGB(0,0,0));
		return 12 + 4*(ch == 'w') - 2*(ch=='t');

	}else if(ch >='A' && ch <= 'M'){
		dst.draw(*this,
				  (ch-'A')*31.55-2*(ch != 'A'),71,
				  18+(ch == 'M'),20,
				  row,col,
				  RGB(0,0,0));
		return 14-(2*(ch=='I')) + 3*(ch == 'H') + (ch == 'D' || ch == 'M');
	}else if(ch >='N' && ch <= 'Z'){
		dst.draw(*this,
				  (ch-'N')*31.55-(ch !='N'),98,
				  18+3*(ch=='W'),20,
				  row,col,
				  RGB(0,0,0));
		return 15 + (ch == 'N') + 2*(ch == 'O')+7*(ch == 'W') - 2*(ch == 'P') + 3*(ch == 'Q');
	}else if(ch =='.' || ch == ',' || ch == '!'){
		dst.draw(*this,
				  316+31.55*((ch==',')+2*(ch=='!')),0,
				  18,20,
				  row,col,
				  RGB(0,0,0));
		return 8;
	}else{
		return 5;
	}

}

void HSL::Font::put_str(HSL::Image& dst,const std::string& str,int row,int col ){
	
	int p=0;
	for (int i=0;i<str.length();i++)
		p+=put_char(dst,str[i],row,col+p);

}
