#include <stdio.h>

// Function prototypes
void encodeMessage(char message[]);
void decodeMessage(char message[]);
void reverseManual(char str[]);
char toggleBits(char ch);

int main() {
    char message[200];
    int choice;
    int i;

    while (1) {
        printf("\n==== TCS Secure Message Tool ====\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline left by scanf

        if (choice == 3) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        printf("Enter message: ");
        i = 0;
        char ch;
        while ((ch = getchar()) != '\n' && i < 199) {
            message[i++] = ch;
        }
        message[i] = '\0'; // end manually

        switch (choice) {
            case 1:
                encodeMessage(message);
                printf("Encoded message: ");
                for (i = 0; message[i] != '\0'; i++)
                    putchar(message[i]);
                printf("\n");
                break;
            case 2:
                decodeMessage(message);
                printf("Decoded message: ");
                for (i = 0; message[i] != '\0'; i++)
                    putchar(message[i]);
                printf("\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Reverse a string manually (no strlen)
void reverseManual(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    int i, j;
    char temp;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Toggle 2nd and 5th bits
char toggleBits(char ch) {
    ch = ch ^ (1 << 1); // toggle 2nd bit
    ch = ch ^ (1 << 4); // toggle 5th bit
    return ch;
}

// Encode message (reverse + toggle bits)
void encodeMessage(char message[]) {
    reverseManual(message);
    int i = 0;
    while (message[i] != '\0') {
        message[i] = toggleBits(message[i]);
        i++;
    }
}

// Decode message (toggle bits + reverse)
void decodeMessage(char message[]) {
    int i = 0;
    while (message[i] != '\0') {
        message[i] = toggleBits(message[i]);
        i++;
    }
    reverseManual(message);
}

