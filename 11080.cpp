#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int v,e,a,b;
        scanf("%d%d",&v,&e);
        vector<int> adjnode[v];
        for(int i=0; i<e; i++)
        {
            scanf("%d%d",&a,&b);
            adjnode[a].push_back(b);
            adjnode[b].push_back(a);
        }

        vector<int> color(v,100);


        bool bpflag=true;
        int grd_need=0;

        for(int k=0; k<v&&bpflag; k++)
        {
            if(color[k]!=100)continue;
            int ones,zeros;
            ones=zeros=0;
            queue<int> q;
            q.push(k);
            color[k]=1;

            while(!q.empty() && bpflag)
            {
                int u=q.front();
                q.pop();
                if(color[u])
                {
                    ones++;
                }
                else
                {
                    zeros++;
                }
                for(int j=0; j<adjnode[u].size(); j++)
                {
                    int x=adjnode[u][j];
                    if(color[x]==100)
                    {
                        color[x]=1-color[u];
                        q.push(x);

                    }
                    else if(color[x]==color[u])
                    {
                        bpflag=false;
                        break;
                    }
                }
            }
            grd_need=grd_need+(ones<zeros?ones:zeros);
        }

        for(int i=0;i<v;i++)
        {
            if(adjnode[i].size()==0)grd_need++;
        }

        if(bpflag)
            printf("%d",grd_need);
        else
            printf("-1");
        printf("\n");
    }


    return 0;
}
