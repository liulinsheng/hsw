#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <conio.h>

struct Info
{
	char num[20];
    char name[20];
	int  price;
    int  amount;
};


char menu()                              /*菜单选择函数*/
{
 char n;                                 /*n记录选择的菜单*/

 system("cls");

 puts("\t\t             欢迎来到仓库货物管理系统               ");

 puts("\t\t***********************MENU***********************\n");

 puts("\t\t*                  1.录入货物信息                *\n");

 puts("\t\t*                  2.显示货物信息                *\n");

 puts("\t\t*                  3.查找货物信息                *\n");

 puts("\t\t*                  4.修改货物信息                *\n");

 puts("\t\t*                  5.删除货物信息                *\n");

 puts("\t\t*                  6.退出系统                    *\n");

 puts("\t\t**************************************************\n");

 puts("*********************************");

 printf("*  请选择你要输入数(1-6):       *\n");

 puts("*********************************");

 while(1)
 {
	 n=getchar();
	 getchar();
	 if(n<'1'||n>'6')
	 {
       puts("**********************************");

       printf("* 出错了！请再次输入(1-6):       *\n");

       puts("**********************************");
	 }
	 else
       break;
 }
 return n;
}



 void append()               /*货物信息输入函数*/
{
   struct Info info;
   FILE * fp;
   char ch;

if((fp=fopen("F:\\test\\filemolde\\123.txt","wb")) == NULL)
{
   printf("******************\n");

   printf("* 不能打开文件!  *\n");

   printf("******************\n");

   getch();

   exit(1);
}

 do
 {
  printf("\tnum:");
  gets(info.num);

  printf("\tname:");
  gets(info.name);

  printf("\tprice:");
  scanf("%d",&info.price);

  printf("\tamount:");
  scanf("%d",&info.amount);
  getchar();

  fwrite(&info,sizeof(info),1,fp);

  printf("***************************\n");
  printf("*  还需要输入吗?(Y/N):    *\n");
  printf("***************************\n");

  ch=getchar();
  getchar();

 }while(ch=='Y'||ch=='y');
 fclose(fp);
}


 void printf1()
 {
    printf("*************************************************************************\n");
    printf("\t\t%-10s\t%-10s\t%-10s\t%-10s\n","num","name","price","amount\n");
	printf("*************************************************************************\n");

 }

 void printf2(struct Info info)
 {

    printf("-------------------------------------------------------------------------\n");
    printf("\t\t%-10s\t%-10s\t%-10d\t%-10d\n",info.num,info.name,info.price,info.amount );
    printf("-------------------------------------------------------------------------\n");
   
 }


 void display()            /*货物信息显示函数*/
 {
   struct Info info;
   FILE * fp;
   int m=0;

   if((fp=fopen("F:\\test\\filemolde\\123.txt","rb"))==NULL)
   {
      printf("******************");

      printf("* 不能打开文件!  *");

      printf("******************");

       getch();

       exit(1);
   }

   while(fread(&info,sizeof(info),1,fp)==1)
   {
    m++;
	if(m==1)
		printf1();
	    printf2(info);
	if((m!=0)&&(m%10==0))

	{
     printf("*****************************\n");

	 printf("*      输入任何键继续       *");

     printf("*****************************\n");

	 getch();
	 puts("\n\n");
	 printf1();

	}

   }

   fclose(fp);

   printf("************************************\n");
   printf("*       总共有%d条记录在其中!      *\n",m);
   printf("************************************\n");


   getch();
 }


