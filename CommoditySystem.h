
#ifndef COMMODITYSYSTEM_H
#define COMMODITYSYSTEM_H

#endif


#include <math.h>
#include <conio.h>
#include "UserSystem.h"

typedef struct shop {
    char type[20];//����
    char ID[10];//����
    char number[10];//���
    char date[10];//��������
    char passtime[10];//����ʱ��
    char saletime[10];//����ʱ��
    char day[10];//������
    int amount;//�������
    char buyer[10];//������
    char price[10];//�۸�
    int sale;//����
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
