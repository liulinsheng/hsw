#include "cj.h"
// 链栈初始化   为了减少 手工输入可能带来的错误，我决定采用文件读入的方式，来进行初始化
void init_stack() {
    stack_node.head = (node*)malloc(sizeof(node));
    stack_node.head->next = NULL;   // 弄明白头插法，需要看明白这里
    FILE *fp;
    if ((fp = fopen(GIFT_FILE, "r")) == NULL) {
        printf("默认的礼物文件不存在，去找到它\n");
        return ;
    }
    char name[MAXLEN];
    while((fscanf(fp, "%s", name)) != EOF) {
        node *n = (node *)malloc(sizeof(node));
        strcpy(n->g.name, name);   // 将礼物放起来
        n->next = stack_node.head->next; // 弄明白头插法，需要看明白这里
        stack_node.head->next = n;  // 弄明白头插法，需要看明白这里
    }
    //printf("礼物初始化完成\n");
}

// 链队列
void init_queue() {
    queue_node.first = queue_node.last = (node *)malloc(sizeof(node));  // 弄懂链队列，看这里
    queue_node.first->next = NULL;   // 弄懂链队列，看这里
    FILE *fp;
    if ((fp = fopen(PEOPLE_FILE, "r")) == NULL) {
        printf("默认玩家文件不存在\n");
        return ;
    }
    char name[MAXLEN];
    while((fscanf(fp, "%s", name)) != EOF) {
        node *n = (node *)malloc(sizeof(node));
        strcpy(n->p.name, name);
        strcpy(n->g.name, nil);   // 先标记为空
        n->next = NULL;   // 弄懂链队列，看这里
        queue_node.last->next = n; //弄懂链队列，看这里
        queue_node.last = n;  // 弄懂链队列，看这里
    }
    //printf("玩家初始化完成\n");
}

// 拿到一个礼物
node* get_gift() {
    node *n = stack_node.head->next;
    if(stack_node.head->next != NULL) {
        stack_node.head = stack_node.head->next;
    }
    return n;
}

int get_num() {

    int a = rand();
    return a % 10;
}

/********************************************************************/
List_User *initList_User(){
    
    List_User *list = (List_User *)malloc(sizeof(List_User));
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;

    return list;
}//链表初始化

void addTail_User(List_User *list,people *data){
    
    NodeUser *node = (NodeUser *)malloc(sizeof(NodeUser));
    node->data = data;
    node->next = NULL;

    if(list->head == NULL){
        list->head = node;
    }else{
        list->tail->next = node;
    }
    list->tail = node;

    return;
}//头插法构建链表  

void Free_Userlist(NodeUser *list){

    NodeUser *tmp;
    while(list != NULL){
        tmp = list;
        list = list->next;
        free(tmp);
        tmp = NULL;
    }
    return;
}//释放链表 


void UserToFile_list(List_User *list){
    
    NodeUser *tmp = list->head;
    FILE *fp;
    fp = fopen(PEOPLE_FILE,"a");
    if (fp != NULL)
    {
        while(tmp != NULL){
            fprintf(fp, "%s\t", tmp->data->name);

            tmp = tmp->next;
        }
        fclose(fp);
    }else{
        printf("文件保存失败 ！\n");
    }
}

void Write_User(){
    system("clear");
    people *user;
    char flag = 'y';
    List_User *list = initList_User();
    while(flag == 'y'){
        user = Input_User_Data();
        addTail_User(list,user);
        printf("添加成功 !\n");
        printf("是否继续 y or n\n");
        getchar();
        flag = getchar();
        
    }
    UserToFile_list(list);
    Free_Userlist(list->head);

    return;
}
people *Input_User_Data(){
    char name[30];
    people *user = (people *)malloc(sizeof(people));
   
    printf("请输入玩家\n");
    scanf("%s",name);
    strcpy(user->name,name);

    return user;
}

void UserFromFile(List_User *list){
    FILE *fp;
    fp = fopen(PEOPLE_FILE, "r");
    if (fp != NULL)
    {
        while(!feof(fp)){
            people *user = (people *)malloc(sizeof(people));
            fscanf(fp,"%s",user->name);

            addTail_User(list,user);
        }

        fclose(fp);

    }else{
        printf("文件打开失败 ！\n");
    }
    return;
}


/***********************************************/


List_Gift *initList_Gift(){
    
    List_Gift *list = (List_Gift *)malloc(sizeof(List_Gift));
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;

    return list;
}//链表初始化

void addTail_Gift(List_Gift *list,gift *data){
    
    NodeGift *node = (NodeGift *)malloc(sizeof(NodeGift));
    node->data = data;
    node->next = NULL;

    if(list->head == NULL){
        list->head = node;
    }else{
        list->tail->next = node;
    }
    list->tail = node;

    return;
}//头插法构建链表  

