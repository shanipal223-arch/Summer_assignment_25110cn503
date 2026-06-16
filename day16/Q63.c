#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


void findPairWithSum(int arr[], int size, int target) {
    // Sort the array in ascending order
    qsort(arr, size, sizeof(int), compare);

    int left = 0;
    int right = size - 1;


    while (left < right) {
        int currentSum = arr[left] + arr[right];

        if (currentSum == target) {
            printf("Pair found: %d + %d = %d\n", arr[left], arr[right], target);
            return;
        }
        

        if (currentSum < target) {
            left++;
        } else {
            right--;
        }
    }

    printf("No pair exists with the given sum.\n");
}

int main() {
    int nums[] = {10, 5, 2, 3, 7, 1, 9};
    int size = sizeof(nums) / sizeof(nums[0]);
    int targetSum = 12;

    findPairWithSum(nums, size, targetSum);

    return 0;
}
