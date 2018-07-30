#include<stdio.h>

int t,n,num[100],flag_g;

int temp1[100],temp2[100];

void clear()
{
    int i;
    for(i=0;i<100;i++)
    {
        num[i]=temp1[i]=temp2[i]=0;
    }
}

int is_same(int a)
{
    int i;
    for(i=0;i<a;i++)
    {
        if(temp1[i]!=temp2[i])
        {
            return 0;
        }
    }
    return 1;
}

void printdata(int a)
{
    int i,flag_l=0;

    if(is_same(a))
    {
        return;
    }

    flag_g=0;

    for(i=0;i<a;i++)
    {
        if(flag_l)
        {
            printf("+");
        }
        printf("%d",temp1[i]);
        temp2[i]=temp1[i];
        flag_l=1;
    }
    printf("\n");
}

void dfs(int pos,int sum,int len)
{
    if(sum==t)
    {
        printdata(len);
        return;
    }
    if(sum>t)
    {
        return;
    }

    int i=pos,now=0,prev=0;
    for(;i<n;i++)
    {
        now=num[i];
        if(prev==now)
        {
            continue;
        }

        temp1[len]=num[i];
        dfs(1+i,sum+num[i],1+len);
        prev=now;
    }
}


int main()
{
    int i;

    while(scanf("%d%d",&t,&n)==2&&n!=0&&t!=0)
    {
        flag_g=1;
        clear();
        for(i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }

        printf("Sums of %d:\n",t);

        dfs(0,0,0);

        if(flag_g)
        {
            printf("NONE\n");
        }

    }

    return 0;
}
