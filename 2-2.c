#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>  
#include<string.h>  
#define MAX_GOODS 5  

int main() {
    char name[MAX_GOODS][10]; // ��������  
    int price[MAX_GOODS], num[MAX_GOODS]; //  �۸������  
    int channel;//ͨ��
    char s[10];

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
        strcpy(name[channel - 1], s);
        scanf("%d", &num[channel - 1]);
        scanf("%d", &price[channel - 1]);
    }

    while (1) {//��ѭ��ʵ�ֶ�ι���     
        printf("��ѡ������Ʒ ͨ�� ������\n");
        printf("������END����������BACK���ˣ���\n");

        int total = 0, need;//Ӧ���ܼۺ͹�������
        while (1) {//��һ�ι���
            scanf(" %s", s);
            if (strcmp(s, "END") == 0) return 0;//���빺���κλ�Ʒ������ENDֱ���˳�������ѡ���Ƿ��������
            if (strlen(s) != 1) {//�涨��ƷΪ������д��ĸ�����򱨴��ɷ�ֹ��δ�����κλ�Ʒ������BACK���𱨴�
                printf("��������\n");
                continue;
            }
            scanf("%d", &channel);
            scanf("%d", &need);
            if (channel < 0 || channel >MAX_GOODS|| strcmp(name[channel - 1], s) != 0) {
                printf("ͨ����������\n");
                continue;
            }
            if (need > num[channel - 1]) {
                printf("��治��\n");
                continue;
            }
            num[channel - 1] -= need;//����ɹ���������
            total += need * price[channel - 1];//����ɹ���Ӧ���ܼ�����
            break;//��δ���в������ܻ���
        }

        int chance = 3;//���˻���
        while (1) {//��N�ι���N>=2
        scanf(" %s", s);
            if (strcmp(s, "END") == 0) break;//����������룬����END��ʼ���㣬����ѡ���Ƿ��������
            if (strcmp(s, "BACK") == 0) {//����BACK�����ϴβ���
                if (chance > 0) {
                    chance--;//���˻������
                    num[channel - 1] += need;//���ϴμ�ȥ�Ŀ��ӻ�
                    total -= need * price[channel - 1];//���ϴμ��ϵķ��ü�ȥ
                    printf("���˳ɹ���ʣ����˴�����%d\n", chance);
                    continue;
                }
                if (chance == 0) {
                    printf("���˴������㣬����ʧ��\n");
                    continue;
                }
            }
            scanf("%d", &channel);//ͬ��һ�ι���
            scanf("%d", &need);
            if (channel < 0 || channel >MAX_GOODS || strcmp(name[channel - 1], s) != 0) {
                printf("ͨ����������\n");
                continue;
            }
            if (need > num[channel - 1]) {
                printf("��治��\n");
                continue;
            }
            num[channel - 1] -= need;
            total += need * price[channel - 1];
        }

        int money = 0, per;//ʵ���ܼۺ͵���Ͷ��
        printf("��Ͷ�ң�1Ԫ/2Ԫ/5Ԫ\n");
        while (total > money) {//Ͷ��
            scanf("%d", &per);
            if (per == 1 || per == 2 || per == 5) {
                money += per;
            }
            else {
                printf("��ЧͶ��\n");
            }
        }
       
        printf("���㣺%dԪ\n", money - total);// �������  

        printf("�Ƿ�������ף���y/n����\n");
        char cont;
        scanf(" %c", &cont);
        if (cont != 'y' && cont != 'Y') break;//�˳�ѭ��
    }
    return 0;
}