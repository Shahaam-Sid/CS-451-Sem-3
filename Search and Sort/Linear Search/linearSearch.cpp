#include <iostream>

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