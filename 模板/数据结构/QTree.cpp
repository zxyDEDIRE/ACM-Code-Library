#include<bits/stdc++.h>
using namespace std;


class Qtree{
public:
	vector<int>f,son,dep,siz,top,id,di;
	struct node{int l,r,val;};
	vector<vector<int>>v;
	vector<node>t;
	int n,tot;
	Qtree(){}
	void init(int x){
		v.resize(n+1);t.resize(n*4);f.resize(n+1);
		son.resize(n+1);dep.resize(n+1);
		siz.resize(n+1);top.resize(n+1);
		id.resize(n+1);di.resize(n+1);
		tot=0;
	}
	void clear(){
		v.clear();
		dep.clear();
	}
	void add_edge(int x,int y){
		v[x].push_back(y);
		v[y].push_back(x);
	}
	void init()
	{
		dfs1(1,0);
		dfs2(1,1);
		build(1,1,n);
	}
	void build(int r){
		dfs1(1,0);
		dfs2(1,1);
		build(1,1,r);
	}
	void modify(int rt){}
	void pushup(int rt){}
	void pushdown(int rt){}
	void build(int rt,int l,int r){
		t[rt]={l,r,0};
		if(l==r){return ;}
		int mid=(l+r)>>1;
		build(rt<<1,l,mid);
		build(rt<<1|1,mid+1,r);
	}
	void update(int rt,int k){
		if(t[rt].l==t[rt].r){
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
		int ans;
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
		int ans;
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])swap(x,y);
			int now=query(1,id[top[x]],id[x]);
			x=f[top[x]];
		}
		if(dep[x]>dep[y])swap(x,y);
		int now=query(1,id[x],id[y]);
		return ans;
	}
}qt;
