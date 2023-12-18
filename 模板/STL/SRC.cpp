#pragma comment(linker, "/STACK:1024000000,1024000000")
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define ll         long long
#define D          double
#define pii          pair<int,int>
#define pll        pair<long long,long long>
#define fi         first
#define se         second
//-----------------------------------------math----------------------------------------
#define MAX(x,y)   x=max(x,y)
#define MIN(x,y)   x=min(x,y)
#define pow2(x)    (1<<(x))
//-----------------------------------------STL-------------------------------------------
#define pb         push_back
#define ALL(a)     a.begin(),a.end()
#define POS(a,c)   lower_bound( a.begin() , a.end() , (c) ) - a.begin() + 1
#define UNI(a)     sort(ALL(a)),a.erase(unique(ALL(a)),a.end())
#define DELF(a)    a[0]=a[SZ(a)-1],a.resize(SZ(a)-1)
#define SUM(a,l,r) upper_bound(ALL(a),r)-lower_bound(ALL(a),l)
#define E(a,b)     a.find(b)!=a.end()
#define mp(a,b)  make_pair(a,b)
//---------------------------------------------io-------------------------------------------
#define FLUSH      fflush(stdout)
#define TC         int T;cin>>T;while(T--)
#define watch(x)   cout<<(#x)<<"  is  "<<x<<endl
#define END        {cout<<-1;return 0;}
//---------------------------------------segment tree---------------------------------------------
#define callmid    int mid=(L+R)>>1
#define ls         p+p
#define rs         p+p+1
#define rmid       r<=mid
#define midl       l>=mid+1
#define xmid       x<=mid
#define lsg        L,mid
#define rsg        mid+1,R
//-----------------------------------------graph---------------------------------------------------
#define read_edge  a=read(),b=read(),g[a].pb(b),g[b].pb(a)
#define NOT(u)     if(v==u)continue
#define notfa      if(v==fa)continue
//------------------------------------------else---------------------------------------
#define all(a)     a+1,a+n+1
#define SZ(x)      (int)(x).size()
#define mod       1000000007
#define Ceil(a,b)  ((a)/(b)+(a)/(abs(a))*((a)%(b)!=0))
#define mem0(a)    memset(a,0,sizeof(a))
#define mem1(a)    memset(a,-1,sizeof(a))
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


pii operator*(const pii&p,const pii&x){pii np=make_pair(p.fi*x.fi,p.se*x.se);return np;}
pll operator%(const pll&p,const pll&x){pll np=make_pair(p.fi%x.fi,p.se%x.se);return np;}
pll operator*(const pll&p,const pii&x){pll np=make_pair(p.fi*x.fi,p.se*x.se);return np;}
pll operator*(const pll&p,const pll&x){pll np=make_pair(p.fi*x.fi,p.se*x.se);return np;}
pll operator+(const pll&p,const pll&x){pll np=make_pair(p.fi+x.fi,p.se+x.se);return np;}
pll operator-(const pll&p,const pll&x){pll np=make_pair(p.fi-x.fi,p.se-x.se);return np;}
pii operator+(const pii&p,const pii&x){pii np=make_pair(p.fi+x.fi,p.se+x.se);return np;}
pii operator-(const pii&p,const pii&x){pii np=make_pair(p.fi-x.fi,p.se-x.se);return np;}

vector<int> prime;
//*************************************************
bool sortinrev(const pair<int,int> &a,const pair<int,int> &b){return (a.first > b.first);}
bool sortbysecdesc(const pair<int,int> &a,const pair<int,int> &b){if(a.second==b.second)return a.first>b.first;return a.second>b.second;}
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) {if(a.second==b.second)return a.first>b.first;return (a.second < b.second);}
//*************************************************
ll powerm(ll a, ll k) { if (!k) {return 1;}ll b = powerm(a, k / 2);b = b * b % mod;if (k % 2) {return a * b % mod;} else {return b;}}
ll power(ll a , ll b) { if(b == 1) return a; if(b == 0) return 1; ll m1 = power(a,b/2); if(b%2) return m1*m1*a; return m1*m1; }
void PFactor(int x){prime.clear();FOR(i,2,x/i)if(x%i==0){while(x%i==0)x/=i,prime.pb(i);}if (x > 1) prime.pb(x);}
bool isprime (ll a) { if(a<=1) return false; if(a==2||a==3) return true; if(a%2==0||a%3==0) return false; for(ll i=5;i*i<=a;i=i+6) { if(a%i==0||a%(i+2)==0) return false; } return true;}
//-----------------------------------------diao ren kuai du--------------------------------------------
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}


const int LOGN = 20;
const int N = (1 << LOGN);
const int maxn=1e6;
//---------------------------------------------ADDON--------------------------------------------


//-----------------------------------------------------------------------------------------------------------------

int main()
{

    return 0;
}
