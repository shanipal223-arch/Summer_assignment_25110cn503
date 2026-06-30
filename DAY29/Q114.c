#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Maximum capacity of the array

// Function prototypes
void createArray(int arr[], int *size);
void displayArray(int arr[], int size);
void insertElement(int arr[], int *size);
void deleteElement(int arr[], int *size);
void searchElement(int arr[], int size);
void sortArray(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size = 0; // Tracks the current number of elements in the array
    int choice;

    while (1) {
        printf("\n====================================");
        printf("\n    ARRAY OPERATIONS MENU SYSTEM    ");
        printf("\n====================================");
        printf("\n1. Create / Initialize Array");
        printf("\n2. Display Array");
        printf("\n3. Insert Element at a Position");
        printf("\n4. Delete Element from a Position");
        printf("\n5. Search for an Element");
        printf("\n6. Sort the Array (Ascending)");
        printf("\n7. Exit");
        printf("\n====================================");
        printf("\nEnter your choice (1-7): ");
        
        // Validate integer input for menu selection
        if (scanf("%d", &choice) != 1) {
            printf("\nError: Invalid input type! Please enter a number.\n");
            exit(1); 
        }

        switch (choice) {
            case 1:
                createArray(arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                insertElement(arr, &size);
                break;
            case 4:
                deleteElement(arr, &size);
                break;
            case 5:
                searchElement(arr, size);
                break;
            case 6:
                sortArray(arr, size);
                break;
            case 7:
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select a valid option between 1 and 7.\n");
        }
    }
    return 0;
}

// 1. Function to create/initialize the array
void createArray(int arr[], int *size) {
    printf("\nEnter the number of elements (Max %d): ", MAX_SIZE);
    scanf("%d", size);

    // Validate size boundaries
    if (*size < 0 || *size > MAX_SIZE) {
        printf("Invalid size! Resetting size to 0.\n");
        *size = 0;
        return;
    }

    printf("Enter %d elements:\n", *size);
    for (int i = 0; i < *size; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\nArray created successfully!\n");
}

// 2. Function to display array elements
void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("\nArray is empty! Nothing to display.\n");
        return;
    }

    printf("\nCurrent Array Elements:\n");
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

// 3. Function to insert an element at a specific index
void insertElement(int arr[], int *size) {
    int pos, element;

    // Check for Array Overflow
    if (*size >= MAX_SIZE) {
        printf("\nError: Array Overflow! Cannot insert more elements.\n");
        return;
    }

    printf("\nEnter the position (0 to %d) where you want to insert: ", *size);
    scanf("%d", &pos);

    // Validate index boundary
    if (pos < 0 || pos > *size) {
        printf("Invalid position! Insertion failed.\n");
        return;
    }

    printf("Enter the element value to insert: ");
    scanf("%d", &element);

    // Shift elements to the right to clear space
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert element and update size tracking
    arr[pos] = element;
    (*size)++;
    printf("\nElement inserted successfully!\n");
}

// 4. Function to delete an element from a specific index
void deleteElement(int arr[], int *size) {
    int pos;

    // Check for Array Underflow
    if (*size == 0) {
        printf("\nError: Array Underflow! No elements to delete.\n");
        return;
    }

    printf("\nEnter the position (0 to %d) of the element to delete: ", *size - 1);
    scanf("%d", &pos);

    // Validate index boundary
    if (pos < 0 || pos >= *size) {
        printf("Invalid position! Deletion failed.\n");
        return;
    }

    printf("\nDeleted element: %d\n", arr[pos]);

    // Shift elements to the left to collapse the gap
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Update size tracking
    (*size)--;
    printf("Array updated successfully!\n");
}

// 5. Function to search for an element (Linear Search)
void searchElement(int arr[], int size) {
    int target, found = 0;

    if (size == 0) {
        printf("\nArray is empty! Cannot search.\n");
        return;
    }

    printf("\nEnter the element value to search for: ");
    scanf("%d", &target);

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element %d found at index position [%d].\n", target, i);
            found = 1;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", target);
    }
}

// 6. Function to sort the array using Bubble Sort
void sortArray(int arr[], int size) {
    int temp;

    if (size == 0) {
        printf("\nArray is empty! Nothing to sort.\n");
        return;
    }

    // Optimized Bubble Sort algorithm
    for (int i = 0; i < size - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no two elements were swapped by inner loop, then array is sorted
        if (swapped == 0) {
            break;
        }
    }
    printf("\nArray sorted in ascending order successfully!\n");
}
