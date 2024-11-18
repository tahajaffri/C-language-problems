#include<stdio.h>
#include<stdio.h>

int main() {
  int i, j, temp, number[5];
  printf("Bubble Sorting Algorithm\n");
  printf("\nEnter elements of the array:\n");

  for(j = 0; j < 5; j++) {
    printf("--> ");
    scanf("%d", &number[j]);
  }

  // Bubble Sorting
  //In ascending order (if changed to j>4 ,then descending order)
  for(i = 0; i < 5; i++) {
    for(j = 0; j < 4; j++) {  // should go until 4, because we access number[j+1]
      if(number[j] > number[j + 1]) {
        temp = number[j];
        number[j] = number[j + 1];
        number[j + 1] = temp;
      }
    }
  }
  // Print sorted array
  printf("The sorted array is :\n");
  printf("\n[ ");
  for(j=0;j<5;j++){
    printf("%d",number[j]);
    if(j<4){
      printf(",");
    }
  }
  printf(" ]\n");

  return 0;
}

