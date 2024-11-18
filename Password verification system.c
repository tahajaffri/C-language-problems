#include <stdio.h>

int main() {
    char password[16];  // Buffer to store the password (15 digits + null terminator)
    int length = 0;     // To keep track of the length of the password
    int oddCount = 0;   // Count of odd digits
    int evenCount = 0;  // Count of even digits
    int digitSum = 0;   // Sum of the digits

    printf("Enter your password (numeric only, max 15 digits): ");
    scanf("%15s", password); // Read a maximum of 15 characters

    // Iterate over each character in the password
    while (password[length] != '\0') { // Check until the null terminator
        // Check if the character is a digit
        if (password[length] >= '0' && password[length] <= '9') {
            // Convert char to int and add to sum
            int digit = password[length] - '0';
            digitSum += digit;

            // Count odd and even digits
            if (digit % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
            length++; // Increment the length for each valid digit
        } else {
            printf("Password is invalid: non-numeric character detected.\n");
            return 0; // Invalid if any character is not a digit
        }

        // Check length limit in the loop to avoid exceeding it
        if (length > 15) {
            printf("Password is invalid: length exceeds 15 characters.\n");
            return 0; // Invalid if length exceeds 15
        }
    }

    // Check length constraints
    if (length < 8) {
        printf("Password is invalid: length must be at least 8 characters.\n");
        return 0; // Invalid if length is less than 8
    }

    // Check if there are at least 4 odd and 4 even digits
    if (oddCount < 4 || evenCount < 4) {
        printf("Password is invalid: must have at least 4 odd and 4 even digits.\n");
        return 0; // Invalid if not enough odd/even digits
    }

    // Check if the sum of digits is greater than 10
    if (digitSum <= 10) {
        printf("Password is invalid: sum of digits must be greater than 10.\n");
        return 0; // Invalid if sum is not greater than 10
    }

    // If all checks are passed
    printf("Password is valid.\n");

    return 0;
}

