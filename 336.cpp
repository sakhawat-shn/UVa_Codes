#include<stdio.h>
#include<map>
#include<queue>
using namespace std;

int adm[35][35],done[35];

void clear()
{
    int i,j;
    for(i=0;i<35;i++)
    {
        for(j=0;j<35;j++)
        {
            adm[i][j]=0;
        }
    }

}

void dfs(int st,int t)
{
    queue<int> q;
    int working,i;
    q.push(st);
    done[st]=t+1;
    while(!q.empty())
    {
        working=q.front();
        q.pop();
        for(i=1;i<35;i++)
        {
            if(adm[working][i]==1&&!done[i])
            {
                q.push(i);
                done[i]=done[working]-1;
            }
        }

    }
}

int count()
{
    int a=0,i;
    for(i=0;i<35;i++)
    {
        if(done[i]>0)
        {
            a++;
        }
    }

    return a;
}


int main()
{
    int nc,i,cs=1;

    while(scanf("%d",&nc)==1&&nc!=0)
    {
        clear();

        int des1,des2,mcount=1;
        map<int,int> mp;

        for(i=0;i<nc;i++)
        {
            scanf("%d %d",&des1,&des2);
            if(!mp[des1])
            {
                mp[des1]=mcount++;
            }
            if(!mp[des2])
            {
                mp[des2]=mcount++;
            }
            int x=mp[des1];
            int y=mp[des2];
            adm[x][y]=adm[y][x]=1;

        }

        int strt,ttl;

        while(scanf("%d %d",&strt,&ttl)==2&&(strt!=0||ttl!=0))
        {
            for(i=0;i<35;i++)
            {
                done[i]=0;
            }

            dfs(mp[strt],ttl);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cs++,mp.size()-count(),strt,ttl);
            if(!mp[strt])
            {
                mp.erase(strt);
            }
        }


    }

    return 0;
}
