#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>  

int main()
{
    int t, s = 0, p, c = 0; // total�ܼ�, sum�ܻ���, per����Ͷ��, change����  
    printf("�������ܼۣ�\n");
    scanf("%d", &t);

    while (s < t)
    {
        printf("��Ͷ�ң�һԪ(1) ��Ԫ(2) ��Ԫ(5)\n");
        scanf("%d", &p);
        if (p == 1 || p == 2 || p == 5) //
            s += p; // �ۼ�Ͷ�ҽ��  
        else
        {
            printf("����ֻ��ͶһԪ����Ԫ����Ԫ��Ӳ�ҡ�\n"); // ���������Ϣ������
        }
    }

    c = s - t; // ��������  
    printf("���㣺%dԪ\n", c); // ���������  

    printf("(����س��Թر�)");//����������������
    char a = getchar();
    scanf("%c", &a);
    printf("%c", a);

    return 0;
}