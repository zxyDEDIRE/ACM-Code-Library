/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
const int N=2e4+10;
int pre[N];
int dp[N];
int q[N];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int v,w,s;
		cin>>v>>w>>s;
		// 复制上一次的i-1 的DP 
		memcpy(pre,dp,sizeof(dp));
		//  枚举余数为J
		for(int j=0;j<v;j++)
		{
			int head=0;
			int tail=-1;
			for(int k=j;k<=m;k+=v)
			{
				//k-q[head]>s*v 长度长了，最多s个
				if(head<=tail&&q[head]<k-s*v)
					head++;
				while(head<=tail&&pre[q[tail]]-(q[tail]-j)/v*w<=pre[k]-(k-j)/v*w)
					tail--;
				if(head<=tail)
					dp[k]=max(dp[k],pre[q[head]]+(k-q[head])/v*w);
				q[++tail]=k;
			}
		}
	}
	cout<<dp[m]<<endl;
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