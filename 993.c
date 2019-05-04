#include<stdio.h>
#include<math.h>

#define svn 10000000

int d[10];
int n[svn]={0};

void shv()
{
    int i,j,rt;
    rt=sqrt(svn)+2;
    n[0]=1;
    n[1]=1;
    for(i=2;i<svn;i=i+2)
    {
        n[i]=1;
    }

    for(i=3;i<rt;i=i+2)
    {
        if(n[i]==0)
        {
            for(j=i;j<svn;j=j+i)
            {
                if(i<11)
                {
                    n[j]=1;
                }
                else
                {
                    n[j]=6;
                }
            }
        }
    }

}

void fnd(int a)
{
    int i;
    for(i=9;i>=2;i--)
    {
        d[i]=0;
        while(a%i==0)
        {
            d[i]++;
            a=a/i;
        }
    }
    d[1]=a;
}



int main()
{
    int a,nm,i,flag,j,k,x;
    shv();


    scanf("%d",&a);

    for(i=0;i<a;i++)
    {
        scanf("%d",&nm);
        flag=0;
        if(nm<svn)
        {
            if(n[nm]==1)
            {
                flag=1;
            }
        }
        else
        {
            flag=1;
        }
        if(nm==0||nm==1)
        {
            flag=0;
        }
        if(flag)
        {
            fnd(nm);
        }
        if(nm==0||nm==1)
        {
            printf("%d\n",nm);
        }
        else if(flag==1&&d[1]==1)
        {
            for(j=2;j<=9;j++)
            {
                x=d[j];
                for(k=0;k<x;k++)
                {
                    printf("%d",j);
                }
            }
            printf("\n");

        }
        else
        {
            printf("-1\n");
        }


    }

    return 0;
}
