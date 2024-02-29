/******************************************************************************
sort 0s and 1s
*******************************************************************************/
#include <stdio.h>

void sortZerosAndOnes(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                int temp = arr[low];
                arr[low] = arr[mid];
                arr[mid] = temp;
                low++;
                mid++;
                break;

            case 1:
                mid++;
                break;

            default:
                printf("Invalid input! Array should contain only 0s and 1s.\n");
                return;
        }
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

        sortZerosAndOnes(arr, n);

        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}

