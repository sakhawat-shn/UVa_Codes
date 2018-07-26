#include<iostream>
#include<vector>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;

vector<string> big;

int main()
{
    int max,i,count,k,e,x,j,cse=0;
    string str,st,tst;
    map<string,int> word;
    vector<string> strl;
    char z,bigst[100];


    while(scanf("%d%d",&k,&e)==2)
    {
        big.clear();
        word.clear();
        max=0;
        getchar();
        for(i=1; i<=k; i++)
        {
            gets(bigst);
            word[bigst]=1;
        }

        for(i=1; i<=e; i++)
        {
            count=0;
            gets(bigst);
            st="";
            x=strlen(bigst);

            for(j=0; j<x; j++)
            {
                if(bigst[j]>='a'&&bigst[j]<='z')
                {
                    st=st+bigst[j];
                }
                else if(bigst[j]>='A'&&bigst[j]<='Z')
                {
                    z=bigst[j]+32;
                    st=st+z;

                }
                else
                {
                    count=count+word[st];
                    st="";
                }

            }
            count=count+word[st];
            if(count>max)
            {
                big.clear();
                big.push_back(bigst);
                max=count;
            }
            else if(count==max)
            {
                big.push_back(bigst);
            }


        }
        printf("Excuse Set #%d\n",++cse);
        x=big.size();
        for(i=0;i<x;i++)
        {
            cout<<big[i]<<endl;
        }
        printf("\n");

    }



    return 0;
}
