#include <iostream>

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