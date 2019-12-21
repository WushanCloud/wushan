#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#if 1

char* lookup(char *token,char * temp)
{
	if (!strcmp(token, "while")) 
	{
		strcpy(temp, "-"); return("1");
	} 
	else if (!strcmp(token, "if"))
	{
		strcpy(temp, "-"); return("2");
	}
	else if (!strcmp(token, "else"))
	{
		strcpy(temp, "-"); return("3");
	}
	else if (!strcmp(token, "switch"))
	{
		strcpy(temp, "-"); return("4");
	}
	else if (!strcmp(token, "case"))
	{
		strcpy(temp, "-"); return("5");
	}
	else if (*token >= 97 && *token <= 122)
	{
		strcpy(temp, token);return("6");
	}
	else if (*token >= 48 && *token <= 57) 
	{
		strcpy(temp, token);return ("7");
	}
	else if (*token == '+') 
	{
		strcpy(temp, token); return("-");
	}
	else if (*token == '-') 
	{
		strcpy(temp, token); return("-");
	}
	else if (*token == '*')
	{
		strcpy(temp, token); return("-");
	}
	else if (!strcmp(token, "<="))
	{
		strcpy(temp, "LE"); return("relop");
	}
	else if (*token == '<') 
	{
		strcpy(temp, "LT"); return("relop");
	}
	else if (!strcmp(token, "=="))
	{
		strcpy(temp, "EQ"); return("relop");
	}
	else if (*token == '=')
	{
		strcpy(temp, "-"); return("\"=\"");
	}
	else if (*token == ';')
	{
		strcpy(temp, "-"); return("\";\"");
	}
	else { printf("error!\n"); return " "; }
}
void cleaner(char* t)
{
	for (int i = 0; i < 10; i++)
	{
		*(t + i) = '\0';
	}
}
int main()
{
	char word[50] = {0};
	char token[10] = {0};
	char temp[10] = {0};
	int i = 0, c;
	while ((c = getchar()) != '#')
	{
		word[i] = c;
		i++;
	}
	word[i] = '#';
	i = 0;
	while (word[i] != '#')
	{
		int k = i;
		while (word[i] != ' '&& word[i] != '#')
		{
			i++;
		}
		strncpy(token, &word[k], i - k);
		printf("(%s, %s)\n", lookup(token,temp),temp);
		cleaner(token);
		cleaner(temp);
		while (word[i] == ' ') i++;
	}
	return 0;
}
#endif