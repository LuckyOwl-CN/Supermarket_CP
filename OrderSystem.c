//
// Created by hp on 2022/7/15.
//

#include "IntegralSystem.h"

int order_NumOfUser = 0;
int order_NumOfProduct = 0;
int order_GoodsInOrder[20] = {0}; //表示不同用户的订单个数
int order_Position = -1;     //登录成功者在结构体中的位置

int userLoad(userInf user[]){

    char account[20];
    char password[20];
    printf("请输入账号： \n");
    scanf("%s",account);
    fflush(stdin);
    printf("请输入密码： \n");
    scanf("%s",password);
    fflush(stdin);
    int i = 0;
    for(i = 0;i < order_NumOfUser;i++){

        if((strcmp(account,user[i].userAccount) == 0) &&(strcmp(password,user[i].userPassword) == 0)){

            order_Position = i;
            return 1;

        }


    }

    return -1;

}

void userWrite(userInf user[]){


    FILE *fp = fopen("user.txt","w+");
    if(fp==NULL)
    {
        printf("打开文件失败\n");
    }
    fflush(stdin);
    int i = 0;

    for(i = 0;i < order_NumOfUser;i++){

        fprintf(fp,"%s\t%s\t%d\n",user[i].userAccount,user[i].userPassword,
                user[i].userPermission);


    }

    fclose(fp);
    printf("写入 %d 条记录到文件%s\n\n", order_NumOfUser, "user.txt");


}

void userRegister(userInf user[]){

    printf("请设置账号 : ");
    char account[20];
    scanf("%s",account);
    fflush(stdin);
    strcpy(user[order_NumOfUser].userAccount,account);

    printf("请设置密码 : ");
    char password[20];
    scanf("%s",password);
    fflush(stdin);
    strcpy(user[order_NumOfUser].userPassword,password);

    printf("请设置身份 1用户 2管理员 3超管 ： ");
    int permission;
    scanf("%d",&permission);
    fflush(stdin);
    user[order_NumOfUser].userPermission = permission;
    order_NumOfUser++;
    userWrite(user);

    printf("您已经注册成功，请登录\n");


}

void goodsWrite(goods good[]){

    FILE *fp = fopen("goods.txt","w+");
    if(fp==NULL)
    {
        printf("打开文件失败\n");
    }
    fflush(stdin);
    int i = 0;
    for(i = 0;i < order_NumOfProduct;i++){

        fprintf(fp,"%s\t%d\t%d\n",good[i].name,good[i].num,
                good[i].price);

    }

    fclose(fp);
    printf("写入 %d 条记录到文件%s\n\n", order_NumOfProduct, "goods.txt");

}


void addGoods(goods good[]){

    char name[20];
    int num;
    int price;
    printf("请输入商品名称：  ");
    scanf("%s",name);
    fflush(stdin);

    int i = 0;
    int flag = -1;
    for(i = 0;i < order_NumOfProduct;i++){

        if(strcmp(name,good[i].name) == 0){

            flag = i;
            break;

        }

    }

    if(flag != -1){

        printf("该商品已经被设置过了，请输入要新增的数量：");
        scanf("%d",&num);
        fflush(stdin);
        good[flag].num += num;
        printf("添加商品成功\n");
        goodsWrite(good);

    }
    else{

        strcpy(good[order_NumOfProduct].name,name);
        printf("请输入商品数量：  ");
        scanf("%d",&num);
        fflush(stdin);
        good[order_NumOfProduct].num = num;
        printf("请输入商品价格：  ");
        scanf("%d",&price);
        fflush(stdin);
        good[order_NumOfProduct].price = price;

        order_NumOfProduct++;

        printf("添加商品成功\n");
        goodsWrite(good);


    }



}

