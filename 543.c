#include<stdio.h>
#include<math.h>

int prm[1000008];

int shv()
{
    int i,rt,j;
    rt=sqrt(1000008)+2;
    for(i=0;i<=1000008;i++)
    {
        prm[i]=0;
    }
    prm[0]=1;
    prm[1]=1;
    for(i=4;i<1000008;i=i+2)
    {
        prm[i]=1;
    }
    for(i=3;i<=rt;i=i+2)
    {
        if(prm[i]==0)
        {
            for(j=2*i;j<1000008;j=j+i)
            {
                prm[j]=1;
            }
        }
    }
}

int main()
{
    int in,a,i,half;
    shv();
    while(scanf("%d",&in)&&in!=0)
    {
        a=0;
        half=(in/2)+2;
        for(i=2;i<half;i++)
        {
            if(prm[i]==0&&prm[in-i]==0)
            {
                a=i;
                break;
            }
        }
        if(a)
        {
            printf("%d = %d + %d\n",in,a,in-a);
        }
        else
        {
            printf("Goldbach's conjecture is wrong.\n");
        }
    }




    return 0;
}
