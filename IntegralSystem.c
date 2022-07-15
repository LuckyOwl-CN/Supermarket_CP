//
// Created by hp on 2022/7/14.
//
#include "IntegralSystem.h"

ListNode *integralInf_head;

void IntegralMenu(userInf loginUser){
    integralInf_head = loadList(); //��ȡ�ļ�
    while(1){
        switch (loginUser.userPermission) {
            default:
                return;
            case 1:
                IntegralC(loginUser);  //�����û�Ȩ���� ���ֲ���
                return;
            case 2:
                IntegralM(loginUser);   //�������ԱȨ���� ���ֲ���
                return;
            case 3:
                IntegralS(loginUser);  //���볬������ԱȨ���� ���ֲ���
                return;
        }
    }
}

void IntegralC(userInf loginUser){
    printf("[�˿�:%s]��Ļ���Ϊ:%d\n", loginUser.userAccount, loginUser.userIntegral);
    return;
}

void IntegralM(userInf loginUser){
    int ichoice;
    ListNode *p = integralInf_head -> next;
    userInf a;
    printf("[����Ա:%s]������ 1)�鿴���� 2)�޸Ļ��� 3)�����ϼ�:", loginUser.userAccount);
    scanf("%d",&ichoice);
    switch (ichoice) {
        default:
            return;
        case 1:
            printf("[ϵͳ]�������û���:");
            scanf("%s",a.userAccount);
            while(1){
                if(p == NULL){
                    printf("[ϵͳ]���û��������ڣ����������룡\n");
                    return;
                } else{
                    if(!strcmp(a.userAccount,p->data.userAccount)){
                        if(p->data.userPermission == 1){
                            printf("[ϵͳ]�û� %s �Ļ���Ϊ:%d\n",p->data.userAccount,p->data.userIntegral);
                        }
                        else{
                            printf("[����Ա:%s]Ȩ�޲���!\n",loginUser.userAccount);
                        }
                        return;
                    } else{
                        p = p -> next;
                    }
                }
            }
        case 2:
            printf("[ϵͳ]�������û���:");
            scanf("%s",a.userAccount);
            while(1){
                if(p == NULL){
                    printf("[ϵͳ]���û��������ڣ����������룡\n");
                    return;
                } else{
                    if(!strcmp(a.userAccount,p->data.userAccount)){
                        if(p->data.userPermission == 1){
                            printf("[ϵͳ]�������޸ĺ�Ļ���:");
                            int reset_integral;
                            scanf("%d",&(p->data.userIntegral));
                            printf("[ϵͳ]�ѽ��û� %s �Ļ����޸�Ϊ:%d\n",p->data.userAccount,p->data.userIntegral);
                            saveList(integralInf_head);
                        }
                        else{
                            printf("[����Ա:%s]Ȩ�޲���!\n",loginUser.userAccount);
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
    printf("[��������Ա:%s]������ 1)�鿴���� 2)�޸Ļ��� 3)�����ϼ�:", loginUser.userAccount);
    scanf("%d",&ichoice);
    switch (ichoice) {
        default:
            return;
        case 1:
            printf("[ϵͳ]�������û���:");
            scanf("%s",a.userAccount);
            while(1){
                if(p == NULL){
                    printf("[ϵͳ]���û��������ڣ����������룡\n");
                    return;
                } else{
                    if(!strcmp(a.userAccount,p->data.userAccount)){
                        printf("[ϵͳ]�û� %s �Ļ���Ϊ:%d\n",p->data.userAccount,p->data.userIntegral);
                        return;
                    } else{
                        p = p -> next;
                    }
                }
            }
        case 2:
            printf("[ϵͳ]�������û���:");
            scanf("%s",a.userAccount);
            while(1){
                if(p == NULL){
                    printf("[ϵͳ]���û��������ڣ����������룡\n");
                    return;
                } else{
                    if(!strcmp(a.userAccount,p->data.userAccount)){
                        printf("[ϵͳ]�������޸ĺ�Ļ���:");
                        int reset_integral;
                        scanf("%d",&(p->data.userIntegral));
                        printf("[ϵͳ]�ѽ��û� %s �Ļ����޸�Ϊ:%d\n",p->data.userAccount,p->data.userIntegral);
                        saveList(integralInf_head);
                        return;
                    } else{
                        p = p -> next;
                    }
                }
            }
    }
}

int CashDiscount(int orderamount,userInf loginUser) //����ֵΪ���ֽ���󶩵���� ����Ϊ:ԭ�����������˻�
{
    if(loginUser.userIntegral >= orderamount)  //�˻����ִ��ڵ��ڶ������û��ֵֿ�
    {
        loginUser.userIntegral = loginUser.userIntegral - orderamount;
        return 0;
    }
    else  //�˻�����С�ڶ�������ñ��������10%�Ļ���
    {
        loginUser.userIntegral = loginUser.userIntegral + 0.1*orderamount;
        return orderamount;
    }
}
