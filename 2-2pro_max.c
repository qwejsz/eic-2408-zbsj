#define _CRT_SECURE_NO_WARNINGS  // 禁用Visual Studio的安全警告  
#include<stdio.h>    
#include<string.h>    
#define MAX_GOODS 5              // 最多货物种类数量  
#define MAX_BACK 3               // 最多可回退的操作次数  

int main() {
    char name[MAX_GOODS][10] = { }; // 存储货物名称的二维数组  
    int price[MAX_GOODS], num[MAX_GOODS]; // 存储货物价格和数量的数组  
    int channel; // 通道号  
    char s[10];  // 临时字符串，用于读取输入  

    // 放置货物循环  
    printf("放置货物（货品 通道 数量 价格）（输入END结束）：\n");
    while (1) {
        scanf(" %9s", s); // 读取货物名称  
        if (strcmp(s, "END") == 0) break; // 如果输入END，则退出循环  

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

    // 购买循环  
    while (1) {
        // 显示当前货品信息  
        printf("\n货品信息：\n");
        for (channel = 1; channel <= MAX_GOODS; channel++) {
            if (strlen(name[channel - 1]) == 0) {
                printf("通道%d:       空 闲\n", channel);
            }
            else {
                printf("通道%d： %s 共%d个 单价%d元\n", channel, name[channel - 1], num[channel - 1], price[channel - 1]);
            }
        }

        // 用户选择购买或回退  
        printf("\n请选择货物（货品 通道 数量）\n");
        printf("（输入END结束、输入BACK回退）：\n");

        int total = 0, need; // 总金额  
        int back_stack_size = 0; // 回退堆栈大小  
        int needs[100], channels[100]; // 用于存储购买历史的数组  
        static int backcount = 0; // 回退计数器，静态变量以跨函数调用保持值  

        while (1) {
            // 读取用户输入  
            scanf(" %9s", s);
            if (strcmp(s, "END") == 0) break; // 如果输入END，则退出购买循环  

            if (strcmp(s, "BACK") == 0) {
                // 处理回退逻辑  
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
                num[channel - 1] += need; // 恢复库存  
                total -= need * price[channel - 1]; // 减少总金额  
                backcount++;
                printf("回退成功，退回%d号通道货品 %s 共%d个\n", channel, name[channel - 1], need);
                continue;
            }

            // 读取通道号和数量  
            scanf("%d", &channel);
            scanf("%d", &need);

            // 检查输入是否有效  
            if (channel < 1 || channel > MAX_GOODS || strcmp(name[channel - 1], s) != 0 || need > num[channel - 1]) {
                printf("选择有误或库存不足\n");
                continue;
            }

            // 处理购买逻辑  
            num[channel - 1] -= need; // 减少库存  
            total += need * price[channel - 1]; // 增加总金额  
            printf("购买成功，购入%d号通道货品 %s 共%d个\n", channel, name[channel - 1], need);
            needs[back_stack_size] = need;
            channels[back_stack_size++] = channel;
            backcount = 0; // 重置回退计数器  
        }

        // 投币和找零逻辑  
        int money = 0, per;
        printf("\n应付：%d元\n", total);
        while (total > money) {
            printf("请投币：1元/2元/5元\n");
            scanf("%d", &per);
            if (per == 1 || per == 2 || per == 5) {
                money += per;
            }
            else {
                printf("无效投币\n");
            }
        }

        printf("找零：%d元\n", money - total);

        // 询问用户是否继续交易  
        printf("是否继续交易？（y/n）：\n");
        char cont;
        scanf(" %c", &cont);
        if (cont != 'y' && cont != 'Y') break; // 如果输入不是y或Y，则退出购买循环  
    }

    return 0;
}