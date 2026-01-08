#include <iostream>

void selectionSort(int arr[], int size);

int main()
{
    int nums[] = {7, 12, 9, 11, 3};

    int len = sizeof(nums) / sizeof(int);

    selectionSort(nums, len);

    std::cout << "Sorted Array:" << std::endl;

    for (int i = 0; i < len; i++)
    {
        std::cout << nums[i] << " ";
    }
    
}

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