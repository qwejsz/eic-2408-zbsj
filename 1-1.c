#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int c, n, p=0;//channel通道，number数目，price价格
	char g = 'A';//goods货品

	printf("请依次输入货品 通道 数目 价格\n");
	scanf("%c %d %d %d", &g, &c, &n, &p);
	printf("%d: ", c);
	
	int i = 0;
	while (i <n)
	{
		printf("%c ", g);
		i++;
	}	
	printf("%d\n", p);

	printf("(点击回车以关闭)");//方便程序运行所添加
	char a = getchar();
	scanf("%c", &a);
	printf("%c", a);

	return 0;
}