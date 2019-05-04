#include<stdio.h>

int main()
{
    int n,i;
    long long int x[52];
    x[1]=1;
    x[2]=2;
    x[3]=3;
    for(i=4;i<=50;i++)
    {
        x[i]=x[i-1]+x[i-2];
    }

    while(scanf("%d",&n)==1&&n!=0)
    {
        printf("%lld\n",x[n]);
    }



    return 0;
}
