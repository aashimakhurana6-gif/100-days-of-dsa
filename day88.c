//Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.
#include <stdio.h>
#include <stdlib.h>

int possible(int arr[], int n, int k, int mid)
{
    int cow = 1;
    int last = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] - last >= mid)
        {
            cow++;
            last = arr[i];
        }

        if(cow >= k)
            return 1;
    }

    return 0;
}

int cmp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), cmp);

    int low = 1;
    int high = arr[n-1] - arr[0];
    int ans = 0;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(possible(arr, n, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("%d", ans);

    return 0;
}