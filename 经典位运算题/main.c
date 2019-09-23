#include <stdio.h>
#include <stdlib.h>
/*
1.编写函数：
unsigned int reverse_bit(unsigned int value);
这个函数的返回值是value的二进制位模式从左到右翻转后的值。

如：
在32位机器上25这个值包含下列各位：
00000000000000000000000000011001
翻转后：（2550136832）
10011000000000000000000000000000
程序结果返回：
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
	printf("%u\n", ret);//此处一定要用%u而不是%d的，因为若最高位为1，ret代表的是有符号数，其结果为负数
        return 0;}


2.不使用（a+b）/2这种方式，求两个数的平均值。


int main()
{
    int num1 = 0;
    int num2 = 0;
    scanf("%d%d", &num1, &num2);
    int avg = num1 - (num1 - num2) / 2;
    printf("%d", avg);
    return 0;
}
3.编程实现：
一组数据中只有一个数字出现了一次。
其他所有数字都是成对出现的。
请找出这个数字。（使用位运算）


int main()
{
    int arr[] = { 1, 5, 5, 1, 7, 6, 7, 8, 8,9,9};
    int i = 0;
    int len = sizeof(arr) / sizeof(arr[0]);


    for (i = 1; i < len; i++)
    {
        arr[0] = arr[0] ^ arr[i];//^异或运算符，相异为1想同为0.
    }
    printf("%d", arr[0]);
    return 0;
}

4.
有一个字符数组的内容为:"student a am i",
请你将数组的内容改为"i am a student".
要求：
不能使用库函数。
只能开辟有限个空间（空间个数和字符串的长度无关）。
*/

#include <string.h>
#include <assert.h>
void reverve_swap(char *left, char *right)
{
    assert(left != NULL); //断言不是空指针
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
    reverve_swap(p, p + len - 1); //逆序整个字符串
    while (*p)
    {
        start = p;
        while ((*p != ' ') && (*p != '\0')) //找到一块单词
        {
            p++;
        }
        end = p - 1;
        reverve_swap(start, end);//逆序单个单词
        if (*p == ' ') //找到空格
            p++;
    }
    return ret;

}
int main()
{
    char arr[] = "student a am I";
    printf("交换前：%s\n", arr);
    printf("交换后：%s\n", reverve(arr));
    return 0;
}
