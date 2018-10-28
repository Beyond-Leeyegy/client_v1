#pragma once
/*
	FILE:utils.h

	各种通用函数
*/

#ifndef __UTILS_H__
#define __UTILS_H__

#include "def.h"

/*
	日志的画面输出和文件记录函数

*/
void log(char *buf, ...);

/*
	win32 timeGetTime 函数的仿效（emulation）
*/
#ifndef  WIN32
DWORD timeGetTime();
#endif // ! WIN32

#endif // !__UTILS_H__
