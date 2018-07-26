#include<stdio.h>
int chk(int n)
{
    int count=1;
    while(n!=1)
    {
        if(n%2==0)
        {
            n=n/2;
        }
        else
        {
            n=3*n+1;
        }
        count++;
    }
    return count;
}

int loop(int j,int k)
{
    int temp,x,val,max=0;
    if(j>k)
    {
        temp=j;
        j=k;
        k=temp;
    }
    for(x=j;x<=k;x++)
    {
        val=chk(x);
        if(val>max)
        {
            max=val;
        }
    }
    return max;
}

int main()
{
    int i,j,out;
    while(scanf("%d%d",&i,&j)==2)
    {
        out=loop(i,j);
        printf("%d %d %d\n",i,j,out);
    }

    return 0;
}
