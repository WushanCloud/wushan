#include<stdio.h>

#define N 4

int main()
{
	int arr[N][N];
	int i, j;
	int count;
	/* 初始化 */
	for (i = 0; i < N; i++)
		for ( j = 0; j < N; j++)
		{
			arr[i][j] = 0;
		}

	i = 0, j = 0;
	count = 1;
	//arr[0][0] = count++;
	while (i < N)
	{
		arr[i][j] = count;
		if (i == 0)
		{
			i = j + 1;
			j = 0;
		}
		else
		{
			i--;
			j++;
		}
		
		count++;
	}
	/*打印*/
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	/* 初始化 */
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			arr[i][j] = 0;
		}

	i = 3, j = 0;
	count = 1;
	int temp = 1;
	while (arr[N-1][N-1] == 0)
	{
		arr[i][j] = count;
		if (j == N-1)
		{
			i = N-1;
			j = temp++;
		}
		else
		{
			i--;
			j++;
		}
		count++;
	}
	
	/*打印*/
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

