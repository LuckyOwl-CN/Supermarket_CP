//
// Created by hp on 2022/7/13.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntegralSystem.h"

ListNode* loadList()
{
    ListNode *p, *head, *r;

    head = (ListNode*)malloc(sizeof(ListNode));
    head->next = NULL;
    r = head; // r尾指针

    userInf a,b;
    FILE *fp;
    if ((fp = fopen("UserInf.txt", "r")) == NULL)                 /*如果此文件不存在*/
    {
        if ((fp = fopen("UserInf.txt", "w")) == NULL) {
            printf("[系统]无法建立文件！\n");
            return head;
        }
    }
    while (!feof(fp)) {
        fscanf(fp,"%s %s %d %d\n",&b.userAccount,&b.userPassword,&b.userPermission,&b.userIntegral);
        p = (ListNode*)malloc(sizeof(ListNode));
        if(p == NULL)
        {
            exit(-1);
        }
        p->data = b;
        r->next = p;
        r=p;
    }
    r->next = NULL; //最后一个节点指向空
    fclose(fp);
    return head;
}

void saveList(ListNode *head){
    ListNode *p = head -> next;
    printf("[系统]数据已保存\n");
    FILE *fp;
    fp = fopen("UserInf.txt", "w");
    while(p != NULL){
        fprintf(fp,"%s %s %d %d\n",p->data.userAccount,p->data.userPassword,p->data.userPermission,p->data.userIntegral);
        p = p->next;
    }
    fclose(fp);
}

void printList(ListNode *head)
{
    ListNode *p = head->next;
    printf("打印链表:\n");
    while(p != NULL)
    {
        printf("%s %s %d %d\n", p->data.userAccount,p->data.userPassword,p->data.userPermission,p->data.userIntegral);
        p = p->next;
    }
}

int ListLength(ListNode *head)
{
    ListNode *p = head->next;
    int len=0;
    while(p != NULL)
    {
        p = p->next;
        len++;
    }
    printf("链表长度: %d\n", len);
    return len;
}

void insertList(ListNode *head, userInf a, int pos)
{
    if(pos<0)
    {
        printf("节点位置错误\n");
        return;
    }
    int len = ListLength(head);
    if(pos > len)
    {
        printf("节点位置超过链表长度\n");
        return;
    }
    ListNode *p, *r;
    r = head;
    int j=0;
    // 防止节点越界
    while(r->next && j<pos)
    {
        r = r->next;
        j++;
    } // 找到pos位置，在后面插入节点

    p = (ListNode*)malloc(sizeof(ListNode));
    p->data = a;
    p->next = r->next;
    r->next = p;
}

void addList(ListNode *head, userInf a){
    int len = ListLength(head);
    ListNode *p, *r;
    r = head;
    int j=0;
    while(r->next && j<len)
    {
        r = r->next;
        j++;
    }
    p = (ListNode*)malloc(sizeof(ListNode));
    p->data = a;
    p->next = r->next;
    r->next = p;
}

ListNode* findbyAccount(ListNode *head, char account[20])
{
    ListNode *p = head ;
    while(strcmp(p->data.userAccount,account))
    {
        p = p->next;
    }
    return p;
}

void deleteList(ListNode *head, userInf a)
{
    ListNode *p, *r;
    r = head;
    p = head->next;
    while(strcmp(p->data.userAccount,a.userAccount))
    {
        p = p->next;
        r = r->next;
    }
    if(p == NULL)
    {
        printf("节点不存在\n");
    }
    else{
        r->next = p->next;
        free(p);
    }
}
