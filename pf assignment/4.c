#include <stdio.h>


void pushElement(int arr[], int *top, int limit);
void popElement(int arr[], int *top);
void peekElement(int arr[], int top);
void displayElements(int arr[], int top);

int main() {
    int data[100];      
    int top = -1;       
    int limit, choice;

    printf("Enter maximum size of list: ");
    scanf("%d", &limit);

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. PUSH (Insert)\n");
        printf("2. POP (Remove)\n");
        printf("3. PEEK (Top Element)\n");
        printf("4. DISPLAY (All Elements)\n");
        printf("5. EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Program ended.\n");
            break;
        }

        switch (choice) {
            case 1:
                pushElement(data, &top, limit);
                break;
            case 2:
                popElement(data, &top);
                break;
            case 3:
                peekElement(data, top);
                break;
            case 4:
                displayElements(data, top);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

void pushElement(int arr[], int *top, int limit) {
    int value;
    if (*top == limit - 1) {
        printf("List is full (Overflow).\n");
    } else {
        printf("Enter a value to insert: ");
        scanf("%d", &value);
        (*top)++;
        arr[*top] = value;
        printf("%d added successfully.\n", value);
    }
}


void popElement(int arr[], int *top) {
    if (*top == -1) {
        printf("List is empty (Underflow).\n");
    } else {
        printf("%d removed.\n", arr[*top]);
        (*top)--;
    }
}


void peekElement(int arr[], int top) {
    if (top == -1)
        printf("No data (empty).\n");
    else
        printf("Top element: %d\n", arr[top]);
}


void displayElements(int arr[], int top) {
    int i;
    if (top == -1)
        printf("No elements to show.\n");
    else {
        printf("Elements are:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", arr[i]);
    }
}


