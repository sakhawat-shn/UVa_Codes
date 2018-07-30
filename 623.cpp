#include<stdio.h>

int num[100000000];

int main()
{
    int n,size,temp,i,j,inst;

    while(scanf("%d",&n)==1)
    {
        num[1]=1;
        size=1;
        temp=0;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=size;j++)
            {
                inst=num[j]*i+temp;
                num[j]=inst%10;
                temp=inst/10;
            }

            while(temp>0)
            {
                size++;
                num[size]=temp%10;
                temp=temp/10;
            }
        }

        printf("%d!\n",n);
        for(i=size;i>=1;i--)
        {
            printf("%d",num[i]);
        }
        printf("\n");
    }


    return 0;
}
