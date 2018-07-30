#include<stdio.h>

int bn[109];

int main()
{
    int n,i,sum,avg,j=0;

    while(scanf("%d",&n)==1&&n!=0)
    {
        sum=0;
        j++;

        for(i=0;i<n;i++)
        {
            scanf("%d",&bn[i]);
            sum=sum+bn[i];
        }

        avg=sum/n;
        sum=0;

        for(i=0;i<n;i++)
        {
            if(bn[i]>avg)
            {
                sum=sum+(bn[i]-avg);
            }
        }

        printf("Set #%d\n",j);
        printf("The minimum number of moves is %d.\n\n",sum);
    }

    return 0;
}
