#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
    int len = strlen(str);
    
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    char str[] = "radar";

    if (isPalindrome(str)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
