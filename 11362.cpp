#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    bool mark;
    node *nxt[26+1];
    node()
    {
        mark=false;
        for(int i=0;i<26;i++)
            nxt[i]=NULL;
    }
} *root;

void insrt(char *str,int len)
{
    node *curr=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'0';
        if(curr->nxt[id]==NULL)
            curr->nxt[id]=new node();
        curr=curr->nxt[id];
    }
    curr->mark=1;
}

int dfs(node *cur)
{
    int flag=0;
    for(int i=0;i<26;i++)
    {
        if(flag)
        {
            return flag;
        }
        if(cur->nxt[i]!=NULL)
        {
            if(cur->mark==1)
            {
                return 1;
            }
            flag=dfs(cur->nxt[i]);
        }
    }
    return flag;
}

void del(node *cur)
{
    for(int i=0;i<26;i++)
        if(cur->nxt[i])
            del(cur->nxt[i]);
    delete(cur);
}


int main()
{
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        root=new node();
        char st[20];
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%s",st);
            insrt(st,strlen(st));
        }
        printf("%s\n",dfs(root)?"NO":"YES");

        del(root);
    }

    return 0;
}
