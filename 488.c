#include<stdio.h>

int main()
{
    int t,am,f,i,j,k,z,flag=0;

    scanf("%d",&t);
    for(z=1; z<=t; z++)
    {
        scanf("%d%d",&am,&f);
        for(i=1; i<=f; i++)
        {
            if(flag)
            {
                printf("\n");

            }
            flag=1;
            for(j=1; j<=am; j++)
            {
                for(k=1; k<=j; k++)
                {
                    printf("%d",j);
                }
                printf("\n");
            }
            j=j-2;
            for(; j>=1; j--)
            {
                for(k=1; k<=j; k++)
                {
                    printf("%d",j);
                }
                printf("\n");
            }

        }


    }



    return 0;
}
