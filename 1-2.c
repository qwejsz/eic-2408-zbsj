#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>  

int main()
{
    int t, s = 0, p, c = 0; // total总价, sum总花费, per单次投入, change找零  
    printf("请输入总价：\n");
    scanf("%d", &t);

    while (s < t)
    {
        printf("请投币：一元(1) 两元(2) 五元(5)\n");
        scanf("%d", &p);
        if (p == 1 || p == 2 || p == 5) //
            s += p; // 累加投币金额  
        else
        {
            printf("错误：只能投一元、两元或五元的硬币。\n"); // 输出错误信息并换行
        }
    }

    c = s - t; // 计算找零  
    printf("找零：%d元\n", c); // 输出找零金额  

    printf("(点击回车以关闭)");//方便程序运行所添加
    char a = getchar();
    scanf("%c", &a);
    printf("%c", a);

    return 0;
}