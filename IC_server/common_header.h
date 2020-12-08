#ifndef COMMON_HEADER_H
#define COMMON_HEADER_H

#define USER_ACCOUNT_LEN 50	//用户账号最大长度
#define USER_PASSWD_LEN 10	//用户密码最大长度
#define USER_CARDID_LEN 50	//RFID卡id最大长度
#define CMD_BUFFER_SIZE 256	//sqlite命令缓冲区大小

#define SERVER_PORT 6666	//TCP监听端口
#define TRANSFER_MAX_SIZE 102400	//读写一次文件的最大容量
#define TCP_INFO_SEPARATOR ":"
#define REGISTER_CODE 1000
#define REGISTER_ACK 1001
#define LOGIN_CODE 1002
#define LOGIN_ACK 1003
#define GET_VIDEO_CODE 1004
#define GET_VIDEO_ACK 1005

#include <iostream>
#include <QDebug>
//#include "sqlite3.h"

#endif // COMMON_HEADER_H
