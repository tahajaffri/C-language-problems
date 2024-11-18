#include <stdio.h>
#include <string.h>

int compress_word(char *word) {
    int count = 0;

    int j = 0,k;
    while(word[j] != '\0'){
        if(word[j] == word[j + 1]){
            for( k = j; word[k] != '\0'; k++){
                word[k] = word[k + 1];
            }
            count++;
        }else{
            j++;
        }
    }

    return count;
}

int main(){
    int n,i;
    printf("How many words do you want to enter? ");
    scanf("%d", &n);

    char words[n][1000];
    int total_removed = 0;

    for ( i = 0; i < n; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", words[i]);
    }

    for (i = 0; i < n; i++) {
        total_removed += compress_word(words[i]);
    }

    printf("\nFinal words after compression:\n");
    for ( i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    printf("\nTotal characters removed: %d\n", total_removed);

    return 0;
}

