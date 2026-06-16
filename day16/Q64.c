#include <stdio.h>

int removeDuplicatesUnsorted(int arr[], int n) {
    if (n == 0 || n == 1) return n;

    int uniqueCount = 0;
    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;
    
        for (int j = 0; j < uniqueCount; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        
        if (!isDuplicate) {
            arr[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }
    return uniqueCount;
}

int main() {
    int arr[] = {4, 2, 4, 1, 2, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int newSize = removeDuplicatesUnsorted(arr, n);

    printf("Unique array: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]); 
    }
    return 0;
}
