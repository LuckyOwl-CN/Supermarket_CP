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
            printf("[超市系统]当前未登录,请输入：1)登录 2)注册 3)退出:");
            int ichoice;
            scanf("%d",&ichoice);
            switch (ichoice) {
                default:
                	printf("[超市系统]系统已退出！\n");
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
            printf("[超市系统]用户:%s请输入 1)功能 2)登出:",loginUser.userAccount);
            int ichoice;
            scanf("%d",&ichoice);
            switch (ichoice) {
                default:
                    break;
                case 1:
                    switch (loginState) {
                        default:
                            printf("[超市系统]输入错误");
                            break;
                        case 1:
                            Customer_Opr(loginUser);
                            break;
                        case 2:
                            Manager_Opr(loginUser);
                            break;
                        case 3:
                            SManager_Opr(loginUser);
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
    printf("[超市系统]注册|请输入账号名:");
    scanf("%s", &a.userAccount);
    ListNode *p = userInf_head -> next;
    while(p != NULL){
        if(strcmp(a.userAccount,p->data.userAccount)){
            p = p -> next;
        } else{
            printf("[超市系统]注册|此账号已存在！请重新注册！\n");
            return;
        }
    }
    printf("[超市系统]注册|请输入密码:");
    scanf(" %s", &a.userPassword);
    printf("[超市系统]注册|请确认密码:");
    scanf(" %s", &temp);
    do {
        if (!strcmp(a.userPassword, temp)) {
            if(registPermission == 1){
                a.userPermission = registPermission;
            }
            else if(registPermission == 2){
                printf("[超市系统]注册|请输入权限等级 1)顾客 2)管理员:");
                scanf("%d",&a.userPermission);
                while(a.userPermission != 1 && a.userPermission != 2){
                    printf("[超市系统]注册|请输入权限等级 1)顾客 2)管理员:");
                    scanf("%d",&a.userPermission);
                }
            }
            else{
                printf("[超市系统]注册|请输入权限等级 1)顾客 2)管理员 3)超级管理员:");
                scanf("%d",&a.userPermission);
                while(a.userPermission < 1 || a.userPermission > 3){
                    printf("[超市系统]注册|请输入权限等级 1)顾客 2)管理员 3)超级管理员:");
                    scanf("%d",&a.userPermission);
                }
            }
            a.userIntegral = 0;
            addList(userInf_head,a);
            UserUpdate(userInf_head);
            printf("[超市系统]注册|账号注册成功，请登录！\n");
            return;
        } else {
            printf("[超市系统]注册|两次密码不匹配！请重新输入！\n");
            scanf("%s", &a.userPassword);
            printf("[超市系统]注册|请确认密码\n");
            scanf("%s", &temp);
        }
    } while (1);
}

userInf UserLogin()
{
	int i_password_times = 0; //记录尝试密码的次数 
	int wait_time_max = 10 ; //记录最大等待间隔 
    userInf a = {"","",0},b;
    printf("[超市系统]登录|请输入账号:");
    scanf("%s",&b.userAccount);
    ListNode *p = userInf_head -> next;
    while(1){
        if(p == NULL){
            printf("[超市系统]登录|此用户名不存在，请重新输入！\n");
            return a;
        } else{
            if(!strcmp(b.userAccount,p->data.userAccount)){
                break;
            } else{
                p = p -> next;
            }
        }
    }
    
    do{
    	if(i_password_times == 0){
    		printf("[超市系统]登录|请输入密码:");
    		scanf("%s",&b.userPassword);
		} 
		
		
        if (strcmp(b.userPassword, p->data.userPassword)==0)            /*如果密码匹配*/
        {
            b.userPermission = p->data.userPermission;
            printf("[超市系统]登录|尊敬的用户%s,欢迎使用超市系统!\n",b.userAccount);
            return b;
        }
        else
        {   
			printf("[超市系统]登录|密码不正确!请重新输入密码:");
			scanf("%s",&b.userPassword);
			
			i_password_times++;
			int wait_time = wait_time_max;
			if(i_password_times >= 5){
				while(wait_time > 0){
					
					printf("[超市系统]登录|密码尝试次数过多，请%d秒后重试:\r",wait_time);
					wait_time = wait_time - 1; 
					Sleep(1000);
				}
				
				i_password_times = 0;
				wait_time_max = wait_time_max + 10;
			}
			
        }
    }while(!strcmp(b.userPassword, p->data.userPassword)==0);
}

userInf UserLogout(){
    userInf a = {"","",0};
    printf("[超市系统]用户已登出!\n");
    return a;
}

void Customer_Opr(userInf loginUser){
    while(1){
        printf("[超市系统]顾客:%s请输入 1)商品界面 2）我的积分 3)返回上级:",loginUser.userAccount);
        int ichoice;
        scanf("%d",&ichoice);
        switch (ichoice) {
            default:
                return;
            case 1:
                //顾客商品界面
                C_CommodityMenu(loginUser);
                return;
            case 2:
            	//顾客积分界面
				IntegralMenu(loginUser);
				return; 
        }
    }
}

void Manager_Opr(userInf loginUser){
    while(1){
        printf("[超市系统]管理员:%s请输入 1)增加顾客 2)删除顾客 3)更改顾客 4)查询顾客 5)商品菜单 6)用户积分 7)退出:",loginUser.userAccount);
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
        printf("[超市系统]超级管理员:%s请输入 1)增加用户 2)删除用户 3)更改用户 4)查询用户 5)商品菜单 6)用户积分 7)退出:",loginUser.userAccount);
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
    printf("[超市系统]删除账号|请输入账号名:");
    scanf("%s",&a.userAccount);

    ListNode *p = userInf_head -> next;
    while (1)
    {
        if(p == NULL){
            printf("[超市系统]删除账号|此用户名不存在，请重新输入！\n");
            return;
        }
        else{
            if((!strcmp(a.userAccount, p->data.userAccount))){
                if(p->data.userPermission <= permissionLevel){
                    deleteList(userInf_head,p->data);
                    printf("[超市系统]删除账号|已经删除用户:%s\n",a.userAccount);
                    saveList(userInf_head);
                }
                else{
                    printf("[超市系统]删除账号|管理员:%s权限不足!\n",loginAccount);
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
    printf("[超市系统]修改账号|请输入账号:");
    scanf("%s",&a.userAccount);

    ListNode *p = userInf_head -> next;
    while (1)
    {
        if(p == NULL){
            printf("[超市系统]修改账号|此用户名不存在，请重新输入！\n");
            return;
        }
        else{
            if ((!strcmp(a.userAccount, p->data.userAccount)))         //如果有此用户名且权限等级为顾客
            {
                if(p->data.userPermission <= permissionLevel){
                    while(1){
                        printf("[超市系统]修改账号|用户:%s的信息：密码:%s 积分:%d\n",p->data.userAccount,p->data.userPassword,p->data.userIntegral);
                        printf("[超市系统]修改账号|请输入修改用户%s的操作:1)修改密码 2)返回上级:",p->data.userAccount);
                        int ichoice;
                        scanf("%d",&ichoice);
                        switch (ichoice) {
                            default:
                                return;
                            case 1:
                                printf("[超市系统]修改账号|请输入修改后的密码:");
                                scanf("%s",p->data.userPassword);
                                break;
                        }
                        saveList(userInf_head);
                    }
                } else{
                    printf("[超市系统]修改账号|管理员:%s权限不足!\n",loginAccount);
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
    printf("[超市系统]查询账号|请输入账号:");
    scanf("%s",&a.userAccount);

    ListNode *p = userInf_head -> next;
    while(1){
        if(p == NULL){
            printf("[超市系统]查询账号|此用户名不存在，请重新输入！\n");
            break;
        } else{
            if(!strcmp(p->data.userAccount,a.userAccount)){
                if(p->data.userPermission <= permissionLevel){
                    printf("[超市系统]查询账号|用户:%s的密码:%s 积分:%d\n",p->data.userAccount,p->data.userPassword,p->data.userIntegral);
                } else{
                    printf("[超市系统]查询账号|管理员:%s权限不足!\n",loginAccount);
                } 
                break;
            } 
			else{
                p = p->next;
            }
        }
    }
}
