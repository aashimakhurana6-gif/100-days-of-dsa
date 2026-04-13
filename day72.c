//Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

#include <stdio.h>

char firstRepeatedChar(char *s) {
    int freq[26] = {0};  // For 'a' to 'z'

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        // If already seen, return this character
        if (freq[index] == 1) {
            return s[i];
        }

        // Mark as seen
        freq[index] = 1;
    }

    return -1; // No repeated character
}

int main() {
    char s[1000];

    // Input
    scanf("%s", s);

    char result = firstRepeatedChar(s);

    if (result == -1)
        printf("-1\n");
    else
        printf("%c\n", result);

    return 0;
}