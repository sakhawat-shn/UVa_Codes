#include<stdio.h>

int main()
{
    int a,b,c,x,y,z;

    while(scanf("%d%d%d",&a,&b,&c)==3)
    {
        if(a==0&&b==0&&c==0)
        {
            break;
        }
        else
        {
            x=a*a+b*b-c*c;
            y=b*b+c*c-a*a;
            z=c*c+a*a-b*b;
            if(x==0||y==0||z==0)
            {
                printf("right\n");
            }
            else
            {
                printf("wrong\n");
            }
        }
    }
    return 0;
}
