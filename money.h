#ifndef money_h
#define money_h
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include <sqlite3.h>
#define N 15
#define STR 50
#define MAX 100
struct User {//用户信息结构体
		char username[STR];
		char password[STR];
		struct User *next;

};
/*struct contact
{
	char name[30];
	int password1[30];
	struct contact *next;
};*/
struct UseLinkNode {//用户信息链表结构体
		struct User data;
		struct UseLinkNode* next;
};

struct Record {//收支信息结构体
		char id[STR];
		char member[STR];
		float money;
		char type[STR];
		char date[STR];
		char remark[STR];
};
struct RecLinkNode {//收支信息链表结构体
		struct Record data;
		struct RecLinkNode* next;
};
struct Assets {//资产信息结构体
		int id;
		char member[STR];
		float money;
};
struct AssLinkNode {//资产信息链表结构体
		struct Assets data;
		struct AssLinkNode* next;
};
//void create_regtable();
//void reg_Insert();
//void Login();
int creat_table(sqlite3 *db);
int insert_table(sqlite3 *db);
int display(sqlite3 *db);
void saveUserInfo(struct UseLinkNode* useHead);
void readUserInfo(struct UseLinkNode* useHead);
void saveRecordInfo(struct RecLinkNode* recHead);
void readRecordInfo(struct RecLinkNode* recHead);
void saveAssetsInfo(struct AssLinkNode* assHead);
void readAssetsInfo(struct AssLinkNode* assHead);
void addRecordInfo(struct RecLinkNode* recHead);
void modifyRecordInfo(struct RecLinkNode* recHead);
void deleteRecordInfo(struct RecLinkNode* recHead);
void queryRecordInfo(struct RecLinkNode* recHead, struct AssLinkNode* assHead);
void sortRecordInfo(struct RecLinkNode* recHead);
void statisRecordInfo(struct RecLinkNode* recHead, struct AssLinkNode* assHead);
void statisAssetsInfo(struct RecLinkNode* recHead, struct AssLinkNode* assHead);
struct User userLoginRegister(struct UseLinkNode* useHead, int* login);
//void save(Link *useHead);

#endif
