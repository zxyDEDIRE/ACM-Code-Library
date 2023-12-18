/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;

int unit;  // 块的大小

struct node {
  int l, r, id;

  bool operator<(const node &x) const {
    return l / unit == x.l / unit
               ? (r == x.r ? 0 : ((l / unit) & 1) ^ (r < x.r))
               : l < x.l;
  }
};


struct Query{
	int l,r,id,block;
	bool operator < (const Query& q)const
	{
		if(block==q.block)
			return r<q.r;
		else
			return block<q.block;
	}
}p[maxn];
int cnt_a[maxn],cnt_b[maxn];
int a[maxn],b[maxn];
bool ans[maxn];
int n,m,ok=0,cnt=0;
void Debug()
{
	printf("[Debug]:");
	int ma=0;
	for(int i=1;i<=n;i++)
		ma=max({ma,a[i],b[i]});
	for(int i=1;i<=ma;i++)
		cout<<cnt_a[i];cout<<endl;
	printf("[Debug]:");
	for(int i=1;i<=ma;i++)
		cout<<cnt_b[i];
	cout<<endl;
	cout<<cnt<<endl;
}
inline void upd_a(int x,int fl)
{
	int fl_1=0,fl_2=0;
	if((cnt_a[x]>0&&cnt_b[x]>0)||(cnt_a[x]==0&&cnt_b[x]==0))fl_1=1;
	if((cnt_a[x]+fl>0&&cnt_b[x]>0)||(cnt_a[x]+fl==0&&cnt_b[x]==0))fl_2=1;
	if(fl_1>fl_2)cnt++;
	else if(fl_1<fl_2)cnt--;
	cnt_a[x]+=fl;
	if(cnt)ok=1;
	else ok=0;
}
inline void upd_b(int x,int fl)
{
	int fl_1=0,fl_2=0;
	if((cnt_b[x]>0&&cnt_a[x]>0)||(cnt_b[x]==0&&cnt_a[x]==0))fl_1=1;
	if((cnt_b[x]+fl>0&&cnt_a[x]>0)||(cnt_b[x]+fl==0&&cnt_a[x]==0))fl_2=1;
	if(fl_1>fl_2)cnt++;
	else if(fl_1<fl_2)cnt--;
	cnt_b[x]+=fl;
	if(cnt)ok=1;
	else ok=0;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	int tmp=sqrt(n);
	for(int i=1;i<=m;i++)
	{
		cin>>p[i].l>>p[i].r;
		p[i].id=i;
		p[i].block=i/tmp;
	}
	sort(p+1,p+1+m);
	for(int i=1;i<=max(p[1].l,p[1].r);i++)
	{
		if(i<=p[1].l)
			upd_a(a[i],1);
		if(i<=p[1].r)
			upd_b(b[i],1);
	}
	ans[p[1].id]=ok;
	int l=p[1].l;
	int r=p[1].r;
	// Debug();
	for(int i=2;i<=m;i++)
	{
		while(l<p[i].l)//l++;
			l++,upd_a(a[l],1);
		while(l>p[i].l)//l--;
			upd_a(a[l],-1),l--;
		while(r<p[i].r)//r++;
			r++,upd_b(b[r],1);
		while(r>p[i].r)//r--;
			upd_b(b[r],-1),r--;
		ans[p[i].id]=ok;
		// Debug();
	}
	for(int i=1;i<=m;i++)
	{
		if(ans[i])cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}