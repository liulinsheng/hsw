#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct course
{
	int num;
	char name[20];
	char kind[20];
	int ttime,mark,term;
}c;
struct student 
{
	int snum;
	intum;
	charam[20];
	char snam[20];
}s[500];
int count;//全局变量
int main()//主函数
{
	int n;
	int menu();
	int f1();
	int luru();
	int liulan();
	int chaxun();
	int xuanke();
	int tongji();
	printf("\n            **********************        ***********************");
	printf("\n\n             **********     欢迎进入学生选课系统！    **********");
	menu();
	printf("\n");
	printf("            *******************  the   end  *********************\n");
	printf("\n            **********************        ***********************");
	printf("\n\n               请 先 选 择 1 进 行 课 程 信 息 录 入:");
	scanf("%d",&n);//防止错误,请重新输入
	for(;n>5||n<0;)
	{
		printf("\n                       输 入 错 误 ！请 重 新 输 入 ！\n              ");
			scanf("%d",&n);
	}
	while(n>0&&n<6)
	{
		switch(n)
		{
		case 1:luru();break;//录入课程信息
		case 2:liulan();break;//浏览课程信息
		case 3:chaxun();break;//查询课程信息
		case 4:xuanke();break;//进入选课操作
		case 5:tongji();break;//统计选课情况
		}
		scanf("%d",&n);//选择所需操作
		for(;n>5||n<0;)
		{
			printf("\n\n");
			printf("\n                    输 入 错 误 ！ 请 重 新 输 入 ！\n              ");
			scanf("%d",&n);//防止错误，提示重新输入
		}
		system("cls");//清屏
	}  
	if(n==0)
	{
		printf("                     \n\n\n\n\n\n\n");
		printf("                  **********     谢谢使用！     **********\n      ");
	   	printf("\n\n\n\n\n");
	}
	exit(0);//退出选课系统
	return 0; 
}
int menu()//菜单函数
{
	int n;
	printf("\n\n\n\n");
	printf("                           1.  录 入 课 程 信 息\n\n");
    printf("                           2.  浏 览 课 程 信 息\n\n");
    printf("                           3.  查 询 课 程 信 息\n\n");
    printf("                           4.  进 入 选 课 操 作\n\n");
	printf("                           5.  统 计 选 课 情 况\n\n");
	printf("                           0.  退 出 选 课 系 统\n\n");
    return 0;
}
int f1()
{
	printf("\n  课程编号   课程名称   课程性质   总学时   学分   开课学期:\n");
	return 0;
}
int luru()//录入函数
{
	FILE *fp;//定义指向文件的指针
	struct course c;
	
	int i;
	if((fp=fopen("D://course.txt","w"))==NULL)//建立文件"course.txt"
	{
		printf("cannot open file\n");
		exit(0);
	}
	printf("\n                   请 输 入 选 择 的 课 程 门 数:");
	scanf("%d",&count);
	printf("\n\n");
	f1();
	for(i=0;i<count;i++)
	{
		scanf("%d%s%s%d%d%d",&c.num,c.name,c.kind,&c.ttime,&c.mark,&c.term);
		fprintf(fp,"%d\t%s\t%s\t%d\t%d\t%d\t",c.num,c.name,c.kind,c.ttime,c.mark,c.term);
	}
	fclose(fp);//关闭文件
	printf("\n                       ********* 录入成功！*********\n");
	menu();
	return 0;
}
int liulan()//浏览函数
{
	int i=0;
	FILE *fp;//定义指向文件的指针
	struct course c;//定义课程结构体变量
	if((fp=fopen("D://course.txt","r"))==NULL)//打开文件"course.txt"
	{
		printf("\ncannot open course!\n");
		exit(0);
	}
	f1();
	while(!feof(fp)&&i<count)
	{	fscanf(fp,"%d%s%s%d%d%d",&c.num,c.name,c.kind,&c.ttime,&c.mark,&c.term);
		printf("%7d%11s%10s%9d%9d%8d\n",c.num,c.name,c.kind,c.ttime,c.mark,c.term);
		i++;
	}
	fclose(fp);//关闭文件
	menu();
	return 0;
}
int chaxun()//查询函数
{
	FILE *fp;//定义指向文件的指针
	struct course c;//定义课程结构体变量
	int score;
	int b,i=0;
	char kind[20];
	printf("\n     1.按 学 分 查 询\n");
	printf("\n     2.按 课 程 性 质 查 询");
	printf("   请 选 择 查 询 方 式 \n\n      输 入 选 项 数 字:");
	scanf("%d",&b);//防止错误，提示重新输入
	for(;b<1||b>2;)
	{
		printf("\n                       输 入 错 误 ！请 重 新 输 入 ！\n      ");
		scanf("%d",&b);
	}//按学分查询
	if(b==1)
	{
		printf("\n      输 入 你 要 查 询 的 学 分: ");
		scanf("%d",&score);
		if((fp=fopen("D://course.txt","r"))==NULL)
		{
			printf("\ncannot open course!\n");
			exit(0);
		}
		f1();
		while(!feof(fp)&&i<count)//当没有指向文件尾部，读取文件“course.txt”中的数据
		{
			fscanf(fp,"%d%s%s%d%d%d",&c.num,c.name,c.kind,&c.ttime,&c.mark,&c.term);
			if(c.mark==score)//比较输入的分数和结构体中的分数，如果相同，输出那组数据
				printf("%7d%11s%10s%9d%9d%8d\n",c.num,c.name,c.kind,c.ttime,c.mark,c.term);
			i++;
		}
	}
	else if(b==2)//按课程性质查询
	{
		printf("\n\n      输 入 你 要 查 询 的 课 程 性 质:");
		scanf("%s",kind);
		if((fp=fopen("D://course.txt","r"))==NULL)//打开文件"course.txt"
		{
			printf("\ncannot open course!\n");
		}
		f1();
		while(!feof(fp)&&i<count)//当没有到达文件尾部，读取“course.txt”中的数据
		{
			fscanf(fp,"%d%s%s%d%d%d",&c.num,c.name,c.kind,&c.ttime,&c.mark,&c.term);
			if(strcmp(c.kind,kind)==0)//比较输入的字符串与原文件中的课程性质，如果相同，输出那组数据
				printf("%7d%11s%10s%9d%9d%8d\n",c.num,c.name,c.kind,c.ttime,c.mark,c.term);
			i++;
		}
	}
	else
	{
		printf("输入错误！");//选择错误，就退出
		exit(1);
	}
	fclose(fp);
	menu();
	return 0;
}
int xuanke()//选课函数
{
	
	int t=0,flag;
	int i;
	/*struct course c;//定义课程结构体变量*/
	FILE *fp;//定义指向文件的指针
	do
	{
	printf("\n  请 输 入 学 号   姓 名   课 程 编 号 及 课 程 名 称 :");
    scanf("%d%s%d%s",&s[t].snum,s[t].snam,&s[t].cnum,s[t].cnam);
	if((fp=fopen("D://course.txt","r"))==NULL)//打开文件"course.txt"
	{
		printf("\ncannot open course!\n");
		exit(0);
	}
	while(!feof(fp))//如果课程编号和课程名称与学生所选一致，就跳出，执行下一步	
	{
		fscanf(fp,"%d%s%s%d%d%d",&c.num,c.name,c.kind,&c.ttime,&c.mark,&c.term);
	    if((s[t].cnum==c.num)&&(s[t].cnam==c.name))	
			t++;
			break;
	}	fclose(fp);
	printf("\n  是 否 继 续 ，是 1，否 0 \n  ");
		scanf("%d",&flag);
		if((fp=fopen("D://student.txt","a+"))==NULL)//建立文件“student.txt”
		{
		printf("\ncannot open student!\n");
		exit(0);
		} //建立，并将学生选课信息输入"student.txt"
		for(i=0;i<t;i++);
		fprintf(fp,"%d\t%s\t%d\t%s\t\n",s[t].snum,s[t].snam,s[t].cnum,s[t].cnam);
	    fclose(fp);//关闭选课文件"course.txt"
	}while(flag);
	printf("\n                     *********  恭喜选课成功！*********\n");
	menu();
	return 0;
}
int  tongji()//统计函数
{
	int total=0;
	int t,i=0;
	FILE *fp;
	if((fp=fopen("D://student.txt","r"))==NULL)//打开文件“student.txt”
	{
		printf("\ncannot open student!\n");
		exit(0);
	}
	printf("\n   学号  课程编号及课程名称\n");
	while(!feof(fp))//计数
	{
		fscanf(fp,"%d%s%d%s\n",&s[i].snum,s[i].snam,&s[i].cnum,s[i].cnam);//读取文件“student.txt”
		total++;
		i++;
	}
	t=i;
	for(i=0;i<t;i++)
		printf("%5d%6s%7d%10s\n",s[i].snum,s[i].snam,s[i].cnum,s[i].cnam);
	printf("\n    选课学生总人数为:%d人",total);
	fclose(fp);//关闭文件
	menu();
	return 0;
}
