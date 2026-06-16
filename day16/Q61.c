#include <stdio.h>
int findMissingSum(int arr[], int size) {
    int n = size + 1;
    int expectedSum = (n * (n + 1)) / 2;
    int actualSum = 0;
    
    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }
    
    return expectedSum - actualSum;
}

int findMissingXOR(int arr[], int size) {
    int x1 = 0;
    int x2 = 0;
    int n = size + 1;
    
    for (int i = 1; i <= n; i++) {
        x1 ^= i;
    }
    
    for (int i = 0; i < size; i++) {
        x2 ^= arr[i];
    }
    
    return x1 ^ x2;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int missingSum = findMissingSum(arr, size);
    int missingXOR = findMissingXOR(arr, size);
    
    printf("Missing (Sum Method): %d\n", missingSum);
    printf("Missing (XOR Method): %d\n", missingXOR);
    
    return 0;
}
