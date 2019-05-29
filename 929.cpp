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

int ary[1010][1010],z[1010][1010],c[1010][1010];
int m,n;

void init()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            z[i][j]=0;
            c[i][j]=10000000;
        }
}

int dijkstra()
{
    priority_queue< pair< int, pair<int,int> > > q;
    c[0][0]=ary[0][0];
    q.push({c[0][0],{0,0}});

    while(!q.empty())
    {
        pair<int,int> a=q.top().second;q.pop();
        if(z[a.first][a.second]) continue;
        z[a.first][a.second]=1;
        if((a.first-1)>=0)
        {
            if(c[a.first][a.second]+ary[a.first-1][a.second]<c[a.first-1][a.second])
            {
                c[a.first-1][a.second]=c[a.first][a.second]+ary[a.first-1][a.second];
                q.push({-c[a.first-1][a.second],{a.first-1,a.second}});
            }
        }
        if((a.first+1)<n)
        {
            if(c[a.first][a.second]+ary[a.first+1][a.second]<c[a.first+1][a.second])
            {
                c[a.first+1][a.second]=c[a.first][a.second]+ary[a.first+1][a.second];
                q.push({-c[a.first+1][a.second],{a.first+1,a.second}});
            }
        }
        if((a.second-1)>=0)
        {
            if(c[a.first][a.second]+ary[a.first][a.second-1]<c[a.first][a.second-1])
            {
                c[a.first][a.second-1]=c[a.first][a.second]+ary[a.first][a.second-1];
                q.push({-c[a.first][a.second-1],{a.first,a.second-1}});
            }
        }
        if((a.second+1)<m)
        {
            if(c[a.first][a.second]+ary[a.first][a.second+1]<c[a.first][a.second+1])
            {
                c[a.first][a.second+1]=c[a.first][a.second]+ary[a.first][a.second+1];
                q.push({-c[a.first][a.second+1],{a.first,a.second+1}});
            }
        }
    }

    return c[n-1][m-1];
}


int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&m);
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                scanf("%d",&ary[j][k]);
            }
        }
        init();
        printf("%d\n",dijkstra());
    }

    return 0;
}
