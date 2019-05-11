#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

int count;
int flag[10010];

void init()
{
    int i;
    count=0;
    for(i=0;i<10010;i++)
    {
        flag[i]=1;
    }
}

int main()
{
    int t,n,m,l,x,y,z,next,next1;

    scanf("%d",&t);

    while(t--)
    {
        init();

        scanf("%d %d %d",&n,&m,&l);
        vector<int> vec[n+2];
        queue<int> q;
        while(m--)
        {
            scanf("%d %d",&x,&y);
            vec[x].push_back(y);
        }
        while(l--)
        {
            scanf("%d",&z);
            if(flag[z])
            {
                q.push(z);
                flag[z]=0;
                count++;
            }

            while(!q.empty())
            {
                next=q.front();
                q.pop();
                while(!vec[next].empty())
                {
                    next1=vec[next].back();
                    vec[next].pop_back();
                    if(flag[next1])
                    {
                        q.push(next1);
                        flag[next1]=0;
                        count++;
                    }
                }

            }
        }
        printf("%d\n",count);
    }

    return 0;
}
