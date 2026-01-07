#include <iostream>

int linearSearch(int arr[], int x, int size);

int main()
{

    int nums[] = {10, 23, 56, 59, 80};
    int x = 59;

    int len = sizeof(nums) / sizeof(int);

    std::cout << "Element " << x << " found at " << linearSearch(nums, x, len);
}


int linearSearch(int arr[], int x, int size)
{
    for(int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    std::cout << "Not Found in Array";
    return 0;
}