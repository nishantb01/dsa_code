#include <stdio.h>
#define SIZE 10

// ---------- LINEAR PROBING ----------
void insertLinear(long int table[], long int num) {
    int index = num % SIZE;   // direct hash
    int i = 0;

    while (table[(index + i) % SIZE] != -1 && i < SIZE)
        i++;

    if (i < SIZE)
        table[(index + i) % SIZE] = num;
    else
        printf("Table Full!\n");
}

// ---------- QUADRATIC PROBING ----------
void insertQuadratic(long int table[], long int num) {
    int index = num % SIZE;
    int i = 0;

    while (table[(index + i * i) % SIZE] != -1 && i < SIZE)
        i++;

    if (i < SIZE)
        table[(index + i * i) % SIZE] = num;
    else
        printf("Table Full!\n");
}

// ---------- DOUBLE HASHING ----------
void insertDouble(long int table[], long int num) {
    int h1 = num % SIZE;
    int h2 = 7 - (num % 7);   // secondary hash
    int i = 0;

    while (table[(h1 + i * h2) % SIZE] != -1 && i < SIZE)
        i++;

    if (i < SIZE)
        table[(h1 + i * h2) % SIZE] = num;
    else
        printf("Table Full!\n");
}

// ---------- DISPLAY FUNCTION ----------
void display(long int table[]) {
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            printf("[%d] : Empty\n", i);
        else
            printf("[%d] : %ld\n", i, table[i]);
    }
}

// ---------- MAIN FUNCTION ----------
int main() {
    long int table[SIZE];
    int choice, n;
    long int num;

    while (1) {
        // Initialize table here in main
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;

        printf("\n--- Telephone Book using Hashing ---\n");
        printf("1. Linear Probing\n2. Quadratic Probing\n3. Double Hashing\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 4)
            break;

        printf("Enter number of telephone numbers: ");
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            printf("Enter telephone number %d: ", i + 1);
            scanf("%ld", &num);

            if (choice == 1)
                insertLinear(table, num);
            else if (choice == 2)
                insertQuadratic(table, num);
            else if (choice == 3)
                insertDouble(table, num);
            else
                printf("Invalid choice!\n");
        }

        printf("\n--- Hash Table ---\n");
        display(table);
    }

    return 0;
}
