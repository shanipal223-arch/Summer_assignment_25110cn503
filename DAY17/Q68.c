#include <stdio.h>

void findCommon(int arr1[], int n1, int arr2[], int n2) {
    printf("Common elements: ");
    for (int i = 0; i < n1; i++) {
        
        
        int alreadySeen = 0;
        for (int k = 0; k < i; k++) {
            if (arr1[i] == arr1[k]) {
                alreadySeen = 1;
                break;
            }
        }
        if (alreadySeen) continue;

        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                printf("%d ", arr1[i]);
                break; 
            }
        }
    }
    printf("\n");
}

int main() {
    int arr1[] = {4, 2, 5, 2, 8, 1};
    int arr2[] = {2, 9, 1, 2, 5};
    
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    findCommon(arr1, n1, arr2, n2);
    return 0;
}
