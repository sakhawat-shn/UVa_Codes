#include<stdio.h>

int main()
{
    int a,b=1,c,top,inp;
    scanf("%d",&a);
    while(b<=a)
    {
        scanf("%d",&c);
        top=0;
        while(c)
        {
            scanf("%d",&inp);
            if(inp>=top)
            {
                top=inp;
            }
            c--;
        }
        printf("Case %d: %d\n",b,top);
        b++;
    }
    return 0;
}
