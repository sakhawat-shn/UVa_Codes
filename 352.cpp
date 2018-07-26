#include<stdio.h>

int ary[30][30];

void mk0(int i,int j)
{
    ary[i][j]=0;
    if(ary[i-1][j]){mk0(i-1,j);}
    if(ary[i-1][j+1]){mk0(i-1,j+1);}
    if(ary[i][j+1]){mk0(i,j+1);}
    if(ary[i+1][j+1]){mk0(i+1,j+1);}
    if(ary[i+1][j]){mk0(i+1,j);}
    if(ary[i+1][j-1]){mk0(i+1,j-1);}
    if(ary[i][j-1]){mk0(i,j-1);}
    if(ary[i-1][j-1]){mk0(i-1,j-1);}

}

int main()
{
    int i,j,k,l,m,n,count,img=1;
    char inp;

    while(scanf("%d",&m)==1)
    {
        scanf("%c",&inp);
        count=0;
        n=m+1;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(i==0||j==0||i==n)
                {
                    ary[i][j]=0;
                }
                else if(j==n)
                {
                    scanf("%c",&inp);
                    ary[i][j]=0;
                }
                else
                {
                    scanf("%c",&inp);
                    if(inp=='1')
                    {
                        ary[i][j]=1;
                    }
                    else
                    {
                        ary[i][j]=0;
                    }
                }

            }
        }

        for(i=1;i<n;i++)
        {
            for(j=1;j<n;j++)
            {
                if(ary[i][j])
                {
                    count++;
                    mk0(i,j);

                }

            }
        }
        printf("Image number %d contains %d war eagles.\n",img,count);
        img++;

    }


    return 0;
}
