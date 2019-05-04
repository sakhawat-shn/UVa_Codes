#include<cstdio>

int ar[105][105];

int main()
{
    int n,m,i,j,k=0;
    char ch;

    while(scanf("%d%d",&n,&m)==2&&n!=0&&m!=0)
    {
        if(k!=0){printf("\n");}
        k++;
        scanf("%c",&ch);
        for(i=0;i<=n+1;i++)
        {
            for(j=0;j<=m+1;j++)
            {
                if(i==0||j==0||i==n+1)
                {
                    ar[i][j]=0;
                }
                else
                {
                    scanf("%c",&ch);
                    if(ch=='*')
                    {
                        ar[i][j]='*';
                    }
                    else
                    {
                        ar[i][j]=0;
                    }
                }
            }
        }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(ar[i][j]=='*')
                {
                if(ar[i-1][j-1]!='*'){ar[i-1][j-1]++;}
                if(ar[i-1][j]!='*'){ar[i-1][j]++;}
                if(ar[i-1][j+1]!='*'){ar[i-1][j+1]++;}
                if(ar[i][j-1]!='*'){ar[i][j-1]++;}
                if(ar[i][j+1]!='*'){ar[i][j+1]++;}
                if(ar[i+1][j-1]!='*'){ar[i+1][j-1]++;}
                if(ar[i+1][j]!='*'){ar[i+1][j]++;}
                if(ar[i+1][j+1]!='*'){ar[i+1][j+1]++;}
                }
            }
        }

        printf("Field #%d:\n",k);

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(ar[i][j]=='*')
                {
                    printf("%c",ar[i][j]);
                }
                else
                {
                    printf("%d",ar[i][j]);
                }
            }
            printf("\n");
        }


    }

    return 0;
}
