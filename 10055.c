#include<stdio.h>

int main()
{
    double a,b,c;

   while(scanf("%lf%lf",&a,&b)==2)
   {
       if(a>b)
       {
           c=a-b;
       }
       else
       {
           c=b-a;
       }
       printf("%.0lf\n",c);
   }

    return 0;

}

