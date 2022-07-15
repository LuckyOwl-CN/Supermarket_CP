#include "IntegralSystem.h"

SHOP*head = NULL;
SHOP*p1 = NULL;
int count;

void CommodityMenu(userInf loginUser){
    switch (loginUser.userPermission) {
        default:
            return;
        case 1:
            C_CommodityMenu(loginUser);
            return;
        case 2:
            M_CommodityMenu(loginUser);
            return;
    }
}

void Windowstime() {
    SYSTEMTIME sys;

    printf("\t\t\t\t\t  当前时间为：");
    GetLocalTime( &sys ); //获取系统时间到程序的函数
    printf( "%4d--%02d--%02d %02d:%02d \n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wDayOfWeek); //按照年/月/日 时/分/秒 星期几格式打印
    printf("\n");

    return;
}

void C_CommodityMenu(userInf loginUser) {
    readInformation();
    int select = 1;
    while (select != 10) {
        printf("\n\n\n");
        printf("\t\t\t\t\t                                   \n");
        printf("\t\t\t\t\t          超市商品管理系统 \n");
        printf("\t\t\t\t\t                                   \n");
        printf("\n\n");
        printf("\t\t\t\t   ╭════════════════════════════════════════════╮\n");
        printf("\t\t\t\t   │              超市商品购买系统              │\n");
        printf("\t\t\t\t   ╰════════════════════════════════════════════╯\n");
        printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
        printf("\t\t\t\t   │                                            │\n");
        printf("\t\t\t\t   │                1. 显示商品信息             │\n");
        printf("\t\t\t\t   │                2. 查询商品信息             │\n");
        printf("\t\t\t\t   │                3. 商品信息排序             │\n");
        printf("\t\t\t\t   │                4. 查询订单信息             │\n");
        printf("\t\t\t\t   │                5. 退出管理系统             │\n");
        printf("\t\t\t\t   │                                            │\n");
        printf("\t\t\t\t   │                                            │\n");
        printf("\t\t\t\t   └────────────────────────────────────────────┘\n");

        Windowstime();		//windows当前时间
        printf("\t\t\t请你根据上方选择1-10进行下一步\t");//进行下一步选择
        scanf("%d", &select);
        switch (select) {
            case 5:
                getchar();
                system("cls");
                printf("\n您已经成功退出。\n");//退出函数
                break;	//退出商品管理系统
            case 1://打印信息
                showShop();
                break;
            case 2://查询信息
                findInformation();
                break;
            case 3://排序
                sortInformation();
                break;
            case 4:
                findOrderInformation(loginUser);
                break;
            default:
                getchar();
                rewind(stdin);//清除键盘缓存
                printf("输入错误，请重新输入！\n");
                system("pause");
                break; //用户敲错了

        }
    }
}

void M_CommodityMenu(userInf loginUser)
{
    readInformation();
    int select = 1;
    while (select != 10) {
        printf("\n\n\n");
        printf("\t\t\t\t\t                                   \n");
        printf("\t\t\t\t\t          超市商品管理系统 \n");
        printf("\t\t\t\t\t                                   \n");
        printf("\n\n");
        printf("\t\t\t\t   ╭════════════════════════════════════════════╮\n");
        printf("\t\t\t\t   │              超市商品管理系统              │\n");
        printf("\t\t\t\t   ╰════════════════════════════════════════════╯\n");
        printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
        printf("\t\t\t\t   │                                            │\n");
        printf("\t\t\t\t   │                1. 录入商品信息             │\n");
        printf("\t\t\t\t   │                2. 显示商品信息             │\n");
        printf("\t\t\t\t   │                3. 保存商品信息             │\n");
        printf("\t\t\t\t   │                4. 查询订单信息             │\n");
        printf("\t\t\t\t   │                5. 统计商品信息             │\n");
        printf("\t\t\t\t   │                6. 查询商品信息             │\n");
        printf("\t\t\t\t   │                7. 修改商品信息             │\n");
        printf("\t\t\t\t   │                8. 删除商品信息             │\n");
        printf("\t\t\t\t   │                9. 商品信息排序             │\n");
        printf("\t\t\t\t   │                10.退出管理系统             │\n");
        printf("\t\t\t\t   │                                            │\n");
        printf("\t\t\t\t   │                                            │\n");
        printf("\t\t\t\t   └────────────────────────────────────────────┘\n");

        Windowstime();		//windows当前时间
        printf("\t\t\t请你根据上方选择1-10进行下一步\t");//进行下一步选择
        scanf("%d", &select);
        switch (select) {
            case 10:
                getchar();
                system("cls");
                printf("\n您已经成功退出。\n");//退出函数
                break;	//退出商品管理系统

            case 1://录入信息
                inputInformation();
                break;

            case 2://打印信息
                showShop();
                break;

            case 3://保存信息到文件
                saveInformation();
                break;

            case 4://读取文件信息
                findOrderInformation(loginUser);
                break;

            case 5://统计信息
                infoshop();
                break;

            case 6://查询信息
                findInformation();
                break;

            case 7://修改信息
                amendInformation();
                break;

            case 8://删除
                delInformation();
                break;

            case 9://排序
                sortInformation();
                break;

            default:
                getchar();
                rewind(stdin);//清除键盘缓存
                printf("输入错误，请重新输入！\n");
                system("pause");
                break; //用户敲错了

        }
    }
}

void cursor(int x, int y) { //光标函数
    COORD pos;
    HANDLE h;           //HANDLE:句柄
    pos.X = x;
    pos.Y = y;
    h = GetStdHandle(STD_OUTPUT_HANDLE); //获得当前输出窗口的句柄
    SetConsoleCursorPosition(h, pos);
}
void inputInformation() {
    SHOP *p2 = NULL;//结构体指针
    int choose = 1;
    int chooses = 1;//循环判断真假

    while (choose == 1) {
        system("cls");//清屏

        p2 = (SHOP *)malloc(sizeof(SHOP)); //为p2申请内存单元

        inputDate(p2);//录入信息界面

        if (head == NULL) { //判断是否为头结点
            head = p1 = p2;
            p2->next = NULL;
        } else {
            p1->next = p2;//p1指向p2
            p2->next = NULL;//p2指向空
            p1 = p2;//p2的值赋给p1
        }
        system("cls");

        printf("是否要继续录入商品信息  1.继续  2.退出\n");
        scanf("%d", &choose);
        if (choose != 1 && choose != 2) {
            printf("选项有误，请重新输入！\n");

            printf("是否继续录入：1.继续     2.退出\n");

            scanf("%d", &choose);

            if (choose == 1) {
                continue;
            } else {
                printf("输入有误，退出录入\n");
                system("pause");
                break;
            }
        }
    }

    system("cls"); //清屏




}
void inputDate(SHOP*p) {

    printf("\n\n");
    printf("\t\t\t\t   ╭════════════════════════════════════╮\n");
    printf("\t\t\t\t   │              超市商品信息          │\n");
    printf("\t\t\t\t   ╰════════════════════════════════════╯\n");
    printf("\t\t\t\t   ┌───────────────────────────────────-┐\n");
    printf("\t\t\t\t   │===================================== \n");
    printf("\t\t\t\t   │ 类型:                              │\n");
    printf("\t\t\t\t   │===================================== \n");
    printf("\t\t\t\t   │ 名称:                              │\n");
    printf("\t\t\t\t   │===================================== \n");
    printf("\t\t\t\t   │ 编号:                              │\n");
    printf("\t\t\t\t   │===================================== \n");
    printf("\t\t\t\t   │ 价格:                              │\n");
    printf("\t\t\t\t   │===================================== \n");
    printf("\t\t\t\t   │ 库存:                              │\n");
    printf("\t\t\t\t   │===================================== \n");
    printf("\t\t\t\t   │ 销量:                              │\n");
    printf("\t\t\t\t   │===================================== \n");
    printf("\t\t\t\t   │ 销售时间:                          │\n");
    printf("\t\t\t\t   │===================================== \n");
    printf("\t\t\t\t   │ 进货商:                            │\n");
    printf("\t\t\t\t   │===================================== \n");
    printf("\t\t\t\t   │ 生产日期:                          │\n");
    printf("\t\t\t\t   │===================================== \n");
    printf("\t\t\t\t   │ 保质期:                            │\n");
    printf("\t\t\t\t   │===================================== \n");
    printf("\t\t\t\t   └────────────────────────────────────┘\n");


    cursor(44, 7);
    scanf("%s", p->type); //种类
    fflush(stdin);
    cursor(44, 9);
    scanf("%s", p->ID); //名称
    fflush(stdin);
    cursor(44, 11);
    scanf("%s", p->number); //编号
    fflush(stdin);
    cursor(44, 13);
    fflush(stdin);
    scanf("%s", p->price); //价格
    fflush(stdin);
    cursor(44, 15);
    scanf("%d", &p->amount); //库存
    fflush(stdin);
    cursor(44, 17);
    scanf("%d", &p->sale); //销量
    fflush(stdin);
    cursor(47, 19);
    scanf("%s", p->saletime); //销售时间
    fflush(stdin);
    cursor(44, 21);
    scanf("%s", p->buyer); //产地
    fflush(stdin);
    cursor(47, 23);
    scanf("%s", p->date); //生产日期
    fflush(stdin);
    cursor(45, 25);
    scanf("%s", p->day); //保质期
    fflush(stdin);
    count++;//节点个数 +1

}





void showShop() {
    SHOP*p;
    if (head = NULL) {
        printf("尚未录入商品信息！按任意键返回。\n");
        getch();
        system("pause");
        system("cls");
        return;
    }
    printf("商品信息罗列如下。\n");
    p = head;
    printf("\t名称\t\t类型\t\t编号\t\t生产日期\t\t进库时间\t\t保质期\t\t库存数量\t\t进货商\t\t出售时间\n");
    while (p != NULL) {
        printf("%5s  %5s  %5s  %5s  %5s  %5s  %d  %5s  %5s\n", p->ID, p->type, p->number, p->date, p->passtime, p->day, p->amount, p->buyer, p->saletime);
        p = p->next;
    }
    printf("\n");
    printf("商品信息已经全部打印。");
    printf("\n");
    system("pause");
    system("cls");


}
void  saveInformation() {
    FILE *fp;//文件指针
    SHOP *p;//相关信息指针

    p = head;

    fp = fopen("CommodityInf.txt", "w"); //写入文件信息(覆盖原数据)

    if (fp == NULL) { //判断文件是否正常打开
        printf("不能打开文件！");
        exit(1);
    }

    while (p != NULL) { //p2不为空时进行数据的录入

        fprintf(fp, "%10s\t%10s\t%10s\t%10s\t%d\t%10s\t%d\t%10s\t%10s\t%10s  \n", p->number, p->ID, p->type, p->price, p->amount, p->saletime, p->sale, p->buyer, p->date, p->day);
        p = p->next;

    }

    printf("文件保存成功！\n");

    system("pause");
    system("cls");
    exit(1);

    if (fclose(fp)) {
        printf("不能关闭文件！");
        exit(1);
    }

}

void readInformation() {
    FILE*fp;
    SHOP*p;
    int i = 0;
    head = (SHOP*)malloc(sizeof(SHOP));
    head->next = NULL;
    if ((fp = fopen("CommodityInf.txt", "r")) == NULL)                 /*如果此文件不存在*/
    {
        if ((fp = fopen("CommodityInf.txt", "w")) == NULL) {
            printf("[系统]无法建立文件！\n");
            return;
        }
    }
    if (fp != NULL) {
        p1 = head;

        while (!feof(fp)) {
            p = (SHOP*)malloc(sizeof(SHOP));
            p->next = NULL;
            p1->next = p;
            p1 = p;
            fscanf(fp, "%10s %10s %10s %10s %d %10s %d %10s %10s %10s  ", p->number, p->ID, p->type, p->price, &p->amount, p->saletime, &p->sale, p->buyer, p->date, p->day);


            i++;	//TODO
        }
        if (i == 1) {
            head = p;

        }
    }
    if (fclose(fp)) {
        printf("关闭文件失败啦。");
        exit(1);

    }





}

void infoshop() {
    SHOP *p;	//结构体指针

    int temp = 0;//做判断
    int temf = 0;
    p = head;/*头结点赋值给 p */

    printf("\t统计进行中,请稍后");

    fflush(stdin);

    printf("\t结果如下：\n");


    while (p != NULL) {
        /*库存小于50的商品信息*/

        if (p->amount < 50) {

            printf("\n");
            printf("销量:%d		编号：%s	名称：%7s	种类：%7s	 价格：%5s	 库存：%d	销售日期：%7s	 产地：%7s	生产日期：%7s	保质期：%s \n",
                   p->sale, p->number, p->ID, p->type, p->price, p->amount, p->saletime, p->buyer, p->date, p->day);



            temp = 1;

        }
        p = p->next;

    }
    if (temp == 0) {

        printf("没有库存小于50的商品. . .\n");

    } else {
        printf("\n\t以上商品库存不足。请尽快补货\n");
    }
    printf("\n\n\n");
    p = head;/*头结点赋值给 p */
    while (p != NULL) {
        /*保质期小于一个月的商品信息*/

        if (atoi(p->day) <= 30) {
            printf("\n");
            printf("销量:%d		编号：%s	名称：%7s	种类：%7s	 价格：%5s	 库存：%d	销售日期：%7s	 产地：%7s	生产日期：%7s	保质期：%s \n",
                   p->sale, p->number, p->ID, p->type, p->price, p->amount, p->saletime, p->buyer, p->date, p->day);



            temf = 1;



        }
        p = p->next;

    }
    if (temf == 0) {

        printf("没有离过期小于一个月的的商品. . .\n");

    } else {
        printf("\n\t以上商品库存即将过期。请尽快优惠销售\n");
    }

    printf("\n");
    system("pause");
    system("cls");


}

void findInformation() {

    SHOP *p2; //结构体


    int opt_c;			//用户输入选项
    int ture = 1;
    int flag = 0; 		//判断真假
    char s_ID[10];		//用户输入要查询的商品名称
    char s_number[10];	//用户输入要查询的商品编号

    p2 = head; //p2赋值为头结点


    while (ture == 1) {

        printf("\n");
        printf("\t\t\t\t\t\t┌-----------------┐\n");;
        printf("\t\t\t\t\t\t |1.按照编号查询  |\n");
        printf("\t\t\t\t\t\t |2.按照名称查询  |\n");
        printf("\t\t\t\t\t\t |3.退出查询      |\n");
        printf("\t\t\t\t\t\t└-----------------┘\n");


        printf("请选择：\n");
        fflush(stdin);//清空键盘缓存
        scanf("%s", &opt_c);

        switch (opt_c) {
            case '1'://编号查询

                system("pause");
                system("cls");		//暂停和清屏

                p2 = head;

                printf("\n\n");
                printf("\t\t\t\t   │=========================================== │\n");
                printf("\t\t\t\t   │ 请输入编号：             		        │\n");
                printf("\t\t\t\t   │=========================================== │\n");

                cursor(50, 3);
                scanf("%s", &s_number);
                flag = 0;

                while (p2 != NULL) {
                    //flag = 1;
                    if (strcmp(s_number, p2->number) == 0) {

                        flag = 1;
                        printf("\n\n");
                        printf("\t\t\t\t   ╭════════════════════════════════════════════╮\n");
                        printf("\t\t\t\t   │                 查询商品信息               │\n");
                        printf("\t\t\t\t   ╰════════════════════════════════════════════╯\n");
                        printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   │ 种类：%s             			│\n", p2->type);
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   │ 名称：%s            			│\n", p2->ID);
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   │ 价格：%s              		\t│\n", p2->price);
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   │ 库存：%d            			│\n", p2->amount);
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   │ 销量：%d             			│\n", p2->sale);
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   │ 销售时间:%s            		        │\n", p2->saletime);
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   │ 产地：%s            			│\n", p2->buyer);
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   │ 生产日期:	%s            		        │\n", p2->date);
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   │ 保质期：%s             		\t│\n", p2->day);
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   └────────────────────────────────────────────┘\n");

                    }



                    p2 = p2->next;

                }
                if (flag == 0) {
                    printf("查无此商品. . .");
                    printf("\n");

                    break;
                }

                system("pause");
                system("cls");

                break;


            case '2'://名称查询

                system("pause");
                system("cls");

                p2 = head;

                printf("\n\n");
                printf("\t\t\t\t   │=========================================== │\n");
                printf("\t\t\t\t   │ 请输入名称：             		        │\n");
                printf("\t\t\t\t   │=========================================== │\n");

                cursor(50, 3);
                scanf("%s", &s_ID);
                flag = 0;

                while (p2 != NULL) {
                    //flag = 1;
                    if (strcmp(s_ID, p2->ID) == 0 ) {


                        flag = 1;
                        printf("\n\n");
                        printf("\t\t\t\t   ╭════════════════════════════════════════════╮\n");
                        printf("\t\t\t\t   │                 查询商品信息               │\n");
                        printf("\t\t\t\t   ╰════════════════════════════════════════════╯\n");
                        printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   │ 种类：%s             			│\n", p2->type);
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   │ 名称：%s            			│\n", p2->ID);
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   │ 价格：%s              		\t│\n", p2->price);
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   │ 库存：%d            			│\n", p2->amount);
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   │ 销量：%d             			│\n", p2->sale);
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   │ 销售时间:%s            		        │\n", p2->saletime);
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   │ 产地：%s            			│\n", p2->buyer);
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   │ 生产日期:	%s            		        │\n", p2->date);
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   │ 保质期：%s             		\t│\n", p2->day);
                        printf("\t\t\t\t   │==========================================	│\n");
                        printf("\t\t\t\t   └────────────────────────────────────────────┘\n");




                    }

                    p2 = p2->next;

                }

                if (flag == 0) {
                    printf("查无此商品. . .");
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
                }

                system("pause");
                system("cls");


                break;

            case '3'://退出
                printf("使用完毕！\n");
                system("pause");
                system("cls");
                return;


            default:
                getchar();
                printf("您输入错误，请重新输入：\n");
                system("pause");
                break;

        }

    }

}




void amendInformation() {
    SHOP *p2; //初始化结构体指针p2

    int opt_c;	//用户输入选项
    //int choose;
    int flag;	//判断真假

    char s_ID[10];	//按照名称
    char s_number[10];	//按照编号

    int content; 	//用户输入选项
    int content1; 	//用户输入选项

    p2 = head;


    printf("\n");
    printf("\t\t\t\t\t\t┌-----------------┐\n");;
    printf("\t\t\t\t\t\t |1.编号查询修改  |\n");
    printf("\t\t\t\t\t\t |2.名称查询修改  |\n");
    printf("\t\t\t\t\t\t |3.退出修改      |\n");
    printf("\t\t\t\t\t\t└-----------------┘\n");


    //rewind(stdin);
    printf("请选择：\n");
    scanf("%d", &opt_c);


    while (opt_c != 3) {

        if (opt_c == 1) { //编号查询

            system("pause");
            system("cls");

            p2 = head;
            printf("\n\n");
            printf("\t\t\t\t   │=========================================== │\n");
            printf("\t\t\t\t   │ 请输入编号：             		        │\n");
            printf("\t\t\t\t   │=========================================== │\n");
            cursor(54, 3);
            scanf("%s", &s_number);
            flag = 0;

            while (p2 != NULL) {
                if (strcmp(s_number, p2->number) == 0) {
                    flag = 1;
                    printf("\n\n");
                    //p2 = head;
                    printf("\t\t\t\t   ╭════════════════════════════════════════════╮\n");
                    printf("\t\t\t\t   │                 修改商品信息               │\n");
                    printf("\t\t\t\t   ╰════════════════════════════════════════════╯\n");
                    printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 1.种类：%s             			│\n", p2->type);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 2.名称：%s            			│\n", p2->ID);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 3.价格：%s              		\t│\n", p2->price);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 4.库存：%d            			│\n", p2->amount);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 5.销量：%d             			│\n", p2->sale);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 6.销售时间:%s            		        │\n", p2->saletime);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 7.产地：%s            			│\n", p2->buyer);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 8.生产日期:	%s            		        │\n", p2->date);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 9.保质期：%s             		\t│\n", p2->day);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   └────────────────────────────────────────────┘\n");
                    fflush(stdin);

                    printf("请输入要修改的内容选项(前面的数字)：\n");
                    scanf("%d", &content);

                    switch (content) {
                        case 1:
                            printf("请输入商品种类：\n");
                            scanf("%s", p2->type);
                            break;

                        case 2:
                            printf("请输入商品名称：\n");
                            scanf("%s", p2->ID);
                            break;


                        case 3:
                            printf("请输入商品价格：\n");
                            scanf("%s", &p2->price);
                            break;


                        case 4:
                            printf("请输入商品库存：\n");
                            scanf("%d", &p2->amount);
                            break;


                        case 5:
                            printf("请输入商品销量：\n");
                            scanf("%d", &p2->sale);
                            break;

                        case 6:
                            printf("请输入商品销售日期：\n");
                            scanf("%s", p2->saletime);
                            break;

                        case 7:
                            printf("请输入商品产地：\n");
                            scanf("%s", p2->buyer);
                            break;

                        case 8:
                            printf("请输入商品生产日期：\n");
                            scanf("%s", p2->date);
                            break;

                        case 9:
                            printf("请输入商品保质期：\n");
                            scanf("%s", p2->day);
                            break;

                        default:
                            printf("输入错误，请重新输入\n");
                            break;

                    }

                }

                p2 = p2->next;

            }


            if (flag == 0) {
                printf("无该商品相关信息. . .");
                printf("\n");
                break;
            }




            fflush(stdin);

            printf("修改成功！\n");


            printf("\t\t\t请问要接着修改吗？\n");
            printf("\t\t\t1.是的。\n\t\t\t2.退出修改");
            scanf("%d", &opt_c);
            switch (opt_c) {
                case 1:
                    //TODO
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    //TODO
                    opt_c = 3;
                    system("pause");
                    system("cls");
                    break;
                default:
                    printf("输入错误，已经自动为你退出");//TODO
                    opt_c = 3;
                    system("pause");
                    system("cls");
                    break;
            }



        }

        else if (opt_c == 2 ) { //名称查询修改

            system("pause");
            system("cls");

            p2 = head;

            printf("\n\n");
            printf("\t\t\t\t   │=========================================== │\n");
            printf("\t\t\t\t   │ 请输入名称：             		        │\n");
            printf("\t\t\t\t   │=========================================== │\n");

            cursor(50, 3);
            scanf("%s", &s_ID);
            flag = 0;


            while (p2 != NULL) {
                if (strcmp(s_ID, p2->ID) == 0) {
                    flag = 1;
                    printf("\n\n");

                    p2 = head;

                    printf("\t\t\t\t   ╭════════════════════════════════════════════╮\n");
                    printf("\t\t\t\t   │                 修改商品信息               │\n");
                    printf("\t\t\t\t   ╰════════════════════════════════════════════╯\n");
                    printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 1.种类：%s             			│\n", p2->type);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 2.名称：%s            			│\n", p2->ID);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 3.价格：%s              		\t│\n", p2->price);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 4.库存：%d            			│\n", p2->amount);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 5.销量：%d             			│\n", p2->sale);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 6.销售时间:%s            		        │\n", p2->saletime);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 7.产地：%s            			│\n", p2->buyer);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 8.生产日期:	%s            		        │\n", p2->date);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 9.保质期：%s             		\t│\n", p2->day);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   └────────────────────────────────────────────┘\n");

                    fflush(stdin);

                    printf("请输入要修改的内容选项(前面的数字)：\n");
                    scanf("%d", &content1);

                    switch (content1) {
                        case 1:
                            printf("请输入商品编号：\n");
                            scanf("%s", p1->number);
                            break;

                        case 2:
                            printf("请输入商品种类：\n");
                            scanf("%s", p1->type);
                            break;


                        case 3:
                            printf("请输入商品价格：\n");
                            scanf("%s", &p2->price);
                            break;


                        case 4:
                            printf("请输入商品库存：\n");
                            scanf("%d", &p1->amount);
                            break;


                        case 5:
                            printf("请输入商品销量：\n");
                            scanf("%d", &p1->sale);
                            break;

                        case 6:
                            printf("请输入商品销售日期：\n");
                            scanf("%s", p1->saletime);
                            break;

                        case 7:
                            printf("请输入商品产地：\n");
                            scanf("%s", p1->buyer);
                            break;

                        case 8:
                            printf("请输入商品生产日期：\n");
                            scanf("%s", p1->date);
                            break;

                        case 9:
                            printf("请输入商品保质期：\n");
                            scanf("%s", p1->day);
                            break;

                        default:
                            printf("输入错误，请重新输入：\n");
                            system("pause");
                            break;

                    }

                }


                p2 = p2->next;

            }

            if (flag == 0) {
                printf("无该商品相关信息. . .");
                printf("\n");
                break;
            }





            printf("修改成功！\n");
            printf("\t\t\t请问要接着修改吗？\n");
            printf("\t\t\t1.是的。\n\t\t\t2.退出修改");
            scanf("%d", &opt_c);
            switch (opt_c) {
                case 1:
                    //TODO
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    //TODO
                    opt_c = 3;
                    system("pause");
                    system("cls");
                    break;
                default:
                    printf("输入错误，已经自动为你退出");//TODO
                    opt_c = 3;
                    system("pause");
                    system("cls");
                    break;
            }



        }


        else if (opt_c == 3 ) {
            printf("成功退出修改！\n");
            return;
        } else {
            printf("输入错误、已退出！\n");
            system("pause");
            system("cls");
            return;
        }

    }
}




