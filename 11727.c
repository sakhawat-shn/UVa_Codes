#include<stdio.h>

int main()
{
    int i,j,sal[3],k,temp;
    scanf("%d",&j);
    for(i=1;i<=j;i++)
    {
        scanf("%d%d%d",&sal[0],&sal[1],&sal[2]);
        for(k=0;k<3;k++)
        {
            if(sal[0]>sal[1])
            {
                temp=sal[1];
                sal[1]=sal[0];
                sal[0]=temp;
            }
            if(sal[1]>sal[2])
            {
                temp=sal[1];
                sal[1]=sal[2];
                sal[2]=temp;
            }
        }

        printf("Case %d: %d\n",i,sal[1]);



    }



    return 0;
}
