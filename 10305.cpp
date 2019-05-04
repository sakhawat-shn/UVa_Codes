#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GREY 1
#define BLACK 2

vector<int> graph[105],top_sort;
int visit[105];

void init(int a)
{
    for(int i=0;i<=a+1;i++)
    {
        graph[i].clear();
        visit[i]=0;
    }
    top_sort.clear();
}


bool dfs(int u)
{
    visit[u]=GREY;
    bool no_cycle=true;
    int sz=graph[u].size();
    for(int i=0;i<sz;i++)
    {
        int v=graph[u][i];
        if(visit[v]==WHITE)
        {
            no_cycle=dfs(v);
        }
        else if(visit[v]==GREY)
        {
            return false;
        }
    }
    visit[u]=BLACK;
    top_sort.push_back(u);
    return no_cycle;
}

bool topsort(int N)
{
    int no_cycle=true;
    for(int i=1;i<=N;i++)
    {
        if(visit[i]==WHITE) no_cycle&=dfs(i);
    }
    return no_cycle;
}


int main()
{
    int m,n,a,b,sz,flag;

    while(scanf("%d %d",&n,&m)==2&&!(n==m&&n==0))
    {
        init(n);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
        }
        topsort(n);
        sz=top_sort.size();
        flag=0;
        for(int i=sz-1;i>=0;i--)
        {
            if(flag)
            {
                printf(" ");
            }
            flag=1;
            printf("%d",top_sort[i]);
        }
        printf("\n");
    }

}
