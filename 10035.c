#include<stdio.h>

int main()
{
    int a,b,carry,count,c,d,e,i;

    while(scanf("%d%d",&a,&b)==2)
    {
        if(a==0&&b==0)
        {
            break;
        }


        carry=0;
        count=0;
        for(i=1;i<=10;i++)
        {
            c=a%10;
            d=b%10;
            e=c+d+carry;
            if(e>=10)
            {
                count++;
                carry=e/10;
            }
            else
            {
                carry=0;
            }
            a=a/10;
            b=b/10;


        }

        if(count==1)
        {
            printf("%d carry operation.\n",count);
        }
        else if(count>1)
        {
            printf("%d carry operations.\n",count);
        }
        else
        {
            printf("No carry operation.\n");
        }


    }


    return 0;
}
