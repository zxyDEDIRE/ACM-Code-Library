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
class Qtree{
public:
	vector<int>f,son,dep,siz,top,id,di;
	struct node{int l,r,val;};
	vector<vector<int>>v;
	vector<node>t;
	int n,tot;
	Qtree(int x):n(x){
		v.resize(n+1);t.resize(n*4);f.resize(n+1);
		son.resize(n+1);dep.resize(n+1);
		siz.resize(n+1);top.resize(n+1);
		id.resize(n+1);di.resize(n+1);
		tot=0;
	}
	void add(int x,int y){
		v[x].push_back(y);
		v[y].push_back(x);
	}
	void init()
	{
		dfs1(1,0);
		dfs2(1,1);
		build(1,1,n);
	}
	void pushup(int rt){
		t[rt].val=min(t[rt<<1].val,t[rt<<1|1].val);
	}
	void pushdown(int rt){}
	void build(int rt,int l,int r){
		t[rt]={l,r,INF};
		if(l==r)return ;
		int mid=(l+r)>>1;
		build(rt<<1,l,mid);
		build(rt<<1|1,mid+1,r);
	}
	void update(int rt,int k){
		if(t[rt].l==t[rt].r){
			if(t[rt].val==INF)t[rt].val=t[rt].l;
			else t[rt].val=INF;
			return ;
		}
		int mid=(t[rt].l+t[rt].r)>>1;
		if(k<=mid)update(rt<<1,k);
		else update(rt<<1|1,k);
		pushup(rt);
	}
	int query(int rt,int l,int r){
		if(l<=t[rt].l&&t[rt].r<=r)
			return t[rt].val;
		int mid=(t[rt].l+t[rt].r)>>1;
		int ans=INF;
		if(l<=mid)ans=min(ans,query(rt<<1,l,r));
		if(r>mid)ans=min(ans,query(rt<<1|1,l,r));
		return ans;
	}
	void dfs1(int x,int fa){
		dep[x]=dep[fa]+1;
		siz[x]=1;
		f[x]=fa;
		son[x]=0;
		for(auto y:v[x])
		{
			if(y==fa)continue;
			dfs1(y,x);
			siz[x]+=siz[y];
			if(siz[y]>siz[son[x]])
				son[x]=y;
		}
	}
	void dfs2(int x,int topf){
		top[x]=topf;
		id[x]=++tot;
		di[tot]=x;
		if(son[x])dfs2(son[x],topf);
		for(auto y:v[x])
		{
			if(y==son[x]||y==f[x])continue;
			dfs2(y,y);
		}
	}
	int qRange(int x,int y=1){
		int ans=INF;
		while(top[x]!=top[y])
		{
			int now=query(1,id[top[x]],id[x]);
			ans=min(ans,now);
			x=f[top[x]];
		}
		int now=query(1,id[top[x]],id[x]);
		ans=min(ans,now);
		return ans;
	}
};