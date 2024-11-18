#include<stdio.h>
int main(){
  
  int i,number[]={10,20,36,85,49,97};
  int size;
  /*
  1. sizeof(arr) returns the total number of bytes occupied by the array.
   Since  1--> 4       ___________
    Then, 4 --> 16 => | 16 bytes |
    
  2. sizeof(arr[0]) returns the number of bytes occupied by one element of the array.
  (one element takes 4 bytes) */
  
  size=sizeof(number)/sizeof(number[0]);

  printf("\nThe size of the array is %d.",size);
  return 0;
}
