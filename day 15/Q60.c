#include <stdio.h>
void moveZeroes(int* nums, int numsSize) {
    int insertPos = 0;
    
    // Shift all non-zero elements to the front
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[insertPos++] = nums[i];
        }
    }
    
    
    while (insertPos < numsSize) {
        nums[insertPos++] = 0;
    }
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    moveZeroes(nums, numsSize);
    
    
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    
    
    return 0;
}
