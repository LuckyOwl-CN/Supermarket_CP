//
// Created by hp on 2022/7/15.
//

#include "IntegralSystem.h"

int order_NumOfUser = 0;
int order_NumOfProduct = 0;
int order_GoodsInOrder[20] = {0}; //��ʾ��ͬ�û��Ķ�������
int order_Position = -1;     //��¼�ɹ����ڽṹ���е�λ��

/*int userLoad(userInf user[]){

    char account[20];
    char password[20];
    printf("�������˺ţ� \n");
    scanf("%s",account);
    fflush(stdin);
    printf("���������룺 \n");
    scanf("%s",password);
    fflush(stdin);
    int i = 0;
    for(i = 0;i < order_NumOfUser;i++){

        if((strcmp(account,user[i].userAccount) == 0) &&(strcmp(password,user[i].userPassword) == 0)){

            order_Position = i;
            return 1;

        }


    }

    return -1;

}*/

void userWrite(userInf user[]){
	

	FILE *fp = fopen("user.txt","w+");
		if(fp==NULL)
	{
		printf("���ļ�ʧ��\n");
	 } 
	 fflush(stdin);
	 int i = 0;

	 for(i = 0;i < order_NumOfUser;i++){
	 	
	 	fprintf(fp,"%s\t%s\t%d\n",user[i].userAccount,user[i].userPassword,
		 					  user[i].userPermission);
	 	
	 	
	 }

	fclose(fp);
	printf("д�� %d ����¼���ļ�%s\n\n", order_NumOfUser, "user.txt");
	
	
}

void addUser(userInf user[],userInf newuser){

    
    char account[20];
    char password[20];
    int i = 0;
    int flag = -1;
    for(i = 0;i < order_NumOfUser;i++){
    	
    	if((strcmp(user[i].userAccount,newuser.userAccount) == 0)&&(strcmp(user[i].userPassword,newuser.userPassword) == 0))  {
    		
    		flag = i;
    		order_Position = i;
    		printf("֮ǰ�Ѿ������Ϣ�ˣ������ٴ����\n");
    		break;
    		
		}
    	
	}
	if(flag == -1){
		
		strcpy(user[order_NumOfUser].userAccount,newuser.userAccount); 
   		strcpy(user[order_NumOfUser].userPassword,newuser.userPassword);
   	 	user[order_NumOfUser].userPermission = newuser.userPermission;
    	order_NumOfUser++;
    	order_Position = order_NumOfUser - 1;
    	userWrite(user);
    	printf("��ӳɹ��������ڿ���ʵ�ֹ���\n");
		
	}

}

void goodsWrite(goods good[]){

    FILE *fp = fopen("goods.txt","w+");
    if(fp==NULL)
    {
        printf("���ļ�ʧ��\n");
    }
    fflush(stdin);
    int i = 0;
    for(i = 0;i < order_NumOfProduct;i++){

        fprintf(fp,"%s\t%d\t%d\t%s\n",good[i].name,good[i].num,
                good[i].price,good[i].date);

    }

    fclose(fp);
    printf("д�� %d ����¼���ļ�%s\n\n", order_NumOfProduct, "goods.txt");

}


/*void addGoods(goods good[]){

    char name[20];
    int num;
    int price;
    printf("��������Ʒ���ƣ�  ");
    scanf("%s",name);
    fflush(stdin);

    int i = 0;
    int flag = -1;
    for(i = 0;i < order_NumOfProduct;i++){

        if(strcmp(name,good[i].name) == 0){

            flag = i;
            break;

        }

    }

    if(flag != -1){

        printf("����Ʒ�Ѿ������ù��ˣ�������Ҫ������������");
        scanf("%d",&num);
        fflush(stdin);
        good[flag].num += num;
        printf("�����Ʒ�ɹ�\n");
        goodsWrite(good);

    }
    else{

        strcpy(good[order_NumOfProduct].name,name);
        printf("��������Ʒ������  ");
        scanf("%d",&num);
        fflush(stdin);
        good[order_NumOfProduct].num = num;
        printf("��������Ʒ�۸�  ");
        scanf("%d",&price);
        fflush(stdin);
        good[order_NumOfProduct].price = price;

        order_NumOfProduct++;

        printf("�����Ʒ�ɹ�\n");
        goodsWrite(good);


    }



}*/

