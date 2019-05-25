#include<stdio.h>

int main()
{
    int t,n,p,q,i,count,sum,j,egg,w8;
    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
       scanf("%d%d%d",&n,&p,&q);
       count=w8=0;

       for(j=1;j<=n;j++)
       {
           scanf("%d",&egg);
           w8=w8+egg;
           if(w8<=q)
           {
               count++;
           }
       }

       if(count>p)
       {
           printf("Case %d: %d\n",i,p);
       }
       else
       {
           printf("Case %d: %d\n",i,count);
       }
    }

    return 0;
}
