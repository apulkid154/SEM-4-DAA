#include <iostream>
#include <array>
#include <ctime>
#include <fstream>

using namespace std;
//  keeping the block size constant i.e 100 and array size 100000
const int limit = 100000;
const int block = 100;

// declaring the partition function
int partition(int arr[], int low, int high)
{
   
    int min = 0;
    // setting the pivot at staring element
    int pivot = arr[low];
    //  checking the count of numbers which are less than pivot
    for (int i = low + 1; i <= high; i++)
    {
        if (arr[i] < pivot)
            min++;
    }

    // setting the pivot index
    int pivotindex = low + min;
    swap(arr[pivotindex], arr[low]);
    // adjusting the smaller elements than pivot at left and larger right of pivot
    for (int i = low, j = high; i<(pivotindex), j>(pivotindex); i++, j--)

    {
        if (arr[i] > pivot && arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
        
            i++;
            j--;
        }
        else if (arr[i] > pivot && arr[j] > pivot)
        {
            j--;
        }
        else if (arr[i] < pivot && arr[j] < pivot)
        {
            j--;
        }
        else
        {
            i++;
            j--;
        }
    }
    //   returning the pivot index
    return pivotindex;
}

void quicksort(int arr[], int low, int high)
{
    clock_t start, end;
    
    start =clock();
    // base case
    if (low >= high)
    {
        return;
    }
    // partition
    int p = partition(arr, low, high);

    // recursively calling the function to sort the left and right part of array
    quicksort(arr, low, p - 1);
    quicksort(arr, p + 1, high);
   


}
void quick_sort (int arr[100000]) {
	int size = 0;
    int arr1[100];
     fstream f;
    f.open("Timesort.txt");

	for (int times = 0; times<limit/block; times++) {
		size+=block;
   
		int arr1 [size];
		for (int i = 0; i<size; ++i)
		
            arr1[i]=arr[i];
		// now our array is ready, we will perform quick sort
        // before that we will start the clock 
		clock_t t;
		t = clock();
		quicksort(arr1, 0, size-1);
	    	t = clock()-t;
	    	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	    	// storing the result in a file
            cout<<times+1<<"\t\t"<<time_taken<<"\t\t"<<"\n";
          f<<time_taken;
          f<<"\n";
	}
	
}

int main () {
    int arr[100000];

    ifstream File;
    File.open("r.txt");
    int i=0;
    while(!File.eof())
    {
        File >> arr[i];
        i++;
    }


    File.close();

	quick_sort(arr);
   

	return 0;
}