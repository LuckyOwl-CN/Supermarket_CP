#include "IntegralSystem.h"

ListNode *userInf_head;

void AddUser(int);
void DeleteUser(char[],int);
void ChangeUser(char[],int);
void SearchUser(char[],int);

void UserMenu(){
    userInf_head = loadList();
    int loginState = 0; /* 0为未登录/1为用户/2为管理员/3为超级管理员 */
    userInf loginUser;
    while(1){
        if(!loginState){
            printf("[系统]当前未登录,请输入：1)登录 2)注册 3)退出:");
            int ichoice;
            scanf("%d",&ichoice);
            switch (ichoice) {
                default:
                    return;
                case 1:
                    loginUser = UserLogin();
                    loginState = loginUser.userPermission;
                    break;
                case 2:
                    UserRegist(0);
                    break;
                case 4:
                    printList(userInf_head);
                    break;
            }
        }

        while(loginState) {
            printf("[用户:%s]请输入 1)功能 2)登出:",loginUser.userAccount);
            int ichoice;
            scanf("%d",&ichoice);
            switch (ichoice) {
                default:
                    break;
                case 1:
                    switch (loginState) {
                        default:
                            printf("[系统]输入错误");
                            break;
                        case 1:
                            Customer_Opr(loginUser);
                            //printf("Customer\n");
                            break;
                        case 2:
                            Manager_Opr(loginUser);
                            //printf("Manager\n");
                            break;
                        case 3:
                            SManager_Opr(loginUser);
                            //printf("SManager\n");
                            break;
                    }
                    break;
                case 2:
                    loginUser = UserLogout();
                    loginState = loginUser.userPermission;
                    break;
            }
        }
    }
}

void UserUpdate(ListNode* head){
    saveList(head);
}

void UserRegist(int registPermission)
{
    userInf a;
    char temp[20];
    printf("[注册]请输入账号:");
    scanf("%s", &a.userAccount);
    ListNode *p = userInf_head -> next;
    while(p != NULL){
        if(strcmp(a.userAccount,p->data.userAccount)){
            p = p -> next;
        } else{
            printf("[系统]此账号已存在！请重新注册！\n");
            return;
        }
    }
    printf("[注册]请输入密码:");
    scanf(" %s", &a.userPassword);
    printf("[注册]请确认密码:");
    scanf(" %s", &temp);
    do {
        if (!strcmp(a.userPassword, temp)) {
            if(registPermission == 1){
                a.userPermission = registPermission;
            }
            else if(registPermission == 2){
                printf("[注册]请输入权限等级 1)顾客 2)管理员:");
                scanf("%d",&a.userPermission);
                while(a.userPermission != 1 && a.userPermission != 2){
                    printf("[注册]请输入权限等级 1)顾客 2)管理员:");
                    scanf("%d",&a.userPermission);
                }
            }
            else{
                printf("[注册]请输入权限等级 1)顾客 2)管理员 3)超级管理员:");
                scanf("%d",&a.userPermission);
                while(a.userPermission < 1 || a.userPermission > 3){
                    printf("[注册]请输入权限等级 1)顾客 2)管理员 3)超级管理员:");
                    scanf("%d",&a.userPermission);
                }
            }
            a.userIntegral = 0;
            addList(userInf_head,a);
            UserUpdate(userInf_head);
            printf("[系统]账号注册成功，请登录！\n");
            return;
        } else {
            printf("[系统]两次密码不匹配！请重新输入！\n");
            scanf("%s", &a.userPassword);
            printf("[系统]请确认密码\n");
            scanf("%s", &temp);
        }
    } while (1);
}

userInf UserLogin()
{
    userInf a = {"","",0},b;
    printf("[登录]请输入账号:");
    scanf("%s",&a.userAccount);
    ListNode *p = userInf_head -> next;
    while(1){
        if(p == NULL){
            printf("[系统]此用户名不存在，请重新输入！\n");
            return a;
        } else{
            if(!strcmp(a.userAccount,p->data.userAccount)){
                break;
            } else{
                p = p -> next;
            }
        }
    }
    printf("[登录]请输入密码:");
    scanf("%s",&a.userPassword);
    do{
        if (strcmp(a.userPassword, p->data.userPassword)==0)            /*如果密码匹配*/
        {
            a.userPermission = p->data.userPermission;
            printf("[用户:%s]登录成功,欢迎使用!\n",a.userAccount);
            return a;
        }
        else
        {    printf("[系统]密码不正确!请重新输入密码:");
            scanf("%s",&a.userPassword);
        }
    }while(strcmp(a.userPassword, p->data.userPassword)==0);
}

userInf UserLogout(){
    userInf a = {"","",0};
    printf("[系统]用户已登出!\n");
    return a;
}

