#include<cstdio>

#define dll long long int

dll rv(dll a)
{
    dll c,b=0;
    while(a)
    {
        b=b*10;
        c=a%10;
        b=b+c;
        a=a/10;

    }
    return b;
}


int main()
{
    int n,i,count;
    long long int a,b;

    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a);
        count=0;
        b=rv(a);

        do
        {
            count++;
            a=a+b;
            b=rv(a);
        }
        while((a-b)!=0);

        printf("%d %lld\n",count,a);


    }


    return 0;
}
