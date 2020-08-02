#include <stdio.h>

int main(void)
{
	int i, j, temp;
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 9 - i; j++)
		{
			// 옆에 있는 값과 비교를 해 더 작은 값을 앞으로 보낸다
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}
