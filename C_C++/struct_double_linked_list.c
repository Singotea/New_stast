#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char text = '\0';
    struct Box
    { //  每个数据结构存储下一个的指针
        //  数据项
        unsigned b_data;
        //  结构指针项
        struct Box *next; //  下一位
        struct Box *prev; //  上一位
    };
    struct Box *current = NULL;                //  当前
    struct Box *next_or_prev = NULL;           //  上一位
    struct Box *end = NULL;                    //  结束位
    struct Box *first = NULL;                  //  起始位
    printf(" \n this is a 双向链表数据结构 \n "); //  倒序插值--第一个输入的值最后一个显示
    for (;;)                                   //  无限循环
    {
        printf("\n 结束请输入 n 否则继续添加:  ");
        scanf("%c", &text);
        if (text == 'n')
        {
            end = current;
            break;
        }
        current = (struct Box *)calloc(1, sizeof(struct Box));
        while (getchar() != '\n')
            ;
        printf("\n 请输入数据:  ");
        scanf("%u", &current->b_data);
        if (first == NULL)
        {
            first = current; //  第一个
            current->prev = NULL;
        }
        else
        {
            next_or_prev->next = current;
            current->prev = next_or_prev;
        }
        current->next = NULL;   //  每次结束前清空指针 做最后一个的准备 若不是最后指针将在下次循环前面进行修改
        next_or_prev = current; //  每次结束前存储为上一个 下次循环载入的是 previous
        while (getchar() != '\n');
    }
    current = first;
    printf("顺序表-------------------------\nb_data:  ");
    for (;;)
    {
        if (current == NULL)
            break;
        printf(" %u ", current->b_data);
        next_or_prev = current;  //  此处将current存入previous  上一位
        current = current->next; //  此处将下一位存入current 下轮循环读取下一位
    }
    printf("\n");
    current = end;
    printf("倒序表-------------------------\nb_data:  ");
    for (;;)
    {
        if (current == NULL)
            break;
        printf(" %u ", current->b_data);
        next_or_prev = current;  //  此处将current存入previous 实际是作为下一位
        current = current->prev; //  此处将上一位存入current 下轮循环读取上一位
        free(next_or_prev);      //  将已打印的指针释放 当前位已存入next_or_prev
    }
    printf("\n");
    system("pause");   
    
}