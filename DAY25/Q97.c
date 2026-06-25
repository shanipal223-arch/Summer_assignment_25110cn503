#include <stdio.h>

// Function to merge two sorted arrays
void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0; // Index for arr1
    int j = 0; // Index for arr2
    int k = 0; // Index for merged array

    // Traverse both arrays simultaneously
    while (i < n1 && j < n2) {
        // Compare elements and pick the smaller one
        if (arr1[i] <= arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Store remaining elements of the first array (if any)
    while (i < n1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    // Store remaining elements of the second array (if any)
    while (j < n2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    // Initialized sorted arrays
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8, 10};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    // The merged array must be large enough to hold both sets of elements
    int merged[n1 + n2];

    // Function call
    mergeSortedArrays(arr1, n1, arr2, n2, merged);

    // Printing the result
    printf("Merged Sorted Array:\n");
    for (int idx = 0; idx < n1 + n2; idx++) {
        printf("%d ", merged[idx]);
    }
    printf("\n");

    return 0;
}
