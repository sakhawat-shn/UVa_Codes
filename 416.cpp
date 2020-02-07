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
#define pdbug(args...) {string _s = #args;replace(_s.begin(), _s.end(), ',', ' ');stringstream _ss(_s);istream_iterator<string> _it(_ss);cout<<"[\n";err(_it, args); }
#define sz(a) int(a.size())
#define F first
#define S second
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
bool isConsonant(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}

//-----Template-----
template <class T> void dbug(T a) {cout<<"["<<a<<"]";}
template <class T> T gcd(T a, T b) {if(a < b) swap(a, b); while(b) {T t = b; b = a % b; a = t;} return a;}
template <class T> T big_mod(T n,T p,T m){if(p==0)return (T)1;T x=big_mod(n,p/2,m);x=(x*x)%m;if(p&1)x=(x*n)%m;return x;}
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <class T> void print_vector(T &v){int sz=v.size();if(sz)cout<<v[0];for(int i = 1; i < sz; i++)cout << ' '<<v[i];cout<<"\n";}
void err(istream_iterator<string> it) {cout<<"]"<<endl;}
template <typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) {cout << *it << " = " << a <<','<< endl;err(++it, args...);}


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

string al[10]={
    "YYYYYYN",
    "NYYNNNN",
    "YYNYYNY",
    "YYYYNNY",
    "NYYNNYY",
    "YNYYNYY",
    "YNYYYYY",
    "YYYNNNN",
    "YYYYYYY",
    "YYYYNYY"
    };
string good="1111111";

int chker(string s, int a)
{
    for(int i=0;i<7;i++)
    {
        if((good[i]=='0'&&s[i]=='Y')||(s[i]=='Y'&&al[a][i]=='N'))
            return 0;
    }
    for(int i=0;i<7;i++)
    {
        if(s[i]=='N'&&al[a][i]=='Y')
        {
            good[i]='0';
        }
    }
    return 1;
}


int main()
{
    int n;
    while(scanf("%d",&n)==1&&n!=0)
    {
        string s[n];
        for(int i=0;i<n;i++)
        {
            scan(s[i]);
        }

        int match=0;

        for(int i=9;i>=0;i--)
        {

            if((i-n+1)>=0)
            {
                good="1111111";
                match=1;
                int k=0;
                for(int j=i;k<n;j--)
                {
                    match=match*chker(s[k],j);
                    k++;
                }
                if(match)
                {
                    //pdbug(i);
                    break;
                }
            }
        }

        /*
        for(int i=0;i<(1<<10);i++)
        {
            if(__builtin_popcount(i)==n)
            {
                match=1;
                int k=0;
                for(int j=9;j>=0;j--)
                {
                    if((1<<j)&i)
                    {
                        match=match*chker(s[k],j);
                        k++;
                    }
                }
                if(match) break;
            }
        }*/


        print(match?"MATCH":"MISMATCH");
        print(newline);
    }

    return 0;
}

/*

2 --MISMATCH
NNYNNNY
NYYYYYY
0

*/
