#include<stdio.h>
int ary[100010];


int main()
{
    int stp,mod,i,st;

    while(scanf("%d%d",&stp,&mod)==2)
    {
        for(i=0; i<=mod; i++)
        {
            ary[i]=0;
        }
        st=0;
        ary[0]=1;
        for(i=1;i<mod;i++)
        {
            st=st+stp;
            st=st%mod;
            if(ary[st]==0)
            {
                ary[st]=1;
            }
            else
            {
                break;
            }

        }
        printf("%10d%10d    ",stp,mod);
        if(i==mod)
        {
            printf("Good Choice");
        }
        else
        {
            printf("Bad Choice");
        }
        printf("\n\n");
    }


    return 0;
}