void orderWrite(userInf user[]){

    FILE *fp = fopen("order.txt","w+");
    if(fp==NULL)
    {
        printf("���ļ�ʧ��\n");
    }
    fflush(stdin);
    int i = 0;
    int j = 0;
    for(i = 0;i < order_NumOfUser;i++){


        if(order_GoodsInOrder[i] != 0){

            for(j = 0;j < order_GoodsInOrder[i];j++){

                fprintf(fp,"%d\t%s\t%d\n",i,user[i].order[j].name,user[i].order[j].number);
            }


        }

    }

    fclose(fp);


}

void buyGoods(goods good[],userInf user[]){

    int permission = 0;
    permission = user[order_Position].userPermission;
    if(permission == 1)
    {

        printf("������Ҫ�������Ʒ���ƣ�");
        int i = 0;
        char nameOfGood[20];
        int count = -1;
        while(1)
        {

            scanf("%s",nameOfGood);
            fflush(stdin);
            for(i = 0;i < order_NumOfProduct;i++){

                if(strcmp(good[i].name , nameOfGood) == 0){

                    count = i;
                    break;

                }

            }


            if(count != -1){

                break;

            }
            else{

                printf("������Ʒ���ƴ�������������\n");

            }

        }

        printf("���������빺�򼸼�����Ʒ��");

        int number;
        while(1){

            scanf("%d",&number);
            fflush(stdin);
            if((number <= good[count].num)&&(number > 0)){

                printf("��ϲ�㹺��ɹ�\n");
                good[count].num -= number;
                goodsWrite(good);
                break;
            }

            else if(number <= 0){

                printf("Ҫ��Ļ�����һ��Ŷ\n");
                printf("������ѡ��������\n");

            }

            else{

                printf("����Ʒ����%d��������ѡ����%d��\n",good[count].num,number);
                printf("������ѡ��������\n");

            }
        }

        if(count != -1){

            int flag = -1;
            int j = 0;
            for(j = 0;j < order_GoodsInOrder[order_Position];j++){

                if(strcmp(nameOfGood,user[order_Position].order[j].name) == 0){

                    flag = j;
                    break;

                }

            }//��֤֮ǰ�������Ʒ�������µĶ���;

            if(flag == -1){

                user[order_Position].order[order_GoodsInOrder[order_Position]].number += number;
                strcpy(	user[order_Position].order[order_GoodsInOrder[order_Position]].name,nameOfGood );
                order_GoodsInOrder[order_Position]++;

            }
            else{

                user[order_Position].order[flag].number += number;

            }

            orderWrite(user);

        }

    }

    else{

        printf("�ܱ�Ǹ��ֻ���û����Թ�����Ʒ\n");

    }




}

void deleteSingleOrder(goods good[],userInf user[]){

    int permission = 0;
    permission = user[order_Position].userPermission;
    if(permission == 1){

        printf("��ѡ����Ҫɾ���ڼ���������");
        while(1){

            int num ;
            int count = 0;
            scanf("%d",&num);
            fflush(stdin);
            char flagname[20];
            if((num <= order_GoodsInOrder[order_Position])&&(num > 0))  {

                int i = 0;
                if( num == order_GoodsInOrder[order_Position]){

                    strcpy(flagname,user[order_Position].order[order_GoodsInOrder[order_Position]-1].name);
                    count = user[order_Position].order[order_GoodsInOrder[order_Position]-1].number;
                    order_GoodsInOrder[order_Position]--;


                }
                else{

                    strcpy(flagname,user[order_Position].order[num - 1].name);
                    count = user[order_Position].order[num - 1].number;
                    for(i = num - 1;i < order_GoodsInOrder[order_Position] - 1;i++){

                        user[order_Position].order[i] = user[order_Position].order[i + 1];

                    }

                    order_GoodsInOrder[order_Position]--;


                }

                for(i = 0;i < order_NumOfProduct;i ++){

                    if(strcmp(flagname,good[i].name) == 0){

                        printf("****%d�ж���****\n",count);
                        good[i].num += count;

                    }

                }
                orderWrite(user);
                goodsWrite(good);
                printf("ɾ���ɹ�\n");
                break;

            }

            else if(num <= 0){

                printf("������󣬶���Ӧ�ôӵ�һ������\n");
                break;

            }
            else{

                printf("û����ô�ඩ����������ѡ��\n");
                break;

            }

        }

    }

    else{

        printf("�ܱ�Ǹ��ֻ���û�����ɾ����Ʒ\n");

    }



}

