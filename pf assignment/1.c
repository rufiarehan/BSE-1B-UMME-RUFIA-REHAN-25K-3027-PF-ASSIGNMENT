#include <stdio.h>

void addBook(int isbns[], char titles[][50], float prices[], int quantities[], int *bookCount, int maxBooks);
void processSale(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount);
void lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount);
int findBookIndex(int isbns[], int bookCount, int isbn);
void removeNewline(char str[]);

int main() {
    int maxBooks = 100;  
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int bookCount = 0;
    int choice;

    do {
        printf("\n===== Liberty Books Inventory System =====\n");
        printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(isbns, titles, prices, quantities, &bookCount, maxBooks);
                break;
            case 2:
                processSale(isbns, titles, prices, quantities, bookCount);
                break;
            case 3:
                lowStockReport(isbns, titles, prices, quantities, bookCount);
                break;
            case 4:
                printf("Exiting... Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}


int findBookIndex(int isbns[], int bookCount, int isbn) {
    int i;
    for (i = 0; i < bookCount; i++) {
        if (isbns[i] == isbn)
            return i;
    }
    return -1;
}

void removeNewline(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}

void addBook(int isbns[], char titles[][50], float prices[], int quantities[], int *bookCount, int maxBooks) {
    if (*bookCount >= maxBooks) {
        printf("Error: Inventory full! Cannot add more books.\n");
        return;
    }

    int isbn;
    printf("Enter ISBN: ");
    scanf("%d", &isbn);

    if (findBookIndex(isbns, *bookCount, isbn) != -1) {
        printf("Error: Book with ISBN %d already exists!\n", isbn);
        return;
    }

    isbns[*bookCount] = isbn;

    printf("Enter Title: ");
    getchar();  
    fgets(titles[*bookCount], 50, stdin);
    removeNewline(titles[*bookCount]);

    printf("Enter Price: ");
    scanf("%f", &prices[*bookCount]);

    printf("Enter Quantity: ");
    scanf("%d", &quantities[*bookCount]);

    (*bookCount)++;
    printf("Book added successfully!\n");
}

void processSale(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount) {
    if (bookCount == 0) {
        printf("No books in inventory!\n");
        return;
    }

    int isbn, qty;
    printf("Enter ISBN to sell: ");
    scanf("%d", &isbn);

    int index = findBookIndex(isbns, bookCount, isbn);
    if (index == -1) {
        printf("Error: Book not found!\n");
        return;
    }

    printf("Enter quantity sold: ");
    scanf("%d", &qty);

    if (quantities[index] < qty) {
        printf("Error: Not enough stock! Available: %d\n", quantities[index]);
        return;
    }

    quantities[index] -= qty;
    printf("Sale processed successfully!\n");
    printf("Remaining stock for \"%s\": %d\n", titles[index], quantities[index]);
}

void lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount) {
    int i, found = 0;
    printf("\n===== Low Stock Report (less than 5) =====\n");
    for (i = 0; i < bookCount; i++) {
        if (quantities[i] < 5) {
            printf("ISBN: %d | Title: %s | Price: %.2f | Qty: %d\n",
                   isbns[i], titles[i], prices[i], quantities[i]);
            found = 1;
        }
    }
    if (!found)
        printf("All books have sufficient stock.\n");
}


