#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

#define edge pair<int,int>

int pos[2][1000],point_num[1000];

vector< pair<double,edge> > V,mst;

int findx(int x)
{
    if(point_num[x]==x) return x;
    return point_num[x]=findx(point_num[x]);
}

void uni(int a,int b)
{
    point_num[findx(b)]=findx(a);
}

double find_dist(int a,int b)
{
    int x=pos[0][a]-pos[0][b];
    int y=pos[1][a]-pos[1][b];

    return sqrt((x*x)+(y*y));
}


void make_vec(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(i!=j)
            {
                V.push_back(pair <double,edge >(find_dist(i,j),edge(i,j)));
            }
        }
    }
}

int kruskal()
{
    int pa,pb,flag=0,namb_edge;

    sort(V.begin(),V.end());
    namb_edge=V.size();

    for(int i=0;i<namb_edge;i++)
    {
        pa=V[i].second.first;
        pb=V[i].second.second;
        if(findx(pa)!=findx(pb))
        {
            flag=1;
            mst.push_back(V[i]);
            uni(pa,pb);
        }
    }


    return flag;
}

int main()
{
    int test_case,N,M,a,b,flag=0;
    scanf("%d",&test_case);

    while(test_case--)
    {
        V.clear();
        mst.clear();
        if(flag)
        {
            printf("\n");
        }
        flag=1;
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
        {
            scanf("%d %d",&pos[0][i],&pos[1][i]);
            point_num[i]=i;
        }
        scanf("%d",&M);
        for(int i=1;i<=M;i++)
        {
            scanf("%d %d",&a,&b);
            uni(a,b);
        }
        make_vec(N);
        int fla=kruskal();

        if(fla)
        {
            int sz=mst.size();
            for(int i=0;i<sz;i++)
            {
                printf("%d ",mst[i].second.first);
                printf("%d\n",mst[i].second.second);
            }
        }
        else
        {
            printf("No new highways need\n");
        }
    }

    return 0;
}
