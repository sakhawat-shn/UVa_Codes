#include<stdio.h>
#include<float.h>
#include<math.h>

struct point
{
    int x,y;
};

point com[10];

int templist[10],minlist[10],minlist_last,n;
double minlen,templen;

void clear()
{
    for(int i=0;i<10;i++)
    {
        templist[i]=minlist[i]=0;
    }
    minlist_last=0;
    minlen=1999999999;//DBL_MAX;
    templen=0;
}

double pointdis(point a,point b)
{
    double dis,p,q;
    p=(a.x-b.x)*1.0;
    q=(a.y-b.y)*1.0;
    dis=sqrt(p*p+q*q);
    return dis;
}


void setmin(int a)
{
    int i;
    if(templen<minlen)
    {
        for(i=1;i<=n;i++)
        {
            minlist[i]=templist[i];
        }
        minlen=templen;
        minlist_last=a;
    }
}


void dfs(int from)
{
    int i,flag=1;
    double nextdis;
    for(i=1;i<=n;i++)
    {
        if(templist[i]==0)
        {
            flag=0;
            nextdis=pointdis(com[from],com[i]);
            templen=templen+nextdis;
            templist[i]=from;
            dfs(i);
            templist[i]=0;
            templen=templen-nextdis;
        }
    }

    if(flag)
    {
        setmin(from);
    }
}

int main()
{
    int i,now,tcase=0;
    double totcable,x;

    while(scanf("%d",&n)==1&&n!=0)
    {
        clear();
        //printf("%lf",minlen);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&com[i].x,&com[i].y);
        }

        for(i=1;i<=n;i++)
        {
            templen=0;
            templist[i]=-1;
            dfs(i);
            templist[i]=0;
        }

        now=minlist_last;
        totcable=0;

        printf("**********************************************************\n");
        printf("Network #%d\n",++tcase);

        for(i=1;i<n;i++)
        {
            if(minlist[now]==-1)
            {
                break;
            }
            printf("Cable requirement to connect (");
            printf("%d,%d",com[now].x,com[now].y);
            printf(") to (");
            printf("%d,%d",com[minlist[now]].x,com[minlist[now]].y);
            x=pointdis(com[now],com[minlist[now]])+16.0;
            printf(") is %.2lf feet.\n",x);
            totcable=totcable+x;
            now=minlist[now];
        }

        printf("Number of feet of cable required is %.2lf.\n",totcable);



    }

    return 0;
}
