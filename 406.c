#include<stdio.h>

int prim[1100]={0},list[500];

void siv()
{
    int a,b,rnk=2;
    list[1]=1;

    for(a=2;a<=1090;a++)
    {
        if(prim[a]==0)
        {
            list[rnk]=a;
            rnk++;

            for(b=a+a;b<=1090;b=b+a)
            {
                prim[b]=1;
            }
        }
    }
}

int main()
{
    int n,c,i,x,p,xx;
    siv();
    while(scanf("%d%d",&n,&c)==2)
    {
        x=0;
        for(i=1;i<=n;i++)
        {
            if(prim[i]==0)
            {
                x++;
            }
        }
        if(x%2)
        {
            p=(x+1)-(2*c);
            p=p/2;
            xx=p+(2*c-1);
        }
        else
        {
            p=x-(2*c);
            p=p/2;
            xx=p+(2*c);
        }

        printf("%d %d:",n,c);
        if(p<=0)
        {
            for(i=1;i<=x;i++)
            {
                printf(" %d",list[i]);
            }

        }
        else
        {
            for(i=p+1;i<=xx;i++)
            {
                printf(" %d",list[i]);
            }
        }
        printf("\n\n");


    }




    return 0;
}
