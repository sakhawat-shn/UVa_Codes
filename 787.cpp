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

struct Bigint
{
    string a;
    int sgn;
    Bigint(){}
    Bigint(string b){(*this)=b;}
    int size(){return a.size();}
    Bigint inverseSign(){sgn*=-1;return (*this);}
    Bigint normalize(int newSign)
    {
        for(int i=a.size()-1;i>0&&a[i]=='0';i--)
            a.erase(a.begin()+i);
        sgn=(a.size()==1&&a[0]=='0')?1:newSign;
        return (*this);
    }
    void operator=(string b)
    {
        a=(b[0]=='-')?b.substr(1):b;
        reverse(a.begin(),a.end());
        this->normalize(b[0]=='-'?-1:1);
    }
    bool operator<(const Bigint &b) const
    {
        if(sgn!=b.sgn) return sgn<b.sgn;
        if(a.size()!=b.a.size())
            return sgn==1?a.size()<b.a.size():a.size()>b.a.size();
        for(int i=a.size()-1;i>=0;i--)if(a[i]!=b.a[i])
            return sgn==1?a[i]<b.a[i]:a[i]>b.a[i];
        return false;
    }
    bool operator==(const Bigint &b) const
    {
        return a==b.a&&sgn==b.sgn;
    }
    Bigint operator+(Bigint b)
    {
        if(sgn!=b.sgn) return (*this)-b.inverseSign();
        Bigint c;
        for(int i=0,carry=0;i<a.size()||i<b.size()||carry;i++)
        {
            carry+=(i<a.size()?a[i]-48:0)+(i<b.size()?b.a[i]-48:0);
            c.a+=(carry%10+48);
            carry/=10;
        }
        return c.normalize(sgn);
    }

    Bigint operator - ( Bigint b )
    {
        // subtraction operator overloading
        if( sgn != b.sgn ) return (*this) + b.inverseSign();
        int s = sgn;
        sgn = b.sgn = 1;
        if( (*this) < b ) return ((b - (*this)).inverseSign()).normalize(-s);
        Bigint c;
        for( int i = 0, borrow = 0; i < a.size(); i++ )
        {
            borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);
            c.a += borrow >= 0 ? borrow + 48 : borrow + 58;
            borrow = borrow >= 0 ? 0 : 1;
        }
        return c.normalize(s);
    }


    Bigint operator*(Bigint b)
    {
        Bigint c("0");
        for(int i=0,k=a[i]-48;i<a.size();i++,k=a[i]-48)
        {
            while(k--)c=c+b;
            b.a.insert(b.a.begin(),'0');
        }
        return c.normalize(sgn*b.sgn);
    }
    void print()
    {
        if(sgn==-1)printf("-");
        for(int i=a.size()-1;i>=0;i--)printf("%c",a[i]);
    }
};


vector<int> vc;
Bigint ary[110][110];

Bigint maxMulSubset(int n)
{
    Bigint temp;
    for(int i=0;i<n;i++)
    {
        temp=Bigint(tostring(vc[i]));
        for(int j=0;j<=i;j++)
        {
            if(j==0)
            {
                ary[j][i]=temp;
            }
            else
            {
                ary[j][i]=temp*ary[j-1][i-1];
            }
        }
    }
    temp=ary[0][0];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            temp=max(temp,ary[j][i]);
        }
    }
    return temp;
}


int main()
{
    int n;

    while(scanf("%d",&n)==1)
    {
        if(n!=-999999)
        {
            vc.push_back(n);
        }
        else
        {
            Bigint res=maxMulSubset(vc.size());
            res.print();
            printf("\n");
            vc.clear();
        }
    }

    return 0;
}
