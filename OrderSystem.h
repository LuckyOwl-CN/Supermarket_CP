
#ifndef ORDERSYSTEM_H
#define ORDERSYSTEM_H

#endif

#include "CommoditySystem.h"


void OrderMenu(userInf,SHOP*head);
void readFromFile(userInf user[],goods good[],SHOP*head);
void userFunction(userInf user[],goods good[],userInf newuser);
void deleteUserAndOrder(userInf user[],goods good[]);
void showGoodsInfor(goods good[]);
void showOrderByUserName(userInf user[],goods good[],userInf newuser);
void deleteSingleOrder(goods good[],userInf user[]);
void buyGoods(goods good[],userInf user[]);
void orderWrite(userInf user[]);
void addGoods(goods good[]);
void goodsWrite(goods good[]);
void userRegister(userInf user[]);
void userWrite(userInf user[]);
void addGoods(goods good[]);
void CountTotalPrice(userInf user[],goods good[],userInf newuser); 
