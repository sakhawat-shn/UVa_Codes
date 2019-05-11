#include<stdio.h>

int main()
{
    int a,b,c,d=1;

    while(scanf("%d",&a)==1&&a>0)
    {
        c=1;

        for(b=0;c<a;b++)
        {
            c=c*2;
        }
        printf("Case %d: %d\n",d,b);
        d++;

    }



    return 0;
}
