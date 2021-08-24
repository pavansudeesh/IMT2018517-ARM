#include<stdio.h>
#include <limits.h>
int main()
{
  int out = INT_MIN;
  int count;
   printf("enter the three number to be compared\n");
  for(int i  =0;i<3;i++)
  {
    int temp;
    scanf("%d",&temp);
    if(out < temp)
    {
      out = temp;
    }
  }
  printf(" largest number is: %d\n",out);
  return 0;
}

