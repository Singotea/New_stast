#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 int main(void){
     char text = '\0';
    struct Box {  //  每个数据结构存储下一个的指针
        //  数据项
        unsigned b_data;
        //  结构指针项
        struct Box *next;
    };
    struct Box *current = NULL;  //  当前
    struct Box *previous = NULL;  //  上一个
    struct Box *first = NULL;  //  第一个
    printf("\nthis is a 链表数据结构\n");  //  倒序插值--第一个输入的值最后一个显示
    for(;;)  //  无限循环
    {
        printf("\n结束请输入 n 否则继续添加:  ");
        scanf("%c",&text);
        if(text =='n') break;
        current = (struct Box*)calloc(1,sizeof(struct Box));
        while( getchar() !='\n');
        printf("\n请输入数据:  ");
        scanf("%u", &current->b_data);
        if(first == NULL){
        first = current;  //  第一个
        }
        if(previous!= NULL){  //  
            previous-> next = current;
        }
        current-> next = NULL;  //  每次结束前清空指针 做最后一个的准备 若不是最后指针将在下次循环前面进行修改
        previous = current;  //  每次结束前存储为上一个 下次循环载入的是 previous
         while( getchar() !='\n');
        
    }
    current = first;
    printf("-------------------------\nb_data:  ");
    for(;;)
    {
        if(current == NULL) break;
        printf(" %u ",current-> b_data);
        previous = current;
        current = current-> next;
        free(previous);
    }
    printf("\n");
    system("pause");
 }