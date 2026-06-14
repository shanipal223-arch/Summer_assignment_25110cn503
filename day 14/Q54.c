#include <stdio.h>

void printFrequencies(int arr[], int size) {
    
    int visited[size]; 
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        
        if (visited[i] == 1) {
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = 1;
                count++;
            }
        }
        printf("Element %d occurs %d times\n", arr[i], count);
    }
}

int main() {
    int nums[] = {10, 5, 10, 15, 10, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    printFrequencies(nums, size);
    return 0;
}