void delInformation() {
    SHOP *p2;//判断的当前节点
    SHOP *pb;//要删除的节点数据
    SHOP *pf;//要删除的节点的前趋节点

    p2 = head;
    pf = head;
    pb = head;

    int ture;
    int flag;//判断真假

    int option;//用户输入的选项
    int s_option;//判断选项

    char S_id[20];//临时存放名称
    char s_num[10];//临时存放编号


    printf("\n");
    printf("\t\t\t\t\t\t┌-----------------┐\n");;
    printf("\t\t\t\t\t\t |1.编号查询删除  |\n");
    printf("\t\t\t\t\t\t |2.名称查询删除  |\n");
    printf("\t\t\t\t\t\t |3.退出删除      |\n");
    printf("\t\t\t\t\t\t└-----------------┘\n");

    rewind(stdin);
    printf("请选择：");
    scanf("%s", &option);


    switch (option) {

        case '1'://编号删除

            system("pause");
            system("cls");

            p2 = head;

            printf("\n\n");
            printf("\t\t\t\t   │=========================================== │\n");
            printf("\t\t\t\t   │ 请输入编号：             		        │\n");
            printf("\t\t\t\t   │=========================================== │\n");

            cursor(54, 3);
            scanf("%s", &s_num);

            while (pb != NULL ) {

                if (strcmp(s_num, pb->number) == 0) {
                    flag = 1;
                    printf("\n\n");
                    printf("\t\t\t\t   ╭════════════════════════════════════════════╮\n");
                    printf("\t\t\t\t   │                   商品信息               │\n");
                    printf("\t\t\t\t   ╰════════════════════════════════════════════╯\n");
                    printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 种类：%s             			│\n", p2->type);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 名称：%s            			│\n", p2->ID);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 价格：%s              		\t│\n", p2->price);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 库存：%d            			│\n", p2->amount);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 销量：%d             			│\n", p2->sale);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 销售时间:%s            		        │\n", p2->saletime);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 产地：%s            			│\n", p2->buyer);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 生产日期:	%s            		        │\n", p2->date);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 保质期：%s             		\t│\n", p2->day);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   └────────────────────────────────────────────┘\n");


                    printf("是否选择删除?\n");
                    printf("1.yse	2.no\n");


                    printf("请选择：");
                    scanf("%d", &s_option);


                    if (s_option == 1) {

                        if (pb == head) { //判断pb是否指向头结点
                            head = head->next;
                        } else {
                            pf->next = pb->next; //让pf的下一个节点等于pb的下一个节点
                        }





                        printf("数据删除成功！");
                        saveInformation();//更新文件信息


                    } else if (s_option == 2) {
                        printf("取消删除!");
                    }
                }

                pf = pb;
                pb = pb->next;

            }
            if (flag == 0) {
                printf("无该商品相关信息. . .");
                printf("\n");
            }

            break;

        case '2':

            system("pause");
            system("cls");

            p2 = head;

            printf("\n\n");
            printf("\t\t\t\t   │=========================================== │\n");
            printf("\t\t\t\t   │ 请输入名称：             		        │\n");
            printf("\t\t\t\t   │=========================================== │\n");

            cursor(54, 3);
            scanf("%s", &S_id);

            while (pb != NULL ) {

                if (strcmp(S_id, pb->ID) == 0) {

                    flag = 1;
                    printf("\n\n");
                    //p2 = head;
                    printf("\t\t\t\t   ╭════════════════════════════════════════════╮\n");
                    printf("\t\t\t\t   │                   商品信息               │\n");
                    printf("\t\t\t\t   ╰════════════════════════════════════════════╯\n");
                    printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 种类：%s             			│\n", p2->type);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 名称：%s            			│\n", p2->ID);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 价格：%s              		\t│\n", p2->price);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 库存：%d            			│\n", p2->amount);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 销量：%d             			│\n", p2->sale);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 销售时间:%s            		        │\n", p2->saletime);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 产地：%s            			│\n", p2->buyer);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 生产日期:	%s            		        │\n", p2->date);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   │ 保质期：%s             		\t│\n", p2->day);
                    printf("\t\t\t\t   │==========================================	│\n");
                    printf("\t\t\t\t   └────────────────────────────────────────────┘\n");


                    printf("是否选择删除?\n");
                    printf("1.yse	2.no\n");

                    printf("请选择：");
                    scanf("%d", &s_option);

                    if (s_option == 1) {

                        if (pb == head) { //判断pb是否指向头结点
                            head = head->next;
                        } else {
                            pf->next = pb->next; //让pf的下一个节点等于pb的下一个节点
                        }




                        printf("数据删除成功！");
                        saveInformation();//更新文件信息

                    } else if (s_option == 0) {
                        printf("取消删除!");
                    } else {
                        printf("输入错误，请重新输入\n");
                        continue;
                    }
                }

                pf = pb;
                pb = pb->next;

            }
            if (flag == 0) {
                printf("无该商品相关信息. . .");
                printf("\n");
            }

            break;

        case '3':	//退出删除
            printf("使用over！\n");
            break;

        default:
            printf("输入错误，已退出！\n");
            system("pause");
            system("cls");
            break;

    }

}
void sortInformation() {
    char chose;		//用户选项

    SHOP *pb;
    SHOP *pf;
    SHOP temp;	//临时存放数据地址
    SHOP *p2;	//定义临时节点指针变量

    p2 = head;

    while (chose != '3') {

        printf("\n");
        printf("\t\t\t\t\t\t┌================┐\n");;
        printf("\t\t\t\t\t\t |1、依据库存排序|\n");
        printf("\t\t\t\t\t\t |2、依据价格排序|\n");
        printf("\t\t\t\t\t\t |3、退出        |\n");
        printf("\t\t\t\t\t\t└================┘\n");
        printf("\t\t\t\t\t\t");
        printf("请选择：");
        scanf("%s", &chose);

        //库存数量进行排序
        if (chose == '1') {
            p2 = head;
            if (p2 == NULL) {
                //链表为空
                printf("无相关数据. . .\n");
                return ;

            }

            if (p2->next == NULL) {
                //链表有1个节点
                printf("数据仅存在一条\n");
                return ;
            }

            while (p2->next != NULL) {	//p2的下一个节点不为空
                pb = p2->next;	//将该节点数据赋值给pb

                while (pb != NULL) { //pb不为空
                    //从小到大排序
                    //冒泡排序

                    if (p2->amount > pb->amount) { //pb与p2进行比较

                        //交换数据
                        temp = *p2;	//取amount的值进行交换 放在临时空间
                        *p2 = *pb;	//pb的数据给p2
                        *pb = temp;	//临时存放的数据给pb

                        //将临时申请的节点与原有的链表节点进行连接
                        temp.next = p2->next;
                        p2->next = pb->next;
                        pb->next = temp.next;

                    }
                    pb = pb->next;//pb指向尾
                }
                p2 = p2->next;//p2指向尾
            }
            printf("排序成功！请返回打印查看. . .\n");
            system("pause");
            system("cls");
        }


            //价格进行排序
        else if (chose == '2') {

            p2 = head;

            if (p2 == NULL) {
                //链表为空
                printf("无相关数据\n");
                system("pause");
                system("cls");
                return ;

            }

            if (p2->next == NULL) {
                //链表有1个节点
                printf("数据仅存在一条\n");
                system("pause");
                system("cls");
                return ;
            }

            while (p2->next != NULL) { //以p2指向的节点为基准节点
                pb = p2->next;//pb从基准点的下一个节点开始
                while (pb != NULL) {
                    //从小到大排序
                    //冒泡排序
                    if (p2->price > pb->price) {
                        temp = *p2;
                        *p2 = *pb;
                        *pb = temp;
                        temp.next = p2->next;
                        p2->next = pb->next;
                        pb->next = temp.next;

                    }
                    pb = pb->next;
                }
                p2 = p2->next;
            }

            printf("排序成功！请返回打印查看. . .\n");
            system("pause");
            system("cls");

        }

            //退出
        else if (chose == '3') {
            system("pause");
            system("cls");
            break;
            //return 1;
        } else {
            printf("输入错误请重新输入！\n");
            system("pause");

        }

    }


}
void findOrderInformation(userInf loginUser) {
    OrderMenu(loginUser);
}
