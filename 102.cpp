#include<stdio.h>

int val[10],mov;
char ch[5]="BCG",cns[10]=" BCG";

void fun(int a,int b,int c)
{
    int sum=0;

    if(a==1)
    {
        sum=sum+val[2]+val[3];
    }
    else if(a==2)
    {
        sum=sum+val[1]+val[2];
    }
    else
    {
        sum=sum+val[1]+val[3];
    }

    if(b==1)
    {
        sum=sum+val[5]+val[6];
    }
    else if(b==2)
    {
        sum=sum+val[4]+val[5];
    }
    else
    {
        sum=sum+val[4]+val[6];
    }

    if(c==1)
    {
        sum=sum+val[8]+val[9];
    }
    else if(c==2)
    {
        sum=sum+val[7]+val[8];
    }
    else
    {
        sum=sum+val[7]+val[9];
    }

    if(a==1&&b==2&&c==3)
    {
        mov=sum;
        ch[0]=cns[a];
        ch[1]=cns[b];
        ch[2]=cns[c];
    }
    else
    {
        if(sum<mov)
        {
            mov=sum;
            ch[0]=cns[a];
            ch[1]=cns[b];
            ch[2]=cns[c];
        }
    }

}


int main()
{
    int a,b;

    while(scanf("%d%d%d %d%d%d %d%d%d",&val[1],&val[2],&val[3],&val[4],&val[5],&val[6],&val[7],&val[8],&val[9])==9)
    {
        fun(1,2,3);
        fun(1,3,2);
        fun(2,1,3);
        fun(2,3,1);
        fun(3,1,2);
        fun(3,2,1);

        printf("%s %d\n",ch,mov);

    }

    return 0;
}