void CountTotalPrice(userInf user[],goods good[],userInf newuser){

    int i = 0;
    int j = 0;
    int count = -1;
    int num = newuser.userPermission;
    if(num == 3){
    	
    	num = 2;
    	
	}
	switch(num){
		
		case 1:
			while(1){

 
       			char account[20];
       			strcpy(account,newuser.userAccount);
        		fflush(stdin);

        		char password[20];
        		strcpy(password,newuser.userPassword);
        		fflush(stdin);
        		for(i = 0;i < order_NumOfUser ;i ++){

           		 if((strcmp(account,user[i].userAccount) == 0) &&(strcmp(password,user[i].userPassword)==0)){

               		 count = i;
               		 break;

           		 }

       			}


				if(count != -1){

           			 printf("���ҳɹ�\n");
            			break;
        			}
        			else{

            			printf("����ʧ��\n");
            			break;

        			}
    		}
    		break;
    		case 2:
    			while(1){

        			printf("��������û����˺ţ�");
        			char account[20];
        			scanf("%s",account);
        			fflush(stdin);
        			printf("��������û������룺");
        			char password[20];
        			scanf("%s",password);
        			fflush(stdin);
        			for(i = 0;i < order_NumOfUser ;i ++){

        			    if((strcmp(account,user[i].userAccount) == 0) &&(strcmp(password,user[i].userPassword)==0)){

               			 count = i;
               			 break;

           			}

        			}

        			if(count != -1){

           			 printf("���ҳɹ�\n");
            			break;
        			}
        			else{

            			printf("����ʧ��\n");
            			break;

        			}

    			}
			break;
		
	}

    int totalPrice = 0;
    for(i = 0;i < order_GoodsInOrder[count];i++){

        for(j = 0;j < order_NumOfProduct;j++){

            if(strcmp(user[count].order[i].name,good[j].name) == 0){

                totalPrice += user[count].order[i].number * good[j].price;

            }

        }

    }

    if(count != -1){

        printf("������Ʒ���ܼ�Ϊ��%d\n",totalPrice);

    }


}


void showOrderByUserName(userInf user[],goods good[],userInf newuser){

    int i = 0;
    int j = 0;
    int count = -1;
    int num = newuser.userPermission;
    if(num == 3){
    	
    	num = 2;
    	
	}
    switch(num){
    	
    	case 1:
    		while(1){

        	
        	char account[20];
        	strcpy(account,user[order_Position].userAccount); 
        	
        	fflush(stdin);
        	
       		 char password[20];
        	strcpy(password,user[order_Position].userPassword);
        	
       		fflush(stdin);
        	for(i = 0;i < order_NumOfUser ;i ++){

            	if((strcmp(account,user[i].userAccount) == 0) &&(strcmp(password,user[i].userPassword)==0)){

               	 count = i;
              	  break;

           	 }

       		}

      	  		if(count != -1){

          	  	printf("���ҳɹ�\n");
           	 	break;
        		}
        		else{

          	  	printf("����ʧ��\n");
           	 	break;

        		}

   	 		}
   	 	break;
   	 	case 2:
			while(1){

        	printf("��������û����˺ţ�");
        	char account[20];
       
        	scanf("%s",account);
        	fflush(stdin);
        	printf("��������û������룺");
        	char password[20];
       
        	scanf("%s",password);
        	fflush(stdin);
        	for(i = 0;i < order_NumOfUser ;i ++){

            	if((strcmp(account,user[i].userAccount) == 0) &&(strcmp(password,user[i].userPassword)==0)){

               	 count = i;
               	 break;

            	}

       		}

       	 		if(count != -1){
       	 			
       	 			printf("���ҳɹ�\n");
					if(order_GoodsInOrder[count] == 0){
						
						printf("���û���ʱδ������Ʒ\n");
						
					}
           		 	
            		break;
       	 		}
        		else{

            		printf("����ʧ��\n");
            	break;

        		}

    		}	 
    	break;
    		
    	
	}


    for(i = 0;i < order_GoodsInOrder[count];i ++){

        printf("��%d���˵���ϢΪ��\n",i+1);
        printf("��Ʒ���ƣ�%s\n",user[count].order[i].name);
        printf("��������Ϊ��%d\n",user[count].order[i].number);

    }
    


}

