#include <stdio.h>
#include <stdlib.h>
/*
1.��д������
unsigned int reverse_bit(unsigned int value);
��������ķ���ֵ��value�Ķ�����λģʽ�����ҷ�ת���ֵ��

�磺
��32λ������25���ֵ�������и�λ��
00000000000000000000000000011001
��ת�󣺣�2550136832��
10011000000000000000000000000000
���������أ�
2550136832

unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	int sum = 0;
	int b = 0;
	for (i=0; i<32; i++)
	{
		b = ((value>>i)&1)*pow(2,31-i);
		sum += b;
	}
	return sum;
}

int main()
{
	int a = 25;
	int ret = 0;
	ret = reverse_bit(a);
	printf("%u\n", ret);//�˴�һ��Ҫ��%u������%d�ģ���Ϊ�����λΪ1��ret��������з�����������Ϊ����
        return 0;}


2.��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ��


int main()
{
    int num1 = 0;
    int num2 = 0;
    scanf("%d%d", &num1, &num2);
    int avg = num1 - (num1 - num2) / 2;
    printf("%d", avg);
    return 0;
}
3.���ʵ�֣�
һ��������ֻ��һ�����ֳ�����һ�Ρ�
�����������ֶ��ǳɶԳ��ֵġ�
���ҳ�������֡���ʹ��λ���㣩


int main()
{
    int arr[] = { 1, 5, 5, 1, 7, 6, 7, 8, 8,9,9};
    int i = 0;
    int len = sizeof(arr) / sizeof(arr[0]);


    for (i = 1; i < len; i++)
    {
        arr[0] = arr[0] ^ arr[i];//^��������������Ϊ1��ͬΪ0.
    }
    printf("%d", arr[0]);
    return 0;
}

4.
��һ���ַ����������Ϊ:"student a am i",
���㽫��������ݸ�Ϊ"i am a student".
Ҫ��
����ʹ�ÿ⺯����
ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
*/

#include <string.h>
#include <assert.h>
void reverve_swap(char *left, char *right)
{
    assert(left != NULL); //���Բ��ǿ�ָ��
    assert(right != NULL);
    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}
char *reverve(char *p)
{
    int len = strlen(p);
    char *start = p;
    char *end = NULL;
    char *ret = p;
    reverve_swap(p, p + len - 1); //���������ַ���
    while (*p)
    {
        start = p;
        while ((*p != ' ') && (*p != '\0')) //�ҵ�һ�鵥��
        {
            p++;
        }
        end = p - 1;
        reverve_swap(start, end);//���򵥸�����
        if (*p == ' ') //�ҵ��ո�
            p++;
    }
    return ret;

}
int main()
{
    char arr[] = "student a am I";
    printf("����ǰ��%s\n", arr);
    printf("������%s\n", reverve(arr));
    return 0;
}
