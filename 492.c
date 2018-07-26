#include<stdio.h>

int chkch(char a)
{
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U')
    {
        return 1;
    }
    else if((a>=65&&a<=90)||(a>=97&&a<=122))
    {
        return 2;
    }
    else
    {
        return 4;
    }


}

int main()
{
    int a,b,isword=0,iscon=0;
    char ch,con;
    while(scanf("%c",&ch)==1)
    {
        if(chkch(ch)!=4)
        {

            if(isword==0)
            {
                if(chkch(ch)==1)
                {
                    printf("%c",ch);

                    iscon=0;
                }
                else
                {
                    con=ch;
                    iscon=1;

                }
            }
            else
            {
                printf("%c",ch);
            }
            isword=1;
        }
        else
        {
            if(isword==1)
            {
                if(iscon==1)
                {
                    printf("%cay",con);
                    iscon=0;
                }
                else
                {
                    printf("ay");
                }
            }
            printf("%c",ch);
            isword=0;
        }

    }


    return 0;
}
