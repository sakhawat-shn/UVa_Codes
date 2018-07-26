#include<stdio.h>

long long int big(long long int b,long long int p,long long int m)
{
    long long int x;
    if(p==0)
    {
        return 1%m;
    }
    if(p==1)
    {
        return b%m;
    }
    x=big(b,p/2,m);
    x=(x*x)%m;



    if(p%2)
    {
        return (x*(b%m))%m;
    }
    else
    {
        return x;
    }
}


int main()
{
    long long int b,p,m;

    while(scanf("%lld%lld%lld",&b,&p,&m)==3)
    {
        printf("%lld\n",big(b,p,m));
    }

    return 0;
}
