#include<stdio.h>
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void bubbleSort(int arr[]) 
{ 
    int i, j; 
    int n = 20;
    for (i = 0; i < n-1; i++)
    {     
    for (j = 0; j < n-i-1; j++) 
    {
        if (arr[j] > arr[j+1]) 
            swap(&arr[j], &arr[j+1]); 
     }
    }
} 
  
int main()
{
printf("enter the 20 numbers you want to sort:\n");
int arr[20] ={};
  for(int i =0;i<20;i++)
  {
  	int temp;
  	scanf(" %d",&temp);
  	arr[i] = temp;
  }
  bubbleSort(arr);
  for (int i=0; i < 20; i++)
        printf("%d ", arr[i]);
    printf("\n");
  return 0;
}
