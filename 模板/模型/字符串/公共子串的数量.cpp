#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
#define int long long
const int INF=1e18+7;
const int maxn=111;
int dp[155][155][155];
class SQAM{
public:
	int ch[maxn][26];
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
}sa,sb,sc;

string a,b,c;
int n;
int dfs(int x,int y,int z)
{
	if(dp[x][y][z])return dp[x][y][z];
	int res=1;
	for(int i=0;i<26;i++)
		if(sa.ch[x][i]&&sb.ch[y][i]&&sc.ch[z][i])
			res+=dfs(sa.ch[x][i],sb.ch[y][i],sc.ch[z][i]);
	return dp[x][y][z]=res;
}
void solve()
{
	cin>>a>>b>>c;
	sa.init(a);
	sb.init(b);
	sc.init(c);
	cout<<dfs(0,0,0)-1<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}