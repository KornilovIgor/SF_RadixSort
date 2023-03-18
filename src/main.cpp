#include <iostream>

void radixSort(int* arr, int n);

int main()
{
    int n = 7;

    int* arr = new int[n] {11, 40, 4, 311, 23, 51, 27};

    for (size_t i = 0; i < n; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

    radixSort(arr, n);

    for (size_t i = 0; i < n; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;


    return 0;
}

int getMax(int* arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int* arr, int n, int exp)
{
    int* output = new int[n];
    int count[10] = { 0 };

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int* arr, int n)
{
    int m = getMax(arr, n);

    for (int exp = 1; exp <= m; exp *= 10)
        countSort(arr, n, exp);
}