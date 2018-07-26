#include<stdio.h>
#include<math.h>


int chk(int a,int b)
{
    int temp;
    if(b>a)
    {
        temp=a;
        a=b;
        b=temp;
    }
    while(b)
    {
        temp=b;
        b=a%temp;
        a=temp;
    }
    if(temp==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }


}


int main()
{
    int n,i,j;
    double ans;
    while(scanf("%d",&n)&&n!=0)
    {
        int numb[n],count=0,jor=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&numb[i]);
        }

        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                count=count+chk(numb[i],numb[j]);
                jor++;
            }

        }
        if(count)
        {
            ans=sqrt(((double)jor*6)/(double)count);
            printf("%.6lf\n",ans);
        }
        else
        {
            printf("No estimate for this data set.\n");
        }



    }





    return 0;
}
