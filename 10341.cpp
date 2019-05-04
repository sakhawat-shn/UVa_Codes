#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int p,q,r,s,t,u;

double fy(double x)
{
    return p*exp((-1)*x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

double chk(double sm,double big)
{
    double mid=(sm+big)/2.0;
    if(fy(mid)==0||fabs(fy(big)-fy(sm))<0.0000001)
    {
        return mid;
    }
    if((fy(mid)*fy(sm))<0)
    {
        return chk(sm,mid);
    }
    else
    {
        return chk(mid,big);

    }
}


int main()
{
    int flag,i;
    double j,x,k;
    while(scanf("%d%d%d %d%d%d",&p,&q,&r,&s,&t,&u)==6)
    {
        flag=0;
        k=0;

        for(i=0;i<=10;i++)
        {
            j=(double)(i/10.0);
            if(fy(j)==0)
            {
                flag=1;
                x=j;
                break;
            }
            else if((fy(j)*fy(k))<0)
            {
                flag=1;
                x=chk(k,j);
                break;
            }
            k=j;

        }

        if(flag)
        {
            printf("%.4lf\n",x);
        }
        else
        {
            printf("No solution\n");
        }

    }

    return 0;
}
