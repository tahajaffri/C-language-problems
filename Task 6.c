#include<stdio.h>

int canWin(int n){
	if(n % 5 != 0){
		return -1;
	}
}

int main(){
	int n;
	printf("\nEnter number of matchsticks: ");
	scanf("%d",&n);
	canWin(n);
	if(canWin(n)==-1){
		printf("Player can not win!");
	} else {
		printf("Player can win! ");
	}
	return 0;
}

