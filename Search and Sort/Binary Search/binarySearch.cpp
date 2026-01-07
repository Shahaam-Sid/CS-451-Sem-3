#include <iostream>

int binarySearch(int arr[], int x, int size);


int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int x = 30;
    
    int len = sizeof(arr) / sizeof(int);
    std::cout << "Element " << x << " found at index " << binarySearch(arr, x, len);
    return 0;
}

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