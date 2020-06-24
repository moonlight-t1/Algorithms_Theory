#include <stdio.h>

void ft_sort_int_tab(int *tab, int size)
{
    int i = 0;
    int j;
    int tmp;

    while (i < size - 1)
    {
        j = 0;
        while (j < size - (i + 1))
        {
            // exchange
            if (tab[j] > tab[j + 1])
            {
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};

    printf("Before Sorted\n");
    printArray(values, 8);

    ft_sort_int_tab(values, 8);

    printf("After Sorted\n");
    printArray(values, 8);

    return 0;
}

void printArray(int value[], int count)
{
    int i = 0;
    for (i = 0; i < count; i++)
    {
        printf("%d ", value[i]);
    }
    printf("\n");
}