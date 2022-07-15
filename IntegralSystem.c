//
// Created by hp on 2022/7/14.
//
#include "IntegralSystem.h"

ListNode *integralInf_head;

void IntegralMenu(userInf loginUser){
    integralInf_head = loadList(); //读取文件
    while(1){
        switch (loginUser.userPermission) {
            default:
                return;
            case 1:
                IntegralC(loginUser);  //进入用户权限下 积分操作
                return;
            case 2:
                IntegralM(loginUser);   //进入管理员权限下 积分操作
                return;
            case 3:
                IntegralS(loginUser);  //进入超级管理员权限下 积分操作
                return;
        }
    }
}

void IntegralC(userInf loginUser){
    printf("[顾客:%s]你的积分为:%d\n", loginUser.userAccount, loginUser.userIntegral);
    return;
}

void IntegralM(userInf loginUser){
    int ichoice;
    ListNode *p = integralInf_head -> next;
    userInf a;
    printf("[管理员:%s]请输入 1)查看积分 2)修改积分 3)返回上级:", loginUser.userAccount);
    scanf("%d",&ichoice);
    switch (ichoice) {
        default:
            return;
        case 1:
            printf("[系统]请输入用户名:");
            scanf("%s",a.userAccount);
            while(1){
                if(p == NULL){
                    printf("[系统]此用户名不存在，请重新输入！\n");
                    return;
                } else{
                    if(!strcmp(a.userAccount,p->data.userAccount)){
                        if(p->data.userPermission == 1){
                            printf("[系统]用户 %s 的积分为:%d\n",p->data.userAccount,p->data.userIntegral);
                        }
                        else{
                            printf("[管理员:%s]权限不足!\n",loginUser.userAccount);
                        }
                        return;
                    } else{
                        p = p -> next;
                    }
                }
            }
        case 2:
            printf("[系统]请输入用户名:");
            scanf("%s",a.userAccount);
            while(1){
                if(p == NULL){
                    printf("[系统]此用户名不存在，请重新输入！\n");
                    return;
                } else{
                    if(!strcmp(a.userAccount,p->data.userAccount)){
                        if(p->data.userPermission == 1){
                            printf("[系统]请输入修改后的积分:");
                            int reset_integral;
                            scanf("%d",&(p->data.userIntegral));
                            printf("[系统]已将用户 %s 的积分修改为:%d\n",p->data.userAccount,p->data.userIntegral);
                            saveList(integralInf_head);
                        }
                        else{
                            printf("[管理员:%s]权限不足!\n",loginUser.userAccount);
                        }
                        return;
                    } else{
                        p = p -> next;
                    }
                }
            }
    }
}

void IntegralS(userInf loginUser){
    int ichoice;
    ListNode *p = integralInf_head -> next;
    userInf a;
    printf("[超级管理员:%s]请输入 1)查看积分 2)修改积分 3)返回上级:", loginUser.userAccount);
    scanf("%d",&ichoice);
    switch (ichoice) {
        default:
            return;
        case 1:
            printf("[系统]请输入用户名:");
            scanf("%s",a.userAccount);
            while(1){
                if(p == NULL){
                    printf("[系统]此用户名不存在，请重新输入！\n");
                    return;
                } else{
                    if(!strcmp(a.userAccount,p->data.userAccount)){
                        printf("[系统]用户 %s 的积分为:%d\n",p->data.userAccount,p->data.userIntegral);
                        return;
                    } else{
                        p = p -> next;
                    }
                }
            }
        case 2:
            printf("[系统]请输入用户名:");
            scanf("%s",a.userAccount);
            while(1){
                if(p == NULL){
                    printf("[系统]此用户名不存在，请重新输入！\n");
                    return;
                } else{
                    if(!strcmp(a.userAccount,p->data.userAccount)){
                        printf("[系统]请输入修改后的积分:");
                        int reset_integral;
                        scanf("%d",&(p->data.userIntegral));
                        printf("[系统]已将用户 %s 的积分修改为:%d\n",p->data.userAccount,p->data.userIntegral);
                        saveList(integralInf_head);
                        return;
                    } else{
                        p = p -> next;
                    }
                }
            }
    }
}

int CashDiscount(int orderamount,userInf loginUser) //返回值为积分结算后订单金额 参数为:原订单金额，登入账户
{
    if(loginUser.userIntegral >= orderamount)  //账户积分大于等于订单金额，用积分抵扣
    {
        loginUser.userIntegral = loginUser.userIntegral - orderamount;
        return 0;
    }
    else  //账户积分小于订单金额，获得本订单金额10%的积分
    {
        loginUser.userIntegral = loginUser.userIntegral + 0.1*orderamount;
        return orderamount;
    }
}
