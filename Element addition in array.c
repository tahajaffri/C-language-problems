#include<stdio.h>

int main() {
  int i,size,newelement,number[10];
  
  printf("Enter size of the array: \n");
  scanf("%d",&size);
  
  printf("Enter %d elements of array: \n",size);
  for(i=0;i<size;i++){
    printf("--> ");
    scanf("%d",&number[i]);
  }
  
  printf("Enter element to add in te array: \n");
  printf("--> ");
  scanf("%d",&newelement);
  
  number[size]=newelement;
  size++;
  
  printf("The updated array is: \n[");
  for(i=0;i<size;i++){
    printf("%d",number[i]);
    if(i<size-1){
      printf(",");
    }
  }
  printf("]\n");
}

