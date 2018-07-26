#include<stdio.h>

int main()
{
    int flag=0;
    char ch;

    while(scanf("%c",&ch)==1)
    {
        if(ch=='"')
        {
            if(flag)
            {
                printf("''");
                flag=0;
            }
            else
            {
                printf("``");
                flag=1;
            }
        }
        else
        {
            printf("%c",ch);
        }
    }

    return 0;
}
