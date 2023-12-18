#include<bits/stdc++.h>
#define mid ((t[rt].l+t[rt].r)>>1)
using namespace std;
const int maxn=1e5+10;
int to[maxn<<1],nex[maxn<<1],head[maxn<<1],cnt;
int dep[maxn],fa[maxn],siz[maxn],son[maxn];
int id[maxn],wt[maxn],top[maxn];
int w[maxn];
int tot;
int n,m,r,p;
int res;
struct Seg{	int l,r,val,lazy;
}t[maxn<<2];
inline void add(int from,int too)
{
	to[++cnt]=too;
	nex[cnt]=head[from];
	head[from]=cnt;
}

inline void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
	t[rt].val%=p;
}
inline void pushdown(int rt)
{
	t[rt<<1].lazy+=t[rt].lazy;
	t[rt<<1|1].lazy+=t[rt].lazy;

	t[rt<<1].val+=t[rt].lazy*(t[rt<<1].r-t[rt<<1].l+1);
	t[rt<<1|1].val+=t[rt].lazy*(t[rt<<1|1].r-t[rt<<1|1].l+1);

	t[rt<<1].val%=p;
	t[rt<<1|1].val%=p;

	t[rt].lazy=0;
}
inline void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r)
	{
		t[rt].val=wt[l];
		return ;
	}
	int md=(l+r)>>1;
	build(rt<<1,l,md);
	build(rt<<1|1,md+1,r);
	pushup(rt);
}
inline void query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		res+=t[rt].val;
		res%=p;
		return ;
	}
	if(t[rt].lazy) pushdown(rt);
	if(l<=mid)query(rt<<1,l,r);
	if(r>mid)query(rt<<1|1,l,r);
	pushup(rt);
}
inline void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].lazy+=k;
		t[rt].val+=(t[rt].r-t[rt].l+1)*k;
		return ;
	}
	if(t[rt].lazy)pushdown(rt);
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}



inline int qRange(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		res=0;
		query(1,id[top[x]],id[x]);
		ans+=res;
		ans%=p;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	res=0;
	query(1,id[x],id[y]);
	ans+=res;
	return ans%p;
}
inline void upRange(int x,int y,int k)
{
	k%=p;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(1,id[top[x]],id[x],k);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	update(1,id[x],id[y],k);
}
inline int qSon(int x)
{
	res=0;
	query(1,id[x],id[x]+siz[x]-1);
	return res;
}
inline void upSon(int x,int k)
{
	update(1,id[x],id[x]+siz[x]-1,k);
}




inline void dfs1(int x,int f,int deep)//当前点，父亲点，深度
{
	dep[x]=deep;	//记录每个点的深度
	fa[x]=f;	//记录每个点的父亲
	siz[x]=1;	//记录每个点子树大小
	int maxson=-1;	//记录重儿子的儿子树 要计较
	for(int i=head[x];i;i=nex[i])
	{
		int y=to[i];
		if(y==f)continue;
		dfs1(y,x,deep+1);	//遍历儿子
		siz[x]+=siz[y];	//加上子树大小
		if(siz[y]>maxson)son[x]=y,maxson=siz[y];//记录比较重儿子
	}
}
inline void dfs2(int x,int topf)//当前节点，topf当前链的链首
{
	id[x]=++tot;	//标记每个点的新编号
	wt[tot]=w[x];	//每个点的初始值赋值到新编号
	top[x]=topf;	//当前点的链首
	if(!son[x])return ;	//没有儿子
	dfs2(son[x],topf);	//先处理重儿子，在处理轻儿子
	for(int i=head[x];i;i=nex[i])
	{
		int y=to[i];
		if(y==fa[x]||y==son[x])
			continue;

		dfs2(y,y);//新建重链
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>r>>p;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	
	dfs1(r,0,1);
	dfs2(r,r);
	build(1,1,n);
	
	while(m--)
	{
		int k,x,y,z,fl;
		cin>>fl;
		if(fl==1)
		{
			cin>>x>>y>>z;
			upRange(x,y,z);
		}
		else if(fl==2)
		{
			cin>>x>>y;
			cout<<qRange(x,y)<<"\n";
		}
		else if(fl==3)
		{
			cin>>x>>y;
			upSon(x,y);
		}
		else if(fl==4)
		{
			cin>>x;
			cout<<qSon(x)<<"\n";
		}
	}
}