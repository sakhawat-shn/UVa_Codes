#include<stdio.h>

int main()
{
    int n,f,i,j;
    long long int total,jm,na,ef,temp;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        total=0;
        scanf("%d",&f);
        for(j=1;j<=f;j++)
        {
            scanf("%lld%lld%lld",&jm,&na,&ef);
            temp=jm*ef;
            total=total+temp;
        }
        printf("%lld\n",total);
    }



    return 0;
}
