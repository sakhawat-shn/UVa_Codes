#include<stdio.h>

int main()
{
    int t,n,i,j,mile,juice,ip;
    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        mile=juice=0;

        for(j=1;j<=n;j++)
        {
            scanf("%d",&ip);
            mile=((int)ip/30)*10+10+mile;
            juice=((int)ip/60)*15+15+juice;
        }

        if(mile<juice)
        {
            printf("Case %d: Mile %d\n",i,mile);
        }
        else if(mile>juice)
        {
            printf("Case %d: Juice %d\n",i,juice);
        }
        else
        {
            printf("Case %d: Mile Juice %d\n",i,juice);
        }

    }


    return 0;
}
