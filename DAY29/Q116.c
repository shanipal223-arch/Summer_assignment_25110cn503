#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define FILE_NAME "inventory.txt"

// Structure to define an inventory item
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

// Global array and tracking variables
Item inventory[MAX_ITEMS];
int itemCount = 0;

// Function declarations
void loadInventory();
void saveInventory();
void addItem();
void viewInventory();
void searchItem();
void updateItem();
void deleteItem();
void clearInputBuffer();

int main() {
    int choice;
    
    // Load existing items from file at startup
    loadInventory();

    while (1) {
        printf("\n=== INVENTORY MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Item\n");
        printf("2. View All Items\n");
        printf("3. Search Item by ID\n");
        printf("4. Update Item Quantity/Price\n");
        printf("5. Delete Item\n");
        printf("6. Save & Exit\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addItem(); break;
            case 2: viewInventory(); break;
            case 3: searchItem(); break;
            case 4: updateItem(); break;
            case 5: deleteItem(); break;
            case 6: 
                saveInventory();
                printf("Data saved successfully. Exiting program...\n");
                exit(0);
            default: 
                printf("Invalid choice! Please select a valid menu option.\n");
        }
    }
    return 0;
}

// Loads the inventory data from text file
void loadInventory() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        // File doesn't exist yet, which is fine for the first run
        itemCount = 0;
        return;
    }
    
    itemCount = 0;
    while (fscanf(file, "%d,%49[^,],%d,%f\n", 
                  &inventory[itemCount].id, 
                  inventory[itemCount].name, 
                  &inventory[itemCount].quantity, 
                  &inventory[itemCount].price) == 4) {
        itemCount++;
        if (itemCount >= MAX_ITEMS) break;
    }
    fclose(file);
}

// Saves current array back into text file
void saveInventory() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error: Could not save inventory data to file.\n");
        return;
    }
    
    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%d,%s,%d,%.2f\n", 
                inventory[i].id, 
                inventory[i].name, 
                inventory[i].quantity, 
                inventory[i].price);
    }
    fclose(file);
}

// Adds a new product to the array
void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory Full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("\nEnter Unique Item ID (Integer): ");
    scanf("%d", &newItem.id);

    // Validate ID uniqueness
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == newItem.id) {
            printf("Error: Item ID already exists!\n");
            return;
        }
    }

    printf("Enter Item Name: ");
    clearInputBuffer(); // Prevent trailing layout issues from prior scans
    fgets(newItem.name, sizeof(newItem.name), stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; // Strip trailing newline

    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Price: ");
    scanf("%f", &newItem.price);

    inventory[itemCount] = newItem;
    itemCount++;
    printf("Item '%s' added successfully!\n", newItem.name);
}

// Displays all records cleanly in a tabular form
void viewInventory() {
    if (itemCount == 0) {
        printf("\nYour inventory is completely empty.\n");
        return;
    }

    printf("\n-----------------------------------------------------\n");
    printf("%-10s %-25s %-10s %-10s\n", "Item ID", "Item Name", "Quantity", "Price ($)");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%-10d %-25s %-10d %-10.2f\n", 
               inventory[i].id, 
               inventory[i].name, 
               inventory[i].quantity, 
               inventory[i].price);
    }
    printf("-----------------------------------------------------\n");
}

// Looks up an individual item using its ID
void searchItem() {
    int searchId;
    printf("\nEnter Item ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == searchId) {
            printf("\nItem Found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: $%.2f\n", 
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Item with ID %d not found.\n", searchId);
}

// Modifies quantity or price details of an item
void updateItem() {
    int updateId;
    printf("\nEnter Item ID to update: ");
    scanf("%d", &updateId);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == updateId) {
            printf("Current Details - Name: %s | Qty: %d | Price: $%.2f\n", 
                   inventory[i].name, inventory[i].quantity, inventory[i].price);
            
            printf("Enter New Quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter New Price: ");
            scanf("%f", &inventory[i].price);
            
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found.\n", updateId);
}

// Removes a item and shifts the remaining array index forward
void deleteItem() {
    int deleteId;
    printf("\nEnter Item ID to delete: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == deleteId) {
            // Shift subsequent objects backward to clear the index gap
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item deleted successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found.\n", deleteId);
}

// Helper to flush out standard input streams
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
