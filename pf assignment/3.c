#include <stdio.h>

void updateSector(int grid[5][5], int row, int col, int flag, int value);
void querySector(int grid[5][5], int row, int col);
void runDiagnostic(int grid[5][5], int rows, int cols);

int main() {
    int grid[5][5] = {0};
    int choice, row, col, flag, value;

    while (1) {
        printf("\n--- IESCO Power Grid System ---\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4)
            break;

        switch (choice) {
            case 1:
                printf("Enter row (0-4): ");
                scanf("%d", &row);
                printf("Enter column (0-4): ");
                scanf("%d", &col);
                printf("Select flag (0=Power, 1=Overload, 2=Maintenance): ");
                scanf("%d", &flag);
                printf("Enter value (1=Set, 0=Clear): ");
                scanf("%d", &value);
                updateSector(grid, row, col, flag, value);
                break;

            case 2:
                printf("Enter row (0-4): ");
                scanf("%d", &row);
                printf("Enter column (0-4): ");
                scanf("%d", &col);
                querySector(grid, row, col);
                break;

            case 3:
                runDiagnostic(grid, 5, 5);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void updateSector(int grid[5][5], int row, int col, int flag, int value) {
    int bit;

    // Decide which bit to use without shifting
    if (flag == 0)
        bit = 1;   // Power
    else if (flag == 1)
        bit = 2;   // Overload
    else
        bit = 4;   // Maintenance

    if (value == 1)
        grid[row][col] = grid[row][col] | bit;    // Turn ON that bit
    else
        grid[row][col] = grid[row][col] & (~bit); // Turn OFF that bit
}

void querySector(int grid[5][5], int row, int col) {
    int status = grid[row][col];
    printf("\nSector (%d,%d) Status:\n", row, col);

    if (status & 1)
        printf("Power: ON\n");
    else
        printf("Power: OFF\n");

    if (status & 2)
        printf("Overload: YES\n");
    else
        printf("Overload: NO\n");

    if (status & 4)
        printf("Maintenance Required: YES\n");
    else
        printf("Maintenance Required: NO\n");
}

void runDiagnostic(int grid[5][5], int rows, int cols) {
    int overloadCount = 0, maintenanceCount = 0;
    int r, c;

    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            if (grid[r][c] & 2)
                overloadCount++;
            if (grid[r][c] & 4)
                maintenanceCount++;
        }
    }

    printf("\n--- System Diagnostic Report ---\n");
    printf("Total Overloaded Sectors: %d\n", overloadCount);
    printf("Total Maintenance Required Sectors: %d\n", maintenanceCount);
}