void Customer_Opr(userInf loginUser){
    while(1){
        printf("[顾客:%s]请输入 1)商品界面 2）我的积分 3)返回上级:",loginUser.userAccount);
        int ichoice;
        scanf("%d",&ichoice);
        switch (ichoice) {
            default:
                IntegralMenu(loginUser);
                return;
            case 1:
                //顾客商品界面
                return;
        }
    }
}

void Manager_Opr(userInf loginUser){
    while(1){
        printf("[管理员:%s]请输入 1)增加顾客 2)删除顾客 3)更改顾客 4)查询顾客 5)商品菜单 6)用户积分 7)退出:",loginUser.userAccount);
        int ichoice;
        scanf("%d",&ichoice);
        switch (ichoice) {
            default:
                return;
            case 1:
                AddUser(1);
                break;
            case 2:
                DeleteUser(loginUser.userAccount,1);
                break;
            case 3:
                ChangeUser(loginUser.userAccount,1);
                break;
            case 4:
                SearchUser(loginUser.userAccount,1);
                break;
            case 5:
                system("cls"); //清屏
                M_CommodityMenu(loginUser);
                break;
            case 6:
                IntegralMenu(loginUser);
                break;
        }
    }
}

void SManager_Opr(userInf loginUser){
    while(1){
        printf("[超级管理员:%s]请输入 1)增加用户 2)删除用户 3)更改用户 4)查询用户 5)商品菜单 6)用户积分 7)退出:",loginUser.userAccount);
        int ichoice;
        scanf("%d",&ichoice);
        switch (ichoice) {
            default:
                return;
            case 1:
                AddUser(2);
                break;
            case 2:
                DeleteUser(loginUser.userAccount,2);
                break;
            case 3:
                ChangeUser(loginUser.userAccount,2);
                break;
            case 4:
                SearchUser(loginUser.userAccount,2);
                break;
            case 5:
                system("cls"); //清屏
                M_CommodityMenu(loginUser);
                break;
            case 6:
                IntegralMenu(loginUser);
        }
    }
}

void AddUser(int permissionLevel){
    UserRegist(permissionLevel);
}

void DeleteUser(char loginAccount[20], int permissionLevel){
    userInf a;
    printf("[删除]请输入账号:");
    scanf("%s",&a.userAccount);

    ListNode *p = userInf_head -> next;
    while (1)
    {
        if(p == NULL){
            printf("[系统]此用户名不存在，请重新输入！\n");
            return;
        }
        else{
            if((!strcmp(a.userAccount, p->data.userAccount))){
                if(p->data.userPermission <= permissionLevel){
                    deleteList(userInf_head,p->data);
                    printf("[系统]已经删除用户:%s\n",a.userAccount);
                    saveList(userInf_head);
                }
                else{
                    printf("[管理员:%s]权限不足!\n",loginAccount);
                }
                return;
            }
            else {
                p = p ->next;
            }
        }
    }
}

void ChangeUser(char loginAccount[20], int permissionLevel){
    userInf a;
    printf("[修改]请输入账号:");
    scanf("%s",&a.userAccount);

    ListNode *p = userInf_head -> next;
    while (1)
    {
        if(p == NULL){
            printf("[系统]此用户名不存在，请重新输入！\n");
            return;
        }
        else{
            if ((!strcmp(a.userAccount, p->data.userAccount)))         //如果有此用户名且权限等级为顾客
            {
                if(p->data.userPermission <= permissionLevel){
                    while(1){
                        printf("[用户:%s]密码:%s 积分:%d\n",p->data.userAccount,p->data.userPassword,p->data.userIntegral);
                        printf("[管理员:%s]请输入修改用户%s的操作:1)修改密码 2)返回上级:",loginAccount,p->data.userAccount);
                        int ichoice;
                        scanf("%d",&ichoice);
                        switch (ichoice) {
                            default:
                                return;
                            case 1:
                                printf("[系统]请输入修改后的密码:");
                                scanf("%s",p->data.userPassword);
                                break;
                        }
                        saveList(userInf_head);
                    }
                } else{
                    printf("[管理员:%s]权限不足!\n",loginAccount);
                }
                return;
            }
            else {
                p = p ->next;
            }
        }
    }
}

void SearchUser(char loginAccount[20], int permissionLevel){
    userInf a;
    printf("[查询]请输入账号:");
    scanf("%s",&a.userAccount);

    ListNode *p = userInf_head -> next;
    while(1){
        if(p == NULL){
            printf("[系统]此用户名不存在，请重新输入！\n");
            break;
        } else{
            if(!strcmp(p->data.userAccount,a.userAccount)){
                if(p->data.userPermission <= permissionLevel){
                    printf("[用户:%s]密码:%s 积分:%d\n",p->data.userAccount,p->data.userPassword,p->data.userIntegral);
                } else{
                    printf("[管理员:%s]权限不足!\n",loginAccount);
                }
                break;
            } else{
                p = p->next;
            }
        }
    }
}
