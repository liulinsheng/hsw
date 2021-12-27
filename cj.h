#ifndef cj_h
#define cj_h

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLEN 100                //宏定义,以后的MAXLEN都用100替代
#define GIFT_FILE "gift.txt"       
#define PEOPLE_FILE "people.txt"
#define nil  "null"

typedef struct {
    char name[MAXLEN];
}gift;

typedef struct {
    char name[MAXLEN];
}people;

// 链表常用的方式
typedef struct node{
    gift g;   // 奖品
    people p; // 玩家
    struct node *next; // 指针域 
}node;


typedef struct _node
{
	people  *data;
	struct _node *next;

}NodeUser;

typedef struct _linkedList
{
	NodeUser *head;
	NodeUser *tail;
	NodeUser *current;

}List_User;

typedef struct _nodeg
{
	gift  *data;
	struct _nodeg *next;

}NodeGift;

typedef struct _linkedListg
{
	NodeGift *head;
	NodeGift *tail;
	NodeGift *current;

}List_Gift;


// 头插法 == 栈， 栈只要一个指针，就够了。
typedef struct  {
    node *head;
}stack;

// 尾插法 == 队列
typedef struct {
    node *first;
    node *last;
}queue;

// 定义一个链栈，一个链队列

stack stack_node;
queue queue_node;

void init_stack();
void init_queue();
node* get_gift();
int get_num();
void play_game();
void User();
List_User *initList_User();
void addTail_User(List_User *list,people *data);
void Free_Userlist(NodeUser *list);
void UserToFile_list(List_User *list);
void Write_User();
people *Input_User_Data();
void UserFromFile(List_User *list);

List_Gift *initList_Gift();
void addTail_Gift(List_Gift *list,gift *data);
void Free_Giftlist(NodeGift *list);
void GiftToFile_list(List_Gift *list);
void Write_Gift();
gift *Input_Gift_Data();
void GiftFromFile(List_Gift *list);

void Main_Menu();

#endif
