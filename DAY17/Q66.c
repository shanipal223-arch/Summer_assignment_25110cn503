#include <stdio.h>

int exists(int arr[], int size, int number) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == number) {
            return 1; // Found duplicate
        }
    }
    return 0; // Unique number
}

int main() {
    int arr1[] = {1, 2, 3, 2, 1};
    int arr2[] = {3, 2, 4, 5, 4};
    
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int unionArr[100]; 
    int unionSize = 0;

    for (int i = 0; i < n1; i++) {
        if (!exists(unionArr, unionSize, arr1[i])) {
            unionArr[unionSize] = arr1[i];
            unionSize++;
        }
    }

    for (int i = 0; i < n2; i++) {
        if (!exists(unionArr, unionSize, arr2[i])) {
            unionArr[unionSize] = arr2[i];
            unionSize++;
        }
    }

    printf("Union: ");
    for (int i = 0; i < unionSize; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");

    return 0;
}
