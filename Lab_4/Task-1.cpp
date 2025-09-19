#include <iostream>
using namespace std;

int bubbleSort(int arr[], int size)
{
    int comparisons = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            comparisons++;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return comparisons;
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = 7;

    int comparisions = bubbleSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }

    cout << "\n Comparisions: " << comparisions << endl;
}