#include<stdio.h>

int fact(int n);
int nCr(int n , int r);

int main() {
    int n,r,ans;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter r: ");
    scanf("%d",&r);

    if(r>n){
        printf("Invalid input!\n'r' should be less than ' n'");
        return 1;
    }
    ans = nCr(n,r);
    printf("Ans: %d",ans);
    return 0;
}

int fact(int n){
    int i,fact=1;
    for(i=2 ; i<=n ; i++){
        fact*=i;
    }
    return fact;
}

int nCr(int n , int r){
    return fact(n) / (fact(r) * fact(n - r));
}

