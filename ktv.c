#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
char admin_password[16] = "admin123"; 
void select_song();
void select_singer();
int login();
void del_song();
void add_song();
void change_password();

int main()
{
    int num=0,state=0;
    // char choice;
    char namebuf[32]={0},singerbuf[32]={0};
    printf("大爷来玩啊？？boo~\n");
    while(1)
    {
        printf("***********************************************************\n");
        printf("**点歌请输入1 查看歌手信息请输入2 输入3登录管理员 否则退出*\n");
        printf("***********************************************************\n");
        scanf("%d",&num);
        if(num == 1)
            select_song();
        else if(num == 2)
            select_singer();
        else if(num == 3)
        {
            state = login();
            if(state == 1)  //如果登录成功马上跳出次循环，开启下一层循环，选择管理员操作
                break;
        }
        else //输入数据非1 2 3就跳出循环 结束程序
            break;
    }
    //普通用户无法执行次循环
    while(state == 1){
        printf("######################################################\n");
        printf("##删除歌曲选择1 添加歌曲选择2 更改密码选择3 否则退出##\n");
        printf("######################################################\n");
        scanf("%d",&num);
        if(num == 1)
            del_song();
        else if(num == 2)
            add_song();
        else if(num == 3)
            change_password();
        else
            break;
    }
    printf("\n欢迎下次再来！\n");
    return 0;
}

void select_song()
{
    FILE *fp;
    char song_name[20]={0};
    char buff[200] = {0};
    char temp[20] = {0};
    int len;
    printf("请输入歌曲名:");
    scanf("%s",song_name);
    /*给该歌曲名加上文件路径(song文件夹里的歌名.txt文件)*/
    strcpy(temp,song_name);
    strcpy(song_name,"song//");
    strcpy(&song_name[6],temp);
    len=strlen(song_name);
    strcpy(&song_name[len],".txt");
    /*从该路径打开以歌曲命名的文件，提取歌词*/
    if((fp=fopen(song_name,"r"))==NULL)
    {
        printf("不存在这首歌曲!\n");
    }
    else
    {
        printf("#############################################\n");
        printf("    正在播放:%s\n",temp);
        printf("歌词：\n");
        while(fgets(buff,200,fp)!=NULL)
            printf("%s",buff);
        printf("\n    播放完毕:%s",temp);
        printf("\n#############################################\n");
        fclose(fp);
    }
}

void select_singer()
{
    FILE *fp1;
    char singer_name[20]={0};
    char temp[20]={0};
    char buff[100] = {0};
    int len;
    printf("请输入歌手名：");
    scanf("%s",singer_name);
    /*给该歌手加上文件路径*/
    strcpy(temp,singer_name);
    strcpy(singer_name,"singer//");
    strcpy(&singer_name[8],temp);//strlen("singer//")=8
    len=strlen(singer_name);
    strcpy(&singer_name[len],".txt");
    /*读取歌手文件中保存的该歌手的所有歌曲*/
    if((fp1=fopen(singer_name,"r"))==NULL)
    {
        printf("不存在歌手!");
    }
    else
    {
        printf("歌手全部歌曲如下:\n");
        printf("|--------------------------|\n");
        while(fgets(buff,100,fp1)!=NULL)
        {
            printf("%s",buff);
        }
        fclose(fp1);
        printf("\n|--------------------------|\n");
    }
}

int login(){
    int state=0;
    char buf[16]={0};
    printf("输入密码：  ");
    scanf("%s",buf);
    if(strcmp(admin_password,buf)==0){
        printf("登陆成功！\n");
        state=1;
    }
    else
        printf("登录失败，以普通用户身份访问系统。\n");
    return state;
}

void del_song()
{
    char song_name[32]={0},temp[64]={0};
    int len = 0;
    printf("输入要删除的歌曲名字：\n");
    scanf("%s",song_name);  //song_name = "xxx"
    strcpy(temp,song_name); //先把歌曲名赋值给temp
    strcpy(song_name,"song//");//song_name = "song//"  song文件夹下存放歌曲文件
    strcpy(&song_name[6],temp); //song_name = "song//xxx"
    len=strlen(song_name);
    strcpy(&song_name[len],".txt"); //song_name = "song//xxx.txt"
    if (!remove(song_name))
        printf("删除歌曲 %s 成功!\n",song_name); //删除成功
    else
        perror("删除歌曲失败！");//打印错误信息
}
void add_song()
{  
    char song_name[32]={0},temp[64]={0},buf[1024]={0};
    int len = 0;
    FILE *fp;
    printf("输入要新建的歌曲名字：\n"); 
    scanf("%s",song_name);  //song_name = "xxx"
    strcpy(temp,song_name); //先把歌曲名赋值给temp
    strcpy(song_name,"song//");//song_name = "song//"  song文件夹下存放歌曲文件
    strcpy(&song_name[6],temp);//song_name = "song//xxx"
    len=strlen(song_name);
    strcpy(&song_name[len],".txt");//song_name = "song//xxx.txt"
    fp = fopen(song_name,"w");
    if(fp == NULL)
        perror("歌曲添加失败");
    else{   // 新建歌曲文件成功
        printf("现在输入歌词内容,单行输入quit结束输入：\n");
        printf("---------------------------------------\n");
        scanf("%s",buf);  //一次接受一行歌词
        while( strcmp(buf,"quit") != 0 ){ //比较此行内容是否为quit，如果是就结束循环，关闭文件
            buf[strlen(buf)]='\n';  //scanf字符串不接受换行符，为了美观人为在缓冲区歌词末尾加上换行符
            fputs(buf,fp); //写入文件
            memset(buf,0,sizeof(buf));
            scanf("%s",buf); //一次接受一行歌词
        }
        printf("---------------------------------------\n输入完毕！\n");
        fclose(fp);
    }
}

void change_password()
{
    char buf[32]={0};
    printf("输入新的密码：  ");
    scanf("%s",buf);
    memset(admin_password,0,sizeof(admin_password));
    strcpy(admin_password,buf);
    printf("更换成功！新密码：'%s'\n",admin_password);
}
