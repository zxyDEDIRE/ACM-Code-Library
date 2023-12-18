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

/*
a1^2 + a2^2 + .. + an^2 
(a1+k)^2 + (a2+k)^2 + .. + (an+k)^2 ->
(a1^2)+(2*a1*k)+(k^2) + (a2^2)+(2*a2*k)+(k^2) + .. + (an^2)+(2*an*k)+(k^2) ->
(a1+k)^2 + (a2+k)^2 + .. + (an+k)^2 + sum(a1...an)*2*k + n*(k^2)



*/
struct Seg{
	int l,r;
	ll sum,sq; // sum:和 sq平方和
	ll add,mul;
}t[maxn<<2];
ll p[maxn];
void fAdd(int rt,ll k){
	t[rt].sq=t[rt].sq+t[rt].sum*k*2+(t[rt].r-t[rt].l+1)*k*k;
	t[rt].sum=t[rt].sum+k*(t[rt].r-t[rt].l+1);
	t[rt].add+=k;
}
void fMul(int rt,ll k){
	t[rt].sq=t[rt].sq*k*k;
	t[rt].sum=t[rt].sum*k;
	t[rt].add=(t[rt].add*k);
	t[rt].mul=(t[rt].mul*k);
	// t[rt].sq%=mod;t[rt].sum%=mod;t[rt].add%=mod;t[rt].mul%=mod;
}
void pushup(int rt){
	t[rt].sum=(t[rt<<1].sum+t[rt<<1|1].sum);
	t[rt].sq=(t[rt<<1].sq+t[rt<<1|1].sq);
}
void pushdown(int rt){
	if(t[rt].mul!=1){
		fMul(rt<<1,t[rt].mul);
		fMul(rt<<1|1,t[rt].mul);
		t[rt].mul=1;
	}
	if(t[rt].add!=0){
		fAdd(rt<<1,t[rt].add);
		fAdd(rt<<1|1,t[rt].add);
		t[rt].add=0;
	}
}
void build(int rt,int l,int r){
	t[rt].l=l;t[rt].r=r;t[rt].mul=1;t[rt].add=0;
	if(l==r){
		t[rt].sum=p[l];
		t[rt].sq=p[l]*p[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void updateAdd(int rt,int l,int r,ll k){
	if(l<=t[rt].l&&t[rt].r<=r){
		fAdd(rt,k);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)updateAdd(rt<<1,l,r,k);
	if(r>mid)updateAdd(rt<<1|1,l,r,k);
	pushup(rt);
}
void updateMull(int rt,int l,int r,ll k){
	if(l<=t[rt].l&&t[rt].r<=r){
		fMul(rt,k);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)updateMull(rt<<1,l,r,k);
	if(r>mid)updateMull(rt<<1|1,l,r,k);
	pushup(rt);
}
ll querySum(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].sum;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	ll ans=0;
	if(l<=mid)ans+=querySum(rt<<1,l,r);
	if(r>mid)ans+=querySum(rt<<1|1,l,r);
	return ans;
}
ll querySq(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].sq;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	ll ans=0;
	if(l<=mid)ans+=querySq(rt<<1,l,r);
	if(r>mid)ans+=querySq(rt<<1|1,l,r);
	return ans;
}
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	build(1,1,n);
	while(m--)
	{
		int op,l,r,x;cin>>op;
		if(op==1){ // 询问区间和
			cin>>l>>r;
			cout<<querySum(1,l,r)<<endl;
		}
		else if(op==2){ // 询问区间平方和
			cin>>l>>r;
			cout<<querySq(1,l,r)<<endl;
		}
		else if(op==3){ // 修改区间乘
			cin>>l>>r>>x;
			updateMull(1,l,r,x);
		}
		else if(op==4){ // 修改区间加
			cin>>l>>r>>x;
			updateAdd(1,l,r,x);
		}
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*

*/