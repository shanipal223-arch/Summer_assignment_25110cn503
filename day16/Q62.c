#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findMaxFrequencyElement(int arr[], int n) {
    if (n <= 0) {
        printf("Array is empty.\n");
        return;
    }

    // Step 1: Sort the array
    qsort(arr, n, sizeof(int), compare);

    int max_element = arr[0];
    int max_count = 1;
    
    int current_element = arr[0];
    int current_count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            current_count++;
        } else {
            if (current_count > max_count) {
                max_count = current_count;
                max_element = current_element;
            }
            current_element = arr[i];
            current_count = 1;
        }
    }
    
    if (current_count > max_count) {
        max_count = current_count;
        max_element = current_element;
    }

    printf("The maximum frequency element is: %d\n", max_element);
    printf("It appears %d times.\n", max_count);
}

int main() {
    int nums[] = {1, 3, 2, 1, 2, 2, 3, 1, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    
    findMaxFrequencyElement(nums, n);
    return 0;
}
