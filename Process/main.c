#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
void process()
{
	const char* tag = "|/-\\";
	char arr[51] = { 0 };

	for (int i = 0; i < 50; i++)
	{
		arr[i] = '#';
		printf("[%c %-50s][%d%%]\r", tag[i % 4], arr,(i+1)*2);
		fflush(stdout);//Çå³ý»º³åÇø
		Sleep(100);
	}

	printf("\n");
}

int main()
{
	process();
	return 0;
}