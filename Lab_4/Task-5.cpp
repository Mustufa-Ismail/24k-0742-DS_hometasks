#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int x)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

void shellSort(int arr[], int size)
{
    for (int i = size / 2; i > 0; i /= 2)
    {
        for (int j = i; j < size; j++)
        {
            int temp = arr[j];
            int res = j;

            while (res >= i && arr[res - i] > temp)
            {
                arr[res] = arr[res - i];
                res -= i;
            }
            arr[res] = temp;
        }
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    shellSort(arr, size);

    display(arr, size);

    int val;
    cout << "Enter the value to search for: ";
    cin >> val;

    int result = binarySearch(arr,size,val);
    if (result == -1)
    {
        cout << "Value not found";
    }
    else
    {
        cout << val << " is at index: " << result+1;
    }
}