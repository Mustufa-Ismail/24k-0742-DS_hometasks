#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void bubbleSort(int arr[], int size)
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
}

void insertionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
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

int main()
{
    

}