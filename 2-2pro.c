#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>  
#include<string.h>  
#define MAX_GOODS 5
#define MAX_BACK 3

int main() {
    char name[MAX_GOODS][10] = { }; // ��������  
    int price[MAX_GOODS], num[MAX_GOODS]; //  �۸������  
    int channel;//ͨ��
    char s[10];

    // ���û���
    printf("���û����Ʒ ͨ�� ���� �۸񣩣�����END��������\n");
    while (1) {
        scanf(" %9s", s); // ��ȡ�������ƣ����Ƴ���Ϊ9�Է����  
        if (strcmp(s, "END") == 0) break; // �������END���˳�ѭ��  

        scanf(" %d", &channel); // ��ȡͨ���� 
        scanf(" %d", &num[channel - 1]); // ��ȡ����  
        scanf(" %d", &price[channel - 1]); // ��ȡ�۸� 
        if (strlen(name[channel - 1]) != 0) { // ���ͨ���Ƿ��ѱ�ʹ��  
            printf("ͨ��%d�ѱ�ռ�ã����ܷ�����һ�ֻ�Ʒ\n", channel);
            continue; // ͨ����ռ�ã���������ѭ��  
        }
        if (channel <= 0 || channel > MAX_GOODS) {
            printf("ͨ�������Ч\n");
            continue; // ��Ч��ͨ���ţ���������ѭ��  
        }
        strcpy(name[channel - 1], s); // ���������ƴ洢����Ӧͨ��  
    }

    while (1) { // ����ѭ��  
        printf("��ѡ������Ʒ ͨ�� ������\n");
        printf("������END����������BACK���ˣ���\n");

        int total = 0;
        int back_stack_size = 0;
        int needs[100], channels[100]; // ���ڴ洢������ʷ  
        static int backcount = 0;

        while (1) {
            char s[10];
            int channel, need;
            scanf(" %9s", s);
            if (strcmp(s, "END") == 0) break;
            if (strcmp(s, "BACK") == 0) {
                if (back_stack_size == 0) {
                    printf("�޲����ɻ���\n");
                    continue;
                }
                if (backcount >= MAX_BACK) {
                    printf("����ʧ�ܣ������������3��\n");
                    continue;
                }    
                need = needs[--back_stack_size];
                channel = channels[back_stack_size];
                num[channel - 1] += need;
                total -= need * price[channel - 1];
                backcount++;
                printf("���˳ɹ�\n");
                continue;
            }

            scanf("%d", &channel);
            scanf("%d", &need);

            if (channel < 1 || channel > MAX_GOODS || strcmp(name[channel - 1], s) != 0 || need > num[channel - 1]) {
                printf("ѡ��������治��\n");
                continue;
            }

            num[channel - 1] -= need;
            total += need * price[channel - 1];
            needs[back_stack_size] = need;
            channels[back_stack_size++] = channel;
            backcount = 0;
        }

        int money = 0, per;//ʵ���ܼۺ͵���Ͷ��
       
        while (total > money) {//Ͷ��
            printf("��Ͷ�ң�1Ԫ/2Ԫ/5Ԫ\n");
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