#include<stdio.h>
#include<math.h>

int main()
{
    int n,i;
    double d,l,a,b,pi,ans;
    pi=2*acos(0);
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%lf%lf",&d,&l);
        a=l/2;
        d=d/2;
        b=sqrt(a*a-d*d);
        ans=pi*a*b;
        printf("%.3lf\n",ans);
    }

    return 0;
}
