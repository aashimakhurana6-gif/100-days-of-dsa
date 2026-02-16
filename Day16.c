//Given an array of integers, count the frequency of each distinct element and print the result.
#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void sortArray(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    sortArray(arr, n);

    int count = 1;

    for(int i = 0; i < n; i++) {

        if(i < n - 1 && arr[i] == arr[i + 1]) {
            count++;
        } else {
            printf("%d:%d ", arr[i], count);
            count = 1;
        }
    }

    return 0;
}
