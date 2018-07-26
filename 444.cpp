#include<stdio.h>

void prnt(int a)
{

    while(a)
    {
        printf("%d",a%10);
        a=a/10;
    }

}

void prosc()
{
    char ch;
    scanf("%c",&ch);
    if(ch=='\n')
    {
        return;
    }
    prosc();
    prnt(ch);
}

void prosn()
{
    char ch;
    int a;
    scanf("%c",&ch);
    if(ch=='\n')
    {
        return;
    }
    a=ch-'0';
    scanf("%c",&ch);
    a=a+(ch-'0')*10;
    if(a<=22)
    {
        scanf("%c",&ch);
        a=a+(ch-'0')*100;
    }
    prosn();
    printf("%c",a);

}

int main()
{
    int a;
    char ch;
    while(scanf("%c",&ch)==1)
    {
        if(ch=='\n')
        {
            printf("\n");
            continue;
        }
        if(ch>='0'&&ch<='9')
        {
            a=ch-'0';
            scanf("%c",&ch);
            a=a+(ch-'0')*10;
            if(a<=22)
            {
                scanf("%c",&ch);
                a=a+(ch-'0')*100;
            }
            prosn();
            printf("%c\n",a);
        }
        else
        {
            prosc();
            prnt(ch);
            printf("\n");
        }
    }


    return 0;
}
