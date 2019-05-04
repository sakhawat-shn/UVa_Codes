#include<stdio.h>
#include<math.h>

double p,q,c;

double fun(double x)
{
    double px,qx,rt;
    px=sqrt((p*p)-(x*x));
    qx=sqrt((q*q)-(x*x));
    rt=(px*qx)/(px+qx);

    return rt;
}

double binsh(double st,double end)
{
    double mid=(st+end)/2.0;
    if(fabs(fun(mid)-c)<0.000001)
    {
        return mid;
    }

    if(fun(mid)-c<0.0)
    {
        return binsh(st,mid);
    }
    else if(fun(mid)-c>0.0)
    {
        return binsh(mid,end);
    }
}


int main()
{
    double ans,i;

    while(scanf("%lf%lf%lf",&p,&q,&c)==3)
    {
        i=(p<=q)?p:q;
        ans=binsh(0,i);

        printf("%.3lf\n",ans);
    }


    return 0;
}
