#include<stdio.h>

int prime[30]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};

int main()
{
    int n,i,a,j,k;

    while(scanf("%d",&n)==1&&n!=0)
    {
        int num[30]= {0};
        for(i=0; prime[i]<=n; i++)
        {
            a=prime[i];
            for(j=1; a<=n; j++)
            {
                num[i]=num[i]+(n/a);
                a=a*prime[i];

            }
        }


        printf("%3d! =",n);
        for(k=0;k<i;k++)
        {
            if(k==15)
            {
                printf("\n      ");
            }
            printf("%3d",num[k]);
        }

        printf("\n");




    }


    return 0;
}
