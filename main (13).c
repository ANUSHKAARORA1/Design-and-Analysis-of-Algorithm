/******************************************************************************
Given an unsorted array of integers, design an algorithm and a program to sort the array using
insertion sort. Your program should be able to find number of comparisons and shifts (shifts
total number of times the array elements are
shifted from their place) required for sorting the
array.
Input Format:
The first line contains number of test cases,T.
For each test case, there will be two input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
Output Format:
The output will have T number of lines.
For each test case T, there will be three output lines
First line will give the sorted array.
Second line will give total number of comparisons.
Third line will give total number of shift operations required
*******************************************************************************/
#include <stdio.h>

void insertionSort(int arr[], int n, int *comparisons, int *shifts) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        (*comparisons)++;

        while (j >= 0 && arr[j] > key) {
            
            (*shifts)++;
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        int comparisons = 0;
        int shifts = 0;
        insertionSort(arr, n, &comparisons, &shifts);
        printf("Sorted Array:");
        for (int i = 0; i < n; i++) {
            printf(" %d", arr[i]);
        }
        printf("\n");
        printf("Comparisons: %d\n", comparisons);
        printf("Shifts: %d\n", shifts);
    }

    return 0;
}
