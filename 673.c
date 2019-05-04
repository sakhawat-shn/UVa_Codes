#include<stdio.h>

int isEr,isSp;

int br1()
{
    char ch;
    while(isSp==0)
    {
        scanf("%c",&ch);
        if(ch=='\n'){isSp=1;}
        if(ch=='('){br1();}
        if(ch=='['){br3();}
        if(ch==')'){return 0;}
        if(ch==']'||ch=='\n')
        {
            isEr=1;
            return 0;
        }

    }
}

int br3()
{
    char ch;
    while(isSp==0)
    {
        scanf("%c",&ch);
        if(ch=='\n'){isSp=1;}
        if(ch=='('){br1();}
        if(ch=='['){br3();}
        if(ch==']'){return 0;}
        if(ch==')'||ch=='\n')
        {
            isEr=1;
            return 0;
        }

    }
}


int init()
{
    char ch;
    while(isSp==0)
    {
        scanf("%c",&ch);
        if(ch=='\n'){isSp=1;}
        if(ch=='('){br1();}
        if(ch=='['){br3();}
        if(ch==')'||ch==']'){isEr=1;}
    }

}



int main()
{
    int n,i;
    char ch;
    scanf("%d",&n);
    scanf("%c",&ch);

    for(i=1;i<=n;i++)
    {
        isEr=0;
        isSp=0;
        init();


        if(isEr)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }

    }




    return 0;
}
