#include<stdio.h>

int con[25][25],total,path[30],lock_list[30],dest;

void init()
{
    int i,j;
    for(i=0;i<25;i++)
    {
        for(j=0;j<25;j++)
        {
            con[i][j]=0;
        }
    }
    for(i=0;i<30;i++)
    {
        path[i]=0;
        lock_list[i]=0;
    }
    total=0;
}

void ppath()
{
    int i;
    for(i=0;path[i]!=100;i++)
    {
        printf("%4d",path[i]);
    }
    printf("\n");
}

void dfs(int a,int b)
{
    int i;

    if(b!=dest)
    {
        for(i=1;i<25;i++)
        {
            if(con[b][i]&&lock_list[i]==0)
            {
                lock_list[i]=1;
                path[a]=i;
                dfs(a+1,i);

                lock_list[i]=0;
            }
        }
    }
    else
    {
        path[a]=100;
        total++;
        ppath();
    }
}


int main()
{
    int i,j,cs=1;

    while(scanf("%d",&dest)==1)
    {
        init();

        while(scanf("%d%d",&i,&j)==2&&i!=0&&j!=0)
        {
            con[i][j]=con[j][i]=1;
        }
        printf("CASE %d:\n",cs);
        lock_list[1]=1;
        path[0]=1;
        dfs(1,1);
        printf("There are %d routes from the firestation to streetcorner %d.\n",total,dest);
        cs++;
    }

    return 0;
}
