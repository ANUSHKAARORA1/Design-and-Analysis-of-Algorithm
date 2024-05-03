/*Given an array of elements. Assume arr[i] represents the size of file i. Write an algorithm and a
program to merge all these files into single file with minimum computation. For given two files
A and B with sizes m and n, computation cost of merging them is O(m+n). (Hint: use greedy
approach*/

#include <stdio.h>
#include <stdlib.h>
int minComputationCost(int arr[], int n) {
    int totalCost = 0;
    int heapSize = n;
    for (int i = 1; i <= n; i++) {
        arr[i] *= -1; 
    }
    for (int i = n / 2; i >= 1; i--) {
        int j = i;
        while (2 * j <= n) {
            int child = 2 * j;
            if (child + 1 <= n && arr[child + 1] < arr[child]) {
                child++;
            }
            if (arr[j] > arr[child]) {
                int temp = arr[j];
                arr[j] = arr[child];
                arr[child] = temp;
            } else {
                break;
            }
            j = child;
        }
    }
    while (heapSize > 1) {
        int min1 = arr[1];
        arr[1] = arr[heapSize--]; 
        int min2 = arr[1];
        arr[1] = arr[heapSize--]; 
        int mergedSize = min1 + min2;
        totalCost += mergedSize;

        arr[++heapSize] = mergedSize;

        int k = heapSize;
        while (k > 1 && arr[k / 2] > arr[k]) {
            int temp = arr[k / 2];
            arr[k / 2] = arr[k];
            arr[k] = temp;
            k /= 2;
        }
    }

    return totalCost;
}
int main() {
    int n;
    printf("Enter the number of files: ");
    scanf("%d", &n);

    int arr[n + 1];
    printf("Enter the size of each file:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    int cost = minComputationCost(arr, n);
    printf("Minimum computation cost required to merge all files: %d\n", cost);

    return 0;
}