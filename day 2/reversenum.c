#include<stdio.h>
int main()
{ 
    int n;
    printf("enter n");
    scanf("%d",&n);
    int revnum=0;
    while(n>0)
    {
      int  ld=n%10;
       revnum=(revnum*10) +ld;
        n=n/10;

    }
    printf("%d",revnum);
    return 0;
}