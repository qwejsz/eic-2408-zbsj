#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>  
#include<string.h>  
#define MAX_GOODS 5  

int main() {
    char name[MAX_GOODS][50]; // ��������  
    int price[MAX_GOODS], num[MAX_GOODS]; //  �۸������  
    int channel;//ͨ��
    char s[50];
      
        // ���û���
        printf("���û����Ʒ ͨ�� ���� �۸񣩣�����END��������\n");
        while (1) {
            scanf(" %s", s);
            if (strcmp(s, "END") == 0) break;
            scanf("%d", &channel);
            if (channel <= 0 || channel > MAX_GOODS) {
                printf("ͨ�������Ч\n");
                continue;
            }
            strcpy(name[channel-1], s);
            scanf("%d", &num[channel-1]);            
            scanf("%d", &price[channel-1]);
        }
    
    while (1) {//��ѭ��ʵ�ֶ�ι���
        int total = 0, need;//Ӧ���ܼۺ͹�������
        // ѡ�����          
        printf("��ѡ�����(��Ʒ ͨ�� ������������END��������\n");
        while (1) {
            scanf(" %s", s);
            if (strcmp(s, "END") == 0) break;
            scanf("%d", &channel);
            scanf("%d", &need);
            if (channel < 0 || channel >MAX_GOODS || need > num[channel-1]
                || strcmp(name[channel-1], s) != 0){
                printf("��������\n");
                continue;
            }
            num[channel-1] -= need;
            total += need * price[channel-1];
        }
        
        // Ͷ��
        int money = 0,per;//ʵ���ܼۺ͵���Ͷ��
        while (total > money) {
            printf("��Ͷ�ң�1Ԫ/2Ԫ/5Ԫ\n");
            scanf("%d", &per);
            if (per == 1 || per == 2 || per == 5) {
                money += per;
            }
            else{    
            printf("��ЧͶ��\n");
            }
        }

        // �������  
        printf("���㣺%dԪ\n", money - total);

        // �˳�ѭ��
        printf("�Ƿ�������ף���y/n����\n");
        char cont;  
        scanf(" %c", &cont);
        if (cont != 'y' && cont != 'Y') break;  
    }

    return 0;
}
