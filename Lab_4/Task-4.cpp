#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int size, int x)
{
    int low = 0;
    int high = size - 1;
    while (low <= high && x >= arr[low] && x <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == x)
            {
                return low;
            }
            return -1;
        }

        int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[pos] == x)
        {
            return pos;
        }
        else if (arr[pos] < x)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
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
    int arr[10] = {1, 55, 11, 93, 00, 45, 39, 41, 77, 2};

    shellSort(arr, 10);
    display(arr, 10);
    int pos = interpolationSearch(arr, 10, 45);

    cout << "Index is :" << pos + 1;
}