void showGoodsInfor(goods good[]){

    int i = 0;
    for(i = 0;i < order_NumOfProduct;i++){

        printf("��%d����Ʒ�������ǣ�%s\n",i+1,good[i].name);
        printf("��%d����Ʒ�������ǣ�%d\n",i+1,good[i].num);
        printf("��%d����Ʒ�ļ۸��ǣ�%d\n",i+1,good[i].price);
        printf("��%d����Ʒ������������%s\n\n",i+1,good[i].date);

    }

}


void deleteUserAndOrder(userInf user[],goods good[]){

    //printf("������Ҫɾ�����û����˺ţ�");
    char account[20];
    strcpy(account,user[order_Position].userAccount);
   // scanf("%s",account);
    fflush(stdin);
    //printf("������Ҫɾ�����û������룺");
    char password[20];
    strcpy(password,user[order_Position].userPassword);
    //scanf("%s",password);
    fflush(stdin);

    int i = 0;
    int j = 0;
    int k = 0;
    int flag = -1;
    for(i = 0;i < order_NumOfUser;i++){

        if((strcmp(user[i].userAccount,account)==0)&&(strcmp(user[i].userPassword,password)==0)){

            flag = i;
            for(j = 0;j < order_NumOfProduct;j++){

                for(k = 0;k < order_GoodsInOrder[i];k++){

                    if(strcmp(user[i].order[k].name,good[j].name)==0){

                        good[j].num += user[i].order[k].number;

                    }


                }

            }//����ɾ���û����ѹ���Ʒ������������Ʒ
            goodsWrite(good);

            break;

        }

    }

    if(flag != -1){

        if(order_NumOfUser == 1){

            order_NumOfUser--;
            order_GoodsInOrder[0] = 0;

        }
        else{

            for(i = flag;i < order_NumOfUser - 1;i++){

                strcpy(user[i].userAccount,user[i+1].userAccount);
                strcpy(user[i].userPassword,user[i+1].userPassword);
                user[i].userPermission = user[i+1].userPermission;
                order_GoodsInOrder[i] = order_GoodsInOrder[i+1];

                for(j = 0;j < order_GoodsInOrder[i+1];j++){


                    strcpy(user[i].order[j].name,user[i+1].order[j].name);
                    user[i].order[j].number = user[i+1].order[j].number;

                }


            }

            order_NumOfUser--;

        }

        userWrite(user);
        orderWrite(user);

    }


}

