//Given an unsorted array of integers , design an algorithm and progrsm to sort an array using selection sort your programs must be able to find comparisions are number of shifts required for sorting an array
#include<stdio.h>
int main()
{
    int i,j,n;
    int comparisions=0,shift=0;
    int T;
    printf("enter total no. of test cases");
    scanf("%d", &T);
    while (T--) {
    printf("enter no.of elements to input");
    scanf("%d",&n);
    int arr[n];
    printf("enter values ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i = 0;i < n; i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        {
        comparisions++;
        if(arr[i] > arr[j])
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            shift++;
        }
        }
    }
    printf("sorted array :");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d",arr[i]);
    }
    printf(" total number of comparisions are : %d",comparisions);
    printf("total number of shifts are : %d",shift);
}
}

