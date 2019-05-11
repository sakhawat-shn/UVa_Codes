#include<stdio.h>

int bin(int x)
{
    int a;
    if(x==0)
    {
        return 1;
    }
    a=x;
    x=x>>1;
    bin(x);
    printf("%d",a&1);
    return 1;

}

int main()
{
    int a,i;

    while(scanf("%d",&a)==1&&a>0)
    {
        i=0;
        printf("The parity of ");

        bin(a);

        for(;a!=0;)
        {
            i=i+(a&1);
            a=a>>1;

        }
        printf(" is %d \(mod 2\).",i);
        printf("\n");

    }


    return 0;
}
