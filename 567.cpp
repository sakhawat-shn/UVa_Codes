#include<stdio.h>
#include<queue>
using namespace std;

int con[21][21];
int visited[30],rak[30];

void clear()
{
    int i,j;
    for(i=0;i<21;i++)
    {
        for(j=0;j<21;j++)
        {
            con[i][j]=0;
        }
    }
}

void bfs(int s)
{
    queue<int>Q;
    int i,now;
    for(i=0;i<30;i++)
    {
        visited[i]=0;
        rak[i]=0;
    }
    Q.push(s);
    visited[s]=1;
    rak[s]=0;

    while(!Q.empty())
    {
        now=Q.front();
        Q.pop();
        for(i=1;i<21;i++)
        {
            if(con[now][i]&&visited[i]==0)
            {
                visited[i]=1;
                Q.push(i);
                rak[i]=rak[now]+1;
            }
        }
    }
}


int main()
{
    int i,a,b,j,tc=0;

    clear();
    while(scanf("%d",&a)==1)
    {
        for(i=1;i<=a;i++)
        {
            scanf("%d",&b);
            con[1][b]=con[b][1]=1;
        }

        for(i=2;i<20;i++)
        {
            scanf("%d",&a);
            for(j=1;j<=a;j++)
            {
                scanf("%d",&b);
                con[i][b]=con[b][i]=1;
            }
        }
        scanf("%d",&a);
        printf("Test Set #%d\n",++tc);
        for(i=1;i<=a;i++)
        {
            scanf("%d%d",&b,&j);
            bfs(b);
            printf("%2d to %2d: %d\n",b,j,rak[j]);
        }
        printf("\n");

        clear();
    }


    return 0;
}
