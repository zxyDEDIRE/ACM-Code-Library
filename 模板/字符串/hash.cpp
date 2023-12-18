/*
双哈希 测试
https://ac.nowcoder.com/acm/contest/64384/D
*/
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using PLL=pair<ull,ull>;
const int maxn=1e6+200;
char s[maxn];
int n,m,k;

// 常用的模板最好双一下
namespace POPSDF{
class Hash{
public:
	ull Prime_Pool[3] = {233317ull,1998585857ul,23333333333ul};
	ull Seed_Pool[4]={911,146527,19260817,91815541};
	ull Mod_Pool[5]={29123,998244353,1000000009,4294967291ull,212370440130137957ll};
	ull sum[maxn],bas[maxn];
	int perm[maxn];
	int sigma;
	ull Seed,Mod;
	int N;
	Hash(int x,int y):Seed(Seed_Pool[x]),Mod(Mod_Pool[y]){
	}
	void init(string&s){
		N=s.size();
		for(int i=1;i<=N;i++)
			sum[i]=(sum[i-1]*Seed%Mod+s[i-1])%Mod;
		bas[0]=1;
		for(int i=1;i<=N;i++)
			bas[i]=bas[i-1]*Seed%Mod;
	}
	void indexInit(string&s){
		N=s.size();
		sigma=N+100;
		iota(perm+1,perm+1+sigma,1);
		random_shuffle(perm+1,perm+1+sigma);
		for(int i=1;i<=N;i++)
			sum[i]=(sum[i-1]*Seed%Mod+perm[s[i-1]])%Mod;
		bas[0]=1;
		for(int i=1;i<=N;i++)
			bas[i]=bas[i-1]*Seed%Mod;
	}
	ull get(int l,int r){
		return (sum[r]-sum[l-1]*bas[r-l+1]%Mod+Mod)%Mod;
	}
}h[2]{Hash(2,2),Hash(3,3)};


}




