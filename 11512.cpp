#include<bits/stdc++.h>
using namespace std;

//-----Typedef-----
typedef long long int LLD;
typedef pair<int, int> pi;
typedef pair<LLD, LLD> pll;
typedef vector<int> vi;
typedef vector<LLD> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<string> vstr;



//------fast I/O----
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

//-----constants----
#define ERR 1e-9
#define PI (acos(-1))
#define MAX 300005
const int INF = 0x3f3f3f3f;
const int MOD = (int)1e9+7;

//---mem set-----
#define memo(a,b) memset((a),(b),sizeof(a))
#define CLR(x) memset(x,0,sizeof(x))

//----function shortcut----
#define pb push_back
#define mkp make_pair
#define Sort(v) sort(v.begin(),v.end())
#define RSort(v) sort(v.rbegin(),v.rend())
#define CSort(v,C) sort(v.begin(),v.end(),C)
#define all(v) (v).begin(),(v).end()
#define sqr(x) ((x)*(x))
#define find_dist(a,b) sqrt(sqr(a.x-b.x)+sqr(a.y-b.y))
#define sz(a) int(a.size())
#define F first
#define S second
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
bool isConsonant(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}

//-----Template-----
template <class T> T gcd(T a, T b) {if(a < b) swap(a, b); while(b) {T t = b; b = a % b; a = t;} return a;}
template <class T> T big_mod(T n,T p,T m){if(p==0)return (T)1;T x=big_mod(n,p/2,m);x=(x*x)%m;if(p&1)x=(x*n)%m;return x;}
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <class T> void print_vector(T &v){int sz=v.size();if(sz)cout<<v[0];for(int i = 1; i < sz; i++)cout << ' '<<v[i];cout<<"\n";}



//----direction-----
//int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1}; ///8 Direction
//int dx[4] = {0, 1, 0, -1};int dy[4] = {1, 0, -1, 0}; ///4 Direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};///Knight Direction
//int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; ///Hexagonal Direction

//-----I/O------
char tcstr[300];
void scan(int &a){scanf("%d",&a);}
void scan(LLD &a){scanf("%lld",&a);}
void scan(char &a){scanf("%c",&a);}
void scan(double &a){scanf("%lf",&a);}
void scan(string &a){scanf("%s",tcstr);a=tcstr;}
void scanln(string &a){scanf("%[^\n]",tcstr);a=tcstr;}
#define newline '\n'
void print(int a){printf("%d",a);}
void print(LLD a){printf("%lld",a);}
void print(char a){printf("%c",a);}
void print(double a){printf("%lf",a);}
void print(string a){printf("%s",a.c_str());}
//-----I/O-------

int mapper[100];
char *kar="ACGT";

struct node
{
    bool endmark;
    int val;
    node* nxt[4];
    node()
    {
        endmark=false;
        val=0;
        for(int i=0;i<4;i++)
        {
            nxt[i]=NULL;
        }
    }
} *root;

void insrt(char *str,int len)
{
    node *curr=root;
    for(int i=0;i<len;i++)
    {
        int id=mapper[str[i]];
        if(curr->nxt[id]==NULL)
            curr->nxt[id]=new node();
        curr=curr->nxt[id];
        (curr->val)++;
    }
    curr->endmark=1;
}

void del(node *cur)
{
    for(int i=0;i<4;i++)
        if(cur->nxt[i])
            del(cur->nxt[i]);
    delete(cur);
}

int maxlen,times;
char ans[10000],maker[10000];

void dfs(node *cur,int pos)
{
    int stlen=strlen(maker);
    if(stlen>maxlen&&((cur->val)>1))
    {
        strcpy(ans,maker);
        maxlen=stlen;
        times=(cur->val);
    }
    for(int i=0;i<4;i++)
    {
        if(cur->nxt[i])
        {
            maker[pos]=kar[i];maker[pos+1]=0;
            dfs(cur->nxt[i],pos+1);
        }
    }

}

int main()
{
    mapper['A']=0;
    mapper['C']=1;
    mapper['G']=2;
    mapper['T']=3;
    int t;
    scan(t);
    for(int i=0;i<t;i++)
    {
        char st[1099];
        scanf("%s",st);
        int len=strlen(st);
        root=new node();
        for(int j=0;j<len;j++)
        {
            insrt(&st[j],strlen(&st[j]));
        }
        maxlen=0;times=0;maker[0]=0;
        dfs(root,0);
        if(times!=0){printf("%s %d\n",ans,times);}
        else{printf("No repetitions found!\n");}
        del(root);
    }


    return 0;
}
