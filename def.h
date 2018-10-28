#pragma once
/*
	FILE: def.h

	为多平台的头文件综合

*/

#ifndef __DEF_H__
#define __DEF_H__

#define dSERVER_PORT  7000
#define dMAX_LISTEN	  200

/*
	当使用select时，为了重新设置FD_SETSIZE限制，而进行的define。
		当是linux或者FreeBSD时，默认值是1024；
			当win32：默认值是64
*/
#define FD_SETSIZE 6000


/*
	跨平台 for win32
*/
#if defined(WIN32)
#include <windows.h>
#include <winsock.h>
#include <mmsystem.h>
#include <stdio.h>
#include <time.h>

//#include "resource.h" //?????????????????


#else


/*
	跨平台： for FreeBSD / Linux 的头文件
*/
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <sys/time.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <sys/select.h>
/*
	在UNIX系列操作系统当中使用close函数关闭套接字
*/
#define closesocket(sock) close(sock)

#define INVALID_SOCKET (-1)
#define TRUE 1
#define FALSE 0

typedef int SOCKET;			// 4 bytes
typedef int BOOL;			// 4 bytes
typedef unsigned char BYTE;  // 1 bytes
typedef unsigned int DWORD; // 
typedef unsigned short WORD; // 2 bytes
typedef int COLORREF;



#endif // end of if defined (Win32)

#endif // !__DEF_H__
