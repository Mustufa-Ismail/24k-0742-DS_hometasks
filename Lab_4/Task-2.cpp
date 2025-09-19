#include <iostream>
#include <ctime>
#include <cstdlib>
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

int insertionSort(int arr[], int size)
{
    int comparisions = 0;
    for (int i = 0; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparisions++;
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = key;
    }
    return comparisions;
}

int selectionSort(int arr[], int size)
{
    int comparisions = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < size; j++)
        {
            comparisions++;
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    return comparisions;
}

int shellSort(int arr[], int size)
{
    int comparisions = 0;
    for (int i = size / 2; i > 0; i /= 2)
    {
        for (int j = i; j < size; j++)
        {
            int temp = arr[j];
            int res = j;

            while (res >= i)
            {
                comparisions++;
                if (arr[res - i] > temp)
                {
                    arr[res] = arr[res - i];
                    res -= i;
                }
                else
                {
                    break;
                }
            }
            arr[res] = temp;
        }
    }
    return comparisions;
}

void generateArray(int arr[], int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
}

void copyArray(int arr[], int copyarr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        copyarr[i] = arr[i];
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
    int arr[20] = {};
    generateArray(arr, 20);
    cout << "Unsorted array\n";
    display(arr, 20);

    int arr1[20] = {};
    copyArray(arr, arr1, 20);

    cout << "Using Bubble sort\n";
    int comparisions = bubbleSort(arr1, 20);
    display(arr1, 20);
    cout << "Comparisions made: " << comparisions << endl;

    copyArray(arr, arr1, 20);

    cout << "Using insertion sort\n";
    comparisions = insertionSort(arr1, 20);
    display(arr1, 20);
    cout << "Comparisions made: " << comparisions << endl;

    copyArray(arr, arr1, 20);

    cout << "Using selection sort\n";
    comparisions = selectionSort(arr1, 20);
    display(arr1, 20);
    cout << "Comparisions made: " << comparisions << endl;

    copyArray(arr, arr1, 20);

    cout << "Using Shell sort\n";
    comparisions = shellSort(arr1, 20);
    display(arr1, 20);
    cout << "Comparisions made: " << comparisions << endl;
}