#include<stdio.h>

int main()
{
    int a,b,c,d,l,fx,count,i;

    while(scanf("%d%d%d%d%d",&a,&b,&c,&d,&l)==5&&(a||b||c||d||l))
    {
        count=0;
        for(i=0;i<=l;i++)
        {
            fx=((a*i+b)*i)+c;
            if(fx%d==0)
            {
                count++;
            }
        }
        printf("%d\n",count);
    }

    return 0;
}
