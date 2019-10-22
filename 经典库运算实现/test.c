#include <stdio.h>

char * my_strcpy(char *str1,const char *str2)
{

	char *head = str1;

	while (*str1++ = *str2++)
	{
	}
	*str1 = '\0';
	return head;
}
char * my_strcat(char *str1,const char *str2)
{
	char *head = str1;
	
	while (*str1)
	{
		str1++;
	}
	while (*str1++ = *str2++)
	{
	}
	*str1 = '\0';
	return head;
}
const char* my_strstr(const char* str1,const char* str2)//str1是原文档str2是要找的字符
{
	const char* start = str1;
	const char* sup = str2;
	while(*start)
	{
		while (*str1 == *sup && *sup != '\0')
		{
			str1++;
			sup++;
		}
		if(*sup == '\0')
		{
			return start;
		}
		else
		{
			str1 = start +1;
			sup = str2;
			start++;
		}
	}
	return NULL;
}
char *my_strchr( char *str, int c )
{
	while (*str) 
	{
		if (*str == c) 
		{
			return str;
		}
		str++;
	}
	return NULL;

}
int my_strcmp(const char* str1, const char* str2)
{
	while (*str1 && *str2)
	{
		if (*str1 > *str2)
		{
			return 1;
		}
		else if (*str1 < * str2)
		{
			return -1;
		}
		else
		{
			++str1;
			++str2;
		}
	}
	if (*str1 == '\0' && *str2 != '\0')
	{
		return -1;
	}
	else if (*str1 != '\0' && *str2 == '\0')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void * my_memcpy ( void * dst, const void * src, size_t count)
{
	char *p1 = (char*)dst;
	const char *p2 = (const char*)src;

	while (count--)
	{
		p1[count] = p2[count];
	}

}
void * my_memmove ( void * dst, const void * src, size_t count)
{
	char *p1 = (char *)dst;
	const char *p2 = (const char *)src;
	size_t i = 0;
	if (p1>p2 && p2+count>p1)
	{
		while (count--)
		{
			p1[count] = p2[count];
		}
	}
	else
	{
		for ( i = 0;i<count;i++)
		{
			p1[i] = p2[i];
		}
	}
}