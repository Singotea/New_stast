#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char text = '\0';
    struct Box
    { //  ÿ�����ݽṹ�洢��һ����ָ��
        //  ������
        unsigned b_data;
        //  �ṹָ����
        struct Box *next; //  ��һλ
        struct Box *prev; //  ��һλ
    };
    struct Box *current = NULL;                //  ��ǰ
    struct Box *next_or_prev = NULL;           //  ��һλ
    struct Box *end = NULL;                    //  ����λ
    struct Box *first = NULL;                  //  ��ʼλ
    printf(" \n this is a ˫���������ݽṹ \n "); //  �����ֵ--��һ�������ֵ���һ����ʾ
    for (;;)                                   //  ����ѭ��
    {
        printf("\n ���������� n ����������:  ");
        scanf("%c", &text);
        if (text == 'n')
        {
            end = current;
            break;
        }
        current = (struct Box *)calloc(1, sizeof(struct Box));
        while (getchar() != '\n')
            ;
        printf("\n ����������:  ");
        scanf("%u", &current->b_data);
        if (first == NULL)
        {
            first = current; //  ��һ��
            current->prev = NULL;
        }
        else
        {
            next_or_prev->next = current;
            current->prev = next_or_prev;
        }
        current->next = NULL;   //  ÿ�ν���ǰ���ָ�� �����һ����׼�� ���������ָ�뽫���´�ѭ��ǰ������޸�
        next_or_prev = current; //  ÿ�ν���ǰ�洢Ϊ��һ�� �´�ѭ��������� previous
        while (getchar() != '\n');
    }
    current = first;
    printf("˳���-------------------------\nb_data:  ");
    for (;;)
    {
        if (current == NULL)
            break;
        printf(" %u ", current->b_data);
        next_or_prev = current;  //  �˴���current����previous  ��һλ
        current = current->next; //  �˴�����һλ����current ����ѭ����ȡ��һλ
    }
    printf("\n");
    current = end;
    printf("�����-------------------------\nb_data:  ");
    for (;;)
    {
        if (current == NULL)
            break;
        printf(" %u ", current->b_data);
        next_or_prev = current;  //  �˴���current����previous ʵ������Ϊ��һλ
        current = current->prev; //  �˴�����һλ����current ����ѭ����ȡ��һλ
        free(next_or_prev);      //  ���Ѵ�ӡ��ָ���ͷ� ��ǰλ�Ѵ���next_or_prev
    }
    printf("\n");
    system("pause");   
    
}