#include<stdio.h>

int main()
{
    char ch;

    while(scanf("%c",&ch)==1)
    {
        if(ch=='\n')
        {
            printf("\n");
        }
        else
        {
            ch=ch-7;
            printf("%c",ch);
        }
    }

    return 0;
}
