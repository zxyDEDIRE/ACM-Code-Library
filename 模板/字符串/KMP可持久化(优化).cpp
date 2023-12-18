#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
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
const int maxn=2e6+1e4;
int nxt[maxn];
char s[maxn];
char t[maxn];
int n,len;
void solve()
{
	cin>>s+1;
	nxt[1]=0;
	len=strlen(s+1);
	for(int i=2;i<=len;i++)
	{
		nxt[i]=nxt[i-1];
		while(s[nxt[i]+1]!=s[i]&&nxt[i]){
			if(nxt[nxt[i]]<=i/2||s[nxt[nxt[i]]+1]==s[i])
				nxt[i]=nxt[nxt[i]];
			else {
				nxt[i]=(nxt[i]%(nxt[i]-nxt[nxt[i]])+nxt[i]-nxt[nxt[i]]);
			}
		}
		if(s[nxt[i]+1]==s[i])nxt[i]++;
	}

	cin>>n;
	while(n--)
	{
		cin>>t+1;
		for(int i=1;i<=strlen(t+1);i++)
			s[i+len]=t[i];
		int length=len+strlen(t+1);
		for(int i=len+1;i<=length;i++)
		{
			nxt[i]=nxt[i-1];
			while(s[nxt[i]+1]!=s[i]&&nxt[i]){
				if(nxt[nxt[i]]<=i/2||s[nxt[nxt[i]]+1]==s[i])
					nxt[i]=nxt[nxt[i]];
				else {
					nxt[i]=(nxt[i]%(nxt[i]-nxt[nxt[i]])+nxt[i]-nxt[nxt[i]]);
				}
			}
			if(s[nxt[i]+1]==s[i])nxt[i]++;
			cout<<nxt[i]<<" ";
		}
		cout<<endl;
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