#include<stdio.h>

int main()
{
    int t,g,l,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d%d",&g,&l);
        if(g>0&&l>0&&g<=l&&l%g==0)
        {
            printf("%d %d\n",g,l);
        }
        else
        {
            printf("-1\n");
        }
    }


    return 0;
}
