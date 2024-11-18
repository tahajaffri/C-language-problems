#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int BinaryToDecimal(int number) {
    int decimal = 0, base = 1, remainder;
    while (number > 0) {
        remainder = number % 10;
        decimal += remainder * base;
        number /= 10;
        base *= 2;
    }
    return decimal;
}

int DecimalToBinary(int number) {
    int binary = 0, base = 1;
    while (number > 0) {
        binary += (number % 2) * base;
        number /= 2;
        base *= 10;
    }
    return binary;
}

void DecimalToHexadecimal(int number) {
    char hex[20];
    int i = 0,j;
    while (number != 0) {
        int temp = number % 16;
        if (temp < 10) {
            hex[i] = temp + '0';
        } else {
            hex[i] = temp - 10 + 'A';
        }
        number /= 16;
        i++;
    }
    hex[i] = '\0';
    for (j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
}

void HexadecimalToDecimal(char hexNumber[]) {
    int decimal = 0,i;
    for ( i = 0; hexNumber[i] != '\0'; i++) {
        decimal *= 16;
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9') {
            decimal += hexNumber[i] - '0';
        } else if (toupper(hexNumber[i]) >= 'A' && toupper(hexNumber[i]) <= 'F') {
            decimal += toupper(hexNumber[i]) - 'A' + 10;
        }
    }
    printf("%d\n", decimal);
}

void BinaryToHexadecimal(int number) {
    int decimal = BinaryToDecimal(number);
    DecimalToHexadecimal(decimal);
}

void HexadecimalToBinary(char hexNumber[]) {
    int decimal = 0,i;
    for ( i = 0; hexNumber[i] != '\0'; i++) {
        decimal *= 16;
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9') {
            decimal += hexNumber[i] - '0';
        } else if (toupper(hexNumber[i]) >= 'A' && toupper(hexNumber[i]) <= 'F') {
            decimal += toupper(hexNumber[i]) - 'A' + 10;
        }
    }
    printf("%d\n", DecimalToBinary(decimal));
}

int main() {
    int choice, binaryNumber, decimalNumber;
    char hexNumber[20];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Hexadecimal to Binary\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%d", &binaryNumber);
                printf("Decimal: %d\n", BinaryToDecimal(binaryNumber));
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                printf("Binary: %d\n", DecimalToBinary(decimalNumber));
                break;
            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                printf("Hexadecimal: ");
                DecimalToHexadecimal(decimalNumber);
                break;
            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                printf("Decimal: ");
                HexadecimalToDecimal(hexNumber);
                break;
            case 5:
                printf("Enter a binary number: ");
                scanf("%d", &binaryNumber);
                printf("Hexadecimal: ");
                BinaryToHexadecimal(binaryNumber);
                break;
            case 6:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                printf("Binary: ");
                HexadecimalToBinary(hexNumber);
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

