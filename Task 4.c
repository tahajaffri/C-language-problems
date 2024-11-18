#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void sort_string(char *str) {
    int n = strlen(str),i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    int size,i,j;
    printf("Enter the number of transactions: ");
    scanf("%d", &size);
    getchar();

    char transactions[size][MAX_LENGTH];

    for ( i = 0; i < size; i++) {
        printf("Enter transaction %d: ", i + 1);
        fgets(transactions[i], sizeof(transactions[i]), stdin);
        transactions[i][strcspn(transactions[i], "\n")] = '\0';
    }

    char sorted[size][MAX_LENGTH];
    int grouped[size][size];
    int group_sizes[size];
    int group_count = 0;

    for ( i = 0; i < size; i++) {
        strcpy(sorted[i], transactions[i]);
        sort_string(sorted[i]);
    }

    for ( i = 0; i < size; i++) {
        int found_group = 0;
        for ( j = 0; j < group_count; j++) {
            if (strcmp(sorted[i], sorted[grouped[j][0]]) == 0) {
                grouped[j][group_sizes[j]] = i;
                group_sizes[j]++;
                found_group = 1;
                break;
            }
        }
        if (!found_group) {
            grouped[group_count][0] = i;
            group_sizes[group_count] = 1;
            group_count++;
        }
    }

    printf("[\n");
    for ( i = 0; i < group_count; i++) {
        printf("  [");
        for ( j = 0; j < group_sizes[i]; j++) {
            printf("\"%s\"", transactions[grouped[i][j]]);
            if (j < group_sizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (i < group_count - 1) {
            printf(",\n");
        }
    }
    printf("\n]\n");

    return 0;
}

