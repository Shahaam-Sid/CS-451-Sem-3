#include <iostream>

void bubbleSort(int arr[], int size);

int main()
{
    int nums[] = {7, 12, 9, 11, 3};
    int len = sizeof(nums) / sizeof(int);

    bubbleSort(nums, len);

    std::cout << "Sorted Array:" << std::endl;
    for (int i = 0; i < len; i++)
    {
        std::cout << nums[i] << " ";
    }
    
    return 0;
}

void bubbleSort(int arr[], int size) {

    int temp;
    bool swapped;

    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) {break;}
        
    }
}