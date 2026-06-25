#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if str2 is a rotation of str1
int areRotations(const char *str1, const char *str2) {
    int len1 = strlen(str1), len2 = strlen(str2);
    if (len1 != len2) return 0;

    char *temp = (char *)malloc(2 * len1 + 1);
    if (!temp) return 0;
    
    // Concatenate str1 with itself
    strcpy(temp, str1);
    strcat(temp, str1);
    
    // Check if str2 is a substring
    char *ptr = strstr(temp, str2);
    free(temp);
    return (ptr != NULL);
}

int main() {
    char s1[] = "ABCD", s2[] = "CDAB";
    if (areRotations(s1, s2)) printf("Strings are rotations.\n");
    else printf("Strings are NOT rotations.\n");
    return 0;
}
