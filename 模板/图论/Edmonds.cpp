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
const int INF=2e9+7;
const int maxn=1e6+100;

class Edmonds{
public:
	struct node{int x,y,w;}p[maxn];
	int vis[maxn],pre[maxn],in[maxn],id[maxn];
	int n,m,root,cnt,pos;
	Edmonds(){}
	void init(int _n){
		n=_n;m=0;pos=0;
	}
	void add(int x,int y,int w){
		p[++m]={x,y,w};
	}
	int run(int _root){
		root=_root;
		int ans=0;
		while(1){
			for(int i=1;i<=n;i++)in[i]=INF;
			for(int i=1;i<=m;i++){
				auto [x,y,w]=p[i];
				if(x!=y&&w<in[y]){
					in[y]=w,pre[y]=x;
					if(x==root)pos=i;
				}
			}
			for(int i=1;i<=n;i++)
				if(i!=root&&in[i]==INF)
					return -1;
			int cnt=0;
			for(int i=1;i<=n;i++)
				vis[i]=id[i]=0;
			for(int i=1;i<=n;i++){
				if(i==root)continue;
				ans+=in[i];
				int v=i;
				while(vis[v]!=i&&!id[v]&&v!=root){
					vis[v]=i;v=pre[v];
				}
				if(!id[v]&&v!=root){
					id[v]=++cnt;
					for(int u=pre[v];u!=v;u=pre[u])
						id[u]=cnt;
				}
			}
			if(cnt==0)break;
			for(int i=1;i<=n;i++)
				if(!id[i])id[i]=++cnt;
			in[root] = 0;
			for(int i=1;i<=m;i++){
				auto [u,v,w]=p[i];
				p[i].x=id[u];
				p[i].y=id[v];
				if(id[u]!=id[v])
					p[i].w-=in[v];
			}
			root=id[root];
			n=cnt;
		}
		return ans;
	}
	int get_rt(){
		return pos;
	}
}edm;


struct node{
	int x,y,w;
}e[maxn];
int vis[maxn];
int pre[maxn];
int in[maxn];
int id[maxn];
int n,m,root;
int Edmonds()
{
	int ans=0;
	while(1)
	{
		for(int i=1;i<=n;i++)
			in[i]=INF;
		for(int i=1;i<=m;i++)
		{
			int x=e[i].x;
			int y=e[i].y;
			if(x!=y&&e[i].w<in[y])
				in[y]=e[i].w,pre[y]=x;
		}
		for(int i=1;i<=n;i++)
			if(i!=root&&in[i]==INF)
				return -1;
		int cnt=0;
		for(int i=1;i<=n;i++)
			vis[i]=id[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(i==root)continue;
			ans+=in[i];
			int v=i;
			while(vis[v]!=i&&!id[v]&&v!=root)
			{
				vis[v]=i;
				v=pre[v];
			}
			if(!id[v]&&v!=root)
			{
				id[v]=++cnt;
				for (int u=pre[v];u!=v;u=pre[u])
					id[u]=cnt;
			}
		}
		if(cnt==0)break;
		for(int i=1;i<=n;i++)
			if(!id[i])id[i]=++cnt;
		for(int i=1;i<=m;i++)
		{
			int u=e[i].x;
			int v=e[i].y;
			e[i].x=id[u];
			e[i].y=id[v];
			if(id[u]!=id[v])
				e[i].w-=in[v];
		}
		root=id[root];
		n=cnt;
	}
	return ans;
}
void solve()
{
	cin>>n>>m>>root;
	for(int i=1;i<=m;i++)
		cin>>e[i].x>>e[i].y>>e[i].w;
	cout<<Edmonds()<<endl;
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