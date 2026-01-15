#include <iostream>

void selectionSort(int arr[], int size)
{
    int min;
    int minIndex;

    for (int i = 0; i < size - 1; i++)
    {
        min = arr[i];
        minIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minIndex = j;
            }
        }

        arr[minIndex] = arr[i];
        arr[i] = min;
    }
}