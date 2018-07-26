#include<stdio.h>

int numb[100],k,ans[10];

void print()
{
    int i;
    for(i=1;i<=6;i++)
    {
        if(i!=1)printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
}

void dfs(int pl,int n)
{
    int i;
    if(n==7)
    {
        print();
        return;
    }
    for(i=pl;i<=k;i++)
    {
        ans[n]=numb[i];
        dfs(i+1,n+1);
    }

}


int main()
{
    int i,flag=0;
    while(scanf("%d",&k)==1&&k)
    {
        if(flag)
        {
            printf("\n");
        }
        flag=1;
        for(i=1;i<=k;i++)
        {
            scanf("%d",&numb[i]);
        }
        dfs(1,1);
    }

    return 0;
}
