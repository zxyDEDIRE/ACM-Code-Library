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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct Seg{
	int l,r,len,cv,_l,_r,cnt;
}t[maxn];
pp(4) p[maxn];
int w[maxn];
int n,m,cnt;
void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0,0,0,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt)
{
	if(t[rt].cv)
	{
		t[rt]._l=t[rt]._r=1;
		t[rt].len=w[t[rt].r+1]-w[t[rt].l];
		t[rt].cnt=1;
	}
	else if(t[rt].l==t[rt].r)
	{
		t[rt]._l=t[rt]._r=0;
		t[rt].len=0;
		t[rt].cnt=0;
	}
	else
	{
		t[rt]._l=t[rt<<1]._l;
		t[rt]._r=t[rt<<1|1]._r;
		t[rt].len=t[rt<<1].len+t[rt<<1|1].len;
		t[rt].cnt=t[rt<<1].cnt+t[rt<<1|1].cnt-(t[rt<<1]._r&t[rt<<1|1]._l);
	}
}
void update(int rt,int l,int r,int c)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].cv+=c;
		pushup(rt);
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,c);
	if(r>mid)update(rt<<1|1,l,r,c);
	pushup(rt);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y,_x,_y;
		cin>>x>>y>>_x>>_y;
		w[++m]=y;
		w[++m]=_y;
		p[i*2-1]={x,y,_y,1};
		p[i*2]={_x,y,_y,-1};
	}
	sort(w+1,w+1+m);
	m=unique(w+1,w+1+m)-w-1;
	sort(p+1,p+1+n+n,[&](pp(4)a,pp(4)b){
		if(a[0]==b[0])return a[3]>b[3];
		return a[0]<b[0];
	});
	for(int i=1;i<=n<<1;i++)
	{
		p[i][1]=lower_bound(w+1,w+1+m,p[i][1])-w;
		p[i][2]=lower_bound(w+1,w+1+m,p[i][2])-w;
	}
	build(1,1,m);
	int pre=0;
	int ans=0;
	for(int i=1;i<=n<<1;i++)
	{
		auto [x,y,_y,op]=p[i];
		update(1,y,_y-1,op);
		ans+=abs(t[1].len-pre);
		ans+=(p[i+1][0]-p[i][0])*2*t[1].cnt;
		pre=t[1].len;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}