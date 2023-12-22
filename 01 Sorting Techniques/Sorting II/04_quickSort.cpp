//  i wala aage jayenga jab tak usse pivot se chote log milenge, pivot se bada koi mila toh woh wahi peh rukh jayenga
//  j wala aage jayenga jab tak usse pivot bade log milenge, pivot se chota koi mila toh woh wahi peh rukh jayenga
// iBig = jSmall = STOP 

#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    int j = high;
  
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if (low < high)
    {
        int pivot = partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
    
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main()
{
    int arr[] = {4,6,2,5,7,9,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    printArray(arr,n);
    
    return 0;
}