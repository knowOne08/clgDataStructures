#include <stdio.h>


int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i; 
        }
    }
    return -1; 
}

int binarySearch(int arr[], int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {11, 22, 25, 34, 64, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    int linearKey = 34;
    int linearResult = linearSearch(arr, size, linearKey);

    if (linearResult != -1)
    {
        printf("Linear Search: Element %d found at index %d.\n", linearKey, linearResult);
    }
    else
    {
        printf("Linear Search: Element %d not found in the array.\n", linearKey);
    }

    int binaryKey = 64;
    int binaryResult = binarySearch(arr, 0, size - 1, binaryKey);

    if (binaryResult != -1)
    {
        printf("Binary Search: Element %d found at index %d.\n", binaryKey, binaryResult);
    }
    else
    {
        printf("Binary Search: Element %d not found in the array.\n", binaryKey);
    }

    return 0;
}
