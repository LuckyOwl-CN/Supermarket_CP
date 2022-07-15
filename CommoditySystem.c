#include "IntegralSystem.h"

SHOP*head = NULL;
SHOP*p1 = NULL;
int count;

void CommodityMenu(userInf loginUser){
    switch (loginUser.userPermission) {
        default:
            return;
        case 1:
            C_CommodityMenu(loginUser);
            return;
        case 2:
            M_CommodityMenu(loginUser);
            return;
    }
}

void Windowstime() {
    SYSTEMTIME sys;

    printf("\t\t\t\t\t  ��ǰʱ��Ϊ��");
    GetLocalTime( &sys ); //��ȡϵͳʱ�䵽����ĺ���
    printf( "%4d--%02d--%02d %02d:%02d \n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wDayOfWeek); //������/��/�� ʱ/��/�� ���ڼ���ʽ��ӡ
    printf("\n");

    return;
}

void C_CommodityMenu(userInf loginUser) {
    readInformation();
    int select = 1;
    while (select != 10) {
        printf("\n\n\n");
        printf("\t\t\t\t\t                                   \n");
        printf("\t\t\t\t\t          ������Ʒ����ϵͳ \n");
        printf("\t\t\t\t\t                                   \n");
        printf("\n\n");
        printf("\t\t\t\t   �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r\n");
        printf("\t\t\t\t   ��              ������Ʒ����ϵͳ              ��\n");
        printf("\t\t\t\t   �t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
        printf("\t\t\t\t   ����������������������������������������������������������������������������������������-��\n");
        printf("\t\t\t\t   ��                                            ��\n");
        printf("\t\t\t\t   ��                1. ��ʾ��Ʒ��Ϣ             ��\n");
        printf("\t\t\t\t   ��                2. ��ѯ��Ʒ��Ϣ             ��\n");
        printf("\t\t\t\t   ��                3. ��Ʒ��Ϣ����             ��\n");
        printf("\t\t\t\t   ��                4. ��ѯ������Ϣ             ��\n");
        printf("\t\t\t\t   ��                5. �˳�����ϵͳ             ��\n");
        printf("\t\t\t\t   ��                                            ��\n");
        printf("\t\t\t\t   ��                                            ��\n");
        printf("\t\t\t\t   ��������������������������������������������������������������������������������������������\n");

        Windowstime();		//windows��ǰʱ��
        printf("\t\t\t��������Ϸ�ѡ��1-10������һ��\t");//������һ��ѡ��
        scanf("%d", &select);
        switch (select) {
            case 5:
                getchar();
                system("cls");
                printf("\n���Ѿ��ɹ��˳���\n");//�˳�����
                break;	//�˳���Ʒ����ϵͳ
            case 1://��ӡ��Ϣ
                showShop();
                break;
            case 2://��ѯ��Ϣ
                findInformation();
                break;
            case 3://����
                sortInformation();
                break;
            case 4:
                findOrderInformation(loginUser);
                break;
            default:
                getchar();
                rewind(stdin);//������̻���
                printf("����������������룡\n");
                system("pause");
                break; //�û��ô���

        }
    }
}

void M_CommodityMenu(userInf loginUser)
{
    readInformation();
    int select = 1;
    while (select != 10) {
        printf("\n\n\n");
        printf("\t\t\t\t\t                                   \n");
        printf("\t\t\t\t\t          ������Ʒ����ϵͳ \n");
        printf("\t\t\t\t\t                                   \n");
        printf("\n\n");
        printf("\t\t\t\t   �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r\n");
        printf("\t\t\t\t   ��              ������Ʒ����ϵͳ              ��\n");
        printf("\t\t\t\t   �t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
        printf("\t\t\t\t   ����������������������������������������������������������������������������������������-��\n");
        printf("\t\t\t\t   ��                                            ��\n");
        printf("\t\t\t\t   ��                1. ¼����Ʒ��Ϣ             ��\n");
        printf("\t\t\t\t   ��                2. ��ʾ��Ʒ��Ϣ             ��\n");
        printf("\t\t\t\t   ��                3. ������Ʒ��Ϣ             ��\n");
        printf("\t\t\t\t   ��                4. ��ѯ������Ϣ             ��\n");
        printf("\t\t\t\t   ��                5. ͳ����Ʒ��Ϣ             ��\n");
        printf("\t\t\t\t   ��                6. ��ѯ��Ʒ��Ϣ             ��\n");
        printf("\t\t\t\t   ��                7. �޸���Ʒ��Ϣ             ��\n");
        printf("\t\t\t\t   ��                8. ɾ����Ʒ��Ϣ             ��\n");
        printf("\t\t\t\t   ��                9. ��Ʒ��Ϣ����             ��\n");
        printf("\t\t\t\t   ��                10.�˳�����ϵͳ             ��\n");
        printf("\t\t\t\t   ��                                            ��\n");
        printf("\t\t\t\t   ��                                            ��\n");
        printf("\t\t\t\t   ��������������������������������������������������������������������������������������������\n");

        Windowstime();		//windows��ǰʱ��
        printf("\t\t\t��������Ϸ�ѡ��1-10������һ��\t");//������һ��ѡ��
        scanf("%d", &select);
        switch (select) {
            case 10:
                getchar();
                system("cls");
                printf("\n���Ѿ��ɹ��˳���\n");//�˳�����
                break;	//�˳���Ʒ����ϵͳ

            case 1://¼����Ϣ
                inputInformation();
                break;

            case 2://��ӡ��Ϣ
                showShop();
                break;

            case 3://������Ϣ���ļ�
                saveInformation();
                break;

            case 4://��ȡ�ļ���Ϣ
                findOrderInformation(loginUser);
                break;

            case 5://ͳ����Ϣ
                infoshop();
                break;

            case 6://��ѯ��Ϣ
                findInformation();
                break;

            case 7://�޸���Ϣ
                amendInformation();
                break;

            case 8://ɾ��
                delInformation();
                break;

            case 9://����
                sortInformation();
                break;

            default:
                getchar();
                rewind(stdin);//������̻���
                printf("����������������룡\n");
                system("pause");
                break; //�û��ô���

        }
    }
}

void cursor(int x, int y) { //��꺯��
    COORD pos;
    HANDLE h;           //HANDLE:���
    pos.X = x;
    pos.Y = y;
    h = GetStdHandle(STD_OUTPUT_HANDLE); //��õ�ǰ������ڵľ��
    SetConsoleCursorPosition(h, pos);
}
void inputInformation() {
    SHOP *p2 = NULL;//�ṹ��ָ��
    int choose = 1;
    int chooses = 1;//ѭ���ж����

    while (choose == 1) {
        system("cls");//����

        p2 = (SHOP *)malloc(sizeof(SHOP)); //Ϊp2�����ڴ浥Ԫ

        inputDate(p2);//¼����Ϣ����

        if (head == NULL) { //�ж��Ƿ�Ϊͷ���
            head = p1 = p2;
            p2->next = NULL;
        } else {
            p1->next = p2;//p1ָ��p2
            p2->next = NULL;//p2ָ���
            p1 = p2;//p2��ֵ����p1
        }
        system("cls");

        printf("�Ƿ�Ҫ����¼����Ʒ��Ϣ  1.����  2.�˳�\n");
        scanf("%d", &choose);
        if (choose != 1 && choose != 2) {
            printf("ѡ���������������룡\n");

            printf("�Ƿ����¼�룺1.����     2.�˳�\n");

            scanf("%d", &choose);

            if (choose == 1) {
                continue;
            } else {
                printf("���������˳�¼��\n");
                system("pause");
                break;
            }
        }
    }

    system("cls"); //����




}
void inputDate(SHOP*p) {

    printf("\n\n");
    printf("\t\t\t\t   �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r\n");
    printf("\t\t\t\t   ��              ������Ʒ��Ϣ          ��\n");
    printf("\t\t\t\t   �t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
    printf("\t\t\t\t   ������������������������������������������������������������������������-��\n");
    printf("\t\t\t\t   ��===================================== \n");
    printf("\t\t\t\t   �� ����:                              ��\n");
    printf("\t\t\t\t   ��===================================== \n");
    printf("\t\t\t\t   �� ����:                              ��\n");
    printf("\t\t\t\t   ��===================================== \n");
    printf("\t\t\t\t   �� ���:                              ��\n");
    printf("\t\t\t\t   ��===================================== \n");
    printf("\t\t\t\t   �� �۸�:                              ��\n");
    printf("\t\t\t\t   ��===================================== \n");
    printf("\t\t\t\t   �� ���:                              ��\n");
    printf("\t\t\t\t   ��===================================== \n");
    printf("\t\t\t\t   �� ����:                              ��\n");
    printf("\t\t\t\t   ��===================================== \n");
    printf("\t\t\t\t   �� ����ʱ��:                          ��\n");
    printf("\t\t\t\t   ��===================================== \n");
    printf("\t\t\t\t   �� ������:                            ��\n");
    printf("\t\t\t\t   ��===================================== \n");
    printf("\t\t\t\t   �� ��������:                          ��\n");
    printf("\t\t\t\t   ��===================================== \n");
    printf("\t\t\t\t   �� ������:                            ��\n");
    printf("\t\t\t\t   ��===================================== \n");
    printf("\t\t\t\t   ����������������������������������������������������������������������������\n");


    cursor(44, 7);
    scanf("%s", p->type); //����
    fflush(stdin);
    cursor(44, 9);
    scanf("%s", p->ID); //����
    fflush(stdin);
    cursor(44, 11);
    scanf("%s", p->number); //���
    fflush(stdin);
    cursor(44, 13);
    fflush(stdin);
    scanf("%s", p->price); //�۸�
    fflush(stdin);
    cursor(44, 15);
    scanf("%d", &p->amount); //���
    fflush(stdin);
    cursor(44, 17);
    scanf("%d", &p->sale); //����
    fflush(stdin);
    cursor(47, 19);
    scanf("%s", p->saletime); //����ʱ��
    fflush(stdin);
    cursor(44, 21);
    scanf("%s", p->buyer); //����
    fflush(stdin);
    cursor(47, 23);
    scanf("%s", p->date); //��������
    fflush(stdin);
    cursor(45, 25);
    scanf("%s", p->day); //������
    fflush(stdin);
    count++;//�ڵ���� +1

}





void showShop() {
    SHOP*p;
    if (head = NULL) {
        printf("��δ¼����Ʒ��Ϣ������������ء�\n");
        getch();
        system("pause");
        system("cls");
        return;
    }
    printf("��Ʒ��Ϣ�������¡�\n");
    p = head;
    printf("\t����\t\t����\t\t���\t\t��������\t\t����ʱ��\t\t������\t\t�������\t\t������\t\t����ʱ��\n");
    while (p != NULL) {
        printf("%5s  %5s  %5s  %5s  %5s  %5s  %d  %5s  %5s\n", p->ID, p->type, p->number, p->date, p->passtime, p->day, p->amount, p->buyer, p->saletime);
        p = p->next;
    }
    printf("\n");
    printf("��Ʒ��Ϣ�Ѿ�ȫ����ӡ��");
    printf("\n");
    system("pause");
    system("cls");


}
void  saveInformation() {
    FILE *fp;//�ļ�ָ��
    SHOP *p;//�����Ϣָ��

    p = head;

    fp = fopen("CommodityInf.txt", "w"); //д���ļ���Ϣ(����ԭ����)

    if (fp == NULL) { //�ж��ļ��Ƿ�������
        printf("���ܴ��ļ���");
        exit(1);
    }

    while (p != NULL) { //p2��Ϊ��ʱ�������ݵ�¼��

        fprintf(fp, "%10s\t%10s\t%10s\t%10s\t%d\t%10s\t%d\t%10s\t%10s\t%10s  \n", p->number, p->ID, p->type, p->price, p->amount, p->saletime, p->sale, p->buyer, p->date, p->day);
        p = p->next;

    }

    printf("�ļ�����ɹ���\n");

    system("pause");
    system("cls");
    exit(1);

    if (fclose(fp)) {
        printf("���ܹر��ļ���");
        exit(1);
    }

}

void readInformation() {
    FILE*fp;
    SHOP*p;
    int i = 0;
    head = (SHOP*)malloc(sizeof(SHOP));
    head->next = NULL;
    if ((fp = fopen("CommodityInf.txt", "r")) == NULL)                 /*������ļ�������*/
    {
        if ((fp = fopen("CommodityInf.txt", "w")) == NULL) {
            printf("[ϵͳ]�޷������ļ���\n");
            return;
        }
    }
    if (fp != NULL) {
        p1 = head;

        while (!feof(fp)) {
            p = (SHOP*)malloc(sizeof(SHOP));
            p->next = NULL;
            p1->next = p;
            p1 = p;
            fscanf(fp, "%10s %10s %10s %10s %d %10s %d %10s %10s %10s  ", p->number, p->ID, p->type, p->price, &p->amount, p->saletime, &p->sale, p->buyer, p->date, p->day);


            i++;	//TODO
        }
        if (i == 1) {
            head = p;

        }
    }
    if (fclose(fp)) {
        printf("�ر��ļ�ʧ������");
        exit(1);

    }





}

void infoshop() {
    SHOP *p;	//�ṹ��ָ��

    int temp = 0;//���ж�
    int temf = 0;
    p = head;/*ͷ��㸳ֵ�� p */

    printf("\tͳ�ƽ�����,���Ժ�");

    fflush(stdin);

    printf("\t������£�\n");


    while (p != NULL) {
        /*���С��50����Ʒ��Ϣ*/

        if (p->amount < 50) {

            printf("\n");
            printf("����:%d		��ţ�%s	���ƣ�%7s	���ࣺ%7s	 �۸�%5s	 ��棺%d	�������ڣ�%7s	 ���أ�%7s	�������ڣ�%7s	�����ڣ�%s \n",
                   p->sale, p->number, p->ID, p->type, p->price, p->amount, p->saletime, p->buyer, p->date, p->day);



            temp = 1;

        }
        p = p->next;

    }
    if (temp == 0) {

        printf("û�п��С��50����Ʒ. . .\n");

    } else {
        printf("\n\t������Ʒ��治�㡣�뾡�첹��\n");
    }
    printf("\n\n\n");
    p = head;/*ͷ��㸳ֵ�� p */
    while (p != NULL) {
        /*������С��һ���µ���Ʒ��Ϣ*/

        if (atoi(p->day) <= 30) {
            printf("\n");
            printf("����:%d		��ţ�%s	���ƣ�%7s	���ࣺ%7s	 �۸�%5s	 ��棺%d	�������ڣ�%7s	 ���أ�%7s	�������ڣ�%7s	�����ڣ�%s \n",
                   p->sale, p->number, p->ID, p->type, p->price, p->amount, p->saletime, p->buyer, p->date, p->day);



            temf = 1;



        }
        p = p->next;

    }
    if (temf == 0) {

        printf("û�������С��һ���µĵ���Ʒ. . .\n");

    } else {
        printf("\n\t������Ʒ��漴�����ڡ��뾡���Ż�����\n");
    }

    printf("\n");
    system("pause");
    system("cls");


}

void findInformation() {

    SHOP *p2; //�ṹ��


    int opt_c;			//�û�����ѡ��
    int ture = 1;
    int flag = 0; 		//�ж����
    char s_ID[10];		//�û�����Ҫ��ѯ����Ʒ����
    char s_number[10];	//�û�����Ҫ��ѯ����Ʒ���

    p2 = head; //p2��ֵΪͷ���


    while (ture == 1) {

        printf("\n");
        printf("\t\t\t\t\t\t��-----------------��\n");;
        printf("\t\t\t\t\t\t |1.���ձ�Ų�ѯ  |\n");
        printf("\t\t\t\t\t\t |2.�������Ʋ�ѯ  |\n");
        printf("\t\t\t\t\t\t |3.�˳���ѯ      |\n");
        printf("\t\t\t\t\t\t��-----------------��\n");


        printf("��ѡ��\n");
        fflush(stdin);//��ռ��̻���
        scanf("%s", &opt_c);

        switch (opt_c) {
            case '1'://��Ų�ѯ

                system("pause");
                system("cls");		//��ͣ������

                p2 = head;

                printf("\n\n");
                printf("\t\t\t\t   ��=========================================== ��\n");
                printf("\t\t\t\t   �� �������ţ�             		        ��\n");
                printf("\t\t\t\t   ��=========================================== ��\n");

                cursor(50, 3);
                scanf("%s", &s_number);
                flag = 0;

                while (p2 != NULL) {
                    //flag = 1;
                    if (strcmp(s_number, p2->number) == 0) {

                        flag = 1;
                        printf("\n\n");
                        printf("\t\t\t\t   �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r\n");
                        printf("\t\t\t\t   ��                 ��ѯ��Ʒ��Ϣ               ��\n");
                        printf("\t\t\t\t   �t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
                        printf("\t\t\t\t   ����������������������������������������������������������������������������������������-��\n");
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   �� ���ࣺ%s             			��\n", p2->type);
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   �� ���ƣ�%s            			��\n", p2->ID);
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   �� �۸�%s              		\t��\n", p2->price);
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   �� ��棺%d            			��\n", p2->amount);
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   �� ������%d             			��\n", p2->sale);
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   �� ����ʱ��:%s            		        ��\n", p2->saletime);
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   �� ���أ�%s            			��\n", p2->buyer);
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   �� ��������:	%s            		        ��\n", p2->date);
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   �� �����ڣ�%s             		\t��\n", p2->day);
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   ��������������������������������������������������������������������������������������������\n");

                    }



                    p2 = p2->next;

                }
                if (flag == 0) {
                    printf("���޴���Ʒ. . .");
                    printf("\n");

                    break;
                }

                system("pause");
                system("cls");

                break;


            case '2'://���Ʋ�ѯ

                system("pause");
                system("cls");

                p2 = head;

                printf("\n\n");
                printf("\t\t\t\t   ��=========================================== ��\n");
                printf("\t\t\t\t   �� ���������ƣ�             		        ��\n");
                printf("\t\t\t\t   ��=========================================== ��\n");

                cursor(50, 3);
                scanf("%s", &s_ID);
                flag = 0;

                while (p2 != NULL) {
                    //flag = 1;
                    if (strcmp(s_ID, p2->ID) == 0 ) {


                        flag = 1;
                        printf("\n\n");
                        printf("\t\t\t\t   �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r\n");
                        printf("\t\t\t\t   ��                 ��ѯ��Ʒ��Ϣ               ��\n");
                        printf("\t\t\t\t   �t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
                        printf("\t\t\t\t   ����������������������������������������������������������������������������������������-��\n");
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   �� ���ࣺ%s             			��\n", p2->type);
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   �� ���ƣ�%s            			��\n", p2->ID);
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   �� �۸�%s              		\t��\n", p2->price);
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   �� ��棺%d            			��\n", p2->amount);
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   �� ������%d             			��\n", p2->sale);
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   �� ����ʱ��:%s            		        ��\n", p2->saletime);
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   �� ���أ�%s            			��\n", p2->buyer);
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   �� ��������:	%s            		        ��\n", p2->date);
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   �� �����ڣ�%s             		\t��\n", p2->day);
                        printf("\t\t\t\t   ��==========================================	��\n");
                        printf("\t\t\t\t   ��������������������������������������������������������������������������������������������\n");




                    }

                    p2 = p2->next;

                }

                if (flag == 0) {
                    printf("���޴���Ʒ. . .");
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
                }

                system("pause");
                system("cls");


                break;

            case '3'://�˳�
                printf("ʹ����ϣ�\n");
                system("pause");
                system("cls");
                return;


            default:
                getchar();
                printf("������������������룺\n");
                system("pause");
                break;

        }

    }

}




void amendInformation() {
    SHOP *p2; //��ʼ���ṹ��ָ��p2

    int opt_c;	//�û�����ѡ��
    //int choose;
    int flag;	//�ж����

    char s_ID[10];	//��������
    char s_number[10];	//���ձ��

    int content; 	//�û�����ѡ��
    int content1; 	//�û�����ѡ��

    p2 = head;


    printf("\n");
    printf("\t\t\t\t\t\t��-----------------��\n");;
    printf("\t\t\t\t\t\t |1.��Ų�ѯ�޸�  |\n");
    printf("\t\t\t\t\t\t |2.���Ʋ�ѯ�޸�  |\n");
    printf("\t\t\t\t\t\t |3.�˳��޸�      |\n");
    printf("\t\t\t\t\t\t��-----------------��\n");


    //rewind(stdin);
    printf("��ѡ��\n");
    scanf("%d", &opt_c);


    while (opt_c != 3) {

        if (opt_c == 1) { //��Ų�ѯ

            system("pause");
            system("cls");

            p2 = head;
            printf("\n\n");
            printf("\t\t\t\t   ��=========================================== ��\n");
            printf("\t\t\t\t   �� �������ţ�             		        ��\n");
            printf("\t\t\t\t   ��=========================================== ��\n");
            cursor(54, 3);
            scanf("%s", &s_number);
            flag = 0;

            while (p2 != NULL) {
                if (strcmp(s_number, p2->number) == 0) {
                    flag = 1;
                    printf("\n\n");
                    //p2 = head;
                    printf("\t\t\t\t   �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r\n");
                    printf("\t\t\t\t   ��                 �޸���Ʒ��Ϣ               ��\n");
                    printf("\t\t\t\t   �t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
                    printf("\t\t\t\t   ����������������������������������������������������������������������������������������-��\n");
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� 1.���ࣺ%s             			��\n", p2->type);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� 2.���ƣ�%s            			��\n", p2->ID);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� 3.�۸�%s              		\t��\n", p2->price);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� 4.��棺%d            			��\n", p2->amount);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� 5.������%d             			��\n", p2->sale);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� 6.����ʱ��:%s            		        ��\n", p2->saletime);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� 7.���أ�%s            			��\n", p2->buyer);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� 8.��������:	%s            		        ��\n", p2->date);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� 9.�����ڣ�%s             		\t��\n", p2->day);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   ��������������������������������������������������������������������������������������������\n");
                    fflush(stdin);

                    printf("������Ҫ�޸ĵ�����ѡ��(ǰ�������)��\n");
                    scanf("%d", &content);

                    switch (content) {
                        case 1:
                            printf("��������Ʒ���ࣺ\n");
                            scanf("%s", p2->type);
                            break;

                        case 2:
                            printf("��������Ʒ���ƣ�\n");
                            scanf("%s", p2->ID);
                            break;


                        case 3:
                            printf("��������Ʒ�۸�\n");
                            scanf("%s", &p2->price);
                            break;


                        case 4:
                            printf("��������Ʒ��棺\n");
                            scanf("%d", &p2->amount);
                            break;


                        case 5:
                            printf("��������Ʒ������\n");
                            scanf("%d", &p2->sale);
                            break;

                        case 6:
                            printf("��������Ʒ�������ڣ�\n");
                            scanf("%s", p2->saletime);
                            break;

                        case 7:
                            printf("��������Ʒ���أ�\n");
                            scanf("%s", p2->buyer);
                            break;

                        case 8:
                            printf("��������Ʒ�������ڣ�\n");
                            scanf("%s", p2->date);
                            break;

                        case 9:
                            printf("��������Ʒ�����ڣ�\n");
                            scanf("%s", p2->day);
                            break;

                        default:
                            printf("�����������������\n");
                            break;

                    }

                }

                p2 = p2->next;

            }


            if (flag == 0) {
                printf("�޸���Ʒ�����Ϣ. . .");
                printf("\n");
                break;
            }




            fflush(stdin);

            printf("�޸ĳɹ���\n");


            printf("\t\t\t����Ҫ�����޸���\n");
            printf("\t\t\t1.�ǵġ�\n\t\t\t2.�˳��޸�");
            scanf("%d", &opt_c);
            switch (opt_c) {
                case 1:
                    //TODO
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    //TODO
                    opt_c = 3;
                    system("pause");
                    system("cls");
                    break;
                default:
                    printf("��������Ѿ��Զ�Ϊ���˳�");//TODO
                    opt_c = 3;
                    system("pause");
                    system("cls");
                    break;
            }



        }

        else if (opt_c == 2 ) { //���Ʋ�ѯ�޸�

            system("pause");
            system("cls");

            p2 = head;

            printf("\n\n");
            printf("\t\t\t\t   ��=========================================== ��\n");
            printf("\t\t\t\t   �� ���������ƣ�             		        ��\n");
            printf("\t\t\t\t   ��=========================================== ��\n");

            cursor(50, 3);
            scanf("%s", &s_ID);
            flag = 0;


            while (p2 != NULL) {
                if (strcmp(s_ID, p2->ID) == 0) {
                    flag = 1;
                    printf("\n\n");

                    p2 = head;

                    printf("\t\t\t\t   �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r\n");
                    printf("\t\t\t\t   ��                 �޸���Ʒ��Ϣ               ��\n");
                    printf("\t\t\t\t   �t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
                    printf("\t\t\t\t   ����������������������������������������������������������������������������������������-��\n");
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� 1.���ࣺ%s             			��\n", p2->type);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� 2.���ƣ�%s            			��\n", p2->ID);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� 3.�۸�%s              		\t��\n", p2->price);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� 4.��棺%d            			��\n", p2->amount);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� 5.������%d             			��\n", p2->sale);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� 6.����ʱ��:%s            		        ��\n", p2->saletime);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� 7.���أ�%s            			��\n", p2->buyer);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� 8.��������:	%s            		        ��\n", p2->date);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� 9.�����ڣ�%s             		\t��\n", p2->day);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   ��������������������������������������������������������������������������������������������\n");

                    fflush(stdin);

                    printf("������Ҫ�޸ĵ�����ѡ��(ǰ�������)��\n");
                    scanf("%d", &content1);

                    switch (content1) {
                        case 1:
                            printf("��������Ʒ��ţ�\n");
                            scanf("%s", p1->number);
                            break;

                        case 2:
                            printf("��������Ʒ���ࣺ\n");
                            scanf("%s", p1->type);
                            break;


                        case 3:
                            printf("��������Ʒ�۸�\n");
                            scanf("%s", &p2->price);
                            break;


                        case 4:
                            printf("��������Ʒ��棺\n");
                            scanf("%d", &p1->amount);
                            break;


                        case 5:
                            printf("��������Ʒ������\n");
                            scanf("%d", &p1->sale);
                            break;

                        case 6:
                            printf("��������Ʒ�������ڣ�\n");
                            scanf("%s", p1->saletime);
                            break;

                        case 7:
                            printf("��������Ʒ���أ�\n");
                            scanf("%s", p1->buyer);
                            break;

                        case 8:
                            printf("��������Ʒ�������ڣ�\n");
                            scanf("%s", p1->date);
                            break;

                        case 9:
                            printf("��������Ʒ�����ڣ�\n");
                            scanf("%s", p1->day);
                            break;

                        default:
                            printf("����������������룺\n");
                            system("pause");
                            break;

                    }

                }


                p2 = p2->next;

            }

            if (flag == 0) {
                printf("�޸���Ʒ�����Ϣ. . .");
                printf("\n");
                break;
            }





            printf("�޸ĳɹ���\n");
            printf("\t\t\t����Ҫ�����޸���\n");
            printf("\t\t\t1.�ǵġ�\n\t\t\t2.�˳��޸�");
            scanf("%d", &opt_c);
            switch (opt_c) {
                case 1:
                    //TODO
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    //TODO
                    opt_c = 3;
                    system("pause");
                    system("cls");
                    break;
                default:
                    printf("��������Ѿ��Զ�Ϊ���˳�");//TODO
                    opt_c = 3;
                    system("pause");
                    system("cls");
                    break;
            }



        }


        else if (opt_c == 3 ) {
            printf("�ɹ��˳��޸ģ�\n");
            return;
        } else {
            printf("����������˳���\n");
            system("pause");
            system("cls");
            return;
        }

    }
}




