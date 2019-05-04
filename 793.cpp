#include<stdio.h>

int ary[100000000];
int total_qry,succe;

void init(int a)
{
    for(int i=0;i<=a;i++)
    {
        ary[i]=i;
    }
    total_qry=0;
    succe=0;
}

int findx(int x)
{
    if(ary[x]==x)
    {
        return x;
    }
    return ary[x]=findx(ary[x]);
}

void uni(int a,int b)
{
    ary[findx(b)]=findx(a);
}

void pass_char()
{
    char ch;
    scanf("%c",&ch);
}

int main()
{
    int n,num_node,a,b,flag=0;
    char ch;
    scanf("%d",&n);

    while(n--)
    {
        if(flag)
        {
            printf("\n");
        }
        flag=1;
        scanf("%d",&num_node);
        num_node++;
        pass_char();
        init(num_node);

        while(scanf("%c",&ch)==1&&ch!='\n')
        {
            scanf("%d%d",&a,&b);
            pass_char();
            if(ch=='c')
            {
                uni(a,b);
            }
            else
            {
                total_qry++;
                if(findx(a)==findx(b))
                {
                    succe++;
                }
            }
        }

        printf("%d,%d\n",succe,(total_qry-succe));

    }

    return 0;
}
