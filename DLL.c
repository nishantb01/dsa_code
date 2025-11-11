#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node for each seat
struct Seat {
    int seatNo;
    int booked; // 0 = Free, 1 = Booked
    struct Seat *prev, *next;
};

struct Seat *head = NULL;

// ---------- Create Seats ----------
void createSeats(int totalSeats) {
    struct Seat *temp = NULL;
    for (int i = 1; i <= totalSeats; i++) {
        struct Seat *newSeat = (struct Seat*)malloc(sizeof(struct Seat));
        newSeat->seatNo = i;
        newSeat->booked = 0;
        newSeat->next = NULL;
        newSeat->prev = temp;

        if (head == NULL)
            head = newSeat;
        else
            temp->next = newSeat;

        temp = newSeat;
    }
    printf("\n🎬 %d Seats Created Successfully!\n", totalSeats);
}

// ---------- Display Theater Layout ----------
void displaySeats(int perRow) {
    struct Seat *temp = head;
    int count = 0;

    printf("\n--- Movie Theater Seat Layout ---\n");
    printf("F = Free | B = Booked\n\n");

    while (temp != NULL) {
        printf("[%2d:%c]  ", temp->seatNo, temp->booked ? 'B' : 'F');
        count++;
        if (count % perRow == 0)
            printf("\n");
        temp = temp->next;
    }
    printf("\n");
}

// ---------- Book a Seat ----------
void bookSeat() {
    int seat;
    printf("Enter seat number to book: ");
    scanf("%d", &seat);

    struct Seat *temp = head;
    while (temp != NULL && temp->seatNo != seat)
        temp = temp->next;

    if (temp == NULL)
        printf("❌ Invalid seat number!\n");
    else if (temp->booked)
        printf("❌ Seat %d is already booked!\n", seat);
    else {
        temp->booked = 1;
        printf("✅ Seat %d booked successfully!\n", seat);
    }
}

// ---------- Cancel Booking ----------
void cancelSeat() {
    int seat;
    printf("Enter seat number to cancel: ");
    scanf("%d", &seat);

    struct Seat *temp = head;
    while (temp != NULL && temp->seatNo != seat)
        temp = temp->next;

    if (temp == NULL)
        printf("❌ Invalid seat number!\n");
    else if (temp->booked == 0)
        printf("Seat %d is not booked!\n", seat);
    else {
        temp->booked = 0;
        printf("❌ Booking for seat %d has been cancelled.\n", seat);
    }
}

// ---------- MAIN ----------
int main() {
    int totalSeats, choice, perRow;

    printf("Enter total number of seats in the theater: ");
    scanf("%d", &totalSeats);
    printf("Enter number of seats per row: ");
    scanf("%d", &perRow);

    createSeats(totalSeats);

    while (1) {
        printf("\n--- Movie Theater Booking Menu ---\n");
        printf("1. View Seats\n");
        printf("2. Book Seat\n");
        printf("3. Cancel Seat\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats(perRow);
                break;
            case 2:
                bookSeat();
                break;
            case 3:
                cancelSeat();
                break;
            case 4:
                printf("🎥 Exiting... Enjoy your show!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
