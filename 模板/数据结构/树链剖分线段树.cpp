/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct Seg{int l,r,val,lazy;}t[maxn<<2];
struct Edge{int to,next,w;}edge[maxn];
int head[maxn],cnt;
int siz[maxn],f[maxn],dep[maxn],son[maxn];
int id[maxn],di[maxn],top[maxn],tot;
int w[maxn];
int n,root,q,P;
inline void add(int from,int to,int w=0){
	edge[++cnt]={to,head[from],w};
	head[from]=cnt;
}
inline void pushup(int rt){
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
inline void pushdown(int rt){
	if(t[rt].lazy){
		(t[rt<<1].val+=(t[rt].lazy*(t[rt<<1].r-t[rt<<1].l+1))%P)%=P;
		(t[rt<<1|1].val+=(t[rt].lazy*(t[rt<<1|1].r-t[rt<<1|1].l+1))%P)%=P;
		(t[rt<<1].lazy+=t[rt].lazy)%=P;
		(t[rt<<1|1].lazy+=t[rt].lazy)%=P;
		t[rt].lazy=0;
	}
}
inline void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0};
	if(l==r){
		(t[rt].val=w[di[l]])%=P;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
inline void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		(t[rt].val+=(k*(t[rt].r-t[rt].l+1))%P)%=P;
		(t[rt].lazy+=k)%=P;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
inline int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)(ans+=query(rt<<1,l,r))%=P;
	if(r>mid)(ans+=query(rt<<1|1,l,r))%=P;
	return ans;
}
inline void upRange(int x,int y,int k)
{
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(1,id[top[x]],id[x],k);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	update(1,id[x],id[y],k);
}
inline void upSon(int x,int k){
	update(1,id[x],id[x]+siz[x]-1,k);
}
inline int qRange(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		(ans+=query(1,id[top[x]],id[x]))%=P;
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	(ans+=query(1,id[x],id[y]))%=P;
	return ans;
}
inline int qSon(int x){
	return query(1,id[x],id[x]+siz[x]-1);
}
inline int LCA(int x,int y)
{
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
inline void dfs1(int x)
{
	siz[x]=1;
	for(int i=head[x];i;i=edge[i].next){
		int y=edge[i].to;
		if(y==f[x])continue;
		f[y]=x;dep[y]=dep[x]+1;
		dfs1(y);
		siz[x]+=siz[y];
		if(siz[y]>siz[son[x]])
			son[x]=y;
	}
}
inline void dfs2(int x,int topf)
{
	id[x]=++tot;
	di[tot]=x;
	top[x]=topf;
	if(son[x])dfs2(son[x],topf);
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==f[x]||y==son[x])continue;
		dfs2(y,y);
	}
}
void solve()
{
	cin>>n>>q>>root>>P;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	f[root]=0;
	dfs1(root);
	dfs2(root,root);
	build(1,1,n);
	while(q--)
	{
		int op,x,y,k;
		cin>>op;
		if(op==1)
		{
			cin>>x>>y>>k;
			upRange(x,y,k);
		}
		else if(op==2)
		{
			cin>>x>>y;
			cout<<qRange(x,y)<<endl;
		}
		else if(op==3)
		{
			cin>>x>>k;
			upSon(x,k);
		}
		else
		{
			cin>>x;
			cout<<qSon(x)<<endl;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}