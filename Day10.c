//Read a string and check if it is a palindrome using two-pointer comparison.
#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int start, end;
    int isPalindrome = 1;

    scanf("%s", s);

    start = 0;
    end = strlen(s) - 1;

   
    while (start < end) {
        if (s[start] != s[end]) {
            isPalindrome = 0;
            break;
        }
        start++;
        end--;
    }

    if (isPalindrome)
        printf("YES");
    else
        printf("NO");

    return 0;
}
