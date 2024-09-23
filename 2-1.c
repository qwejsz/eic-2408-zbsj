#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>  
#include<string.h>  
#define MAX_GOODS 5  

int main() {
    char name[MAX_GOODS][50]; // 货物名称  
    int price[MAX_GOODS], num[MAX_GOODS]; //  价格和数量  
    int channel;//通道
    char s[50];
      
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
            strcpy(name[channel-1], s);
            scanf("%d", &num[channel-1]);            
            scanf("%d", &price[channel-1]);
        }
    
    while (1) {//此循环实现多次购买
        int total = 0, need;//应付总价和购买数量
        // 选择货物          
        printf("请选择货物(货品 通道 数量）（输入END结束）：\n");
        while (1) {
            scanf(" %s", s);
            if (strcmp(s, "END") == 0) break;
            scanf("%d", &channel);
            scanf("%d", &need);
            if (channel < 0 || channel >MAX_GOODS || need > num[channel-1]
                || strcmp(name[channel-1], s) != 0){
                printf("输入有误\n");
                continue;
            }
            num[channel-1] -= need;
            total += need * price[channel-1];
        }
        
        // 投币
        int money = 0,per;//实付总价和单次投币
        while (total > money) {
            printf("请投币：1元/2元/5元\n");
            scanf("%d", &per);
            if (per == 1 || per == 2 || per == 5) {
                money += per;
            }
            else{    
            printf("无效投币\n");
            }
        }

        // 输出找零  
        printf("找零：%d元\n", money - total);

        // 退出循环
        printf("是否继续交易？（y/n）：\n");
        char cont;  
        scanf(" %c", &cont);
        if (cont != 'y' && cont != 'Y') break;  
    }

    return 0;
}
