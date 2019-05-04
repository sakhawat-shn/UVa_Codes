#include<stdio.h>
#include<math.h>

int prm[20000000];
int twn[100002];

int shv()
{
    int i,rt,j,x=1;
    rt=sqrt(20000000)+2;
    for(i=0;i<20000000;i++)
    {
        prm[i]=0;
    }
    prm[0]=1;
    prm[1]=1;
    /*for(i=4;i<20000000;i=i+2)
    {
        prm[i]=1;
    }*/
    for(i=3;i<20000000&&x<100002;i=i+2)
    {
        if(prm[i]==0&&i<=rt)
        {
            for(j=2*i;j<20000000;j=j+i)
            {
                prm[j]=1;
            }
        }
        if(prm[i]==0&&prm[i-2]==0)
        {
            twn[x]=i-2;
            x++;
        }

    }
    /*for(i=2;i<20000000&&x<100002;i++)
    {
        if(prm[i]==0&&prm[i-2]==0)
        {
            twn[x]=i-2;
            x++;
        }
    }*/
}

int main()
{
    int k;

    shv();

    while(scanf("%d",&k)==1)
    {
        printf("(%d, %d)\n",twn[k],twn[k]+2);
    }



    return 0;
}
