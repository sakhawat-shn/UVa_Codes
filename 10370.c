#include<stdio.h>

int main()
{
    int t,n,i,sum,avrg,up;
    float out;
    scanf("%d",&t);
    while(t)
    {
        scanf("%d",&n);
        int mark[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&mark[i]);
        }
        sum=0;
        for(i=0;i<n;i++)
        {
            sum=sum+mark[i];
        }
        avrg=sum/n;
        up=0;
        for(i=0;i<n;i++)
        {
            if(mark[i]>avrg){up++;}
        }
        out=((float)(100*up))/((float)n);
        printf("%.3f\%\n",out);
        t--;
    }
    return 0;
}
