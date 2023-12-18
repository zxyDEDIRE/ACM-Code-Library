#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
const int mod=1e8;
const int INF=1e9+7;
const int maxn=1e6+100;
class SQAM{
public:
	int ch[maxn][26];
	int f[maxn];
	string s;
	int tot;
	void init(){init(s);}
	void init(string&s)
	{
		int n=s.size();
		// for(int i=0;i<26;i++)
		// 	ch[n][i]=INF;
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<26;j++)
				ch[i][j]=ch[i+1][j];
			ch[i][s[i]-'a']=i+1;
		}
	}
	void debug(){
		for(int i=0;i<=tot;i++)
			for(int j=0;j<26;j++)
				if(ch[i][j]){
					// cout<<i<<" --"<<(char)(j+'a')<<"--> "<<ch[i][j]<<endl;
					cout<<i<<" "<<ch[i][j]<<" "<<(char)(j+'a')<<endl;
				}
	}
	void query(string&str)
	{
		int rt=1;
		f[1]=1;
		for(auto i:str)
		{
			int tmp=i-'a';
			if(ch[rt][tmp]){
				f[ch[rt][tmp]]+=f[rt];
				rt=ch[rt][tmp];
			}
			else rt=1;
		}
		for(int i=1;i<=tot;i++)
			cout<<f[i]<<" ";cout<<endl;
	}
}sa,sb,sc;
ll dp[155][155][155];
ll dfs(int x,int y,int z)
{
	if(dp[x][y][z])return dp[x][y][z];
	for(int i=0;i<26;i++)
		if(sa.ch[x][i]&&sb.ch[y][i]&&sc.ch[z][i])
		{
			dp[x][y][z]+=dfs(sa.ch[x][i],sb.ch[y][i],sc.ch[z][i]);
			dp[x][y][z]%=mod;
		}
	if(x>1||y>1||z>1)dp[x][y][z]++;
	return dp[x][y][z]%mod;
}
int n;
void solve()
{
	cin>>n;
	cin>>sa.s>>sb.s>>sc.s;
	sa.init();
	sb.init();
	sc.init();
	cout<<dfs(0,0,0)<<endl;
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
apartment
apache
approach

a p ap pa aa apa
*/