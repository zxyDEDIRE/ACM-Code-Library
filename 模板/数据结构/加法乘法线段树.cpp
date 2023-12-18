#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
struct Seg{
	ll l,r,val,add,mu;
}t[maxn<<1];
ll p[maxn];
int n,T,mod;

void pushup(int rt)
{
	t[rt].val=(t[rt<<1].val+t[rt<<1|1].val)%mod;
}
void build(int rt,int l,int r)
{
	
	t[rt].l=l;
	t[rt].r=r;
	t[rt].add=0;
	t[rt].mu=1;
	if(l==r){
		t[rt].val=p[l]%mod;
		
		return ;
	}
	int m=(t[rt].l+t[rt].r)>>1;
	build(rt<<1,l,m);
	build(rt<<1|1,m+1,r);
	pushup(rt);
	
}
void pushdown(int rt)
{
	t[rt<<1].val=(t[rt].mu*t[rt<<1].val+(t[rt<<1].r-t[rt<<1].l+1)*t[rt].add)%mod ;
	t[rt<<1|1].val=(t[rt].mu*t[rt<<1|1].val+(t[rt<<1|1].r-t[rt<<1|1].l+1)*t[rt].add)%mod ;

	t[rt<<1].mu=t[rt<<1].mu*t[rt].mu%mod;
	t[rt<<1|1].mu=t[rt<<1|1].mu*t[rt].mu%mod;

	t[rt<<1].add=(t[rt<<1].add*t[rt].mu+t[rt].add)%mod ;
	t[rt<<1|1].add=(t[rt<<1|1].add*t[rt].mu+t[rt].add)%mod ;

	t[rt].mu=1;
	t[rt].add=0;
}
void add(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].add=(t[rt].add+ k)%mod;
		t[rt].val=(t[rt].val+k*(t[rt].r-t[rt].l+1)%mod)%mod;
		return ;
	}
	pushdown(rt);
	int m=(t[rt].l+t[rt].r)>>1;
	if(l<=m)add(rt<<1,l,r,k);
	if(r>m)add(rt<<1|1,l,r,k);
	pushup(rt);
}
void mu(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].mu=(t[rt].mu*k)%mod;
		t[rt].add=(t[rt].add*k)%mod;
		t[rt].val=(t[rt].val*k)%mod;
		return ;
	}
	pushdown(rt);
	int m=(t[rt].l+t[rt].r)>>1;
	if(l<=m)mu(rt<<1,l,r,k);
	if(r>m)mu(rt<<1|1,l,r,k);
	pushup(rt);
}
ll query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	int m=(t[rt].l+t[rt].r)>>1;
	int ans1=0,ans2=0;
	pushdown(rt);
	if(l<=m)ans1=query(rt<<1,l,r);
	if(r>m)ans2=query(rt<<1|1,l,r);
	return (ans1+ans2)%mod;
}
void dfs(int rt,int l,int r)
{
	cout<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].val<<endl;
	if(t[rt].l==t[rt].r)return ;
	int m=(t[rt].l+t[rt].r);
	dfs(rt<<1,l,r);
	dfs(rt<<1|1,l,r);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n>>T>>mod;
	for(int i=1;i<=n;i++)
		cin>>p[i];

	build(1,1,n);
	

	while(T--)
	{
		int fl,x,y,k;
		cin>>fl;
		if(fl==1)
		{
			cin>>x>>y>>k;
			mu(1,x,y,k);
		}
		else if(fl==2)
		{
			cin>>x>>y>>k;
			add(1,x,y,k);
		}
		else if(fl==3)
		{
			cin>>x>>y;
			cout<<query(1,x,y)<<"\n";
		}
	}
}