void orderWrite(userInf user[]){

    FILE *fp = fopen("order.txt","w+");
    if(fp==NULL)
    {
        printf("打开文件失败\n");
    }
    fflush(stdin);
    int i = 0;
    int j = 0;
    for(i = 0;i < order_NumOfUser;i++){


        if(order_GoodsInOrder[i] != 0){

            for(j = 0;j < order_GoodsInOrder[i];j++){

                fprintf(fp,"%d\t%s\t%d\n",i,user[i].order[j].name,user[i].order[j].number);
            }


        }

    }

    fclose(fp);


}

void buyGoods(goods good[],userInf user[]){

    int permission = 0;
    permission = user[order_Position].userPermission;
    if(permission == 1)
    {

        printf("请输入要购买的商品名称：");
        int i = 0;
        char nameOfGood[20];
        int count = -1;
        while(1)
        {

            scanf("%s",nameOfGood);
            fflush(stdin);
            for(i = 0;i < order_NumOfProduct;i++){

                if(strcmp(good[i].name , nameOfGood) == 0){

                    count = i;
                    break;

                }

            }


            if(count != -1){

                break;

            }
            else{

                printf("输入商品名称错误，请重新输入\n");

            }

        }

        printf("请输入你想购买几件该商品：");

        int number;
        while(1){

            scanf("%d",&number);
            fflush(stdin);
            if((number <= good[count].num)&&(number > 0)){

                printf("恭喜你购买成功\n");
                good[count].num -= number;
                goodsWrite(good);
                break;
            }

            else if(number <= 0){

                printf("要买的话至少一件哦\n");
                printf("请重新选择购买数量\n");

            }

            else{

                printf("该商品现有%d件，但你选择购买%d个\n",good[count].num,number);
                printf("请重新选择购买数量\n");

            }
        }

        if(count != -1){

            int flag = -1;
            int j = 0;
            for(j = 0;j < order_GoodsInOrder[order_Position];j++){

                if(strcmp(nameOfGood,user[order_Position].order[j].name) == 0){

                    flag = j;
                    break;

                }

            }//保证之前买过的商品不产生新的订单;

            if(flag == -1){

                user[order_Position].order[order_GoodsInOrder[order_Position]].number += number;
                strcpy(	user[order_Position].order[order_GoodsInOrder[order_Position]].name,nameOfGood );
                order_GoodsInOrder[order_Position]++;

            }
            else{

                user[order_Position].order[flag].number += number;

            }

            orderWrite(user);

        }

    }

    else{

        printf("很抱歉，只有用户可以购买商品\n");

    }




}

void deleteSingleOrder(goods good[],userInf user[]){

    int permission = 0;
    permission = user[order_Position].userPermission;
    if(permission == 1){

        printf("请选择你要删除第几个订单：");
        while(1){

            int num ;
            int count = 0;
            scanf("%d",&num);
            fflush(stdin);
            char flagname[20];
            if((num <= order_GoodsInOrder[order_Position])&&(num > 0))  {

                int i = 0;
                if( num == order_GoodsInOrder[order_Position]){

                    strcpy(flagname,user[order_Position].order[order_GoodsInOrder[order_Position]-1].name);
                    count = user[order_Position].order[order_GoodsInOrder[order_Position]-1].number;
                    order_GoodsInOrder[order_Position]--;


                }
                else{

                    strcpy(flagname,user[order_Position].order[num - 1].name);
                    count = user[order_Position].order[num - 1].number;
                    for(i = num - 1;i < order_GoodsInOrder[order_Position] - 1;i++){

                        user[order_Position].order[i] = user[order_Position].order[i + 1];

                    }

                    order_GoodsInOrder[order_Position]--;


                }

                for(i = 0;i < order_NumOfProduct;i ++){

                    if(strcmp(flagname,good[i].name) == 0){

                        printf("****%d有多少****\n",count);
                        good[i].num += count;

                    }

                }
                orderWrite(user);
                goodsWrite(good);
                printf("删除成功\n");
                break;

            }

            else if(num <= 0){

                printf("输入错误，订单应该从第一个算起\n");
                break;

            }
            else{

                printf("没有这么多订单，请重新选择\n");
                break;

            }

        }

    }

    else{

        printf("很抱歉，只有用户可以删除商品\n");

    }



}

