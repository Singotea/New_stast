#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 int main(void){
     char text = '\0';
    struct Box {  //  ÿ�����ݽṹ�洢��һ����ָ��
        //  ������
        unsigned b_data;
        //  �ṹָ����
        struct Box *next;
    };
    struct Box *current = NULL;  //  ��ǰ
    struct Box *previous = NULL;  //  ��һ��
    struct Box *first = NULL;  //  ��һ��
    printf("\nthis is a �������ݽṹ\n");  //  �����ֵ--��һ�������ֵ���һ����ʾ
    for(;;)  //  ����ѭ��
    {
        printf("\n���������� n ����������:  ");
        scanf("%c",&text);
        if(text =='n') break;
        current = (struct Box*)calloc(1,sizeof(struct Box));
        while( getchar() !='\n');
        printf("\n����������:  ");
        scanf("%u", &current->b_data);
        if(first == NULL){
        first = current;  //  ��һ��
        }
        if(previous!= NULL){  //  
            previous-> next = current;
        }
        current-> next = NULL;  //  ÿ�ν���ǰ���ָ�� �����һ����׼�� ���������ָ�뽫���´�ѭ��ǰ������޸�
        previous = current;  //  ÿ�ν���ǰ�洢Ϊ��һ�� �´�ѭ��������� previous
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