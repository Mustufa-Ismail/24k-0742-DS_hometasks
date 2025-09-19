#include <iostream>
using namespace std;

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

    cout << "Unsorted array\n";
    display(arr,size);

    cout << "sorted array\n";
    shellSort(arr,size);
    display(arr,size);
}