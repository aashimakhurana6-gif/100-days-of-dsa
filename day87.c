//Implement Binary Search Iterative - Implement the algorithm.
#include <stdio.h>

int main() {
    int n, i, key;
    
    scanf("%d", &n);
    
    int arr[n];
    
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &key);
    
    int low = 0, high = n - 1, mid, found = -1;
    
    while(low <= high) {
        mid = (low + high) / 2;
        
        if(arr[mid] == key) {
            found = mid;
            break;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    printf("%d", found);
    
    return 0;
}