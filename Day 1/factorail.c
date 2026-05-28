#include<stdio.h>
int main()
{
    int n,i,fact=1;
    printf("enter a number :");
    scanf("%d",&n);
    while(n>0){
        fact*=n;
        n--;
    }
    printf("factorial %d",fact);
    return 0;
}