#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

const int limits = 100000;
const int block = 100;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial inde
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int *arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void merge_sort(int arr[100000])
{
    fstream f;
    f.open("Timesort2.txt");
    int size = 0;
    int arr1[100];
    for (int times = 0; times < limits / block; times++)
    {
        size = size + block;
        int arr1[size];
        for (int i = 0; i < size; i++)
            arr1[i] = arr[i];
        clock_t start, end, t;
        start = clock();
        mergesort(arr1, 0, size - 1);
        end = clock();
        t = end - start;
        double time_taken = ((double)t) / CLOCKS_PER_SEC;
        cout << times + 1 << "\t\t\t\t" << time_taken << "\t\t\t\t"
             << "\n";
        f << time_taken;
        f << "\n";
    }
}
int main()
{
    // fstream file;
    fstream file;
    int arr[100000];

    file.open("random.txt");
    for (int i = 0; i < 100000; i++)
        file >> arr[i];
    file.close();
    merge_sort(arr);

    return 0;
}