void Free_Giftlist(NodeGift *list){

    NodeGift *tmp;
    while(list != NULL){
        tmp = list;
        list = list->next;
        free(tmp);
        tmp = NULL;
    }
    return;
}//释放链表 


void GiftToFile_list(List_Gift *list){
    
    NodeGift *tmp = list->head;
    FILE *fp;
    fp = fopen(GIFT_FILE,"a");
    if (fp != NULL)
    {
        while(tmp != NULL){
            fprintf(fp, "%s\t", tmp->data->name);

            tmp = tmp->next;
        }
        fclose(fp);
    }else{
        printf("文件保存失败 ！\n");
    }
}

void Write_Gift(){
    system("clear");
    gift *g;
    char flag = 'y';
    List_Gift *list = initList_Gift();
    while(flag == 'y'){
        g = Input_Gift_Data();
        addTail_Gift(list,g);
        printf("添加成功 !\n");
        printf("是否继续 y or n\n");
        getchar();
        flag = getchar();
        
    }
    GiftToFile_list(list);
    Free_Giftlist(list->head);
}

gift *Input_Gift_Data(){
    char name[30];
    gift *g = (gift *)malloc(sizeof(gift));
   
    printf("请输入礼物\n");
    scanf("%s",name);
    strcpy(g->name,name);

    return g;
}

void GiftFromFile(List_Gift *list){
    FILE *fp;
    fp = fopen(GIFT_FILE, "r");
    if (fp != NULL)
    {
        while(!feof(fp)){
            gift *g = (gift *)malloc(sizeof(gift));
            fscanf(fp,"%s",g->name);

            addTail_Gift(list,g);
        }

        fclose(fp);

    }else{
        printf("文件打开失败 ！\n");
    }
    return;
}
/***********************************************************/

void display_User(){
    system("clear");
    char name[20];
    NodeUser *user;
    List_User *list = initList_User();
    UserFromFile(list);

    NodeUser *tmp = list->head;
    while(tmp->next != NULL){
            printf(" 玩家:%s\n",tmp->data->name);
            tmp = tmp->next;
        
    }
    Free_Userlist(list->head);
    return;
}

void display_Gift(){
    system("clear");
    char name[20];
    NodeGift *gift;
    List_Gift *list = initList_Gift();
    GiftFromFile(list);

    NodeGift *tmp = list->head;
    while(tmp->next != NULL){
            printf(" 奖品:%s\n",tmp->data->name);
            tmp = tmp->next;
        
    }
    Free_Giftlist(list->head);
    return;
}






void play_game() {
    printf("游戏现在开始\n");
    int a, b;
    node *p = queue_node.first->next;
    while(p != NULL) {
        b = get_num();
        printf("请 '%s' 开始从0到9里选一个数字:\n", p->p.name);
        scanf("%d", &a);
        if (a != b) {
            printf("这个数字是：'%d' 不幸的是，玩家  : '%s'没有猜到!!\n", b, p->p.name);
        } else {
            node *g = get_gift();
            if (g != NULL) {
                strcpy(p->g.name, g->g.name);
                printf("恭喜玩家: '%s', 猜到数字:%d, 带礼物回家: '%s'!!!\n", p->p.name, b, g->g.name);
                free(g);
            } else {
                printf("对不起，这里没有更多的礼物了  ，现在退出程序\n");
                return ;
            }
        }
        p = p->next;
    }
    printf("游戏的最后，所有的玩家都被选中了，每个人送一瓶可乐\n");
}


void User(){
    system("clear");
    init_queue();
    init_stack();
    //printf("--------------------欢迎来到抽奖游戏--------------------\n");
    printf("游戏规则: \n");
    printf("系统会随机从0到9里生成一个数字，如果你猜对的话，你会得到奖品，每个人只能选一次\n");
    play_game();
    printf("--------------------游戏结束，再见，谢谢各位的参与！--------------------\n");

    return;
}


void Main_Menu(){
    system("clear");
    char flat;
    while(1){
        printf("1.开始抽奖\n");
        printf("2.添加玩家\n");
        printf("3.添加奖品\n");
        printf("4.查看玩家\n");
        printf("5.查看奖品\n");
        printf("6.退出\n");
        flat = getchar();
        switch(flat){
            case '1':   User();
                        printf("游戏结束 !\n");
                        printf("\n");
                        getchar();
                        getchar();
                        printf("请按任意键返回\n");
                        system("clear");
                        break;
            case '2':   Write_User();
                        getchar();
                        printf("请按任意键返回\n");
                        system("clear");
                        break;
            case '3':   Write_Gift();
                        getchar();
                        printf("请按任意键返回\n");
                        system("clear");
                        break;
            case '4':   display_User();
                        getchar();
                        getchar();
                        printf("请按任意键返回\n");
                        system("clear");
                        break;
            case '5':   display_Gift();
                        getchar();
                        getchar();
                        printf("请按任意键返回\n");
                        system("clear");
                        break;
            case '6':   system("clear");
                        return;
        }

    }


    return;
}
