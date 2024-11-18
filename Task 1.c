#include<stdio.h>
int main(){
  
  int i,j,temp,arr[5];
  printf("\nEnter 5 elements of the array: \n");
  for(j=0;j<5;j++){
  printf("-->\t");
  scanf("%d",&arr[j]);
}

  //Bubble sorting algorithm,asc order
  for(i=0;i<5;i++){
    for(j=0;j<5-1;j++){
      if(arr[j]>arr[j+1]){
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
  }
  
  int second_smallest=arr[1];
  
  printf("%d\t",arr[1]);
  
  return 0;
}
