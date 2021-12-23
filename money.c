#include"money.h"
int creat_table(sqlite3 *db)
  {
  char *sql;
  char *errmsg;

  sql = "create table if not exists contact (id integer primary key,name text,sex text,number text,address text);";

  if(SQLITE_OK != sqlite3_exec(db,sql,NULL,NULL,&errmsg))//判断是否成功成功返回SQLITE_OK
  {
 // printf("fail:%s\n");
  printf("\n");
  exit(-1);
  }
  }
  int insert_table(sqlite3 *db)//第三步向表中插入数据
  {
  char sql[100];
  char *errmsg;

  int id;
  int i;
  int n;
  int flag = 1;
  char ch;
  char name[N];
  char password1[N];
  while(flag)
  {
  printf("input the number of contact you want to add!\n");//现插入几个数据
  scanf("%d",&n);
  getchar();

  for(i = 0; i < n; i++){

  printf("input name:\n");
  scanf("%s",name);
  getchar();

  printf("input password:\n");
  scanf("%s",password1);
  getchar();

  sprintf(sql,"insert into contact (name,password) values ('%s','%s');",name,password1);

  if(SQLITE_OK != sqlite3_exec(db,sql,NULL,NULL,&errmsg))//判断是否插入成功成功返回SQLITE_OK
  {
  printf("fail:%s\n",errmsg);
  printf("\n");
  exit(-1);
  }
  }

  printf("continue insert[Y/N]?\n");//判断是否继续插入
  scanf("%c",&ch);
  getchar();

  if((ch == 'y') || (ch == 'Y'))
  {
  flag = 1;
  }
  else
  {
  flag = 0;
  }
  }
  }
  int display(sqlite3 *db)//查看整个表的数据
  {
  char *sql;
  char *errmsg;
  char **aresult;

int i;
int nrow;
int ncol;

sql = "select * from contact;";

if(SQLITE_OK != sqlite3_get_table(db,sql,&aresult,&nrow,&ncol,&errmsg))//判断sqlite3_get_table是否运用成功，成功返回SQLITE_OK
{
		printf("fail:%s\n",errmsg);
		printf("\n");
		exit(-1);
}

for(i = 0; i < (nrow + 1) * ncol; i++)//将表中的数据打印出来
{
		printf("%-12s",aresult[i]);

		if((i + 1) % ncol == 0)
		{
				printf("\n");
		}
}

sqlite3_free_table(aresult);//释放aresult

}
/*void create_regtable()
{    
		int rc;       //rc为返回值,判断函数是否执行成功  rc=0函数执行成功，rc !=0函数执行失败
		sqlite3 *db;  //SQLite数据库指针 数据库结构体指针sqlite3为结构体
		char *pFileName = "users.db";  //数据库文件名
		char *zErr;


		rc = sqlite3_open(pFileName, &db); //打开数据库
		if(rc)                             //假，关闭数据库
		{
				cleardevice();
				setmode();
				outtextxy(170,200,"打开数据库失败！");
				Sleep(1000);
				main();
				sqlite3_close(db);
		}

		char *pSQL="create table users(id int , pwd int ,primary key(id,pwd))";

		rc = sqlite3_exec(db, pSQL, 0,0, &zErr);   //sqlite执行接口实现表的创建

		if(rc!=SQLITE_OK)
		{
				if (zErr!=NULL)
				{

						cleardevice();
						setmode();
						outtextxy(170,200,"SQL错误！");
						Sleep(1000);
						main();
						sqlite3_free(zErr);  //释放错误信息所占用的空间
				}
		}
		sqlite3_close(db);

}
*/



