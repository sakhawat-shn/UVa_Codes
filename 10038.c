#include<stdio.h>

int a[3009];

int main()
{
    int n,n1,n2,i,m;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n+11;i++)
        {
            a[i]=0;
        }
        scanf("%d",&n1);
        for(i=2;i<=n;i++)
        {
            scanf("%d",&n2);
            m=n2-n1;
            if(m<0)
            {
                m=(-1)*m;
            }
            if(m<n)
            {
                a[m]=1;
            }
            n1=n2;
        }
        for(i=1;i<n;i++)
        {
            if(a[i]==0)
            {
                break;
            }
        }
        if(i==n)
        {
            printf("Jolly\n");
        }
        else
        {
            printf("Not jolly\n");
        }
    }



    return 0;
}