void showOrderByUserName(userInf user[],goods good[]){

    int i = 0;
    int j = 0;
    int count = -1;
    while(1){

        printf("请输入该用户的账号：");
        char account[20];
        scanf("%s",account);
        fflush(stdin);
        printf("请输入该用户的密码：");
        char password[20];
        scanf("%s",password);
        fflush(stdin);
        for(i = 0;i < order_NumOfUser ;i ++){

            if((strcmp(account,user[i].userAccount) == 0) &&(strcmp(password,user[i].userPassword)==0)){

                count = i;
                break;

            }

        }

        if(count != -1){

            printf("查找成功\n");
            break;
        }
        else{

            printf("查找失败\n");
            break;

        }

    }

    int totalPrice = 0;
    for(i = 0;i < order_GoodsInOrder[count];i++){

        for(j = 0;j < order_NumOfProduct;j++){

            if(strcmp(user[count].order[i].name,good[j].name) == 0){

                totalPrice += user[count].order[i].number * good[j].price;

            }

        }

    }

    for(i = 0;i < order_GoodsInOrder[count];i ++){

        printf("第%d个账单信息为：\n",i+1);
        printf("商品名称：%s\n",user[count].order[i].name);
        printf("购买数量为：%d\n",user[count].order[i].number);

    }
    if(count != -1){

        printf("已买商品的总价为：%d\n",totalPrice);

    }


}

void showGoodsInfor(goods good[]){

    int i = 0;
    for(i = 0;i < order_NumOfProduct;i++){

        printf("第%d个商品的名称是：%s\n",i+1,good[i].name);
        printf("第%d个商品的数量是：%d\n",i+1,good[i].num);
        printf("第%d个商品的价格是：%d\n\n",i+1,good[i].price);

    }

}


void deleteUserAndOrder(userInf user[],goods good[]){

    printf("请输入要删除的用户的账号：");
    char account[20];
    scanf("%s",account);
    fflush(stdin);
    printf("请输入要删除的用户的密码：");
    char password[20];
    scanf("%s",password);
    fflush(stdin);

    int i = 0;
    int j = 0;
    int k = 0;
    int flag = -1;
    for(i = 0;i < order_NumOfUser;i++){

        if((strcmp(user[i].userAccount,account)==0)&&(strcmp(user[i].userPassword,password)==0)){

            flag = i;
            for(j = 0;j < order_NumOfProduct;j++){

                for(k = 0;k < order_GoodsInOrder[i];k++){

                    if(strcmp(user[i].order[k].name,good[j].name)==0){

                        good[j].num += user[i].order[k].number;

                    }


                }

            }//将被删除用户的已购物品数量返还给商品
            goodsWrite(good);

            break;

        }

    }

    if(flag != -1){

        if(order_NumOfUser == 1){

            order_NumOfUser--;
            order_GoodsInOrder[0] = 0;

        }
        else{

            for(i = flag;i < order_NumOfUser - 1;i++){

                strcpy(user[i].userAccount,user[i+1].userAccount);
                strcpy(user[i].userPassword,user[i+1].userPassword);
                user[i].userPermission = user[i+1].userPermission;
                order_GoodsInOrder[i] = order_GoodsInOrder[i+1];

                for(j = 0;j < order_GoodsInOrder[i+1];j++){


                    strcpy(user[i].order[j].name,user[i+1].order[j].name);
                    user[i].order[j].number = user[i+1].order[j].number;

                }


            }

            order_NumOfUser--;

        }

        userWrite(user);
        orderWrite(user);

    }


}

