#include"money.h"
int main() {//主函数
		int choice;
		int running = 1;
		struct User user;
		struct UseLinkNode* useHead;
		struct RecLinkNode* recHead;
		struct AssLinkNode* assHead;
		useHead = (struct UseLinkNode*)malloc(sizeof(struct UseLinkNode));
		useHead->next = NULL;
		recHead = (struct RecLinkNode*)malloc(sizeof(struct RecLinkNode));
		recHead->next = NULL;
		assHead = (struct AssLinkNode*)malloc(sizeof(struct AssLinkNode));
		assHead->next = NULL;
		readUserInfo(useHead);
		readRecordInfo(recHead);
		readAssetsInfo(assHead);
		user = userLoginRegister(useHead, &choice);
		if (choice == 1) {
				system("cls");
				while (running) {
						printf("==============================================\n");
						printf("=                家庭记账系统                =\n");
						printf("=--------------------------------------------=\n");
						printf("=                                            =\n");
						printf("=               1.添加收支信息               =\n");
						printf("=               2.修改收支信息               =\n");
						printf("=               3.删除收支信息               =\n");
						printf("=               4.查询收支信息               =\n");
						printf("=               5.排序收支信息               =\n");
						printf("=               6.统计收支信息               =\n");
						printf("=               0.退出系统                   =\n");
						printf("=                                            =\n");
						printf("==============================================\n");
						printf("请输入您需要执行的功能编号:");
						scanf("%d", &choice);
						switch (choice) {
								case 0:
										running = 0;
										break;
								case 1:
										addRecordInfo(recHead);
										saveRecordInfo(recHead);
										statisAssetsInfo(recHead, assHead);
										saveAssetsInfo(assHead);
										break;
								case 2:
										modifyRecordInfo(recHead);
										saveRecordInfo(recHead);
										statisAssetsInfo(recHead, assHead);
										saveAssetsInfo(assHead);
										break;
								case 3:
										deleteRecordInfo(recHead);
										saveRecordInfo(recHead);
										statisAssetsInfo(recHead, assHead);
										saveAssetsInfo(assHead);
										break;
								case 4:
										queryRecordInfo(recHead, assHead);
										break;
								case 5:
										sortRecordInfo(recHead);
										break;
								case 6:
										statisRecordInfo(recHead, assHead);
										break;
								default:
										printf("您输入的功能编号不存在,请重新输入!\n\n");
										break;
						}
						if (running) {
								system("pause");
								system("cls");
						}
				}
		}
		printf("感谢您的使用,再见!~\n");
		return 0;
}

