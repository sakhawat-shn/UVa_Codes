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

struct data
{
    int v_l,v_r,mx,n_l,n_r,n_mx;
};
data seg[1000000];
int inp[1000000];

void build(int att,int L,int R)
{
    if(L==R)
    {
        seg[att].mx=seg[att].v_l=seg[att].v_r=inp[R];
        seg[att].n_mx=seg[att].n_l=seg[att].n_r=1;
        return ;
    }
    int mid=(L+R)/2;
    build(att*2,L,mid);
    build(att*2+1,mid+1,R);

    data lft=seg[att*2],r8=seg[att*2+1];
    seg[att].v_l=lft.v_l;seg[att].n_l=lft.n_l;
    seg[att].v_r=r8.v_r;seg[att].n_r=r8.n_r;
    if(lft.n_mx>r8.n_mx)
    {
        seg[att].mx=lft.mx;
        seg[att].n_mx=lft.n_mx;
    }
    else
    {
        seg[att].mx=r8.mx;
        seg[att].n_mx=r8.n_mx;
    }
    if(lft.v_r==r8.v_l)
    {
        int tmp=lft.n_r+r8.n_l;
        if(seg[att].n_mx<tmp)
        {
            seg[att].n_mx=tmp;
            seg[att].mx=lft.v_r;
        }
    }
    if(lft.v_l==r8.v_l)
    {
        seg[att].n_l=lft.n_l+r8.n_l;
    }
    if(lft.v_r==r8.v_r)
    {
        seg[att].n_r=lft.n_r+r8.n_r;
    }

}

data query(int att,int L,int R,int l,int r)
{
    if(r<L||R<l)
    {
        data tmp;
        tmp.n_mx=tmp.n_l=tmp.n_r=-1;
        tmp.mx=tmp.v_l=tmp.v_r=99999999;
        return tmp;
    }
    if(l<=L&&R<=r) return seg[att];
    int mid=(L+R)/2;
    data x=query(att*2,L,mid,l,r);
    data y=query(att*2+1,mid+1,R,l,r);

    data tm;
    tm.v_l=x.v_l;tm.n_l=x.n_l;
    tm.v_r=y.v_r;tm.n_r=y.n_r;
    if(x.n_mx>y.n_mx)
    {
        tm.n_mx=x.n_mx;
        tm.mx=x.mx;
    }
    else
    {
        tm.n_mx=y.n_mx;
        tm.mx=y.mx;
    }
    if(x.v_r==y.v_l)
    {
        if(tm.n_mx<(x.n_r+y.n_l))
        {
            tm.n_mx=x.n_r+y.n_l;
            tm.mx=x.v_r;
        }
    }

    if(x.v_l==y.v_l)
    {
        tm.n_l=x.n_l+y.n_l;
    }
    if(x.v_r==y.v_r)
    {
        tm.n_r=x.n_r+y.n_r;
    }
    return tm;

}


void printdata(data a)
{
    cout<<"mx\tn_mx\tv_l\tn_l\tv_r\tn_r\n";
    cout<<a.mx<<"\t"<<a.n_mx<<"\t"<<a.v_l<<"\t"<<a.n_l<<"\t"
                        <<a.v_r<<"\t"<<a.n_r<<"\n";
}

int main()
{
    int n,q,a,b;
    while(scanf("%d",&n)==1&&n!=0)
    {
        scanf("%d",&q);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&inp[i]);
        }
        build(1,0,n-1);
        /*
        for(int i=0;i<40;i++)
        {
            cout<<i<<"\n";
            printdata(seg[i]);
            cout<<"\n\n";
        }*/
        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&a,&b);
            data ans=query(1,0,n-1,a-1,b-1);
            printf("%d\n",ans.n_mx);
        }
    }

    return 0;
}
