#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to find unique intersection elements
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // Sort both arrays first
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    // Allocate maximum possible memory for result
    int minSize = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int* result = (int*)malloc(minSize * sizeof(int));
    
    int i = 0, j = 0, k = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            // Check for duplicates before adding
            if (k == 0 || result[k - 1] != nums1[i]) {
                result[k++] = nums1[i];
            }
            i++;
            j++;
        }
    }

    *returnSize = k;
    return result;
}

int main() {
    int nums1[] = {4, 9, 5};
    int nums2[] = {9, 4, 9, 8, 4};
    
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize;

    int* res = intersection(nums1, size1, nums2, size2, &returnSize);

    printf("Intersection: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    free(res); 
    return 0;
}
