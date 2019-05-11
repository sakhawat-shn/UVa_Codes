#include<stdio.h>

int tar(int x)
{
    int vagfol,vagses;
    if(x==0)
    {
        printf("0");
        return 1;
    }
    vagses=x%3;
    vagfol=x/3;
    if(vagfol==0)
    {
        printf("%d",vagses);
        return 1;
    }
    tar(vagfol);
    printf("%d",vagses);
    return 1;

}

int main()
{
    int a;

    while(scanf("%d",&a)==1&&a>=0)
    {
        tar(a);
        printf("\n");
    }


    return 0;
}
