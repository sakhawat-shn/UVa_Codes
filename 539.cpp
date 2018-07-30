#include<stdio.h>

int adj[40][40];
int max;
int n,m;

void clear()
{
    max=0;
    for(int i=0;i<40;i++)
    {
        for(int j=0;j<40;j++)
        {
            adj[i][j]=0;
        }
    }
}

void setmax(int a)
{
    if(a>max)
    {
        max=a;
    }
}

void dfs(int node,int step)
{
    int flag=1;
    for(int i=0;i<n;i++)
    {
        if(adj[node][i])
        {
            flag=0;
            adj[node][i]--;
            adj[i][node]--;
            dfs(i,step+1);
            adj[node][i]++;
            adj[i][node]++;
        }
    }

    if(flag)
    {
        setmax(step);
    }
}




int main()
{
    int i;
    int a,b;
    while(scanf("%d %d",&n,&m)==2&n!=0&m!=0)
    {
        clear();

        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            adj[a][b]++;
            adj[b][a]++;
        }

        for(i=0;i<n;i++)
        {
            dfs(i,0);
        }

        printf("%d\n",max);

    }


    return 0;
}
