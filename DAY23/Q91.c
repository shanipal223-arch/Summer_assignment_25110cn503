#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], temp;
    int len1, len2;

    // 1. Get input from user
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    
    if (len1 != len2) {
        printf("Not anagrams.\n");
        return 0;
    }

    
    for (int i = 0; i < len1 - 1; i++) {
        for (int j = i + 1; j < len1; j++) {
            if (str1[i] > str1[j]) {
                temp = str1[i];
                str1[i] = str1[j];
                str1[j] = temp;
            }
        }
    }

    
    for (int i = 0; i < len2 - 1; i++) {
        for (int j = i + 1; j < len2; j++) {
            if (str2[i] > str2[j]) {
                temp = str2[i];
                str2[i] = str2[j];
                str2[j] = temp;
            }
        }
    }

  
    if (strcmp(str1, str2) == 0) {
        printf("They are anagrams.\n");
    } else {
        printf("Not anagrams.\n");
    }

    return 0;
}


