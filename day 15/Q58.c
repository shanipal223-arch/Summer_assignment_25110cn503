#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void leftRotate(int arr[], int d, int n) {
    if (n == 0) return;
    d %= n; // Handles cases where d >= n
    
    reverse(arr, 0, d - 1);   
    reverse(arr, d, n - 1);   
    reverse(arr, 0, n - 1);   
}

// Driver code to test the program
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    leftRotate(arr, d, n);

    // Print the rotated array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
