#include <iostream>

int binarySearchMulti(int arr[], int x, int size, int indexes[]) {
    int count = 0;
    int l = 0;
    int r = size - 1;

    while (l <= r)
    {
        int m = (l + r) / 2;
        
        if (arr[m] == x)
        {
            for (int i = m - 1; i >= 0; i--)
            {
                if (arr[i] == x)
                {
                    indexes[count] = i;
                    count++;
                } 
                else
                {
                    break;
                }
            }
            
            indexes[count] = m;
            count++;
            
            for (int i = m + 1; i < size; i++)
            {
                if (arr[i] == x)
                {
                    indexes[count] = i;
                    count++;
                } 
                else
                {
                    break;
                }   
            }
            break;
        }
        else if (arr[m] < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    
    return count;
}