#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>  

int main()
{
	int c, c0, n, n0, p0; // channel通道、number数目、price价格  
	char g, g0; // goods货品  

	printf("请依次输入货品 通道 数目 价格\n");
	scanf(" %c %d %d %d", &g0, &c0, &n0, &p0); 

	while (1) 
	{
		printf("输入需要购买的货品 通道 数量\n");
		scanf(" %c %d %d", &g, &c, &n);

		if (g == g0 && c == c0 && n <= n0) 
		{
			break; // 正确的输入，跳出循环  
		}
		else if (g != g0 || c != c0 || n > n0) 
		{
			printf("输入错误或货品不足，请重新输入\n");
		}
	}

	int t = p0 * n; // 计算总价  
	int sum = 0, ch = 0; // sum总花费, change找零  

	while (sum < t) {
		printf("请投币：一元(1) 两元(2) 五元(5)\n");
		int per;//per单次投入
		scanf("%d", &per);
		if (per == 1 || per == 2 || per == 5)
		{
			sum += per;
		}
		else
		{
			printf("错误：只能投一元、两元或五元的硬币。\n");
		}
	}

	ch = sum - t; // 计算找零  
	printf("找零：%d元\n", ch);

	printf("(点击回车以关闭)");//方便程序运行所添加
	char a = getchar();
	scanf("%c", &a);
	printf("%c", a);

	return 0;

}