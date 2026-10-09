#include <stdio.h>
void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid ;
    int k = low;

    int temp[100];

    while (i <= mid || j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

   
    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }

     for(int i=0;i<=6;i++){
        printf("%d   ",arr[i]);
    }
}
int main(){
    int arr[] = {10 ,30,50,40,20,60,70};

     merge(arr,0,6/2,6);
}