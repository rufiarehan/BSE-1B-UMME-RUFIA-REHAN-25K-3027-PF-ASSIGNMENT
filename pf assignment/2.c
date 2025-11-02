#include <stdio.h>

void customerInfo(char name[], char cnic[]);
void displayInventory(int codes[], int quantities[], int prices[], int size);
void addToCart(int codes[], int quantities[], int prices[], int size, int *totalBill);
void showInvoice(char name[], char cnic[], int totalBill);
void updateInventory(int quantities[], int index, int purchasedQuantity);

int main() {
    int codes[4] = {1, 2, 3, 4};         
    int quantities[4] = {50, 10, 20, 8}; 
    int prices[4] = {100, 200, 300, 150}; 

    char name[50], cnic[20];
    int choice, totalBill = 0;
    int size = 4;

    printf("\n=== SUPERMARKET INVENTORY SYSTEM ===\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enter Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Display Total Bill\n");
        printf("5. Show Invoice\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                customerInfo(name, cnic);
                break;

            case 2:
                displayInventory(codes, quantities, prices, size);
                break;

            case 3:
                addToCart(codes, quantities, prices, size, &totalBill);
                break;

            case 4:
                printf("\nTotal bill so far: Rs. %d\n", totalBill);
                break;

            case 5:
                showInvoice(name, cnic, totalBill);
                break;

            case 6:
                printf("\nExiting system. Thank you!\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}


void customerInfo(char name[], char cnic[]) {
    int i;
    char temp;
    printf("\nEnter customer name: ");
    scanf("%c", &temp); 
    i = 0;
    while (1) {
        char ch = getchar();
        if (ch == '\n') break;
        name[i++] = ch;
    }
    name[i] = '\0';

    printf("Enter CNIC number: ");
    i = 0;
    while (1) {
        char ch = getchar();
        if (ch == '\n') break;
        cnic[i++] = ch;
    }
    cnic[i] = '\0';
}


void displayInventory(int codes[], int quantities[], int prices[], int size) {
    int i;
    printf("\n%-12s %-15s %-10s\n", "Product Code", "Quantity in Stock", "Price");
    for (i = 0; i < size; i++) {
        printf("%03d\t\t%d\t\tRs.%d\n", codes[i], quantities[i], prices[i]);
    }
}


void addToCart(int codes[], int quantities[], int prices[], int size, int *totalBill) {
    int code, qty, i, found = 0;

    printf("\nEnter product code: ");
    scanf("%d", &code);
    printf("Enter quantity: ");
    scanf("%d", &qty);

    for (i = 0; i < size; i++) {
        if (codes[i] == code) {
            found = 1;
            if (quantities[i] >= qty) {
                quantities[i] -= qty; 
                *totalBill += qty * prices[i];
                printf("Added %d of product %03d to cart.\n", qty, code);
            } else {
                printf("Not enough stock available!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Invalid product code!\n");
    }
}

void showInvoice(char name[], char cnic[], int totalBill) {
    char promo[10];
    int i, j;
    int discountApplied = 0;
    char eid[] = {'E','i','d','2','0','2','5','\0'};

    printf("\nEnter promo code (if any): ");
    scanf("%s", promo);

  
    for (i = 0; eid[i] != '\0' && promo[i] != '\0'; i++) {
        if (eid[i] != promo[i]) break;
    }
    if (eid[i] == '\0' && promo[i] == '\0') {
        discountApplied = 1;
    }

    printf("\n--- INVOICE ---\n");
    printf("Customer Name: %s\n", name);
    printf("CNIC: %s\n", cnic);
    printf("Total Bill: Rs.%d\n", totalBill);

    if (discountApplied) {
        float discount = totalBill * 0.25;
        printf("Discount (25%%): Rs.%.0f\n", discount);
        printf("Final Bill: Rs.%.0f\n", totalBill - discount);
    } else {
        printf("No discount applied.\n");
        printf("Final Bill: Rs.%d\n", totalBill);
    }
}

