#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

map<string,int> mp;
map<int,string> mp_name;
vector<int> graph[110],ans;
int indeg[110];

void init(int a)
{
    ans.clear();
    mp.clear();
    mp_name.clear();
    for(int i=0;i<=a+1;i++)
    {
        graph[i].clear();
        indeg[i]=0;
    }

}


bool topsort(int N)/*it's void*/
{
    priority_queue<int> pq;
    for(int i=0;i<N;i++)
    {
        if(indeg[i]==0)
        {
            pq.push((-1)*i);
        }
    }

    while(!pq.empty())
    {
        int now=pq.top();pq.pop();
        now=now*(-1);
        ans.push_back(now);
        int sz=graph[now].size();
        for(int i=0;i<sz;i++)
        {
            indeg[graph[now][i]]--;
            if(indeg[graph[now][i]]==0)
            {
                pq.push(graph[now][i]*(-1));
            }
        }
    }
}


int main()
{
    int a,b,i,cse=0;
    string s,s1;

    while(scanf("%d",&a)==1)
    {
        init(a);
        for(i=0;i<a;i++)
        {
            cin>>s;
            mp[s]=i;
            mp_name[i]=s;
        }
        scanf("%d",&b);
        for(i=0;i<b;i++)
        {
            cin>>s;
            cin>>s1;
            graph[mp[s]].push_back(mp[s1]);
            indeg[mp[s1]]++;
        }
        topsort(a);

        printf("Case #%d: ",++cse);
        printf("Dilbert should drink beverages in this order:");
        b=ans.size();
        for(i=0;i<b;i++)
        {
            int v=ans[i];
            cout<<" "<<mp_name[v];
        }
        printf(".\n\n");
    }

    return 0;
}
