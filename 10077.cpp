#include<stdio.h>

struct vg
{
    int up,down;
};

vg point;

void fun(vg small,vg mid,vg big)
{
    double x,y;
    vg temp;
    if((mid.up-point.up)==0&&(mid.down-point.down)==0)
    {
        return;
    }

    x=(double)(point.down/(double)mid.down);
    x=x*mid.up;
    y=(double)point.up;

    if(x>y)
    {
        printf("L");
        temp.up=mid.up+small.up;
        temp.down=mid.down+small.down;
        fun(small,temp,mid);
    }
    else
    {
        printf("R");
        temp.up=mid.up+big.up;
        temp.down=mid.down+big.down;
        fun(mid,temp,big);
    }

}

int main()
{
    vg zero,inf,st1;
    zero.up=0;
    zero.down=1;
    inf.down=0;
    inf.up=1;
    st1.down=1;
    st1.up=1;

    while(scanf("%d%d",&point.up,&point.down)==2)
    {
        if(point.up==1&&point.down==1)
        {
            break;
        }

        fun(zero,st1,inf);
        printf("\n");
    }

    return 0;
}
