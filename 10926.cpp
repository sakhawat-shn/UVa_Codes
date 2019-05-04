#include<stdio.h>

int task[110][110];
int list[110];
int bigtask,bigtasknum,count;

void inittask()
{
    int i,j;
    for(i=0;i<110;i++)
    {
        for(j=0;j<110;j++)
        {
            task[i][j]=0;
        }
    }
    bigtask=1;
    bigtasknum=0;
}

void initlist()
{
    int i;
    for(i=0;i<110;i++)
    {
        list[i]=1;
    }
    count=0;
}

void dfs(int a,int b)
{
    int i;
    for(i=1;i<=b;i++)
    {
        if(task[a][i]&&list[i])
        {
            count++;
            list[i]=0;
            dfs(i,b);
        }
    }

}

int main()
{
    int n,t,i,j,x,ctn;

    while(scanf("%d",&n)==1&&n!=0)
    {
        inittask();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&t);
            for(j=1;j<=t;j++)
            {
                scanf("%d",&x);
                task[i][x]=1;
            }
        }

        for(i=1;i<=n;i++)
        {
            initlist();
            dfs(i,n);
            if(count>bigtasknum)
            {
                bigtasknum=count;
                bigtask=i;
            }
        }
        printf("%d\n",bigtask);

    }

    return 0;
}
