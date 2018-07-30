#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;

string ok="12345678x";

int can_go[9][4]={
    {0,1,1,0},
    {0,1,1,1},
    {0,0,1,1},
    {1,1,1,0},
    {1,1,1,1},
    {1,0,1,1},
    {1,1,0,0},
    {1,1,0,1},
    {1,0,0,1}
    };

struct dat
{
    int pos_x;
    string data;
    string how;

};


dat build_new(dat a,int i)
{
    char temp;
    int p,q;
    switch(i)
    {
        case 0:
            p=a.pos_x;
            q=p-3;

            temp=a.data[p];
            a.data[p]=a.data[q];
            a.data[q]=temp;

            a.pos_x=q;
            a.how=a.how+'d';

            return a;

            break;
        case 1:
            p=a.pos_x;
            q=p+1;

            temp=a.data[p];
            a.data[p]=a.data[q];
            a.data[q]=temp;

            a.pos_x=q;
            a.how=a.how+'l';

            return a;

            break;
        case 2:
            p=a.pos_x;
            q=p+3;

            temp=a.data[p];
            a.data[p]=a.data[q];
            a.data[q]=temp;

            a.pos_x=q;
            a.how=a.how+'u';

            return a;

            break;
        case 3:
            p=a.pos_x;
            q=p-1;

            temp=a.data[p];
            a.data[p]=a.data[q];
            a.data[q]=temp;

            a.pos_x=q;
            a.how=a.how+'r';

            return a;

            break;
    }

}


int main()
{
    int n,i,j,flag=0;
    char ch,c;
    string ppq,qqp;

    dat st;
    st.data=ok;
    st.pos_x=8;
    st.how="";

    queue<dat> q;
    map<string,string> m;

    q.push(st);
    m[st.data]=st.how;

    dat now,neu;

    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            if(can_go[now.pos_x][i])
            {
                neu=build_new(now,i);

                if(!m.count(neu.data))
                {
                    q.push(neu);
                    m[neu.data]=neu.how;
                }
            }
        }
    }




    scanf("%d",&n);

    while(n--)
    {
        if(flag)
        {
            printf("\n");

        }
        flag=1;
        ppq="";

        for(i=0;i<9;i++)
        {
            cin>>qqp;

            ppq=ppq+qqp;
        }


        if(m.count(ppq))
        {
            ppq=m[ppq];
            j=ppq.length();
            for(i=j-1;i>=0;i--)
            {
                printf("%c",ppq[i]);
            }
            printf("\n");

        }
        else
        {
            printf("unsolvable\n");
        }


    }

    return 0;
}