void userFunction(userInf user[],goods good[],userInf newuser){


    int flag = 1;
    while(flag == 1){

		printf("\t\t\t  ***********************             ************************\n");
		printf("\t\t\t                          ���ж���ϵͳ                        \n");
		printf("\t\t\t  ************************            ************************\n");
        printf("\t\t\t                          1��������Ʒ                         \n");
        printf("\t\t\t                          2��ɾ����Ʒ                          \n");
        printf("\t\t\t                          3����ʾ��Ʒ��Ϣ                      \n");
        printf("\t\t\t                          4��ɾ�����������Ϣ�Ͷ���            \n");
        printf("\t\t\t                          5����ʾ�����ܼ�                      \n");
        printf("\t\t\t                          6��Ϊ�����Ʒ                        \n");
        printf("\t\t\t                          7��Ϊ��ʾ������Ʒ                    \n");
        printf("\t\t\t                          8��������һ��                        \n\n");
        printf("���ѡ���ǣ�");
        int choice = 0;
        scanf("%d",&choice);
        switch(choice){

            case 1:
                buyGoods(good,user);
                system("PAUSE");
                break;
            case 2:
                deleteSingleOrder(good,user);
                system("PAUSE");
                break;
            case 3:
                showOrderByUserName(user,good,newuser);
                system("PAUSE");
                break;
            case 4:
                 deleteUserAndOrder(user,good);
                system("PAUSE");
                break;
            case 5:
            	CountTotalPrice(user,good,newuser);
            	system("PAUSE");
                break;
            case 6:
                //addGoods(good);
                system("PAUSE");
                break;
            case 7:
                showGoodsInfor(good);
                system("PAUSE");
                break;
            case 8:
            	flag = 0;
            	break;
            default :
                printf("�����������������\n");
                break;

        }

    }

}

void readFromFile(userInf user[],goods good[],SHOP*head){

    //���û���Ϣ

    FILE *fp1 = fopen("user.txt", "r");
    if(fp1 == NULL)
    {
        printf("���ļ�����\n");
    }



    while(fscanf(fp1,"%s%s%d",user[order_NumOfUser].userAccount,user[order_NumOfUser].userPassword,
                 &user[order_NumOfUser].userPermission)!=EOF){

        /*printf("%s\t%s\t%d\n",user[numOfUser].userAccount,user[numOfUser].userPassword,
                            user[numOfUser].userPermission);*/
        order_NumOfUser++;

    }
    fclose(fp1);
    printf("ԭ��%d���û�\n",order_NumOfUser);


	SHOP*p;
	p = (SHOP*)malloc(sizeof(SHOP));
	if(head == NULL){
		
		printf("��δ¼����Ʒ��Ϣ��\n");

		
	}
	p = head;
	while(p != NULL){
		
		strcpy(good[order_NumOfProduct].name,p->ID);
		good[order_NumOfProduct].price = atoi(p->price);
		good[order_NumOfProduct].num = p->amount;
		strcpy(good[order_NumOfProduct].date,p->date);
		order_NumOfProduct++;
		p = p->next;
		
	}
	printf("����%d����Ʒ��Ϣ\n",order_NumOfProduct);
    //��������Ϣ
    /*FILE *fp2 = fopen("goods.txt", "r");
    if(fp2 == NULL)
    {
        printf("���ļ�����\n");
    }

    while(fscanf(fp2,"%s%d%d",good[order_NumOfProduct].name,
                 &good[order_NumOfProduct].num,&good[order_NumOfProduct].price)!=EOF){

        /* printf("%s\n\n",good[numOfProduct].name);
         printf("%d\n\n",good[numOfProduct].price);
         printf("%d\n\n",good[numOfProduct].num);


        order_NumOfProduct++;

    }

    fclose(fp2);
    printf("ԭ��%d����Ʒ\n",order_NumOfProduct);*/

    FILE *fp3 = fopen("order.txt","r");
    if(fp3==NULL){

        printf("���ļ�����\n");

    }

    int count;
    char name[20];
    int num;
    while(fscanf(fp3,"%d%s%d", &count,name,&num)!=EOF){


        user[count].order[order_GoodsInOrder[count]].number = num;
        strcpy(user[count].order[order_GoodsInOrder[count]].name,name);
        order_GoodsInOrder[count]++;


    }
    int i = 0;
    for(i = 0;i < order_NumOfUser;i++){
        printf("��%d���û�����%d������\n",i+1,order_GoodsInOrder[i]);

    }
    fclose(fp3);


}

void OrderMenu(userInf loginUser,SHOP*head){

    userInf user[20];
    goods good[30];
    readFromFile(user,good,head); //��ȡ�û�����Ʒ��Ϣ 
    addUser(user,loginUser); //�����û� 
    userFunction(user,good,loginUser); //ʹ�ù��� 

}
