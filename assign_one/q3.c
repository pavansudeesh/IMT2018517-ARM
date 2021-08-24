 #include <stdio.h>
int main()
{
    int a[20],i,n,even=0;
 
    printf("Enter elements in array : ");
    for(i=0; i<20; i++)
    {
        scanf("%d",&a[i]);
    }
 
     for(i=0; i<20; i++)
    {
          if(a[i]%2==0)
          even++;         
    }
     printf("even numbers in array: %d\n",even);
    return 0;
}