void delInformation() {
    SHOP *p2;//�жϵĵ�ǰ�ڵ�
    SHOP *pb;//Ҫɾ���Ľڵ�����
    SHOP *pf;//Ҫɾ���Ľڵ��ǰ���ڵ�

    p2 = head;
    pf = head;
    pb = head;

    int ture;
    int flag;//�ж����

    int option;//�û������ѡ��
    int s_option;//�ж�ѡ��

    char S_id[20];//��ʱ�������
    char s_num[10];//��ʱ��ű��


    printf("\n");
    printf("\t\t\t\t\t\t��-----------------��\n");;
    printf("\t\t\t\t\t\t |1.��Ų�ѯɾ��  |\n");
    printf("\t\t\t\t\t\t |2.���Ʋ�ѯɾ��  |\n");
    printf("\t\t\t\t\t\t |3.�˳�ɾ��      |\n");
    printf("\t\t\t\t\t\t��-----------------��\n");

    rewind(stdin);
    printf("��ѡ��");
    scanf("%s", &option);


    switch (option) {

        case '1'://���ɾ��

            system("pause");
            system("cls");

            p2 = head;

            printf("\n\n");
            printf("\t\t\t\t   ��=========================================== ��\n");
            printf("\t\t\t\t   �� �������ţ�             		        ��\n");
            printf("\t\t\t\t   ��=========================================== ��\n");

            cursor(54, 3);
            scanf("%s", &s_num);

            while (pb != NULL ) {

                if (strcmp(s_num, pb->number) == 0) {
                    flag = 1;
                    printf("\n\n");
                    printf("\t\t\t\t   �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r\n");
                    printf("\t\t\t\t   ��                   ��Ʒ��Ϣ               ��\n");
                    printf("\t\t\t\t   �t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
                    printf("\t\t\t\t   ����������������������������������������������������������������������������������������-��\n");
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� ���ࣺ%s             			��\n", p2->type);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� ���ƣ�%s            			��\n", p2->ID);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� �۸�%s              		\t��\n", p2->price);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� ��棺%d            			��\n", p2->amount);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� ������%d             			��\n", p2->sale);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� ����ʱ��:%s            		        ��\n", p2->saletime);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� ���أ�%s            			��\n", p2->buyer);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� ��������:	%s            		        ��\n", p2->date);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� �����ڣ�%s             		\t��\n", p2->day);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   ��������������������������������������������������������������������������������������������\n");


                    printf("�Ƿ�ѡ��ɾ��?\n");
                    printf("1.yse	2.no\n");


                    printf("��ѡ��");
                    scanf("%d", &s_option);


                    if (s_option == 1) {

                        if (pb == head) { //�ж�pb�Ƿ�ָ��ͷ���
                            head = head->next;
                        } else {
                            pf->next = pb->next; //��pf����һ���ڵ����pb����һ���ڵ�
                        }





                        printf("����ɾ���ɹ���");
                        saveInformation();//�����ļ���Ϣ


                    } else if (s_option == 2) {
                        printf("ȡ��ɾ��!");
                    }
                }

                pf = pb;
                pb = pb->next;

            }
            if (flag == 0) {
                printf("�޸���Ʒ�����Ϣ. . .");
                printf("\n");
            }

            break;

        case '2':

            system("pause");
            system("cls");

            p2 = head;

            printf("\n\n");
            printf("\t\t\t\t   ��=========================================== ��\n");
            printf("\t\t\t\t   �� ���������ƣ�             		        ��\n");
            printf("\t\t\t\t   ��=========================================== ��\n");

            cursor(54, 3);
            scanf("%s", &S_id);

            while (pb != NULL ) {

                if (strcmp(S_id, pb->ID) == 0) {

                    flag = 1;
                    printf("\n\n");
                    //p2 = head;
                    printf("\t\t\t\t   �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r\n");
                    printf("\t\t\t\t   ��                   ��Ʒ��Ϣ               ��\n");
                    printf("\t\t\t\t   �t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
                    printf("\t\t\t\t   ����������������������������������������������������������������������������������������-��\n");
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� ���ࣺ%s             			��\n", p2->type);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� ���ƣ�%s            			��\n", p2->ID);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� �۸�%s              		\t��\n", p2->price);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� ��棺%d            			��\n", p2->amount);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� ������%d             			��\n", p2->sale);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� ����ʱ��:%s            		        ��\n", p2->saletime);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� ���أ�%s            			��\n", p2->buyer);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� ��������:	%s            		        ��\n", p2->date);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   �� �����ڣ�%s             		\t��\n", p2->day);
                    printf("\t\t\t\t   ��==========================================	��\n");
                    printf("\t\t\t\t   ��������������������������������������������������������������������������������������������\n");


                    printf("�Ƿ�ѡ��ɾ��?\n");
                    printf("1.yse	2.no\n");

                    printf("��ѡ��");
                    scanf("%d", &s_option);

                    if (s_option == 1) {

                        if (pb == head) { //�ж�pb�Ƿ�ָ��ͷ���
                            head = head->next;
                        } else {
                            pf->next = pb->next; //��pf����һ���ڵ����pb����һ���ڵ�
                        }




                        printf("����ɾ���ɹ���");
                        saveInformation();//�����ļ���Ϣ

                    } else if (s_option == 0) {
                        printf("ȡ��ɾ��!");
                    } else {
                        printf("�����������������\n");
                        continue;
                    }
                }

                pf = pb;
                pb = pb->next;

            }
            if (flag == 0) {
                printf("�޸���Ʒ�����Ϣ. . .");
                printf("\n");
            }

            break;

        case '3':	//�˳�ɾ��
            printf("ʹ��over��\n");
            break;

        default:
            printf("����������˳���\n");
            system("pause");
            system("cls");
            break;

    }

}
void sortInformation() {
    char chose;		//�û�ѡ��

    SHOP *pb;
    SHOP *pf;
    SHOP temp;	//��ʱ������ݵ�ַ
    SHOP *p2;	//������ʱ�ڵ�ָ�����

    p2 = head;

    while (chose != '3') {

        printf("\n");
        printf("\t\t\t\t\t\t��================��\n");;
        printf("\t\t\t\t\t\t |1�����ݿ������|\n");
        printf("\t\t\t\t\t\t |2�����ݼ۸�����|\n");
        printf("\t\t\t\t\t\t |3���˳�        |\n");
        printf("\t\t\t\t\t\t��================��\n");
        printf("\t\t\t\t\t\t");
        printf("��ѡ��");
        scanf("%s", &chose);

        //���������������
        if (chose == '1') {
            p2 = head;
            if (p2 == NULL) {
                //����Ϊ��
                printf("���������. . .\n");
                return ;

            }

            if (p2->next == NULL) {
                //������1���ڵ�
                printf("���ݽ�����һ��\n");
                return ;
            }

            while (p2->next != NULL) {	//p2����һ���ڵ㲻Ϊ��
                pb = p2->next;	//���ýڵ����ݸ�ֵ��pb

                while (pb != NULL) { //pb��Ϊ��
                    //��С��������
                    //ð������

                    if (p2->amount > pb->amount) { //pb��p2���бȽ�

                        //��������
                        temp = *p2;	//ȡamount��ֵ���н��� ������ʱ�ռ�
                        *p2 = *pb;	//pb�����ݸ�p2
                        *pb = temp;	//��ʱ��ŵ����ݸ�pb

                        //����ʱ����Ľڵ���ԭ�е�����ڵ��������
                        temp.next = p2->next;
                        p2->next = pb->next;
                        pb->next = temp.next;

                    }
                    pb = pb->next;//pbָ��β
                }
                p2 = p2->next;//p2ָ��β
            }
            printf("����ɹ����뷵�ش�ӡ�鿴. . .\n");
            system("pause");
            system("cls");
        }


            //�۸��������
        else if (chose == '2') {

            p2 = head;

            if (p2 == NULL) {
                //����Ϊ��
                printf("���������\n");
                system("pause");
                system("cls");
                return ;

            }

            if (p2->next == NULL) {
                //������1���ڵ�
                printf("���ݽ�����һ��\n");
                system("pause");
                system("cls");
                return ;
            }

            while (p2->next != NULL) { //��p2ָ��Ľڵ�Ϊ��׼�ڵ�
                pb = p2->next;//pb�ӻ�׼�����һ���ڵ㿪ʼ
                while (pb != NULL) {
                    //��С��������
                    //ð������
                    if (p2->price > pb->price) {
                        temp = *p2;
                        *p2 = *pb;
                        *pb = temp;
                        temp.next = p2->next;
                        p2->next = pb->next;
                        pb->next = temp.next;

                    }
                    pb = pb->next;
                }
                p2 = p2->next;
            }

            printf("����ɹ����뷵�ش�ӡ�鿴. . .\n");
            system("pause");
            system("cls");

        }

            //�˳�
        else if (chose == '3') {
            system("pause");
            system("cls");
            break;
            //return 1;
        } else {
            printf("����������������룡\n");
            system("pause");

        }

    }


}
void findOrderInformation(userInf loginUser) {
    OrderMenu(loginUser);
}
