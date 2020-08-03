#include <stdio.h>

int main(void)
{
	int i, j, min, index, temp;
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

	for (i = 0; i < 10; i++)
	{
		min = 9999;
		// i부터 끝까지 최솟값 찾기
		for (j = i; j < 10; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				index = j;
			}
		}
		// 최솟값을 찾은 후 i의 위치와 교환해준다
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}
