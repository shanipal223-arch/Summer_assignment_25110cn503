#include <stdio.h>
#include <string.h>

#define TOTAL_SEATS 10
#define TICKET_PRICE 12.50

// Structure to hold passenger details
struct Ticket {
    int seatNumber;
    char passengerName[50];
    int isBooked; // 0 = Available, 1 = Booked
};

// Function prototypes
void displaySeats(struct Ticket status[]);
void bookTicket(struct Ticket status[]);
void cancelTicket(struct Ticket status[]);

int main() {
    struct Ticket seats[TOTAL_SEATS];
    int choice;

    // Initialize all seats as available
    for (int i = 0; i < TOTAL_SEATS; i++) {
        seats[i].seatNumber = i + 1;
        seats[i].isBooked = 0;
        strcpy(seats[i].passengerName, "None");
    }

    // Interactive Menu Loop
    do {
        printf("\n=============================\n");
        printf("    TICKET BOOKING SYSTEM    \n");
        printf("=============================\n");
        printf("1. View Seating Chart\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Ticket\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats(seats);
                break;
            case 2:
                bookTicket(seats);
                break;
            case 3:
                cancelTicket(seats);
                break;
            case 4:
                printf("\nThank you for using the booking system!\n");
                break;
            default:
                printf("\nInvalid choice! Please choose between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to display current seating layout
void displaySeats(struct Ticket status[]) {
    printf("\n--- SEATING LAYOUT ---\n");
    printf("Seat No.\tStatus\t\tPassenger\n");
    printf("---------------------------------------\n");
    
    for (int i = 0; i < TOTAL_SEATS; i++) {
        printf("Seat %d\t\t", status[i].seatNumber);
        if (status[i].isBooked == 1) {
            printf("[RESERVED]\t%s\n", status[i].passengerName);
        } else {
            printf("[AVAILABLE]\t-\n");
        }
    }
}

// Function to book a specific seat
void bookTicket(struct Ticket status[]) {
    int seatNum;
    
    printf("\nEnter the seat number you want to book (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNum);

    // Validate if seat number exists
    if (seatNum < 1 || seatNum > TOTAL_SEATS) {
        printf("Error: Invalid seat number!\n");
        return;
    }

    // Check if the chosen seat is already taken
    if (status[seatNum - 1].isBooked == 1) {
        printf("Sorry, Seat %d is already booked by %s.\n", seatNum, status[seatNum - 1].passengerName);
    } else {
        printf("Enter Passenger Name: ");
        // Clear standard input buffer and read the string name
        scanf(" %[^\n]s", status[seatNum - 1].passengerName); 
        
        status[seatNum - 1].isBooked = 1;
        
        printf("\nSuccess: Seat %d booked successfully!\n", seatNum);
        printf("Total Fare due: $%.2f\n", TICKET_PRICE);
    }
}

// Function to cancel an existing ticket
void cancelTicket(struct Ticket status[]) {
    int seatNum;

    printf("\nEnter the seat number to cancel (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNum);

    // Validate if seat number exists
    if (seatNum < 1 || seatNum > TOTAL_SEATS) {
        printf("Error: Invalid seat number!\n");
        return;
    }

    // Check if the seat is actually booked
    if (status[seatNum - 1].isBooked == 0) {
        printf("Error: Seat %d is already empty.\n", seatNum);
    } else {
        printf("Successfully canceled the booking for %s (Seat %d).\n", status[seatNum - 1].passengerName, seatNum);
        
        // Reset the seat properties back to defaults
        status[seatNum - 1].isBooked = 0;
        strcpy(status[seatNum - 1].passengerName, "None");
    }
}
