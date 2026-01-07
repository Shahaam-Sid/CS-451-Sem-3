#include <iostream>

int linearSearchMulti(int arr[], int x, int size, int indexes[]);

int main()
{
    int nums[] = {10, 23, 56, 59, 23};
    int len = sizeof(nums) / sizeof(int);
    int indexes[len];

    int c = linearSearchMulti(nums, 23, len, indexes);

    std::cout << "Element " << c <<" Found: " << "at Indexes:" << std::endl;
    
    for (int i = 0; i < c; i++)
    {
        std::cout << indexes[i] << std::endl;    
    }
    
    return 0;
}

int linearSearchMulti(int arr[], int x, int size, int indexes[])
{
    int count = 0;
    
    for(int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            indexes[count] = i;
            count++;
        }
    }
    return count;   
}