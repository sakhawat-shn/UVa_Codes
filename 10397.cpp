#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
#define edge pair<int,int>
vector<pair<double,edge > > graph;
int p[1000],pos[2][1000];
double total;

void init()
{
    total=0;
    graph.clear();
    for(int i=0;i<1000;i++)
    {
        p[i]=i;
    }
}

int findx(int x)
{
    if(p[x]==x) return x;
    return p[x]=findx(p[x]);
}

void uni(int a,int b)
{
    p[findx(b)]=findx(a);
}

double count_dist(int i,int j)
{
    int x=pos[0][i]-pos[0][j];
    int y=pos[1][i]-pos[1][j];
    return sqrt((x*x)+(y*y));
}


void make_graph(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(i!=j)
            {
                graph.push_back(pair<double,edge >(count_dist(i,j),edge(i,j)));
            }
        }
    }
}

void kruskal()
{
    int i,pa,pb,num_edge;
    sort(graph.begin(),graph.end());
    num_edge=graph.size();
    for(i=0;i<num_edge;i++)
    {
        pa=graph[i].second.first;
        pb=graph[i].second.second;
        if(findx(pa)!=findx(pb))
        {
            total=total+graph[i].first;
            uni(pa,pb);
        }
    }
}


int main()
{
    int n,m,x,y;

    while(scanf("%d",&n)==1)
    {
        init();
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&pos[0][i],&pos[1][i]);
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d",&x,&y);
            uni(x,y);
        }
        make_graph(n);
        kruskal();
        printf("%.2lf\n",total);
    }

    return 0;

}
