#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int c, n, p=0;//channelͨ����number��Ŀ��price�۸�
	char g = 'A';//goods��Ʒ

	printf("�����������Ʒ ͨ�� ��Ŀ �۸�\n");
	scanf("%c %d %d %d", &g, &c, &n, &p);
	printf("%d: ", c);
	
	int i = 0;
	while (i <n)
	{
		printf("%c ", g);
		i++;
	}	
	printf("%d\n", p);

	printf("(����س��Թر�)");//����������������
	char a = getchar();
	scanf("%c", &a);
	printf("%c", a);

	return 0;
}