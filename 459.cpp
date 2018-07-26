#include<stdio.h>


int node[30];

int makenum(char ch)
{
    return (ch-'A');
}

void clear()
{
    int i;
    for(i=0;i<30;i++)
    {
        node[i]=-1;
    }
}

int find(int x)
{
    if(node[x]==-1)
    {
        return x;
    }
    return node[x]=find(node[x]);
}

void unio(int a,int b)
{
    node[find(b)]=find(a);
}

void passchar()
{
    char ch;
    scanf("%c",&ch);
}


int main()
{
    int n,i,num_node,count,flag=0;;
    char a,b;

    scanf("%d",&n);
    passchar();
    passchar();

    while(n--)
    {
        clear();
        if(flag)
        {
            printf("\n");
        }
        flag=1;

        scanf("%c",&a);
        passchar();
        num_node=makenum(a);
        while(scanf("%c",&a)==1&&a!='\n')
        {
            scanf("%c",&b);
            passchar();
            if(find(makenum(a))!=find(makenum(b)))
            {
                unio(makenum(a),makenum(b));
            }

        }
        count=0;
        for(i=0;i<=num_node;i++)
        {
            if(node[i]==-1)
            {
                count++;
            }
        }
        printf("%d\n",count);
    }

    return 0;
}
