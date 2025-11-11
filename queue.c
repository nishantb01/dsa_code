#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// ---------- ENQUEUE ----------
void enqueue(int job) {
    if (rear == SIZE - 1)
        printf("Queue is Full! No more orders can be taken.\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = job;
        printf("Order %d added to the queue.\n", job);
    }
}

// ---------- DEQUEUE ----------
void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue is Empty! No orders to serve.\n");
    else {
        printf("Order %d served.\n", queue[front++]);
        if (front > rear) front = rear = -1; // reset queue when empty
    }
}

// ---------- DISPLAY ----------
void display() {
    if (front == -1)
        printf("Queue is Empty!\n");
    else {
        printf("Current Orders in Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

// ---------- MAIN ----------
int main() {
    int choice, job;

    while (1) {
        printf("\n--- Pizza Parlour Job Queue ---\n");
        printf("1. Add Job (Enqueue)\n");
        printf("2. Serve Job (Dequeue)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Job Number (Order ID): ");
                scanf("%d", &job);
                enqueue(job);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
