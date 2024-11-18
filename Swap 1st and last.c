#include<stdio.h>
#include<math.h>

void swap (int *p1 , int *p2);

void swap (int *p1 , int *p2){
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int num,len,temp,i;
    printf("Enter a number: ");
    scanf("%d",&num);

    len=(int)log10(num)+1;

    int first = num / pow(10,len-1);

    int last = num % 10;

    swap(&first,&last);
    int newnum=first*pow(10,len-1);

    for(i = len-1 ; i>=1 ; i--){
        if(i==1){
            newnum+=last*(pow(10,i-1));
            break;
        }
        temp = num%(int)pow(10,i);
        temp/=pow(10,i-1);

        newnum+=temp*(pow(10,i-1));
    }

    printf("\n new: %d",newnum);

    return 0;
}

