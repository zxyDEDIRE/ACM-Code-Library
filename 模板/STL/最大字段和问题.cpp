/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
/*
https://codeforces.com/contest/1796/problem/D
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
int p[maxn];
int n,m;
//分治
int MaxIn(int *a)
{
	vector<int>dp(n+1,0);
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		if(dp[i-1]>0)
		{
			dp[i]=dp[i-1]+a[i];
		}
		else dp[i]=a[i];
		ma=max(ma,dp[i]);
	}
	return ma;
}
int MaxIn(int *a,int l,int r)
{
	if(l==r)
		return a[l]>0?a[l]:0;
	int mid=(l+r)>>1;
	//左边区间的最大子段和
	int l_max = MaxIn(a,l,mid);
	//右边区间的最大子段和
	int r_max = MaxIn(a,mid+1,r);

	int sum = 0;
	int left_max = 0;
	for(int i=mid;i>=l;i--)
	{
		sum+=a[i];
		if(sum>left_max)
			left_max = sum;
	}

	sum = 0;
	int right_max = 0;
	for(int i=mid+1;i<=r;i++)
	{
		sum+=a[i];
		if(sum>right_max)
			right_max = sum;
	}
	int res = left_max + right_max;
	if(res < l_max)
		res = l_max;
	if(res < r_max)
		res = r_max;
	return res;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	cout<<MaxIn(p)<<endl;
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
/*
4
10 20 -1 -10
*/