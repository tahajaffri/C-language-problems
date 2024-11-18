#include<stdio.h>

int main() {
  int i, j, temp, number[5];
  printf("Welcome to the Array Largest Number Analysis System!\n");
  printf("\nEnter elements of the array:\n");

  for(i = 0; i < 5; i++) {
    printf("--> ");
    scanf("%d", &number[i]);
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
  // Print largest number
  printf("The largest number in the array is %d ",number[4]);

  return 0;
}

