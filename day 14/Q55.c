#include <stdio.h>
#include <limits.h>


int getSecondLargest(int arr[], int n) {

    if (n < 2) {
        return -1;
    }

    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for (int i = 0; i < n; i++) {
        
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } 
    
        else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }

    
    return (second_largest == INT_MIN) ? -1 : second_largest;
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = getSecondLargest(arr, n);
    
    if (result == -1) {
        printf("No distinct second largest element found.\n");
    } else {
        printf("Second Largest Element: %d\n", result);
    }

    return 0;
}
