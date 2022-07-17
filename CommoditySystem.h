
#ifndef COMMODITYSYSTEM_H
#define COMMODITYSYSTEM_H

#endif


#include <math.h>
#include <conio.h>
#include "UserSystem.h"

typedef struct shop {
    char type[20];//类型
    char ID[10];//名称
    char number[10];//编号
    char date[10];//生产日期
    char passtime[10];//进库时间
    char saletime[10];//出售时间
    char day[10];//保质期
    int amount;//库存数量
    char buyer[10];//进货商
    char price[10];//价格
    int sale;//销量
    struct shop*next;
} SHOP;




void Windowstime();
void inputInformation();
void inputDate();
void showShop();
void saveInformation();
void readInformation();
void infoshop();
void C_CommodityMenu(userInf);
void M_CommodityMenu(userInf);
void findInformation();
void amendInformation();
void delInformation();
void sortInformation();
void findOrderInformation(userInf,SHOP*head);
void CommodityMenu(userInf);