void userFunction(userInf user[],goods good[]){


    int flag = 1;
    while(flag == 1){

        printf("*************************              *************************\n");
        printf("请选择操作 1：购买商品 2：删除商品 3：显示某某的商品信息 4：返回上一步   \n");
        printf("由于没有管理员，所以设置选项 5 为添加商品，6 为显示所有商品信息 7 为删除用户\n");
        printf("*************************              *************************\n\n");
        printf("你的选择是：");
        int choice = 0;
        scanf("%d",&choice);
        switch(choice){

            case 1:
                buyGoods(good,user);
                system("PAUSE");
                break;
            case 2:
                deleteSingleOrder(good,user);
                system("PAUSE");
                break;
            case 3:
                showOrderByUserName(user,good);
                system("PAUSE");
                break;
            case 4:
                flag = 0;
                break;
            case 5:
                addGoods(good);
                system("PAUSE");
                break;
            case 6:
                showGoodsInfor(good);
                system("PAUSE");
                break;
            case 7:
                deleteUserAndOrder(user,good);
                system("PAUSE");
                break;
            default :
                printf("输入错误，请重新输入\n");
                break;

        }

    }

}

void readFromFile(userInf user[],goods good[]){

    //读用户信息

    FILE *fp1 = fopen("user.txt", "r");
    if(fp1 == NULL)
    {
        printf("打开文件错误\n");
    }



    while(fscanf(fp1,"%s%s%d",user[order_NumOfUser].userAccount,user[order_NumOfUser].userPassword,
                 &user[order_NumOfUser].userPermission)!=EOF){

        /*printf("%s\t%s\t%d\n",user[numOfUser].userAccount,user[numOfUser].userPassword,
                            user[numOfUser].userPermission);*/
        order_NumOfUser++;

    }


    fclose(fp1);
    printf("有%d个用户被读入\n",order_NumOfUser);

    //读订单信息
    FILE *fp2 = fopen("goods.txt", "r");
    if(fp2 == NULL)
    {
        printf("打开文件错误\n");
    }

    while(fscanf(fp2,"%s%d%d",good[order_NumOfProduct].name,
                 &good[order_NumOfProduct].num,&good[order_NumOfProduct].price)!=EOF){

        /* printf("%s\n\n",good[numOfProduct].name);
         printf("%d\n\n",good[numOfProduct].price);
         printf("%d\n\n",good[numOfProduct].num);*/


        order_NumOfProduct++;

    }

    fclose(fp2);
    printf("有%d个商品被读入\n",order_NumOfProduct);

    FILE *fp3 = fopen("order.txt","r");
    if(fp3==NULL){

        printf("打开文件错误\n");

    }

    int count;
    char name[20];
    int num;
    while(fscanf(fp3,"%d%s%d", &count,name,&num)!=EOF){


        user[count].order[order_GoodsInOrder[count]].number = num;
        strcpy(user[count].order[order_GoodsInOrder[count]].name,name);
        order_GoodsInOrder[count]++;


    }
    int i = 0;
    for(i = 0;i < order_NumOfUser;i++){
        printf("第%d个用户读入%d个订单\n",i+1,order_GoodsInOrder[i]);

    }
    fclose(fp3);


}

void OrderMenu(userInf loginUser){

    int flag = 1;
    int userflag = 0;
    userInf user[20];
    goods good[30];
    readFromFile(user,good);
    while(flag == 1){


        printf("***************             ****************\n");
        printf("              欢迎进入超市系统             \n");
        printf("	  请选择 1：登录 2：注册 3：退出系统       \n");
        printf("***************             ****************\n\n");
        printf("你的选择是：");
        int choice;
        scanf("%d",&choice);
        switch(choice){

            case 1:
                userflag = userLoad(user);
                break;
            case 2:
                userRegister(user);
                break;
            case 3:
                flag = 0;
                break;
            default :
                printf("输入错误，请重新输入\n");
                break;


        }

        if(choice == 1){

            if(userflag == 1){

                printf("恭喜你登陆成功\n");
                userFunction(user,good);

            }
            else{

                printf("登陆失败，请重新选择操作\n");
            }

        }

        if(choice == 2){

            userflag = userLoad(user);
            if(userflag == 1){

                printf("恭喜你登陆成功\n");
                userFunction(user,good);

            }
            else{

                printf("登陆失败，请重新选择操作\n");
            }

        }


    }

}
