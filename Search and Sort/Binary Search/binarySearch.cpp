#include <iostream>

int binarySearch(int arr[], int x, int size) {
    int l = 0;
    int r = size - 1;
    int m = (l + r) / 2;

    while (l <= r)
    {
        if (arr[m] == x)
        {
            return m;
        }
        if (arr[m] < x)
        {
            l = m + 1;
            m = (l + r) / 2;
        }
        if (arr[m] > x)
        {
            r = m - 1;
            m = (l + r) / 2;
        }
    }
    
    std::cout << "Element not found in array";
    return 0;
}