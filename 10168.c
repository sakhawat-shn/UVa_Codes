#include<stdio.h>
#include<math.h>

int prm[10000005],vl[4];

void shv()
{
    int i,rt,j;
    rt=sqrt(10000005)+2;
    for(i=0;i<10000005;i++)
    {
        prm[i]=1;
    }
    prm[0]=0;
    prm[1]=0;
    for(i=4;i<10000005;i=i+2)
    {
        prm[i]=0;
    }
    for(i=3;i<=rt;i=i+2)
    {
        if(prm[i])
        {
            for(j=2*i;j<10000005;j=j+i)
            {
                prm[j]=0;
            }
        }
    }
}

void cnt(int n)
{
    int i;

    for(i=n/2;i>=2;i--)
    {
        if(prm[i]&&prm[n-i])
        {
            vl[2]=i;
            vl[3]=n-i;
            break;
        }
    }



}


int main()
{
    int a,b;
    shv();
    while(scanf("%d",&a)==1)
    {
        if(a<=7)
        {
            printf("Impossible.\n");
        }
        else
        {
            if(a%2)
            {
                vl[0]=2;
                vl[1]=3;
                b=a-5;
                cnt(b);
            }
            else
            {
                vl[0]=2;
                vl[1]=2;
                b=a-4;
                cnt(b);
            }
            printf("%d %d %d %d\n",vl[0],vl[1],vl[2],vl[3]);
        }
    }




    return 0;
}
