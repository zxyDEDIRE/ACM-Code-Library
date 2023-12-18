/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ull unsigned long long
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
const ull mod=212370440130137957ll;
const ull prime=233317;
const ull base=131;
const ull more=19260817;
map<ull,bool>mp;
ull a[maxn];
int n;
ull get_hash(string &s)
{
	ull ans=0;
	for(int i=0;i<s.size();i++)
		ans=(ans*base+(ull)s[i])%mod+prime;
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		a[i]=get_hash(str);
	}
	sort(a+1,a+1+n);
	int ans=1;
	for(int i=2;i<=n;i++)
		if(a[i]!=a[i-1])
			ans++;
	cout<<ans<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
