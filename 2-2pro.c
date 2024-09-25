#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>  
#include<string.h>  
#define MAX_GOODS 5
#define MAX_BACK 3

int main() {
    char name[MAX_GOODS][10] = { }; // 货物名称  
    int price[MAX_GOODS], num[MAX_GOODS]; //  价格和数量  
    int channel;//通道
    char s[10];

    // 放置货物
    printf("放置货物（货品 通道 数量 价格）（输入END结束）：\n");
    while (1) {
        scanf(" %9s", s); // 读取货物名称，限制长度为9以防溢出  
        if (strcmp(s, "END") == 0) break; // 如果输入END则退出循环  

        scanf(" %d", &channel); // 读取通道号 
        scanf(" %d", &num[channel - 1]); // 读取数量  
        scanf(" %d", &price[channel - 1]); // 读取价格 
        if (strlen(name[channel - 1]) != 0) { // 检查通道是否已被使用  
            printf("通道%d已被占用，不能放置另一种货品\n", channel);
            continue; // 通道已占用，跳过本次循环  
        }
        if (channel <= 0 || channel > MAX_GOODS) {
            printf("通道序号无效\n");
            continue; // 无效的通道号，跳过本次循环  
        }
        strcpy(name[channel - 1], s); // 将货物名称存储到对应通道  
    }

    while (1) { // 购买循环  
        printf("请选择货物（货品 通道 数量）\n");
        printf("（输入END结束、输入BACK回退）：\n");

        int total = 0;
        int back_stack_size = 0;
        int needs[100], channels[100]; // 用于存储购买历史  
        static int backcount = 0;

        while (1) {
            char s[10];
            int channel, need;
            scanf(" %9s", s);
            if (strcmp(s, "END") == 0) break;
            if (strcmp(s, "BACK") == 0) {
                if (back_stack_size == 0) {
                    printf("无操作可回退\n");
                    continue;
                }
                if (backcount >= MAX_BACK) {
                    printf("回退失败，最多连续回退3次\n");
                    continue;
                }    
                need = needs[--back_stack_size];
                channel = channels[back_stack_size];
                num[channel - 1] += need;
                total -= need * price[channel - 1];
                backcount++;
                printf("回退成功\n");
                continue;
            }

            scanf("%d", &channel);
            scanf("%d", &need);

            if (channel < 1 || channel > MAX_GOODS || strcmp(name[channel - 1], s) != 0 || need > num[channel - 1]) {
                printf("选择有误或库存不足\n");
                continue;
            }

            num[channel - 1] -= need;
            total += need * price[channel - 1];
            needs[back_stack_size] = need;
            channels[back_stack_size++] = channel;
            backcount = 0;
        }

        int money = 0, per;//实付总价和单次投币
       
        while (total > money) {//投币
            printf("请投币：1元/2元/5元\n");
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