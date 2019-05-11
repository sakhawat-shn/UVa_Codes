#include<stdio.h>
#include<string.h>

int chkchar(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    {
        return 0;
    }
    else
    {
        return ch;
    }
}

int main()
{
    int n,i,length,j;
    char str1[30],str2[30],c;
    scanf("%d",&n);
    scanf("%d",&c);

    for(i=1;i<=n;i++)
    {
        scanf("%s %s",str1,str2);
        length=strlen(str1);
        if(length==strlen(str2))
        {
            for(j=0;j<length;j++)
            {
                if(chkchar(str1[j])-chkchar(str2[j]))
                {
                    break;
                }
            }

            if(j==length)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }

        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}
