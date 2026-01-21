#include <iostream>

void insertionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int hold = arr[i];
        int gap = i;
        while (gap > 0 && hold < arr[gap - 1])
        {
            if (hold < arr[gap - 1])
            {
                arr[gap] = arr[gap - 1];
                gap--;
            }
        }
        arr[gap] = hold;
    }
}