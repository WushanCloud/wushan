#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<math.h>
#if 0
char a[20], optr[10], s, op;
int i, j, k, opond[10], x1, x2, x3;

int operand(char s) {
	if ((s >= '0') && (s <= '9'))   return(1);
	else  return(0);
}

int f(char s) {
	switch (s)
	{
	case'+': return(4);
	case'-': return(4);
	case'*': return(6);
	case'/': return(4);
	case'(': return(2);
	case')': return(6);
	case'#': return(0);
	default:printf("error!");
	}
}

int g(char s) {
	switch (s)
	{
	case'+':return(3);
	case'-':return(3);
	case'*':return(5);
	case'/':return(5);
	case'(':return(7);
	case')':return(2);
	case'#':return(0);
	default:printf("error!");
	}
}

void get() {
	s = a[i];
	i = i + 1;
}

int main() {
	printf("请输入表达式:\n");
	i = 0;
	do {
		i = i + 1;
		scanf("%c", &a[i]);
	} while (a[i] != '#');
	i = 1; j = k = 1;
	optr[j] = '#';
	get();
	while (!(optr[j] == '#' && (s == '#'))) {
		if (operand(s)) {
			opond[k] = s - 48;
			k = k + 1;
			get();
		}
		else if (f(optr[j]) > g(s)) {
			op = optr[j];
			j = j - 1;
			x1 = opond[k - 2];
			x2 = opond[k - 1];
			k = k - 2;
			switch (op) {
			case'+':x3 = x1 + x2; break;
			case'*':x3 = x1 * x2; break;
			case'-':x3 = x1 - x2; break;
			case'/':x3 = x1 / x2; break;
			}
			opond[k] = x3;
			k++;
			printf("(%c,%d,%d,%d)\n", op, x1, x2, x3);
		}
		else if (f(optr[j]) < g(s)) {
			j = j + 1;
			optr[j] = s;
			get();
		}
		else if (f(optr[j]) == g(s))
		{
			if (optr[j] == '(' || ')')
			{
				j = j - 1;
				get();
			}
			else printf("error!!!\n");
		}
		else printf("error!!!\n");
	}
	return 0;
}
#endif