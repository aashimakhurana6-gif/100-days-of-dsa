//Given an array of integers, find two elements whose sum is closest to zero.
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int n;

    scanf("%d", &n);

    int arr[n];


    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int min_sum = 1000000000;
    int first, second;

    while(left < right)
    {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(min_sum))
        {
            min_sum = sum;
            first = arr[left];
            second = arr[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

 
    printf("%d %d", first, second);

    return 0;
}