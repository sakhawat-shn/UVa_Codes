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

int main()
{
    int n,flag=0;
    scan(n);
    while(n--)
    {
        if(flag)
        {
            print(newline);
        }
        flag=1;
        int b,sg,sb,a;
        scan(b);
        scan(sg);
        scan(sb);
        priority_queue<int> blue, green;
        for(int i=0;i<sg;i++)
        {
            scan(a);
            green.push(a);
        }
        for(int i=0;i<sb;i++)
        {
            scan(a);
            blue.push(a);
        }

        pair<int,int> result[b+10];
        int pos=0,x,y;


        while(blue.size()&&green.size())
        {
            for(pos=0;pos<b&&(blue.size()&&green.size());pos++)
            {
                x=green.top();green.pop();
                y=blue.top();blue.pop();
                result[pos]={x,y};
            }
            for(int i=0;i<pos;i++)
            {
                if(result[i].first>result[i].second)
                {
                    green.push(result[i].first-result[i].second);
                }
                else if(result[i].first<result[i].second)
                {
                    blue.push(result[i].second-result[i].first);
                }
            }
        }
        if(blue.size())
        {
            print("blue wins\n");
            while(blue.size())
            {
                print(blue.top());
                print(newline);
                blue.pop();
            }
        }
        else if(green.size())
        {
            print("green wins\n");
            while(green.size())
            {
                print(green.top());
                print(newline);
                green.pop();
            }
        }
        else
        {
            print("green and blue died\n");
        }
    }

    return 0;
}
