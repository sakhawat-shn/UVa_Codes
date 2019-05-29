#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main()
{
    int node,edge,a,b;

    while(scanf("%d",&node)&&node!=0)
    {
        scanf("%d",&edge);
        vector<int> adjnode[node];
        for(int i=0;i<edge;i++)
        {
            scanf("%d%d",&a,&b);
            adjnode[a].push_back(b);
            adjnode[b].push_back(a);
        }

        queue<int> q;
        vector<int> color(node,100);
        q.push(0);
        color[0]=0;
        bool isBipart=true;

        while(!q.empty()&&isBipart)
        {
            int u=q.front();q.pop();
            int sz=adjnode[u].size();
            for(int i=0;i<sz;i++)
            {
                int v=adjnode[u][i];
                if(color[v]==100)
                {
                    color[v]=1-color[u];
                    q.push(v);
                }
                else if(color[u]==color[v])
                {
                    isBipart=false;
                    break;
                }
            }
        }

        if(isBipart)
        {
            printf("BICOLORABLE.");
        }
        else
        {
            printf("NOT BICOLORABLE.");
        }
        printf("\n");
    }

    return 0;
}