/*void reg_Insert() 
{	
		users a;
		int rc;
		char No_id[10]={0,0,0,0,0,0,0,0,0,0};  
		char code[6]={"12345"};
		char incode[6];
		sqlite3 *db;  //SQLite数据库指针
		char *pSQL;
		char * zErr;   // 定义返回错误信息的变量

		char *pFileName = "users.db";  //数据库文件名  
		rc = sqlite3_open(pFileName, &db); //打开数据库

		if(rc)                             //假，关闭数据库
		{ 
				cleardevice();
				setmode();
				outtextxy(170,200,"打开数据库失败！");
				voice_name_error();
				main();
				sqlite3_close(db);
		}

		InputBox(incode,6,"验证注册编号，非家庭成员不允许注册");

		if(strcmp(incode,code)==0)
		{

				InputBox(a.id,10,"请输入账号");

				outtextxy(295,270,a.id);

				if(strcmp(a.id,No_id)==0)
				{
						cleardevice();
						setmode();
						outtextxy(170,200,"用户名不能为空，请重新注册！");
						voice_name_error();
						main();
				}
				else {


						InputBox(a.pwd,10,"请输入密码");

						outtextxy(293,339,"********");

						Sleep(1000);

						pSQL=sqlite3_mprintf("insert into users values('%s','%s')",a.id,a.pwd); 


						rc = sqlite3_exec(db,pSQL,0,0,&zErr); 

						if(rc) //rc=1
						{
								cleardevice();
								setmode();
								outtextxy(220, 200, "帐号注册失败!");
								voice_register_ok();

								main();
								sqlite3_close(db);
						}
						else
						{
								outtextxy(220, 200, rc);
								cleardevice();
								setmode();
								outtextxy(220, 200, "帐号注册成功!");
								voice_register_ok();

								main();
								sqlite3_close(db);
						}
				}

		} else{ cleardevice();main();}

}*/
/*void Login()
{   
		users a;
		int rc;    
		sqlite3 *db;  //SQLite数据库指针   sqlite3结构体  *db指向sqlite3结构体的指针
		const    char *pFileName = "users.db";   
		char * zErr;   
		rc = sqlite3_open(pFileName, &db);
		if(rc)                             
		{
				cleardevice(); 
				setmode();
				settextstyle(30, 0, "楷体"); 
				settextcolor(RGB(0,500,0)); 
				outtextxy(220, 200, "打开数据库失败!");
				voice_No_name();
				main();
				sqlite3_close(db);
		}
		InputBox(a.id,10,"请输入账号");
		outtextxy(295,270,a.id); 
		InputBox(a.pwd,10,"请输入密码");  
		outtextxy(293,339,"********");  
		Sleep(1500); 
		char *pSQL=sqlite3_mprintf("insert into users(id,pwd)values('%s','%s')",a.id,a.pwd);
		rc = sqlite3_exec(db, pSQL, NULL, NULL, &zErr);
		if (!rc)  
		{  //删除多余的数据
				char *pSQL=sqlite3_mprintf("delete from users where id = '%s' and pwd = '%s' ",a.id,a.pwd); 
				rc = sqlite3_exec(db, pSQL, NULL, NULL, &zErr);
				cleardevice(); 
				setmode();
				settextstyle(30, 0, "楷体");
				settextcolor(RGB(255,0,0)); 
				outtextxy(250, 200, "登录失败!");
				Sleep(1000);
				cleardevice();       
				main();      
		}
		else     ///rc=0 ok
		{
				cleardevice(); 
				setmode();
				settextstyle(30, 0, "楷体");
				settextcolor(RGB(0,500,0)); 
				outtextxy(250, 200, "登录成功,欢迎使用!");
				voice_succeed();
				cleardevice();       
				option_Menu();      
		}
		sqlite3_close(db);
}*/
void saveUserInfo(struct UseLinkNode* useHead) {//保存用户信息
		FILE* fp;
		struct UseLinkNode* pUse;
		fp = fopen("User.txt", "w");
		if (fp == NULL) {
				return;
		}
		if (useHead->next == NULL) {
				fprintf(fp, "");
		}
		else {
				pUse = useHead;
				while (pUse->next != NULL) {
						pUse = pUse->next;
						fprintf(fp, "%s %s\n", pUse->data.username, pUse->data.password);
				}
		}
		fclose(fp);
}
void readUserInfo(struct UseLinkNode* useHead) {//读取用户信息
		FILE* fp;
		struct User temp;
		struct UseLinkNode* pUse, * qUse;
		fp = fopen("User.txt", "r");
		if (fp == NULL) {
				return;
		}
		pUse = useHead;
		while (fscanf(fp, "%s %s\n", temp.username, temp.password) != EOF) {
				qUse = (struct UseLinkNode*)malloc(sizeof(struct UseLinkNode));
				qUse->data = temp;
				qUse->next = NULL;
				pUse->next = qUse;
				pUse = pUse->next;
		}
		fclose(fp);
}
void saveRecordInfo(struct RecLinkNode* recHead) {//保存收支信息
		FILE* fp;
		struct RecLinkNode* pRec;
		fp = fopen("Record.txt", "w");
		if (fp == NULL) {
				return;
		}
		if (recHead->next == NULL) {
				fprintf(fp, "");
		}
		else {
				pRec = recHead;
				while (pRec->next != NULL) {
						pRec = pRec->next;
						fprintf(fp, "%s %s %f %s %s %s\n", pRec->data.id, pRec->data.member, pRec->data.money, pRec->data.type, pRec->data.date, pRec->data.remark);
				}
		}
		fclose(fp);
}
void readRecordInfo(struct RecLinkNode* recHead) {//读取收支信息
		FILE* fp;
		struct Record temp;
		struct RecLinkNode* pRec, * qRec;
		fp = fopen("Record.txt", "r");
		if (fp == NULL) {
				return;
		}
		pRec = recHead;
		while (fscanf(fp, "%s %s %f %s %s %s\n", temp.id, temp.member, &temp.money, temp.type, temp.date, temp.remark) != EOF) {
				qRec = (struct RecLinkNode*)malloc(sizeof(struct RecLinkNode));
				qRec->data = temp;
				qRec->next = NULL;
				pRec->next = qRec;
				pRec = pRec->next;
		}
		fclose(fp);
}
void saveAssetsInfo(struct AssLinkNode* assHead) {//保存资产信息
		FILE* fp;
		struct AssLinkNode* pAss;
		fp = fopen("Assets.txt", "w");
		if (fp == NULL) {
				return;
		}
		if (assHead->next == NULL) {
				fprintf(fp, "");
		}
		else {
				pAss = assHead;
				while (pAss->next != NULL) {
						pAss = pAss->next;
						fprintf(fp, "%d %s %f\n", pAss->data.id, pAss->data.member, pAss->data.money);
				}
		}
		fclose(fp);
}
void readAssetsInfo(struct AssLinkNode* assHead) {//读取资产信息
		FILE* fp;
		struct Assets temp;
		struct AssLinkNode* pAss, * qAss;
		fp = fopen("Assets.txt", "r");
		if (fp == NULL) {
				return;
		}
		pAss = assHead;
		while (fscanf(fp, "%d %s %f\n", &temp.id, temp.member, &temp.money) != EOF) {
				qAss = (struct AssLinkNode*)malloc(sizeof(struct AssLinkNode));
				qAss->data = temp;
				qAss->next = NULL;
				pAss->next = qAss;
				pAss = pAss->next;
		}
		fclose(fp);
}
void addRecordInfo(struct RecLinkNode* recHead) {//添加收支信息
		struct RecLinkNode* pRec, * qRec;
		struct Record input;
		int isExisted = 0;
		printf("请输入编号:");
		scanf("%s", input.id);
		pRec = recHead;
		while (pRec->next != NULL) {
				pRec = pRec->next;
				if (strcmp(pRec->data.id, input.id) == 0) {
						isExisted = 1;
						break;
				}
		}
		if (isExisted == 0) {
				printf("请输入家庭成员:");
				scanf("%s", input.member);
				printf("请输入金额:");
				scanf("%f", &input.money);
				printf("请输入类型:");
				scanf("%s", input.type);
				printf("请输入日期(yyyy-MM-dd):");
				scanf("%s", input.date);
				while (strlen(input.date) != 10 || input.date[4] != '-' || input.date[7] != '-') {
						printf("请重新输入日期(yyyy-MM-dd):");
						scanf("%s", input.date);
				}
				printf("请输入备注:");
				scanf("%s", input.remark);
				qRec = (struct RecLinkNode*)malloc(sizeof(struct RecLinkNode));
				qRec->data = input;
				qRec->next = NULL;
				pRec->next = qRec;
				printf("添加收支信息成功!\n\n");
		}
		else {
				printf("添加收支信息失败,输入的编号已存在!\n\n");
		}
}
void modifyRecordInfo(struct RecLinkNode* recHead) {//修改收支信息
		struct RecLinkNode* pRec;
		struct Record input;
		int isExisted = 0;
		if (recHead->next == NULL) {
				printf("当前收支信息为空,无法继续修改!\n\n");
				return;
		}
		printf("请输入需要修改的编号:");
		scanf("%s", input.id);
		pRec = recHead;
		while (pRec->next != NULL) {
				pRec = pRec->next;
				if (strcmp(pRec->data.id, input.id) == 0) {
						isExisted = 1;
						break;
				}
		}
		if (isExisted == 1) {
				printf("请输入家庭成员:");
				scanf("%s", input.member);
				printf("请输入金额:");
				scanf("%f", &input.money);
				printf("请输入类型:");
				scanf("%s", input.type);
				printf("请输入日期(yyyy-MM-dd):");
				scanf("%s", input.date);
				while (strlen(input.date) != 10 || input.date[4] != '-' || input.date[7] != '-') {
						printf("请重新输入日期(yyyy-MM-dd):");
						scanf("%s", input.date);
				}
				printf("请输入备注:");
				scanf("%s", input.remark);
				pRec->data = input;
				printf("修改收支信息成功!\n\n");
		}
		else {
				printf("修改收支信息失败,输入的编号不存在!\n\n");
		}
}
void deleteRecordInfo(struct RecLinkNode* recHead) {//删除收支信息
		struct RecLinkNode* pRec, * qRec;
		struct Record input;
		int isExisted = 0;
		if (recHead->next == NULL) {
				printf("当前收支信息为空,无法继续删除!\n\n");
				return;
		}
		printf("请输入需要删除的编号:");
		scanf("%s", input.id);
		pRec = recHead;
		while (pRec->next != NULL) {
				if (strcmp(pRec->next->data.id, input.id) == 0) {
						isExisted = 1;
						break;
				}
				pRec = pRec->next;
		}
		if (isExisted == 1) {
				qRec = pRec->next;
				pRec->next = qRec->next;
				free(qRec);
				printf("删除收支信息成功!\n\n");
		}
		else {
				printf("删除收支信息失败,输入的编号不存在!\n\n");
		}
}
void queryRecordInfo(struct RecLinkNode* recHead, struct AssLinkNode* assHead) {//查询收支信息
		int qobj, flag = 0;
		struct RecLinkNode* pRec;
		struct AssLinkNode* pAss;
		struct Record input;
		if (recHead->next == NULL) {
				printf("当前收支信息为空,无法继续查询!\n\n");
				return;
		}
		printf("请输入需要查询的对象编号(0.全部 1.编号 2.家庭成员 3.月份 4.类型 5.资产信息):");
		scanf("%d", &qobj);
		if (qobj == 0 || qobj == 5) {
		}
		else if (qobj == 1) {
				printf("请输入查询的编号:");
				scanf("%s", input.id);
		}
		else if (qobj == 2) {
				printf("请输入查询的家庭成员:");
				scanf("%s", input.member);
		}
		else if (qobj == 3) {
				printf("请输入查询的月份(yyyy-MM):");
				scanf("%s", input.date);
		}
		else if (qobj == 4) {
				printf("请输入查询的类型:");
				scanf("%s", input.type);
		}
		else {
				printf("查询收支信息失败,输入的对象编号不存在!\n\n");
				return;
		}
		if (qobj != 5) {
				pRec = recHead;
				while (pRec->next != NULL) {
						pRec = pRec->next;
						if ((qobj == 0) || (qobj == 1 && strcmp(pRec->data.id, input.id) == 0) || (qobj == 2 && strcmp(pRec->data.member, input.member) == 0) || (qobj == 3 && strstr(pRec->data.date, input.date) != NULL) || (qobj == 4 && strcmp(pRec->data.type, input.type) == 0)) {
								if (flag == 0) {
										printf("+------------+------------+------------+------------+------------+------------+\n");
										printf("|%-12s|%-12s|%-12s|%-12s|%-12s|%-12s|\n", "编号", "家庭成员", "金额", "类型", "日期", "备注");
										printf("+------------+------------+------------+------------+------------+------------+\n");
										flag = 1;
								}
								printf("|%-12s|%-12s|%-12.2f|%-12s|%-12s|%-12s|\n", pRec->data.id, pRec->data.member, pRec->data.money, pRec->data.type, pRec->data.date, pRec->data.remark);
								printf("+------------+------------+------------+------------+------------+------------+\n");
						}
				}
		}
		else {
				printf("+------------+------------+------------+\n");
				printf("|%-12s|%-12s|%-12s|\n", "编号", "家庭成员", "总资产");
				printf("+------------+------------+------------+\n");
				pAss = assHead;
				while (pAss->next != NULL) {
						pAss = pAss->next;
						printf("|%-12d|%-12s|%-12.2f|\n", pAss->data.id, pAss->data.member, pAss->data.money);
						printf("+------------+------------+------------+\n");
				}
		}
		if (flag == 0) {
				printf("查询无结果!\n");
		}
		printf("\n");
}
void sortRecordInfo(struct RecLinkNode* recHead) {//排序收支信息
		int sobj, stype;
		struct RecLinkNode* pRec, * qRec, * pTemp = NULL;
		if (recHead->next == NULL) {
				printf("当前收支信息为空,无法继续排序!\n\n");
				return;
		}
		printf("请输入需要排序的方式编号(1.按金额升序排序 2.按金额降序排序):");
		scanf("%d", &stype);
		if (stype < 1 || stype>2) {
				printf("排序收支信息失败,输入的编号不存在!\n\n");
				return;
		}
		while (recHead->next->next != pTemp) {
				pRec = recHead;
				qRec = recHead->next;
				while (qRec->next != pTemp) {
						if ((stype == 1 && qRec->data.money > qRec->next->data.money) || (stype == 2 && qRec->data.money < qRec->next->data.money)) {
								pRec->next = qRec->next;
								qRec->next = qRec->next->next;
								pRec->next->next = qRec;
								qRec = pRec->next;
						}
						qRec = qRec->next;
						pRec = pRec->next;
				}
				pTemp = qRec;
		}
		printf("+------------+------------+------------+------------+------------+------------+\n");
		printf("|%-12s|%-12s|%-12s|%-12s|%-12s|%-12s|\n", "编号", "家庭成员", "金额", "类型", "日期", "备注");
		printf("+------------+------------+------------+------------+------------+------------+\n");
		pRec = recHead;
		while (pRec->next != NULL) {
				pRec = pRec->next;
				printf("|%-12s|%-12s|%-12.2f|%-12s|%-12s|%-12s|\n", pRec->data.id, pRec->data.member, pRec->data.money, pRec->data.type, pRec->data.date, pRec->data.remark);
				printf("+------------+------------+------------+------------+------------+------------+\n");
		}
		printf("\n");
}
void statisRecordInfo(struct RecLinkNode* recHead, struct AssLinkNode* assHead) {//统计收支信息
		int i, j, flag, sobj, stype, scount = 0;
		float mtemp;
		char metemp[STR];
		struct RecLinkNode* pRec;
		struct Record input;
		struct AssLinkNode* pAss, * qAss, * pTemp = NULL;
		char member1[MAX][STR];
		float money1[MAX];
		int count1 = 0;
		char member2[MAX][STR];
		float money2[MAX];
		int count2 = 0;
		if (recHead->next == NULL) {
				printf("当前收支信息为空,无法继续统计!\n\n");
				return;
		}
		printf("+------------------------------+\n");
		printf("|  1.统计家庭月收支情况        |\n");
		printf("|  2.统计家庭月资产结余情况    |\n");
		printf("|  3.统计家庭年收入最大贡献者  |\n");
		printf("|  4.统计家庭年支出最大类型    |\n");
		printf("|  0.返回主菜单                |\n");
		printf("+------------------------------+\n");
		printf("请输入需要统计的对象编号:");
		scanf("%d", &sobj);
		if (sobj == 0) {
				return;
		}
		else if (sobj == 1 || sobj == 2) {
				printf("请输入统计的月份(yyyy-MM):");
				scanf("%s", input.date);
		}
		else if (sobj == 3 || sobj == 4) {
				printf("请输入统计的年份(yyyy):");
				scanf("%s", input.date);
		}
		else {
				printf("统计收支信息失败,输入的对象编号不存在!\n\n");
				return;
		}
		if (sobj == 1 || sobj == 2) {
				printf("请输入需要排序的方式编号(1.升序排序 2.降序排序):");
				scanf("%d", &stype);
				if (stype < 1 || stype>2) {
						printf("统计收支信息失败,输入的方式编号不存在!\n\n");
						return;
				}
		}
		if (sobj == 1) {//统计家庭月收支情况
				pRec = recHead;
				while (pRec->next != NULL) {
						pRec = pRec->next;
						if (strstr(pRec->data.date, input.date) != NULL) {
								if (pRec->data.money >= 0) {
										for (i = 0; i < count1; i++) {
												if (strcmp(member1[i], pRec->data.member) == 0) {
														break;
												}
										}
										if (i != count1) {
												money1[i] += pRec->data.money;
										}
										else {
												strcpy(member1[count1], pRec->data.member);
												money1[count1] = pRec->data.money;
												count1++;
										}
								}
								else {
										for (i = 0; i < count2; i++) {
												if (strcmp(member2[i], pRec->data.member) == 0) {
														break;
												}
										}
										if (i != count2) {
												money2[i] += pRec->data.money;
										}
										else {
												strcpy(member2[count2], pRec->data.member);
												money2[count2] = pRec->data.money;
												count2++;
										}
								}
						}
				}
				for (i = 0; i < count1 - 1; i++) {
						for (j = 0; j < count1 - i - 1; j++) {
								if ((stype == 1 && money1[j] > money1[j + 1]) || (stype == 2 && money1[j] < money1[j + 1])) {
										mtemp = money1[j];
										money1[j] = money1[j + 1];
										money1[j + 1] = mtemp;
										strcpy(metemp, member1[j]);
										strcpy(member1[j], member1[j + 1]);
										strcpy(member1[j + 1], metemp);
								}
						}
				}
				for (i = 0; i < count2 - 1; i++) {
						for (j = 0; j < count2 - i - 1; j++) {
								if ((stype == 1 && money2[j] > money2[j + 1]) || (stype == 2 && money2[j] < money2[j + 1])) {
										mtemp = money2[j];
										money2[j] = money2[j + 1];
										money2[j + 1] = mtemp;
										strcpy(metemp, member2[j]);
										strcpy(member2[j], member2[j + 1]);
										strcpy(member2[j + 1], metemp);
								}
						}
				}
				printf("+-------------------------+\n");
				printf("|   本月各成员的收入情况  |\n");
				printf("+------------+------------+\n");
				for (i = 0; i < count1; i++) {
						printf("|%-12s|%-12.2f|\n", member1[i], money1[i]);
						printf("+------------+------------+\n");
				}
				printf("\n");
				printf("+-------------------------+\n");
				printf("|   本月各成员的支出情况  |\n");
				printf("+------------+------------+\n");
				for (i = 0; i < count2; i++) {
						printf("|%-12s|%-12.2f|\n", member2[i], money2[i]);
						printf("+------------+------------+\n");
				}
				printf("\n");
		}
		else if (sobj == 2) {//统计家庭月资产结余情况
				pRec = recHead;
				while (pRec->next != NULL) {
						pRec = pRec->next;
						if (strstr(pRec->data.date, input.date) != NULL) {
								for (i = 0; i < count1; i++) {
										if (strcmp(member1[i], pRec->data.member) == 0) {
												break;
										}
								}
								if (i != count1) {
										money1[i] += pRec->data.money;
								}
								else {
										strcpy(member1[count1], pRec->data.member);
										money1[count1] = pRec->data.money;
										count1++;
								}
						}
				}
				for (i = 0; i < count1 - 1; i++) {
						for (j = 0; j < count1 - i - 1; j++) {
								if ((stype == 1 && money1[j] < money1[j + 1]) || (stype == 2 && money1[j] > money1[j + 1])) {
										mtemp = money1[j];
										money1[j] = money1[j + 1];
										money1[j + 1] = mtemp;
										strcpy(metemp, member1[j]);
										strcpy(member1[j], member1[j + 1]);
										strcpy(member1[j + 1], metemp);
								}
						}
				}
				printf("+--------------------------------------+\n");
				printf("|         本月家庭资产结余情况         |\n");
				printf("+------------+------------+------------+\n");
				printf("|%-12s|%-12s|%-12s|\n", "编号", "家庭成员", "总资产");
				printf("+------------+------------+------------+\n");
				for (i = 0; i < count1; i++) {
						printf("|%-12d|%-12s|%-12.2f|\n", i + 1, member1[i], money1[i]);
						printf("+------------+------------+------------+\n");
				}
				printf("\n");
				printf("+--------------------------------------+\n");
				printf("|       本月家庭资产结余为负情况       |\n");
				printf("+------------+------------+------------+\n");
				printf("|%-12s|%-12s|%-12s|\n", "编号", "家庭成员", "总资产");
				printf("+------------+------------+------------+\n");
				flag = 0;
				for (i = 0, j = 0; i < count1; i++) {
						if (money1[i] < 0) {
								printf("|%-12d|%-12s|%-12.2f|\n", ++j, member1[i], money1[i]);
								printf("+------------+------------+------------+\n");
								flag = 1;
						}
				}
				if (flag == 1) {
						printf("请输入需要查看收支明细的指定家庭成员:");
						scanf("%s", input.member);
						flag = 0;
						pRec = recHead;
						while (pRec->next != NULL) {
								pRec = pRec->next;
								if (strcmp(pRec->data.member, input.member) == 0 && strstr(pRec->data.date, input.date) != NULL) {
										if (flag == 0) {
												printf("+------------+------------+------------+------------+------------+------------+\n");
												printf("|                                  收支明细                                   |\n");
												printf("+------------+------------+------------+------------+------------+------------+\n");
												printf("|%-12s|%-12s|%-12s|%-12s|%-12s|%-12s|\n", "编号", "家庭成员", "金额", "类型", "日期", "备注");
												printf("+------------+------------+------------+------------+------------+------------+\n");
												flag = 1;
										}
										printf("|%-12s|%-12s|%-12.2f|%-12s|%-12s|%-12s|\n", pRec->data.id, pRec->data.member, pRec->data.money, pRec->data.type, pRec->data.date, pRec->data.remark);
										printf("+------------+------------+------------+------------+------------+------------+\n");
								}
						}
						printf("\n");
				}
				else {
						printf("当前暂无家庭资产结余为负情况!\n\n");
				}
		}
		else if (sobj == 3) {//统计家庭年收入最大贡献者
				pRec = recHead;
				while (pRec->next != NULL) {
						pRec = pRec->next;
						if (strstr(pRec->data.date, input.date) != NULL) {
								if (pRec->data.money >= 0) {
										for (i = 0; i < count1; i++) {
												if (strcmp(member1[i], pRec->data.member) == 0) {
														break;
												}
										}
										if (i != count1) {
												money1[i] += pRec->data.money;
										}
										else {
												strcpy(member1[count1], pRec->data.member);
												money1[count1] = pRec->data.money;
												count1++;
										}
								}
						}
				}
				for (i = 0; i < count1 - 1; i++) {
						for (j = 0; j < count1 - i - 1; j++) {
								if (money1[j] < money1[j + 1]) {
										mtemp = money1[j];
										money1[j] = money1[j + 1];
										money1[j + 1] = mtemp;
										strcpy(metemp, member1[j]);
										strcpy(member1[j], member1[j + 1]);
										strcpy(member1[j + 1], metemp);
								}
						}
				}
				printf("+-------------------------+\n");
				printf("|    本年收入最大贡献者   |\n");
				printf("+------------+------------+\n");
				printf("|%-12s|%-12.2f|\n", member1[0], money1[0]);
				printf("+------------+------------+\n");
				printf("\n");
		}
		else if (sobj == 4) {//统计家庭年支出最大类型
				pRec = recHead;
				while (pRec->next != NULL) {
						pRec = pRec->next;
						if (strstr(pRec->data.date, input.date) != NULL) {
								if (pRec->data.money < 0) {
										for (i = 0; i < count2; i++) {
												if (strcmp(member2[i], pRec->data.type) == 0) {
														break;
												}
										}
										if (i != count2) {
												money2[i] += pRec->data.money;
										}
										else {
												strcpy(member2[count2], pRec->data.type);
												money2[count2] = pRec->data.money;
												count2++;
										}
								}
						}
				}
				for (i = 0; i < count2 - 1; i++) {
						for (j = 0; j < count2 - i - 1; j++) {
								if (money2[j] > money2[j + 1]) {
										mtemp = money2[j];
										money2[j] = money2[j + 1];
										money2[j + 1] = mtemp;
										strcpy(metemp, member2[j]);
										strcpy(member2[j], member2[j + 1]);
										strcpy(member2[j + 1], metemp);
								}
						}
				}
				printf("+-------------------------+\n");
				printf("|     本年支出最大类型    |\n");
				printf("+------------+------------+\n");
				printf("|%-12s|%-12.2f|\n", member2[0], money2[0]);
				printf("+------------+------------+\n");
				printf("\n");
		}
}
void statisAssetsInfo(struct RecLinkNode* recHead, struct AssLinkNode* assHead) {//统计资产信息
		int i;
		struct Assets temp;
		struct RecLinkNode* pRec;
		struct AssLinkNode* pAss, * qAss;
		char member[MAX][STR];
		float money[MAX];
		int count = 0;
		pRec = recHead;
		while (pRec->next != NULL) {
				pRec = pRec->next;
				for (i = 0; i < count; i++) {
						if (strcmp(member[i], pRec->data.member) == 0) {
								break;
						}
				}
				if (i != count) {
						money[i] += pRec->data.money;
				}
				else {
						strcpy(member[count], pRec->data.member);
						money[count] = pRec->data.money;
						count++;
				}
		}
		assHead->next = NULL;
		pAss = assHead;
		for (i = 0; i < count; i++) {
				temp.id = i + 1;
				strcpy(temp.member, member[i]);
				temp.money = money[i];
				qAss = (struct AssLinkNode*)malloc(sizeof(struct AssLinkNode));
				qAss->data = temp;
				qAss->next = NULL;
				pAss->next = qAss;
				pAss = pAss->next;
		}
}
struct User userLoginRegister(struct UseLinkNode* useHead, int* login) {//用户登陆与注册
		int choice;
		int isFlag;
		struct UseLinkNode* pUse, * qUse;
		int running = 1;
		struct User input;
		while (running) {
				printf("==============================================\n");
				printf("=                家庭记账系统                =\n");
				printf("=--------------------------------------------=\n");
				printf("=                                            =\n");
				printf("=                 1.用户登陆                 =\n");
				printf("=                 2.用户注册                 =\n");
				printf("=                 0.退出系统                 =\n");
				printf("=                                            =\n");
				printf("==============================================\n");
				printf("请输入您需要执行的功能编号:");
				scanf("%d", &choice);
				switch (choice) {
						case 0:
								*login = 0;
								running = 0;
								break;
						case 1:
							//	Login();
								printf("请输入您的用户名:");
								scanf("%s", input.username);
								printf("请输入您的密码:");
								scanf("%s", input.password);
								pUse = useHead;
								isFlag = 0;
								while (pUse->next != NULL) {
										pUse = pUse->next;
										if (strcmp(pUse->data.username, input.username) == 0 && strcmp(pUse->data.password, input.password) == 0) {
												isFlag = 1;
												break;
										}
								}
								if (isFlag) {
										input = pUse->data;
										running = 0;
										*login = 1;
								}
								else {
										printf("很抱歉,登陆失败,您输入的用户名或密码不正确!\n\n");
								}
								break;
						case 2:
							//	create_regtable();
							//	reg_Insert();
								printf("请输入您的用户名:");
								scanf("%s", input.username);
								pUse = useHead;
								isFlag = 0;
								while (pUse->next != NULL) {
										pUse = pUse->next;
										if (strcmp(pUse->data.username, input.username) == 0) {
												isFlag = 1;
												break;
										}
								}
								if (!isFlag) {
										printf("请输入您的密码:");
										scanf("%s", input.password);
										qUse = (struct UseLinkNode*)malloc(sizeof(struct UseLinkNode));
										qUse->data = input;
										qUse->next = NULL;
										pUse->next = qUse;
										saveUserInfo(useHead);
										printf("恭喜您,注册成功,欢迎使用家庭记账系统!\n\n");
										//save(useHead);
								}
								else {
										printf("很抱歉,注册失败,您输入的用户名已存在!\n\n");
								}
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
		return input;
}

/*void save(Link *useHead)
{
	sqlite3 *db;
	char *sql;
	char sql1[100];
	char *errmsg;

	int ret;

	Link p;
	FILE *fp;
	p=(*useHead)->next;

	ret = sqlite3_open("user1.db",&db);

	if(ret!=SQLITE_OK)
	{
		printf("open database error:%s\n",sqlite3_errmsg(db));
		exit(-1);
	}

	sql = "create table if not exists user1table(username text,password integer);";
	ret=sqlite3_exec(db,sql,NULL,NULL,&errmsg);
	if(ret!=SQLITE_OK)
	{
		printf("create table fail:%s\n",errmsg);
		exit(-1);
	}

	while(p!=NULL)
	{
		sprintf(sql1,"insert into user1table (username,password) values ('%s',%d);",p->username,p->password);
		ret=sqlite3_exec(db,sql1,NULL,NULL,&errmsg);
		if(ret!=SQLITE_OK)
		{
			printf("insert error\n");
			exit(1);
		}
		p=p->next;
	}
	printf("保存成功!\n");

	sqlite3_close(db);
}*/
