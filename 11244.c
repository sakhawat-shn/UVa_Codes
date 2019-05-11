#include<stdio.h>

int count;
char x[105][105];

int chk(int a,int b)
{
    if(x[a][b]=='*')
    {
        if(x[a-1][b-1]=='*'||x[a-1][b]=='*'||x[a-1][b+1]=='*'||x[a][b-1]=='*'||x[a][b+1]=='*'||x[a+1][b-1]=='*'||x[a+1][b]=='*'||x[a+1][b+1]=='*')
        {
            return 0;

        }
        else
        {
            return 1;
        }


    }
    else
    {
        return 0;
    }



}

int main()
{
    int r,c,i,j;
    char p;
    while(scanf("%d%d",&r,&c)==2&&r!=0&&c!=0)
    {
        count=0;
        scanf("%c",&p);
        for(i=0;i<=r+1;i++)
        {
            for(j=0;j<=c+1;j++)
            {
                if(i==0||j==0||i==r+1)
                {
                    x[i][j]=0;
                }
                else
                {
                    scanf("%c",&x[i][j]);
                }
            }
        }
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                count=count+chk(i,j);
            }
        }
        printf("%d\n",count);


    }





    return 0;
}
