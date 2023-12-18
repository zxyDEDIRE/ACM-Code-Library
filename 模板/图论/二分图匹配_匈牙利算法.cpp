#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn];
int mt[maxn];
int a[maxn],b[maxn];
int n,m,e;
bitset<maxn>vis;
bool dfs(int x)
{
	if(vis[x])return 0;
	vis[x]=1;
	for(auto y:v[x]){
		if(!mt[y]||dfs(mt[y])){
			mt[y]=x;
			return 1;
		}
	}
	return 0;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(__gcd(a[i],b[j])==1)
				v[i].push_back(j+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		vis.reset();
		if(dfs(i))ans++;
	}
	cout<<ans<<endl;
}