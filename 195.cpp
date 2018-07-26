#include<stdio.h>

int ch[60];
char str[1000];

void init()
{
    int i;
    for(i=0;i<60;i++)
    {
        ch[i]=0;
    }
}

void ldch(char c)
{
    if(c>='A'&&c<='Z')
    {
        ch[(c-'A')*2]++;
    }
    else if(c>='a'&&c<='z')
    {
        ch[((c-'a')*2)+1]++;
    }
}

void dfs(int x)
{
    int i,flag=1;
    for(i=0;i<=51;i++)
    {
        if(ch[i])
        {
            flag=0;
            if(i%2)
            {
                str[x]=('a'+((i-1)/2));
            }
            else
            {
                str[x]=('A'+(i/2));
            }
            ch[i]--;
            dfs(x+1);
            ch[i]++;
        }
    }
    if(flag)
    {
        str[x]='\0';
        printf("%s\n",str);
    }
}

int main()
{
    int t;
    char c;
    scanf("%d",&t);
    scanf("%c",&c);

    init();

    while(scanf("%c",&c)==1)
    {
        if(c!='\n')
        {
            ldch(c);
        }
        else
        {
            dfs(0);
            init();
        }
    }

    return 0;
}
