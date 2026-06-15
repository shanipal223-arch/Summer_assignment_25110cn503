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

void rotateRight(int arr[], int n, int k) {
    if (n == 0) return;
    
    k = k % n;
    
    reverse(arr, 0, n - 1); 
    reverse(arr, 0, k - 1); 
    reverse(arr, k, n - 1); 
}

// Helper function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(nums) / sizeof(nums[0]);
    int steps = 3;

    printf("Original array: ");
    printArray(nums, n);

    rotateRight(nums, n, steps);

    printf("Rotated right by %d steps: ", steps);
    printArray(nums, n);

    return 0;
}
