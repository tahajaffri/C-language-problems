#include <stdio.h>
#include <string.h>

int main() {
    char s[100];  // Declare a string large enough to hold the input

    // Read a full line of input using fgets
    fgets(s, sizeof(s), stdin);

    // Remove the newline character added by fgets (if it exists)
    s[strcspn(s, "\n")] = '\0';

    // Print "Hello, World!" on the first line
    printf("Hello, World!\n");

    // Print the input string on the second line
    printf("%s\n", s);

    return 0;
}

