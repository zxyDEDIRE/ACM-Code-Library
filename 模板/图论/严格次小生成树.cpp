/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=(INT32_MAX);
const int maxn=2e6;
struct Seg{
	int l,r,val;
	int c;
}t[maxn<<2];
struct Edge{
	int to,next,w;
}edge[maxn];
struct node{
	int x,y,w;
}a[maxn];
int fa[maxn],dep[maxn],siz[maxn],son[maxn];
int top[maxn],id[maxn],di[maxn],w[maxn],tot;
int head[maxn],cnt;
vector<int>v[maxn];
bitset<maxn>vis;
int p[maxn];
int n,m;
int find(int r){
	return p[r]=(p[r]==r)?p[r]:find(p[r]);
}
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void pushup(int rt)
{
	if(t[rt<<1].val>t[rt<<1|1].val)
	{
		t[rt].val=t[rt<<1].val;
		t[rt].c=max({t[rt<<1|1].val,t[rt<<1].c});
	}
	else if(t[rt<<1].val<t[rt<<1|1].val)
	{
		t[rt].val=t[rt<<1|1].val;
		t[rt].c=max({t[rt<<1].val,t[rt<<1|1].c});
	}
	else
	{
		t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
		t[rt].c=max(t[rt<<1].c,t[rt<<1|1].c);
	}
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r){
		t[rt].val=w[di[l]];
		t[rt].c=0;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
int query(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		if(t[rt].val>=k)
			return t[rt].c;
		else return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans=max(ans,query(rt<<1,l,r,k));
	if(r>mid)ans=max(ans,query(rt<<1|1,l,r,k));
	return ans;
}
int qRange(int x,int y,int w)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans=max(ans,query(1,id[top[x]],id[x],w));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	if(x!=y)
		ans=max(ans,query(1,id[x]+1,id[y],w));
	return ans;
}
void dfs1(int x,int faa,int deep)
{
	siz[x]=1;
	fa[x]=faa;
	dep[x]=deep;
	int maxson=-1;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==faa)continue;
		w[y]=edge[i].w;
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
	id[x]=++tot;
	di[tot]=x;
	if(son[x])dfs2(son[x],topf);
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==fa[x]||y==son[x])continue;
		dfs2(y,y);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<=m;i++)
		cin>>a[i].x>>a[i].y>>a[i].w;
	sort(a+1,a+1+m,[&](node a,node b){
		return a.w<b.w;
	});
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int fa=find(a[i].x);
		int fb=find(a[i].y);
		if(fa!=fb)
		{
			ans+=a[i].w;
			vis[i]=1;
			p[fa]=fb;
			add(a[i].x,a[i].y,a[i].w);
			add(a[i].y,a[i].x,a[i].w);
		}
	}
	dfs1(1,1,1);
	dfs2(1,1);
	build(1,1,n);

	int mi=INF;
	for(int i=1;i<=m;i++)
	{
		if(vis[i])continue;
		if(a[i].x==a[i].y)continue;
		int x=a[i].x;
		int y=a[i].y;
		int w=a[i].w;

		int len=qRange(x,y,w);
		if(len!=w)
			mi=min(mi,w-len);
	}
	
	cout<<mi+ans<<endl;

}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
4 6
1 2 1
2 2

4 4
1 2 1
2 3 2
1 4 3
3 4 2
*/