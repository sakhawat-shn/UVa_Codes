#include<stdio.h>
#include<math.h>

int prm[50000],flag,pnm[50000]={0};


void shv()
{
    int a,i,j,id=1;
    a=sqrt(50000)+1;
    for(i=0; i<50000; i++)
    {
        prm[i]=1;
    }
    prm[0]=0;
    prm[1]=0;
    for(i=4; i<50000; i=i+2)
    {
        prm[i]=0;
    }
    for(i=3; i<=a; i=i+2)
    {
        if(prm[i])
        {
            for(j=i*2; j<50000; j=j+i)
            {
                prm[j]=0;
            }
        }
    }
    for(i=2;i<50000;i++)
    {
        if(prm[i])
        {
            pnm[id]=i;
            id++;
        }
    }
}

int vag(int nm,int i)
{
    for(; nm%i==0;)
    {
        if(flag)
        {
            printf(" x");

        }
        printf(" %d",i);
        nm=nm/i;
        flag=1;
    }

    return nm;
}


int main()
{
    int nm,i;
    shv();

    while(scanf("%d",&nm)==1&&nm!=0)
    {
        flag=0;
        printf("%d =",nm);
        if(nm<0)
        {
            printf(" -1");
            flag=1;
            nm=nm*(-1);
        }
        for(i=1; i<50000&&pnm[i]!=0; i++)
        {

                if(nm%pnm[i]==0)
                {
                    nm=vag(nm,pnm[i]);
                }

        }
        if(nm!=1)
        {
            if(flag)
            {
                printf(" x");

            }
            printf(" %d",nm);
        }
        printf("\n");



    }



    return 0;
}
