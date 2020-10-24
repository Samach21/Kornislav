#include<stdio.h>

int findWidth(int*);
int findHeight(int*);

int main()
{
	int a[4];
	int width, height;
	for (int i = 0; i < 4; i++)
	{
		if (scanf_s("%d", &a[i]) != 1)
		{
			printf("ERROR");
			return 1;
		}
		else if (a[i] <= 0 || a[i] >= 100)
		{
			printf("ERROR");
			return 1;
		}
	}
	width = findWidth(&a[0]);
	height = findHeight(&a[0]);
	printf("%d", width * height);
	return 0;
}

int findWidth(int* x)
{
	int preresult = 4, result;
	for (int i = 0; i < 4; i++, x++)
	{
		if (*x <= preresult)
		{
			result = *x;
			preresult = *x;
		}
	}
	return result;
}

int findHeight(int* x)
{
	int preresult = 0, result;
	int premax = 0, max;
	int j;
	for (int i = 0; i < 4; i++, x++)
	{
		if (*x >= premax)
		{
			max = *x;
			premax = *x;
			j = i;
		}
	}
	*(x - (4 - j)) = 0;
	for (int i = 0; i < 4; i++, x--)
	{
		if (*x >= preresult)
		{
			result = *x;
			preresult = *x;
		}
	}
	return result;
}
