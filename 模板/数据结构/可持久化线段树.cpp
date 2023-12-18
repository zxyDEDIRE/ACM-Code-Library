#include<bits/stdc++.h>
#define mid ((l+r)>>1)
using namespace std;
using ll=long long;
const int maxn=200010;
int T[maxn],L[maxn<<5],R[maxn<<5],sum[maxn<<5];
int a[maxn],b[maxn];
int n,m,q,tot;
inline int build(int l,int r)
{
	int rt=++tot;
	if(l<r)
	{
		L[rt]=build(l,mid);
		R[rt]=build(mid+1,r);
	}
	return rt;
}
inline int update(int pre,int l,int r,int x)
{
	int rt=++tot;
	L[rt]=L[pre];R[rt]=R[pre];sum[rt]=sum[pre]+1;
	if(l<r)
	{
		if(x<=mid)L[rt]=update(L[pre],l,mid,x);
		else R[rt]=update(R[pre],mid+1,r,x);
	}
	return rt;
}
inline int query(int u,int v,int l,int r,int k)
{
	if(l==r)return l;
	int x=sum[L[v]]-sum[L[u]];
	if(x>=k)return query(L[u],L[v],l,mid,k);
	else return query(R[u],R[v],mid+1,r,k-x);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=a[i];
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-b-1;
	T[0]=build(1,m);
	
	
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(b+1,b+1+m,a[i])-b;
		T[i]=update(T[i-1],1,m,a[i]);
	}
	while(q--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		int p=query(T[x-1],T[y],1,m,z);
		cout<<b[p]<<"\n";
	}
	// cout<<tot<<endl;
	return 0;
}