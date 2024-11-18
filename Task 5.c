#include<stdio.h>
int main() {
	int n,i,j;
	printf("Enter number of integers to input: ");
	scanf("%d",&n);
	int arr[n], highest=0;
	printf("Enter the elements of the array: \n");

	for( i=0 ; i<n ; i++) {
		printf("%d ) ",i+1);
		scanf("%d",&arr[i]);
		if(arr[i]>highest){
			highest=arr[i];
		}
	}

	//Print horizontal histogram
	printf("Horizontal Histogram: \n");
	for( i=0; i<n; i++) {
		printf("Value %d: ",i+1);
		for( j=0; j<arr[i]; j++) {
			printf("* ");
		}
		printf("\n");
	}

	//Print vertical histogram
	printf("Vertical Histogram: \n");
	for( i=highest; i>0 ; i--){
		printf("\t");
		for( j=0; j<n ; j++){
			if(i<=arr[j]){
				printf("* ");
			}else
			printf("  ");
		}
		printf("\n");
	}


	return 0;
}

