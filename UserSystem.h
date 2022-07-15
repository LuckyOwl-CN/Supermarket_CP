#ifndef USERSYSTEM_H
#define USERSYSTEM_H

#endif

#include "LinkList.h"

void UserMenu();
userInf UserLogin();
void UserRegist(int);
userInf UserLogout();
void Create_File();
void Customer_Opr(userInf);
void Manager_Opr(userInf);
void SManager_Opr(userInf);
void UserUpdate(ListNode* head);
