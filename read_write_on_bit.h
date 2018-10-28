#ifndef __READ_WRITE_ON_BIT__
#define __READ_WRITE_ON_BIT__
typedef unsigned char byte;
/***********************************************************************/
/* 函数作用：从buffer读一个位 */
/* 参数pBuffer[in]：指定buffer */
/* 参数nStart[in]：指定位置 */
/* 参数nEnd[out]：返回结束位置 */
/* 参数retByte[out]：返回读取结果值 */
/* 返回：void */
/***********************************************************************/
void ReadOneBit(byte* pBuffer, int nStart, /* out */int& nEnd, /* out */ byte& retByte);





/***********************************************************************/
/* 函数作用：从指定buffer里读任意一段位置数据 */
/* 参数pBuffer[in]：指定buffer */
/* 参数nStart[in]：指定位置 */
/* 参数btLength[in]：读取长度 */
/* 参数nEnd[out]：返回结束位置 */
/* 参数retData[out]：返回读取结果值，支持任意数据类型 */
/* 返回：void */
/***********************************************************************/
//template<typename T>
void ReadDataFromBuffer(byte* pBuffer, int nStart, byte btLength, /* out */int& nEnd, /* out */ int& retData);





/***********************************************************************/
/* 函数作用：从指定buffer里读取一段字符串 */
/* 参数pBuffer[in]：指定buffer */
/* 参数nStart[in]：指定位置 */
/* 参数nCount[in]：字符串长度 */
/* 参数nEnd[out]：返回结束位置 */
/* 参数pRetData[out]：返回读取字符串结果 */
/* 返回：void */
/***********************************************************************/
void ReadStringFromBuffer(byte* pBuffer, int nStart, int nCount, /* out */int& nEnd, /* out */char* pRetData);





/***********************************************************************/
/* 函数作用：向buffer写一个位 */
/* 参数pBuffer[in]：指定buffer */
/* 参数btData[in]：需要写入的值 */
/* 参数nStart[in]：指定位置 */
/* 参数nEnd[out]：返回结束位置 */
/* 返回：void */
/***********************************************************************/
void WriteOneBit(byte* pBuffer, byte btData, int nStart, /* out */int& nEnd);






/***********************************************************************/
/* 函数作用：向指定buffer里写入任意一段数据 */
/* 参数pBuffer[in]：指定buffer */
/* 参数tData[in]：需要写入的数据，支持任意数据类型 */
/* 参数nStart[in]：指定位置 */
/* 参数btLength[in]：读取长度 */
/* 参数nEnd[out]：返回结束位置 */
/* 返回：void */
/***********************************************************************/
//template<typename T>
void WriteDataToBuffer(byte* pBuffer, int tData, int nStart, byte btLength, /* out */int& nEnd);





/***********************************************************************/
/* 函数作用：向指定buffer里写取一段字符串 */
/* 参数pBuffer[in]：指定buffer */
/* 参数pchar[in]：需要写入的字符串 */
/* 参数nStart[in]：指定位置 */
/* 参数nCount[in]：字符串长度 */
/* 参数nEnd[out]：返回结束位置 */
/* 返回：void */
/***********************************************************************/
void WtriteStringToBuffer(byte* pBuffer, char* pchar, int nStart, int nCount, /* out */int& nEnd);




#endif
