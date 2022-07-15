#include "UserInf.h"

typedef struct LNode
{
    userInf data;
    struct LNode *next;
}ListNode;

ListNode* loadList();
void saveList(ListNode *head);
void printList(ListNode *head);
int ListLength(ListNode *head);
void insertList(ListNode *head, userInf a, int pos);
ListNode* findbyAccount(ListNode *head, char account[20]);
void addList(ListNode *head, userInf a);
void deleteList(ListNode *head, userInf a);
