#include "IntegralSystem.h"

ListNode *userInf_head;

void AddUser(int);
void DeleteUser(char[],int);
void ChangeUser(char[],int);
void SearchUser(char[],int);

void UserMenu(){
    userInf_head = loadList();
    int loginState = 0; /* 0Ϊδ��¼/1Ϊ�û�/2Ϊ����Ա/3Ϊ��������Ա */
    userInf loginUser;
    while(1){
        if(!loginState){
            printf("[ϵͳ]��ǰδ��¼,�����룺1)��¼ 2)ע�� 3)�˳�:");
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
            printf("[�û�:%s]������ 1)���� 2)�ǳ�:",loginUser.userAccount);
            int ichoice;
            scanf("%d",&ichoice);
            switch (ichoice) {
                default:
                    break;
                case 1:
                    switch (loginState) {
                        default:
                            printf("[ϵͳ]�������");
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
    printf("[ע��]�������˺�:");
    scanf("%s", &a.userAccount);
    ListNode *p = userInf_head -> next;
    while(p != NULL){
        if(strcmp(a.userAccount,p->data.userAccount)){
            p = p -> next;
        } else{
            printf("[ϵͳ]���˺��Ѵ��ڣ�������ע�ᣡ\n");
            return;
        }
    }
    printf("[ע��]����������:");
    scanf(" %s", &a.userPassword);
    printf("[ע��]��ȷ������:");
    scanf(" %s", &temp);
    do {
        if (!strcmp(a.userPassword, temp)) {
            if(registPermission == 1){
                a.userPermission = registPermission;
            }
            else if(registPermission == 2){
                printf("[ע��]������Ȩ�޵ȼ� 1)�˿� 2)����Ա:");
                scanf("%d",&a.userPermission);
                while(a.userPermission != 1 && a.userPermission != 2){
                    printf("[ע��]������Ȩ�޵ȼ� 1)�˿� 2)����Ա:");
                    scanf("%d",&a.userPermission);
                }
            }
            else{
                printf("[ע��]������Ȩ�޵ȼ� 1)�˿� 2)����Ա 3)��������Ա:");
                scanf("%d",&a.userPermission);
                while(a.userPermission < 1 || a.userPermission > 3){
                    printf("[ע��]������Ȩ�޵ȼ� 1)�˿� 2)����Ա 3)��������Ա:");
                    scanf("%d",&a.userPermission);
                }
            }
            a.userIntegral = 0;
            addList(userInf_head,a);
            UserUpdate(userInf_head);
            printf("[ϵͳ]�˺�ע��ɹ������¼��\n");
            return;
        } else {
            printf("[ϵͳ]�������벻ƥ�䣡���������룡\n");
            scanf("%s", &a.userPassword);
            printf("[ϵͳ]��ȷ������\n");
            scanf("%s", &temp);
        }
    } while (1);
}

userInf UserLogin()
{
    userInf a = {"","",0},b;
    printf("[��¼]�������˺�:");
    scanf("%s",&a.userAccount);
    ListNode *p = userInf_head -> next;
    while(1){
        if(p == NULL){
            printf("[ϵͳ]���û��������ڣ����������룡\n");
            return a;
        } else{
            if(!strcmp(a.userAccount,p->data.userAccount)){
                break;
            } else{
                p = p -> next;
            }
        }
    }
    printf("[��¼]����������:");
    scanf("%s",&a.userPassword);
    do{
        if (strcmp(a.userPassword, p->data.userPassword)==0)            /*�������ƥ��*/
        {
            a.userPermission = p->data.userPermission;
            printf("[�û�:%s]��¼�ɹ�,��ӭʹ��!\n",a.userAccount);
            return a;
        }
        else
        {    printf("[ϵͳ]���벻��ȷ!��������������:");
            scanf("%s",&a.userPassword);
        }
    }while(strcmp(a.userPassword, p->data.userPassword)==0);
}

userInf UserLogout(){
    userInf a = {"","",0};
    printf("[ϵͳ]�û��ѵǳ�!\n");
    return a;
}

void Customer_Opr(userInf loginUser){
    while(1){
        printf("[�˿�:%s]������ 1)��Ʒ���� 2���ҵĻ��� 3)�����ϼ�:",loginUser.userAccount);
        int ichoice;
        scanf("%d",&ichoice);
        switch (ichoice) {
            default:
                IntegralMenu(loginUser);
                return;
            case 1:
                //�˿���Ʒ����
                return;
        }
    }
}

void Manager_Opr(userInf loginUser){
    while(1){
        printf("[����Ա:%s]������ 1)���ӹ˿� 2)ɾ���˿� 3)���Ĺ˿� 4)��ѯ�˿� 5)��Ʒ�˵� 6)�û����� 7)�˳�:",loginUser.userAccount);
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
                system("cls"); //����
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
        printf("[��������Ա:%s]������ 1)�����û� 2)ɾ���û� 3)�����û� 4)��ѯ�û� 5)��Ʒ�˵� 6)�û����� 7)�˳�:",loginUser.userAccount);
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
                system("cls"); //����
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
    printf("[ɾ��]�������˺�:");
    scanf("%s",&a.userAccount);

    ListNode *p = userInf_head -> next;
    while (1)
    {
        if(p == NULL){
            printf("[ϵͳ]���û��������ڣ����������룡\n");
            return;
        }
        else{
            if((!strcmp(a.userAccount, p->data.userAccount))){
                if(p->data.userPermission <= permissionLevel){
                    deleteList(userInf_head,p->data);
                    printf("[ϵͳ]�Ѿ�ɾ���û�:%s\n",a.userAccount);
                    saveList(userInf_head);
                }
                else{
                    printf("[����Ա:%s]Ȩ�޲���!\n",loginAccount);
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
    printf("[�޸�]�������˺�:");
    scanf("%s",&a.userAccount);

    ListNode *p = userInf_head -> next;
    while (1)
    {
        if(p == NULL){
            printf("[ϵͳ]���û��������ڣ����������룡\n");
            return;
        }
        else{
            if ((!strcmp(a.userAccount, p->data.userAccount)))         //����д��û�����Ȩ�޵ȼ�Ϊ�˿�
            {
                if(p->data.userPermission <= permissionLevel){
                    while(1){
                        printf("[�û�:%s]����:%s ����:%d\n",p->data.userAccount,p->data.userPassword,p->data.userIntegral);
                        printf("[����Ա:%s]�������޸��û�%s�Ĳ���:1)�޸����� 2)�����ϼ�:",loginAccount,p->data.userAccount);
                        int ichoice;
                        scanf("%d",&ichoice);
                        switch (ichoice) {
                            default:
                                return;
                            case 1:
                                printf("[ϵͳ]�������޸ĺ������:");
                                scanf("%s",p->data.userPassword);
                                break;
                        }
                        saveList(userInf_head);
                    }
                } else{
                    printf("[����Ա:%s]Ȩ�޲���!\n",loginAccount);
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
    printf("[��ѯ]�������˺�:");
    scanf("%s",&a.userAccount);

    ListNode *p = userInf_head -> next;
    while(1){
        if(p == NULL){
            printf("[ϵͳ]���û��������ڣ����������룡\n");
            break;
        } else{
            if(!strcmp(p->data.userAccount,a.userAccount)){
                if(p->data.userPermission <= permissionLevel){
                    printf("[�û�:%s]����:%s ����:%d\n",p->data.userAccount,p->data.userPassword,p->data.userIntegral);
                } else{
                    printf("[����Ա:%s]Ȩ�޲���!\n",loginAccount);
                }
                break;
            } else{
                p = p->next;
            }
        }
    }
}
