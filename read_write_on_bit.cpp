#include "read_write_on_bit.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void ReadOneBit(byte* pBuffer, int nStart, /* out */int& nEnd, /* out */ byte& retByte)
{
	byte btData = pBuffer[nStart / 8];
	btData = btData << nStart % 8;
	retByte = btData >> 7;
	nEnd = nStart + 1;
}
//template<typename T>
void ReadDataFromBuffer(byte* pBuffer, int nStart, byte btLength, /* out */int& nEnd, /* out */ int& retData)
{
	//顺序读位 
	retData = 0;
	if (btLength > sizeof(int) * 8)
		return;
	byte btData;
	int tData;
	while (btLength--)
	{
		ReadOneBit(pBuffer, nStart, nStart, btData);
		tData = btData << btLength;
		retData |= tData;
	}
	nEnd = nStart;
}
void ReadStringFromBuffer(byte* pBuffer, int nStart, int nCount, /* out */int& nEnd, /* out */char* pRetData)
{
	//for (int nIndex = 0; nIndex<nCount; nIndex++)
	//{
	//	ReadDataFromBuffer(pBuffer, nStart, 8, nStart, pRetData[nIndex]);
	//}
	//nEnd = nStart;
}
void WriteOneBit(byte* pBuffer, byte btData, int nStart, /* out */int& nEnd)
{
	int nSet = nStart / 8;
	byte c = pBuffer[nSet];
	switch (btData)
	{
	case 1:
		c |= (1 << (7 - nStart % 8));
		break;
	case 0:
		c &= (~(1 << (7 - nStart % 8)));
		break;
	default:
		return;
	}
	pBuffer[nSet] = c;
	nEnd = nStart + 1;
}


//template<typename T>
void WriteDataToBuffer(byte* pBuffer, int tData, int nStart, byte btLength, /* out */int& nEnd)
{
	/* //大端机模式
	byte btDataLength = sizeof(T);
	if ( btLength > sizeof(T)*8 )
	return;
	int nDataStart = 0; //数据的第一位位置为0，顺序写入
	while ( btLength-- )
	{
	byte bitData;
	ReadOneBit((byte*)&tData, nDataStart, nDataStart, bitData);
	WriteOneBit(pBuffer, bitData, nStart, nStart);
	}
	nEnd = nStart;
	*/
	//小端机模式：写buffer的时候，不能顺序写位 
	//获得模版占用字节大小 
	byte btDataLength = sizeof(int);
	//校验长度是否越界 
	if (btLength > sizeof(int) * 8)
		return;
	//将待写数据转为byte* 
	byte* ptData = (byte*)&tData;
	//求模与余 
	int nSet = btLength / 8;
	int nRin = btLength % 8;
	//定义字节数据与位数据 
	byte bitData;
	byte byteData;
	int nTempEnd;
	//先写rin数据 
	byteData = ptData[nSet];
	while (nRin--)
	{
		ReadOneBit(&byteData, 7 - nRin, nTempEnd, bitData);
		WriteOneBit(pBuffer, bitData, nStart, nStart);
	}
	//再写Set数据 
	while (nSet)
	{
		byteData = ptData[--nSet];
		//写一个byte 
		int i = 0;
		while (i != 8)
		{
			ReadOneBit(&byteData, i++, nTempEnd, bitData);
			WriteOneBit(pBuffer, bitData, nStart, nStart);
		}
	}
	nEnd = nStart;
}
void WtriteStringToBuffer(byte* pBuffer, char* pchar, int nStart, int nCount, /* out */int& nEnd)
{
	for (int nIndex = 0; nIndex<nCount; nIndex++)
	{
		WriteDataToBuffer(pBuffer, pchar[nIndex], nStart, 8, nStart);
	}
	nEnd = nStart;
}

