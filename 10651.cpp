#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int mint;

int numO(string a)
{
    int b=0;
    for(int i=0;i<12;i++)
    {
        if(a[i]=='o')
        {
            b++;
        }
    }

    return b;
}

string chng(string s,int a,int b,int c)
{
    char temp;
    temp=s[a];
    s[a]=s[c];
    s[c]=temp;
    s[b]='-';
    return s;
}

void dfs(string st)
{
    int flag=1;
    for(int i=0;i<10;i++)
    {
        if(st[i]=='-'&&st[i+1]=='o'&&st[i+2]=='o')
        {
            flag=0;
            dfs(chng(st,i,i+1,i+2));
        }

        if(st[i]=='o'&&st[i+1]=='o'&&st[i+2]=='-')
        {
            flag=0;
            dfs(chng(st,i,i+1,i+2));
        }
    }

    if(flag)
    {
        int ct=numO(st);
        if(ct<mint)
        {
            mint=ct;
        }
    }

}


int main()
{
    int n;
    string st;

    scanf("%d",&n);

    while(n--)
    {
        cin>>st;
        mint=numO(st);
        dfs(st);
        cout<<mint<<endl;
    }

    return 0;
}
