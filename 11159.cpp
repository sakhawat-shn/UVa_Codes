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
    ///this problem is not solved, i have to learn some new things.....
    int t;
    scan(t);
    for(int i=1;i<=t;i++)
    {
        int n,m;
        scan(n);
        int a[n];
        for(int j=0;j<n;j++)
        {
            scan(a[j]);
        }
        scan(m);
        int b[m];
        for(int j=0;j<m;j++)
        {
            scan(b[j]);
        }

        vector<pair<int,char> > nodeA[n],nodeB[m];
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                if(a[j]!=0)
                {
                    if(b[k]%a[j]==0)
                    {
                        nodeA[j].push_back({k,'b'});
                        nodeB[k].push_back({j,'a'});
                        cout<<a[j]<<" "<<b[k]<<endl;
                    }
                }
                else if(b[k]==0)
                {
                    nodeA[j].push_back({k,'b'});
                    nodeB[k].push_back({j,'a'});
                }
            }
        }
        int checkedA[n]={0},
            checkedB[m]={0};
        int ans=0,countA,countB;


        for(int j=0;j<n;j++)
        {
            countA=0;
            countB=0;
            if(!checkedA[j])
            {
                queue<pair<int,char> > q;
                q.push({j,'a'});
                countA++;
                checkedA[j]=1;
                while(!q.empty())
                {
                    pair<int,char> x=q.front();q.pop();
                    if(x.second=='a')
                    {
                        //countA++;
                        //checkedA[x.first]=1;
                        for(int k=0;k<(int)nodeA[x.first].size();k++)
                        {
                            if(!checkedB[nodeA[x.first][k].first])
                            {
                                q.push(nodeA[x.first][k]);
                                countB++;
                                checkedB[nodeA[x.first][k].first]=1;
                            }
                        }
                    }
                    else
                    {
                        //countB++;
                        //checkedB[x.first]=1;
                        for(int k=0;k<(int)nodeB[x.first].size();k++)
                        {
                            if(!checkedA[nodeB[x.first][k].first])
                            {
                                q.push(nodeB[x.first][k]);
                                countA++;
                                checkedA[nodeB[x.first][k].first]=1;
                            }
                        }
                    }
                }

            }
            //pdbug(countA,countB);
            ans=ans+min(countA,countB);
        }

        print("Case ");
        print(i);
        print(": ");
        print(ans);
        print(newline);

    }

    return 0;
}
