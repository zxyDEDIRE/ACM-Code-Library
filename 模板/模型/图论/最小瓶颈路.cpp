#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=1000000007;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e7+100;
struct node{
	int x,y,w;
}a[maxn];
vector<int>v[maxn];
int dep[maxn],fa[maxn],siz[maxn],son[maxn];
int top[maxn];//链首
int val[maxn];
int p[maxn];
int n,m,tot;
int A,B,C,P;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
int rnd(){
	return A=(A*B+C)%P;
}
void dfs1(int x,int f,int deep)
{
	dep[x]=deep;
	fa[x]=f;
	siz[x]=1;
	int maxson=-1;
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(y==f)continue;
		dfs1(y,x,deep+1);
		siz[x]+=siz[y];
		if(siz[y]>maxson)
		{
			maxson=siz[y];
			son[x]=y;
		}
	}
}
void dfs2(int x,int topf)
{
	top[x]=topf;
	if(!son[x])return ;
	dfs2(son[x],topf);
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if(y==fa[x]||y==son[x])continue;
		dfs2(y,y);
	}
}
int LCA(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return val[x];
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i].x>>a[i].y>>a[i].w;
	for(int i=1;i<=n;i++)
		p[i]=i;
	sort(a+1,a+1+m,[&](node a,node b){
		return a.w<b.w;
	});
	tot=n;
	for(int i=1;i<=m;i++)
	{
		int fa=find(a[i].x);
		int fb=find(a[i].y);
		if(fa!=fb)
		{
			tot++; 
			p[fa]=p[fb]=p[tot]=tot;
			val[tot]=a[i].w;
			v[tot].push_back(fa);
			v[tot].push_back(fb);
			v[fa].push_back(tot);
			v[fb].push_back(tot);
		}
	}
	dfs1(tot,0,0);
	dfs2(tot,tot);
	int q,ans=0;
	cin>>q;
	cin>>A>>B>>C>>P;
	while(q--)
	{
		int x=rnd()%n+1;
		int y=rnd()%n+1;
		ans=(ans+LCA(x,y))%mod;
	}
	cout<<ans%mod<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}