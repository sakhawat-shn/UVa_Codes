#include<bits/stdc++.h>
using namespace std;

bool dp[100000];
int coin[200];

void init()
{
    for(int i=0;i<100000;i++)
    {
        dp[i]=0;
    }
    for(int i=0;i<200;i++)
    {
        coin[i]=0;
    }
}

void calculator(int n,int k)
{
    dp[0]=1;
    for(int j=0;j<k;j++)
    {
        for(int i=n;i>=1;i--)
        {
            if(i>=coin[j]&&dp[i-coin[j]])
            {
                dp[i]=1;
            }
        }
    }
}

int finder(int k)
{
    int sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=coin[i];
    }
    calculator(sum+100,k);

    int mn=sum;
    for(int i=(sum/2)+1;i>=0;i--)
    {
        if(dp[i])
            mn=min(mn,abs(sum-(i*2)));
    }
    return mn;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        init();
        for(int j=0;j<t;j++)
        {
            scanf("%d",&coin[j]);
        }
        printf("%d\n",finder(t));
    }
    return 0;
}
