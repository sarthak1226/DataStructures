#include <stdio.h>
#include <stdlib.h>





// int partition(int *arr, int strt, int end)
// {
//     int pivot = 0, i, j;
//     while (strt < end)
//     {
//         for (i = strt + 1; i <= end; i++)
//         {
//             if (arr[pivot] < arr[i])
//                 break;
//         }

//         for (j = end; j > strt; j--)
//         {
//             if (arr[pivot] > arr[j])
//                 break;
//         }

//         if (i < j)
//         {
//             int temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//         else
//             break;
//     }
//     int temp = arr[pivot];
//     arr[pivot] = arr[j];
//     arr[j] = temp;
//     return j;
// }


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

		
int partition(int *arr, int strt, int end)
{
    int i, j = strt - 1, pivot = end;

    for(i = strt; i < end; i++)
    {
        if(arr[i] < arr[pivot])
        {
            j++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[pivot], &arr[j + 1]);

    return j + 1;
}









int quick_sort(int *arr,int strt,int end){
    if(strt<end){
        int index=partition(arr,strt,end);
        quick_sort(arr,strt,index-1);
        quick_sort(arr,index+1,end);
    }
}
int main()
{
    int arr[6]={7,2,1,8,4,6};
  quick_sort(arr,0,5+1);
  for(int i=0;i<5+1;i++){printf("%d  ",arr[i]);}  
}



7,2,1,8,4,6

 2 7 1 8 4 6
 2 1 7 8 4 6
 2 1 4 8 7 6
 2 1 4 6 7 8

 2   1                       4