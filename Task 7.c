#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int search_string(char arr[6][5], char str[]) {
    int len = strlen(str),i,j,k;

    // Horizontal search
    for ( i = 0; i < 6; i++) {
        for ( j = 0; j <= 5 - len; j++) {
            int found = 1;
            for ( k = 0; k < len; k++) {
                if (arr[i][j + k] != str[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) return 1;
        }
    }

    // Vertical search
    for ( j = 0; j < 5; j++) {
        for ( i = 0; i <= 6 - len; i++) {
            int found = 1;
            for ( k = 0; k < len; k++) {
                if (arr[i + k][j] != str[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) return 1;
        }
    }

    return 0;
}

int main() {
    int roll_no,i,j;
    printf("Enter roll no e.g., 0706: ");
    scanf("%d", &roll_no);

    char arr[6][5];
    int score = 0;
    char search_str[100];

    while (1) {
        srand(time(0));

        for ( i = 0; i < 5; i++) {
            printf("\t");
            for ( j = 0; j < 5; j++) {
                arr[i][j] = 'A' + (rand() % 26);
                printf("%c ", arr[i][j]);
            }
            printf("\n");
        }

        printf("\t");
        for ( i = 0; i < 5; i++) {
            if (i < 4) {
                arr[5][i] = (roll_no % 10) + '0';
                roll_no /= 10;
                printf("%c ", arr[5][i]);
            } else {
                arr[5][i] = 'A' + (rand() % 26);
                printf("%c ", arr[5][i]);
            }
        }
        printf("\n");

        while (1) {
            printf("\nSearch Str= ");
            scanf("%s", search_str);

            if (strcmp(search_str, "END") == 0) {
                printf("Exiting the search.\n");
                break;
            }

            if (search_string(arr, search_str)) {
                score++;
                printf("%s is present. Score: %d\n", search_str, score);
            } else {
                score--;
                printf("%s is not present. Score: %d\n", search_str, score);
            }
        }

        printf("Do you want to search again? (yes/no): ");
        char choice[10];
        scanf("%s", choice);
        if (strcmp(choice, "no") == 0) {
            break;
        }
    }

    return 0;
}

