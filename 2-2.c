#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>  
#include<string.h>  
#define MAX_GOODS 5  

int main() {
    char name[MAX_GOODS][10]; // 货物名称  
    int price[MAX_GOODS], num[MAX_GOODS]; //  价格和数量  
    int channel;//通道
    char s[10];

    // 放置货物
    printf("放置货物（货品 通道 数量 价格）（输入END结束）：\n");
    while (1) {
        scanf(" %s", s);
        if (strcmp(s, "END") == 0) break;

        scanf("%d", &channel);
        if (channel <= 0 || channel > MAX_GOODS) {
            printf("通道序号无效\n");
            continue;
        }
        strcpy(name[channel - 1], s);
        scanf("%d", &num[channel - 1]);
        scanf("%d", &price[channel - 1]);
    }

    while (1) {//此循环实现多次购买     
        printf("请选择货物（货品 通道 数量）\n");
        printf("（输入END结束、输入BACK回退）：\n");

        int total = 0, need;//应付总价和购买数量
        while (1) {//第一次购买
            scanf(" %s", s);
            if (strcmp(s, "END") == 0) return 0;//不想购买任何货品，输入END直接退出，无需选择是否继续购买
            if (strlen(s) != 1) {//规定货品为单个大写字母，否则报错，可防止还未购入任何货品就输入BACK引起报错
                printf("输入有误\n");
                continue;
            }
            scanf("%d", &channel);
            scanf("%d", &need);
            if (channel < 0 || channel >MAX_GOODS|| strcmp(name[channel - 1], s) != 0) {
                printf("通道输入有误\n");
                continue;
            }
            if (need > num[channel - 1]) {
                printf("库存不足\n");
                continue;
            }
            num[channel - 1] -= need;//购买成功，库存减少
            total += need * price[channel - 1];//购买成功，应付总价增加
            break;//还未进行操作不能回退
        }

        int chance = 3;//回退机会
        while (1) {//第N次购买，N>=2
        scanf(" %s", s);
            if (strcmp(s, "END") == 0) break;//不想继续购入，输入END开始结算，可以选择是否继续购买
            if (strcmp(s, "BACK") == 0) {//输入BACK回退上次操作
                if (chance > 0) {
                    chance--;//回退机会减少
                    num[channel - 1] += need;//将上次减去的库存加回
                    total -= need * price[channel - 1];//将上次加上的费用减去
                    printf("回退成功，剩余回退次数：%d\n", chance);
                    continue;
                }
                if (chance == 0) {
                    printf("回退次数不足，回退失败\n");
                    continue;
                }
            }
            scanf("%d", &channel);//同第一次购买
            scanf("%d", &need);
            if (channel < 0 || channel >MAX_GOODS || strcmp(name[channel - 1], s) != 0) {
                printf("通道输入有误\n");
                continue;
            }
            if (need > num[channel - 1]) {
                printf("库存不足\n");
                continue;
            }
            num[channel - 1] -= need;
            total += need * price[channel - 1];
        }

        int money = 0, per;//实付总价和单次投币
        printf("请投币：1元/2元/5元\n");
        while (total > money) {//投币
            scanf("%d", &per);
            if (per == 1 || per == 2 || per == 5) {
                money += per;
            }
            else {
                printf("无效投币\n");
            }
        }
       
        printf("找零：%d元\n", money - total);// 输出找零  

        printf("是否继续交易？（y/n）：\n");
        char cont;
        scanf(" %c", &cont);
        if (cont != 'y' && cont != 'Y') break;//退出循环
    }
    return 0;
}