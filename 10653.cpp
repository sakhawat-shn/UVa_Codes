#include<stdio.h>
#include<queue>
using namespace std;


struct pos
{
    int row;
    int col;
    int length;
};

int visited[1009][1009],input[1009][1009];

void clr(int row,int col)
{
    for(int i=0;i<=row;i++)
    {
        for(int j=0;j<=col;j++)
        {
            visited[i][j]=input[i][j]=0;
        }
    }
}


void mask(int a,int b)
{
    for(int i=0;i<=b;i++)
    {
        input[a][i]=1;
    }

    for(int i=0;i<=a;i++)
    {
        input[i][b]=1;
    }
}

int cango(int row,int col)
{
    if(visited[row][col]==0&&input[row][col]==0&&row>=0&&col>=0)
    {
        return 1;
    }
    return 0;
}


int ar[4]={-1,0,1,0};
int ac[4]={0,1,0,-1};

int bfs(int sR,int sC,int dR,int dC)
{
    queue<pos> q;
    pos start,now,make;
    start.row=sR;
    start.col=sC;
    start.length=0;
    visited[sR][sC]=1;

    q.push(start);

    while(!q.empty())
    {
        now=q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            if(cango(now.row+ar[i],now.col+ac[i]))
            {
                make.row=now.row+ar[i];
                make.col=now.col+ac[i];
                make.length=now.length+1;
                if(make.col==dC&&make.row==dR)
                {
                    return make.length;
                }
                visited[make.row][make.col]=1;
                q.push(make);
            }
        }

    }


}




int main()
{
    int r,c;
    int inow,jnow,row,col,sorow,socol,desrow,descol;
    int lowest;

    while(scanf("%d%d",&r,&c)==2&&r!=0&&c!=0)
    {
        clr(r,c);
        mask(r,c);

        scanf("%d",&inow);
        for(int i=0;i<inow;i++)
        {
            scanf("%d%d",&row,&jnow);
            for(int j=0;j<jnow;j++)
            {
                scanf("%d",&col);
                input[row][col]=1;
            }
        }

        scanf("%d%d%d%d",&sorow,&socol,&desrow,&descol);

        lowest=bfs(sorow,socol,desrow,descol);

        printf("%d\n",lowest);

    }

    return 0;
}
