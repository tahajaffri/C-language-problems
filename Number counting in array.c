#include <stdio.h>

int main() {
    int i,n,number[3];
    int counter=0;

    printf("Welcome to the Array Number Counting System!\n");
    printf("\nEnter the number to be counted in your array: \n");
    scanf("%d",&n);
    printf("\nEnter elements of the array :\n");
    for(i=0;i<3;i++){
      printf("--> ");
      scanf("%d",&number[i]);

      if(number[i]=='n'){
        counter++;
      }

    }

    printf("The number ""%d"" came %d times in your array!\n",n,counter);
    return 0;
}

