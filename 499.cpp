#include<stdio.h>

int small[30],big[30],top;

void clear()
{
    int i;
    for(i=0;i<30;i++)
    {
        small[i]=big[i]=0;
    }
    top=0;
}

void add(char ch)
{
    if(ch>='a'&&ch<='z')
    {
        small[ch-'a']++;
        if(small[ch-'a']>top)
        {
            top=small[ch-'a'];
        }
    }
    else if(ch>='A'&&ch<='Z')
    {
        big[ch-'A']++;
        if(big[ch-'A']>top)
        {
            top=big[ch-'A'];
        }
    }
}

void print()
{
    int i;
    for(i=0;i<26;i++)
    {
        if(big[i]==top)
        {
            printf("%c",i+'A');
        }
    }
    for(i=0;i<26;i++)
    {
        if(small[i]==top)
        {
            printf("%c",i+'a');
        }
    }
}

int main()
{
    char ch;
    clear();

    while(scanf("%c",&ch)==1)
    {
        if(ch=='\n')
        {
            if(top!=0)
            {
                print();
                printf(" %d\n",top);
                clear();
            }
        }
        else
        {
            add(ch);
        }
    }


    return 0;
}
