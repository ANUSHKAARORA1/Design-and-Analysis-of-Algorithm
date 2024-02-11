/******************************************************************************
 Given a sorted array of positive integers containing few duplicate elements, design an algorithm
and implement it using a program to find whether the given key element is present in the array
or not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))
*******************************************************************************/
#include <stdio.h>
void searchandcount(int arr[], int n, int key) {
    int count=0;
    int low = 0, high = n - 1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) 
        {
            count++;
            high = mid - 1;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else 
        {
            high = mid - 1;
        }
    }
    if (count!=0) 
    {
        printf("found key %d and number of copies: %d", key, count);
    }
    else 
    {
        printf("Key not found");
    }
}

int main() {
    int T;
    printf("enter number of test cases");
    scanf("%d", &T);
    while (T--) 
    {
        int n;
        printf("enter no.of values to input");
        scanf("%d", &n);
        int arr[n];
        printf("enter values");
        for (int i = 0; i < n; i++) 
        {
            scanf("%d", &arr[i]);
        }
        int key;
        printf("enter key");
        scanf("%d", &key);
        searchandcount(arr, n, key);
    }
    return 0;
}

