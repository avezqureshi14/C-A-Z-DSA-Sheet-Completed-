//Dono meh se kaun chota hai usko swap karo
#include <iostream>
using namespace std;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j+1]<arr[j])
            {
                swap(arr[j+1],arr[j]);
            }
            
        }
        
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
    int arr[] = {4,3,7,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    printArray(arr,n);
    return 0;
}