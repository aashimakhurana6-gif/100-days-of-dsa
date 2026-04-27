//Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

#include <stdio.h>

int squareRoot(int n)
{
    int low = 0, high = n, mid, ans = 0;

    while(low <= high)
    {
        mid = low + (high - low) / 2;

        if(mid * mid == n)
        {
            return mid;
        }
        else if(mid * mid < n)
        {
            ans = mid;      
            low = mid + 1;  
        }
        else
        {
            high = mid - 1; 
        }
    }

    return ans;
}

int main()
{
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    printf("Integer Square Root = %d", squareRoot(n));

    return 0;
}