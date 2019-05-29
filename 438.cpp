#include<bits/stdc++.h>
using namespace std;
#define dbl double

dbl hiseb(dbl x1,dbl y1,dbl x2,dbl y2,dbl x3,dbl y3)
{
    dbl p=x2-x1;
    dbl q=y2-y1;
    dbl m=x3-x1;
    dbl n=y3-y1;
    dbl a=((x1+x2)*p)+((y1+y2)*q);
    dbl b=((x1+x3)*m)+((y1+y3)*n);
    //printf("%.15lf",y1);

    dbl x=((a*n)-(b*q))/(2*((p*n)-(q*m)));
    dbl y=((a*m)-(b*p))/(2*((m*q)-(n*p)));

    dbl X=x-x1;
    dbl Y=y-y1;



    return sqrt((X*X)+(Y*Y));
}

int main()
{
    dbl x1,y1,x2,y2,x3,y3;

    while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3)==6)
    {
        printf("%.2lf\n",2*acos(-1)*hiseb(x1,y1,x2,y2,x3,y3));
    }

    return 0;
}
