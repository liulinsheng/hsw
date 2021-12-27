#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



typedef struct Problem
{
	char title[1000] ;
	char a[1000] ;
	char b[1000] ;
	char c[1000] ;
	char d[1000] ;
	char answer;
	int fraction;

} Pro;



void design() //出题系统
{
	int i = 0;
	char flat = 'y';
	int max;
	printf("请决定出题上限\n");
	scanf("%d",&max);
	Pro problem[max];
	while (flat == 'y') {

		printf("请输入题目：\n") ;
		scanf("%s", problem[i].title);

		printf("请输入A选项：\n");
		scanf("%s", problem[i].a);

		printf("请输入B选项：\n");
		scanf("%s", problem[i].b);

		printf("请输入C选项：\n");
		scanf("%s", problem[i].c);

		printf("请输入D选项：\n");
		scanf("%s", problem[i].d);

		getchar();
		printf("请输入正确选项：\n");
		scanf("%c", &problem[i].answer);
		printf("请输入分数：\n");
		scanf("%d", &problem[i].fraction);
		printf("是否继续y or n\n");
		getchar();
		scanf("%c", &flat);
		i++;

	}
	
	problem[i].fraction = -1;
	i = 0;
	/*
	while(problem[i].fraction != -1);
	{
		printf("%s\n",problem[i].title);
		i++;
	}
	*/
	
	FILE *fp;
	fp = fopen("problem.txt","a");
	if (fp != NULL)
	{
		while (problem[i].fraction >= 0) {

			fprintf(fp, "%-64s", problem[i].title);
			fprintf(fp, "%-64s", problem[i].a);
			fprintf(fp, "%-64s", problem[i].b);
			fprintf(fp, "%-64s", problem[i].c);
			fprintf(fp, "%-64s", problem[i].d);
			fprintf(fp, "%-64c", problem[i].answer);
			fprintf(fp, "%-64d\n",problem[i].fraction);
			i++;
		}
		fclose(fp);
	}else{
		printf("文件保存失败 ！\n");
	}
	
	return;


}

void check()
{
	int i = 0;
	FILE *fp;
	Pro problem[1000];
	fp = fopen("problem.txt", "r");

	if (fp != NULL)
	{
		while(!feof(fp)){

			fscanf(fp,"%s",problem[i].title);
			fscanf(fp,"%s",problem[i].a);
			fscanf(fp,"%s",problem[i].b);
			fscanf(fp,"%s",problem[i].c);
			fscanf(fp,"%s",problem[i].d);
			fscanf(fp,"%s",problem[i].answer);
			fscanf(fp,"%d",&problem[i].fraction);
			i++;

		}
		fclose(fp);
		problem[i].fraction = -1;

	}else{
		printf("文件打开失败 ！\n");
	}
	i = 0;
	while(problem[i].fraction != 0)
	{
		printf("%s\n", problem[i] .title) ;
		printf("  A:%s\n", problem[i] .a) ;
		printf("  B:%s\n", problem[i] .b) ;
		printf("  C:%s\n", problem[i] .c) ;
		printf("  D:%s\n", problem[i] .d) ;
		printf("正确答案为：%c\n", problem[i] .answer) ;
	}

	return;
}












int main(int argc, char **argv)
{
	//design();
	check();	
	return 0;
}

/*


void exam() //考试模块
{
	int book[1000]  = {0} ;
	int i, t, num;
	char key;
	printf("\n  *本系统题库共有 %d 道题目\n\n", a) ;
	printf("  *请输入您要测试的题数 ：") ;
	scanf("%d", &t) ;
	getchar() ;
	printf("\n  *您准备好了吗？考试即将开始！祝您有个好成绩  \n\n") ;
	grade[b] .id = user.ID;
	strcpy(grade[b] .name, user.name) ;
	printf("\n  ***ps.请注意，所有答案均需要填大写。否则，系统将认为您的答案错误！\n***") ;
	for (i = 0; i < t; i++)
	{
		srand(time(NULL) ) ; //设置随机种子
		num = rand()  % a;//随机生成数字
		if (book[num]  == 1)
		{
			i--;
			continue;
		}
		book[num]  = 1;
		printf("\nNo.%d\n", i + 1) ;
		printf("Title:\n") ;
		printf("%s\n", problem[num] .title) ;
		printf("  A:%s\n", problem[num] .a) ;
		printf("  B:%s\n", problem[num] .b) ;
		printf("  C:%s\n", problem[num] .c) ;
		printf("  D:%s\n", problem[num] .d) ;
		printf("请输入您的答案：") ;
		key = getchar() ;
		getchar() ;
		if (key == problem[num] .answer)
		{
			grade[b] .t++;
			printf("回答正确！！！\n\n") ;
		}
		else
		{
			grade[b] .f++;
			printf("回答错误... :( \n") ;
			printf("正确答案是 %c\n\n", problem[num] .answer) ;
		}
	}
	grade[b] .gra = (float) grade[b] .t / t * 100;
	printf("      ***本次考试结束... 您的正确率为 %.2f%% ！***\n\n", grade[b] .gra) ;
	b++;
}


*/

