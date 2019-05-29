#include<bits/stdc++.h>
using namespace std;

vector<int> org,stu;
int dp[30][30],visited[30][30];

int calcLCS(int i,int j)
{
    if(i==org.size()||j==stu.size()) return 0;
    if(visited[i][j]) return dp[i][j];
    int ans=0;
    if(org[i]==stu[j]) ans=1+calcLCS(i+1,j+1);
    else
    {
        int val1=calcLCS(i+1,j);
        int val2=calcLCS(i,j+1);
        ans=max(val1,val2);
    }
    visited[i][j]=1;
    dp[i][j]=ans;
    return ans;
}


vector<int> realoc_vec(vector<int> a)
{
    int n=a.size();
    vector<int> b(n);

    for(int i=0;i<n;i++)
    {
        b[a[i]-1]=i;
    }

    return b;
}

void init()
{
    stu.clear();
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<30;j++)
        {
            dp[i][j]=visited[i][j]=0;
        }
    }
}

int main()
{
    int n,cnt=0,flag=0,x;
    char ch=0;
    scanf("%d",&n);
    while(scanf("%d",&x)==1)
    {
        org.clear();
        org.push_back(x);
        for(int i=1;i<n;i++)
        {
            scanf("%d",&x);
            org.push_back(x);
        }
        org=realoc_vec(org);

        init();
        cnt=0;
        while(scanf("%d",&x)==1)
        {
            cnt++;
            scanf("%c",&ch);
            if(cnt==n)
            {
                stu.push_back(x);
                stu=realoc_vec(stu);
                printf("%d\n",calcLCS(0,0));
                cnt=0;init();
            }
            else if(ch=='\n')
            {
                n=x;
                break;
            }
            else
            {
                stu.push_back(x);
            }
        }

    }

    return 0;
}
