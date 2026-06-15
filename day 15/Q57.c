#include <stdio.h>

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
}

int main() {
    int myArray[] = {10, 20, 30, 40, 50};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    

    reverseArray(myArray, size);
    
    
    printf("Reversed Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");
    
    return 0;
}
