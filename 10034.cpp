#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
#define edge pair<int,int>

double pos[2][110],total;
vector< pair<double,edge > > grap_con;
int parent[110];

double countDist(int p,int q)
{
    double x1=pos[0][p],y1=pos[1][p];
    double x2=pos[0][q],y2=pos[1][q];

    double a=(x1-x2)*(x1-x2);
    double b=(y1-y2)*(y1-y2);

    return sqrt(a+b);
}

int findx(int x)
{
    if(parent[x]==x) return x;
    return parent[x]=findx(parent[x]);
}

void uni(int a,int b)
{
    parent[findx(b)]=findx(a);
}

void make_grap_con(int n)
{
    for(int i=0;i<110;i++)
    {
        parent[i]=i;
    }
    total=0.0;
    grap_con.clear();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                grap_con.push_back(pair<double,edge>(countDist(i,j),edge(i,j)));
            }
        }
    }
}

void kruskal(int n)
{
    int pa,pb,i,j;
    sort(grap_con.begin(),grap_con.end());

    for(i=1,j=0;i<n;j++)
    {
        pa=grap_con[j].second.first;
        pb=grap_con[j].second.second;
        if(findx(pa)!=findx(pb))
        {
            i++;
            total=total+grap_con[j].first;
            uni(pa,pb);
        }
    }
}

int main()
{
    int cs,n,flag=0;

    scanf("%d",&cs);
    while(cs--)
    {
        if(flag)
        {
            printf("\n");
        }
        flag=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lf %lf",&pos[0][i],&pos[1][i]);
        }
        make_grap_con(n);
        kruskal(n);
        printf("%.2lf\n",total);

    }

    return 0;
}