namespace EA{
	class Hash{
	public:
		ull Prime_Pool[3] = {233317ull,1998585857ul,23333333333ul};
		ull Seed_Pool[4]={911,146527,19260817,91815541};
		ull Mod_Pool[5]={29123,998244353,1000000009,4294967291ull,212370440130137957ll};
		ull sum[maxn],bas[maxn];
		int perm[maxn];
		int sigma;
		ull Seed,Mod;
		int N;
		Hash(int x,int y):Seed(Seed_Pool[x]),Mod(Mod_Pool[y]){
			bas[0]=1;
			for (int i = 1; i <= N; i++){
				bas[i] = bas[i - 1] * Seed % Mod;
			}
		}
		void init(char *s){
			N=strlen(s+1);
			for(int i=1;i<=N;i++)
				sum[i]=(sum[i-1]*Seed%Mod+s[i])%Mod;
			bas[0]=1;
			for(int i=1;i<=N;i++)
				bas[i]=bas[i-1]*Seed%Mod;
		}
		void indexInit(char *s){
			N=strlen(s+1);
			sigma=N+100;
			iota(perm+1,perm+1+sigma,1);
			random_shuffle(perm+1,perm+1+sigma);
			// for(int i=1;i<=N;i++)
			// 	cout<<perm[i]<<" ";
			// cout<<endl;
			for(int i=1;i<=N;i++)
				sum[i]=(sum[i-1]*Seed%Mod+perm[s[i]])%Mod;
			bas[0]=1;
			for(int i=1;i<=N;i++)
				bas[i]=bas[i-1]*Seed%Mod;
		}
		ull get(int l,int r){
			return (sum[r]-sum[l-1]*bas[r-l+1]%Mod+Mod)%Mod;
		}
	}h[2]{Hash(2,2),Hash(3,3)};
	void solve()
	{
		cin>>n>>m>>k>>s+1;
		h[0].init(s);
		h[1].init(s);
		// h[0].indexInit(s);
		// h[1].indexInit(s);
		map<PLL,int>cnt;
		map<PLL,int>vis;
		for(int i=m;i<=n;i++)
		{
			ull now[2];
			now[0]=h[0].get(i-m+1,i);
			now[1]=h[1].get(i-m+1,i);
			PLL fl={now[0],now[1]};
			if(vis.count(fl)&&vis[fl]<i-m+1)
			{
				cnt[fl]++;
				vis[fl]=i;
			}
			else if(!vis.count(fl))
			{
				cnt[fl]=1;
				vis[fl]=i;
			}
		}
		int ans=0;
		for(auto [x,y]:cnt)
			if(y==k)ans++;
		cout<<ans<<endl;
	}
};
namespace EB{
	class StringHash{
	public:
		ull Mod_Pool[5]={29123,998244353,1000000009,4294967291ull,212370440130137957ll};
		ull Prime_Pool[3] = {233317ull,1998585857ul,23333333333ul};
		ull seed[4]={911,146527,19260817,91815541};
		ull mod=212370440130137957ll;
		ull prime=233317;
		ull base=131;
		vector<ull>h;
		vector<ull>bas;
		StringHash():h(1),bas(1,1),base(131){}
		// 最好 x=1,y=2
		StringHash(int x,int y):h(1),bas(1,1){base=seed[x];mod=Mod_Pool[y];}
		void push_back(char ch){
			h.push_back((h.back()*base+ch)%mod + prime);
			bas.push_back(bas.back()*base%mod);
		}
		// ull get(int l,int r){
		// 	return (h[r] + __int128(h[l])*(mod-bas[r-l]))%mod;
		// }
		ull get(int l,int r){
			return (h[r]-h[l-1]*bas[r-l+1]%mod+mod)%mod;
		}
	};
	void A()
	{
		string str;
		StringHash hs,rhs;
		int N=int(str.size());
		for(int i=0;i<N;i++)
			hs.push_back(str[i]);
		for(int i=N-1;i>=0;i--)
			rhs.push_back(str[i]);
	}
	void solve()
	{
		cin>>n>>m>>k>>s+1;
		StringHash h[2]{StringHash(1,2),StringHash(2,3)};
		for(int i=1;i<=n;i++)
		{
			h[0].push_back(s[i]);
			h[1].push_back(s[i]);
		}
		map<PLL,int>cnt;
		map<PLL,int>vis;
		for(int i=m;i<=n;i++)
		{
			ull now[2];
			now[0]=h[0].get(i-m+1,i);
			now[1]=h[1].get(i-m+1,i);
			PLL fl={now[0],now[1]};
			if(vis.count(fl)&&vis[fl]<i-m+1)
			{
				cnt[fl]++;
				vis[fl]=i;
			}
			else if(!vis.count(fl))
			{
				cnt[fl]=1;
				vis[fl]=i;
			}
		}
		int ans=0;
		for(auto [x,y]:cnt)
			if(y==k)ans++;
		cout<<ans<<endl;
	}
};
namespace shuang{
	class DoubleHash{
	public:
		const ull b1=137,b2=149,i1=1'603'801'661,i2=1'024'053'074;
		const ull p1=2'034'452'107,p2=2'013'074'419;
		ull m1[maxn],m2[maxn],r1,r2;
		PLL h[maxn];
		int N;
		void init(char*s){
			h[0]={0,0};
			int n=strlen(s+1);
			m1[0]=m2[0]=1;
			N=n+10;
			for(int i=1;i<=N;i++)
			{
				m1[i]=m1[i-1]*b1%p1;
				m2[i]=m2[i-1]*b2%p2;
			}
			h[0]={0,0};
			for(int i=1;i<=n;i++)
			{
				r1=(r1+s[i]*m1[i])%p1;
				r2=(r2+s[i]*m2[i])%p2;
				h[i]={r1,r2};
			}
		}
		PLL getv(int l,int r){
			return {(p1+h[r].first-h[l].first)*m1[N-l]%p1,(p2+h[r].second-h[l].second)*m2[N-l]%p2};
		}
		ull get(int l,int r){
			PLL a=getv(l,r);
			return (ull)a.first<<32|a.second;
		}
	}h;
};
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	EA::solve();
	return 0;
}