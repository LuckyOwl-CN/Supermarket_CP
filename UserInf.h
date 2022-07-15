
#ifndef USERINF_H
#define USERINF_H

#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct orders{
    char name[20];
    int number;
};

typedef struct UserInformation{
    char userAccount[20];
    char userPassword[20];
    int userPermission;
    int userIntegral;
    struct orders order[20];
} userInf;

typedef struct
{

    char name[20];
    int price;
    int num;

}goods;