void search()           /*货物信息查询函数*/
{
  struct Info info;
  FILE * fp;             
  int flag;              /* flag为 1 按编号查询 ,flag为 2 按姓名查询*/
  int total=0;           /*记录符合条件的记录的个数*/
  char ch[10];
  char f;


  if((fp=fopen("F:\\test\\filemolde\\123.txt","rb")) == NULL)
  {
       printf("************************************\n");
       printf("*      \t 不能打开文件!            *\n");
       printf("************************************\n");
       getch();
       exit(1); 
  }


  do
  {
    rewind(fp);
    printf("************************************\n");
	printf("*        查询通过(1:编号 2:姓名):  *\n");
    printf("************************************\n");

	while(1)
	{
      scanf("%d",&flag);
	  getchar();
	  if(flag<1||flag>2)
	  {
          printf("*****************************************\n");
		  printf("*  出错了！请再次输入[1:编号][2：姓名]  *\n");
		  printf("*****************************************\n");
	  }
	  else
		  break;
	}

       if(flag==1)    /*按编号进行查询*/
	   {

         printf("************************************\n");
         printf("*      请输入你要查询的编号：      *\n");
         printf("************************************\n");

		 gets(ch);
		 total=0;          /*符合条件的记录数*/

          while(fread(&info,sizeof(info),1,fp)==1)
			   if(strcmp(ch,info.num)==0)
			   {
                 total++;
	             if(total==1)
		         printf1();
	             printf2(info);
			   }
	   }
	   else                 /*按姓名进行查询*/
	   {

         printf("************************************\n");
         printf("*       请输入你要查询的姓名：     *\n");
         printf("************************************\n");

		 gets(ch);
		 total=0;

           while(fread(&info,sizeof(info),1,fp)==1)
			   if(strcmp(ch,info.name)==0)
			   {
                 total++;
	             if(total==1)
		         printf1();
	             printf2(info);
			   }

	   }

       printf("************************************\n");
	   printf("*          总共有%d记录在其中!     *\n",total);
       printf("************************************\n");

       printf("************************************\n");
	   printf("*       还需要查询吗?(Y/N):        *\n");
	   printf("************************************\n");
	   f=getchar();
	   getchar();
  }while(f=='Y'||f=='y');
  fclose(fp);
}


  void modify()    /*货物信息修改函数*/
  {
    struct Info info;
	FILE * fp1,* fp2;
	int flag;
	char ch[10];
	char f;


	do
	{

        if((fp1=fopen("F:\\test\\filemolde\\123.txt","rb")) == NULL)
		{

            printf("************************************\n");   
            printf(" *        不能打开文件!            *\n");
			printf("************************************\n");
            getch();
            exit(1); 
		}
		if((fp2=fopen("F:\\test\\filemolde\\456.txt","wb")) == NULL)
		{
            printf("************************************\n");   
            printf(" *        不能打开文件!            *\n");
			printf("************************************\n");
            getch();
            exit(1);
		}

        printf("************************************\n");
		printf("*     请输入你要修改的货物编号：   *\n");
        printf("************************************\n");

		gets(ch);

		flag=0;

         while(fread(&info,sizeof(info),1,fp1)==1)
		 {
			 if(strcmp(ch,info.num)==0)
			 {
               printf1();
			   printf2(info);

               printf("************************************\n");
			   printf("*            请输入新的信息：      *\n");
               printf("************************************\n");


                printf("\tnum:");
                gets(info.num);

                printf("\tname:");
                gets(info.name);

                printf("\tprice:");
                scanf("%d",&info.price);

                printf("\tamount:");
                scanf("%d",&info.amount);
                getchar();
				flag=1;
				
				
			 }
               fwrite(&info,sizeof(info),1,fp2);
		 }
		 fclose(fp1);
		 fclose(fp2);
		 if(flag==1)
		 {

            printf("************************************\n");
            printf("*               修改成功!          *\n");
			printf("************************************\n");
			remove("F:\\test\\filemolde\\123.txt");
			rename("F:\\test\\filemolde\\456.txt","F:\\test\\filemolde\\123.txt");
		 }
		 else
		 {
             printf("************************************\n");
			 printf("*       不能找到这个记录!          *\n");
             printf("************************************\n");
		 }


         printf("************************************\n");
		 printf("*          还修改其他吗?(Y/N):     *\n");
		 printf("************************************\n");

		 f=getchar();
		 getchar();
	}while(f=='y'||f=='Y');
  }



void Delete()          /*货物信息删除函数*/
  {
    struct Info info;
	FILE * fp1,* fp2;
	int flag;
	char ch[10];
	char f;

	

	do
	{
      if((fp1=fopen("F:\\test\\filemolde\\123.txt","rb")) == NULL)
		{
		  printf("************************************\n");
          printf("*    \t 不能打开文件!              *\n");
          printf("************************************\n");
          getch();
          exit(1); 
		}

		if((fp2=fopen("F:\\test\\filemolde\\456.txt","wb")) == NULL)
		{
           printf("************************************\n");
           printf("*    \t 不能打开文件!              *\n");
           printf("************************************\n");
           getch();
           exit(1);
		}

		 printf("************************************\n");
         printf("*     请输入你需要删除货物的编号:  *\n");
         printf("************************************\n");

		 gets(ch);
		 flag=0;
          while(fread(&info,sizeof(info),1,fp1)==1)
		  {
			 if(strcmp(ch,info.num)==0)
			 {
               printf1();
			   printf2(info);
			   flag=1;
			   break;
			 }
			 else
                fwrite(&info,sizeof(info),1,fp2);
		  }
            fclose(fp1);
		    fclose(fp2);
		    if(flag==1)
			{

            printf("************************************\n");
            printf("*           删除成功!              *\n");
            printf("************************************\n");
			remove("F:\\test\\filemolde\\123.txt");
			rename("F:\\test\\filemolde\\456.txt","F:\\test\\filemolde\\123.txt");
			}
		     else
			 {
              printf("************************************\n");
			  printf("*         不能找到这个记录!        *\n");
              printf("************************************\n");
			 }

              printf("************************************\n");
		      printf("*       还删除其他吗?(Y/N):        *\n");
			  printf("************************************\n");

		      f=getchar();
		      getchar();
	}while(f=='y'||f=='Y');
  } 

	





 void main()             /*主函数*/
 {
  while(1)
	{

     int a;
	 char f;

	 char ch[10];

	 char num[20]={"12345"};

	 printf("please input the secret :\n");

	 scanf("%s",ch);

	 if(strcmp(num,ch)==0)
		 a=1;
	 if(a==1)
	 {
		 printf("\nplease enter in the telproject !\n");

		 f=getchar();
		 getchar();
	      break;
	 }
	 else 
	 {
		 printf("\n the secret is  error");

	     printf("please input the right secret");
	 }
    }


  while(1)
	  switch(menu())
  {
     case'1':append();break;
     case'2':display();break;
     case'3':search();break;
     case'4':modify();break;
     case'5':Delete();break;
	 case'6':exit(0);break;	   
  }
 }

