#include<stdio.h>
#include<string.h>

int main()
{
    int a,ln,time,i,j,xx;
    char str[110];

    while(scanf("%d",&a)==1&&a!=0)
    {
        scanf("%s",str);
        ln=strlen(str);
        time=ln/a;

        for(i=1;i<=a;i++)
        {
            xx=(time*i)-time;
            for(j=time*i;j>xx;j--)
            {
                printf("%c",str[j-1]);
            }
        }

        printf("\n");


    }





    return 0;
}
