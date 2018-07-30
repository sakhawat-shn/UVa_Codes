#include<stdio.h>

int test(char t)
{
    if(t>='a'&&t<='z') {return 1;}
    else if(t>='A'&&t<='Z'){return 1;}
    else {return 0;}
}


int main()
{
    int count=0;
    char i=' ',j;
    while(scanf("%c",&j)==1)
    {
        if(test(j)==0&&test(i)==1){count++;}
        if(j=='\n')
        {
            printf("%d\n",count);
            count=0;
        }
        i=j;
    }
    return 0;
}
