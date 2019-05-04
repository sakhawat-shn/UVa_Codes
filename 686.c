#include<stdio.h>
#include<math.h>

int prm[33000];

int shv()
{
    int i,rt,j;
    rt=sqrt(33000)+2;
    for(i=0;i<33000;i++)
    {
        prm[i]=1;
    }
    prm[0]=0;
    prm[1]=0;
    for(i=4;i<33000;i=i+2)
    {
        prm[i]=0;
    }
    for(i=3;i<=rt;i=i+2)
    {
        if(prm[i])
        {
            for(j=2*i;j<33000;j=j+i)
            {
                prm[j]=0;
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
        half=in/2;
        for(i=2;i<=half;i++)
        {
            if(prm[i]&&prm[in-i])
            {
                a++;

            }
        }
            printf("%d\n",a);

    }




    return 0;
}
