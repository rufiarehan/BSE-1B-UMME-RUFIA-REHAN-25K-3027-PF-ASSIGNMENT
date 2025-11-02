#include <stdio.h>


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
        getchar();

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
        message[i] = '\0'; 

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


char toggleBits(char ch) {
    ch = ch ^ (1 << 1);
    ch = ch ^ (1 << 4); 
    return ch;
}


void encodeMessage(char message[]) {
    reverseManual(message);
    int i = 0;
    while (message[i] != '\0') {
        message[i] = toggleBits(message[i]);
        i++;
    }
}


void decodeMessage(char message[]) {
    int i = 0;
    while (message[i] != '\0') {
        message[i] = toggleBits(message[i]);
        i++;
    }
    reverseManual(message);
}


