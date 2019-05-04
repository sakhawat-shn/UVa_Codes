#include<stdio.h>

int main()
{
    int a,b,c;



    while(scanf("%d",&a)==1)
    {
        b=0;
        for(c=1;;c++)
        {
            b=10*b+1;
            b=b%a;
            if(b==0)
            {
                break;
            }
        }
        printf("%d\n",c);
    }



    return 0;
}
