#include<stdio.h>

int mat[6][6]={
    {0,0,0,0,0,0},
    {0,0,1,1,0,1},
    {0,1,0,1,0,1},
    {0,1,1,0,1,1},
    {0,0,0,1,0,1},
    {0,1,1,1,1,0}
};

int vgtd[6][6]={0};
int path[11];


void print()
{
    int i;
    for(i=1;i<=9;i++)
    {
        printf("%d",path[i]);
    }
    printf("\n");
}

void dfs(int edg,int stp)
{
    int i;
    path[stp]=edg;
    if(stp==9)
    {
        print();
        return;
    }

    for(i=1;i<=5;i++)
    {
        if(mat[edg][i]&&vgtd[edg][i]==0)
        {
            vgtd[edg][i]=1;
            vgtd[i][edg]=1;
            dfs(i,stp+1);
            vgtd[edg][i]=vgtd[i][edg]=0;
        }
    }

}

int main()
{
    dfs(1,1);
    return 0;
}
