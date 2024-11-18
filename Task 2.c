#include<stdio.h>
#include<string.h>

void count_character_frequency(char slogan[]) {
    int len = strlen(slogan),i,j,k;

    for(i = 0; i < len; i++){
        int count = 0;
        char target = slogan[i];
        int already_counted = 0;

        for(k = 0; k < i; k++){
            if(slogan[k] == target){
                already_counted = 1;
                break;
            }
        }

        if(!already_counted){
            for(j = 0; j < len; j++){
                if(slogan[j] == target){
                    count++;
                }
            }
            printf("'%c' : %d\n", target, count);
        }
    }
}

int main(){
    int num_slogans,i;
    printf("Enter the number of slogans: ");
    scanf("%d", &num_slogans);
    getchar();

    char slogan[100];

    for(i = 0; i < num_slogans; i++){
        printf("Enter slogan %d: ", i + 1);
        fgets(slogan, sizeof(slogan), stdin);

        slogan[strcspn(slogan, "\n")] = '\0';

        printf("\nCharacter frequency in \"%s\":\n", slogan);
        count_character_frequency(slogan);
        printf("\n");
    }

    return 0;
}

