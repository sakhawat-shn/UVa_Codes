#include<stdio.h>

int ary[30][2];
int n;

void clr(int a)
{
    int x;
    if(a<n)
    {
        x=ary[a][1];
        ary[a][0]=(100+a)*(-1);
        ary[a][1]=999999;
        clr(x);

    }
}

int main()
{
    int i,x,y,flag;
    int a,b;
    char ac[5],bc[5];


    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        ary[i][0]=(100+i)*(-1);
        ary[i][1]=999999;
    }
    while(1)
    {
        scanf("%s",ac);
        if(ac[0]=='q')
        {
            break;
        }
        scanf("%d %s %d",&a,bc,&b);
        i=a;
        while(1)
        {
            i=ary[i][1];
            if(i==b)
            {
                a=b;
                break;
            }
            if(i>100)
            {
                break;
            }
        }

        i=b;
        while(1)
        {
            i=ary[i][1];
            if(i==a)
            {
                a=b;
                break;
            }
            if(i>100)
            {
                break;
            }
        }


        if(a==b||a>=n||b>=n||a<0||b<0)
        {
            continue;
        }
        if(ac[0]=='m')
        {
            if(bc[1]=='n')
            {
                clr(ary[a][1]);
                clr(ary[b][1]);
                ary[a][1]=999999;
                ary[b][1]=999999;

                x=ary[a][0];
                y=ary[a][1];
                if(x>=0)
                {
                ary[x][1]=y;
                }
                if(y<n)
                {
                ary[y][0]=x;
                }
                ary[a][1]=ary[b][1];
                x=ary[b][1];
                if(x<n){
                ary[x][0]=a;
                }
                ary[a][0]=b;
                ary[b][1]=a;
            }
            if(bc[1]=='v')
            {
                clr(ary[a][1]);
                ary[a][1]=999999;


                x=ary[a][0];
                y=ary[a][1];
                if(x>=0)
                {
                ary[x][1]=y;
                }
                if(y<n)
                {
                ary[y][0]=x;
                }
                x=b;
                x=ary[x][1];
                while(x<100)
                {
                    b=x;
                    x=ary[x][1];
                }
                ary[b][1]=a;
                ary[a][0]=b;
                ary[a][1]=999999;
            }
        }
        if(ac[0]=='p')
        {
            if(bc[1]=='n')
            {
                clr(ary[b][1]);
                ary[b][1]=999999;

                i=a;
                x=i;
                y=a;
                y=ary[y][1];
                while(y<n)
                {
                    a=y;
                    y=ary[y][1];
                }
                ary[a][1]=ary[b][1];
                x=ary[b][1];
                if(x<n)
                {
                    ary[x][0]=a;
                }
                ary[b][1]=i;
                x=ary[i][0];
                if(x>=0)
                {
                    ary[x][1]=999999;
                }
                ary[i][0]=b;
            }
            if(bc[1]=='v')
            {
                x=a;

                x=b;
                x=ary[x][1];
                while(x<n)
                {
                    b=x;
                    x=ary[x][1];
                }
                x=ary[a][0];
                if(x>=0)
                {
                    ary[x][1]=999999;
                }
                ary[a][0]=b;
                ary[b][1]=a;

            }

        }

    }
    for(i=0;i<n;i++)
    {
        printf("%d:",i);
        flag=0;
        for(x=0;x<n;x++)
        {
            y=ary[x][0];
            if(y<0)
            {
                y=y*(-1);
                y=y%100;
                if(y==i)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
        {
            while(1)
            {
                printf(" %d",x);
                x=ary[x][1];
                if(x>=n)
                {
                    break;
                }
            }
        }
        printf("\n");
    }



    return 0;
}
