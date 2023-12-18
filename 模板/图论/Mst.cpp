#include<bits/stdc++.h>
using namespace std;


using ll=long long;
const ll INF64=1e18+7;
const int maxn=1e6+10;
const int INF=1e9+7;
const int N=1001;


class MstPrim{
public:
	struct node{
		int id;int dis;
		bool operator<(const node&a)const{
			return a.dis<dis;
		}
	};
	int maxD[N][N],mp[N][N];
	bool mst[N][N];
	int dis[N];
	bool vis[N];
	int pre[N];
	int n;
	MstPrim(){}
	void init(int _n){
		n=_n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				mp[i][j]=INF,mst[i][j]=maxD[i][j]=0;
			vis[i]=0;
			dis[i]=INF;
			pre[i]=1;
		}
	}
	int prim(int s=1)
	{
		priority_queue<node>q;
		q.push({s,dis[s]=0});
		int ans=0;
		while(!q.empty())
		{
			auto [x,W]=q.top();q.pop();
			if(vis[x])continue;
			vis[x]=1;
			ans+=W;
			mst[x][pre[x]]=mst[pre[x]][x]=1;
			for(int y=1;y<=n;y++){
				if(vis[y]&&mp[x][y]<INF)
					maxD[x][y]=maxD[y][x]=max(maxD[pre[x]][y],dis[x]);
				if(mp[x][y]<dis[y]){
					dis[y]=mp[x][y];
					pre[y]=x;
					q.push({y,dis[y]});
				}
			}
		}
		return ans;
	}
	void add(int x,int y,int w){mp[x][y]=w;}
	bool had(int x,int y){return mst[x][y];}
	int getmaxD(int x,int y){return maxD[x][y];}
}_mst;


class DSU{
public:
	vector<int>f,num;
	DSU(){}
	void init(int n){
		f.resize(n+1);
		iota(f.begin(),f.end(),0);
	}
	int find(int r){
		return f[r]=f[r]==r?f[r]:find(f[r]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void merge(int x,int y){
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
			f[fa]=fb;
	}
}dsu;


class MstKru{
public:
	struct node{int x,y,w,fl;}p[maxn];
	bool mst[maxn][maxn];
	int maxD[maxn][maxn];
	vector<int>v[maxn];
	int n,m;
	MstKru(){}
	void init(int _n){
		n=_n;m=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mst[i][j]=0;
				maxD[i][j]=0;
			}
			v[i]={i};
		}
	}
	void add(int x,int y,int w){
		p[++m]={x,y,w};
	}
	int run()
	{
		sort(p+1,p+1+m,[&](node a,node b){return a.w<b.w;});
		dsu.init(n);
		ll ans=0;
		int cnt=n;
		for(int i=1;i<=m;i++)
		{
			auto &[x,y,w,fl]=p[i];
			if(!dsu.same(x,y))
			{
				cnt--;
				int fa=dsu.find(x);
				int fb=dsu.find(y);
				ans+=w;	fl=1;
				dsu.merge(x,y);
				for(auto _i:v[fa])
					for(auto _j:v[fb])
						maxD[_i][_j]=maxD[_j][_i]=w;
				for(auto _i:v[fb])
					v[fa].push_back(_i);
			}
			if(cnt==1)break;
		}
		if(cnt!=1)return -2;
		ll res=INF;
		for(int i=1;i<=m;i++)
		{
			if(p[i].fl)continue;
			auto [x,y,w,fl]=p[i];
			res=min(res,ans+w-maxD[x][y]);
		}
		if(res==INF)return -1;
		return res;
	}
}mst;




class STR_Tr{
public:
	struct Edge{int to,next,w;}edge[maxn];
	int head[maxn],cnt;
	int f[maxn][22];
	int dep[maxn];
	int maxx[maxn][22];
	int minn[maxn][22];
	void add(int from,int to,int w){
		edge[++cnt].w=w;
		edge[cnt].to=to;
		edge[cnt].next=head[from];
		head[from]=cnt;
	}
	void Add(int x,int y,int w){
		add(x,y,w);
		add(y,x,w);
	}
	void dfs(int x,int fa)
	{
		dep[x]=dep[fa]+1;
		f[x][0]=fa;
		minn[x][0]=-INF;
		for(int i=1;(1<<i)<=dep[x];i++)
		{
			f[x][i]=f[f[x][i-1]][i-1];
			int kk[4]={maxx[x][i-1],maxx[f[x][i-1]][i-1],
					minn[x][i-1],minn[f[x][i-1]][i-1]};
			sort(kk,kk+4);
			maxx[x][i]=kk[3];
			int ptr=2;
			while(ptr>=0&&kk[ptr]==kk[3])ptr--;
			minn[x][i]=(ptr==-1?-INF:kk[ptr]);
		}
		for(int i=head[x];i;i=edge[i].next)
			if(edge[i].to!=fa){
				maxx[edge[i].to][0]=edge[i].w;
				dfs(edge[i].to,x);
			}
	}
	int lca(int x,int y){
		if(dep[x]<dep[y])swap(x,y);
		for (int j = 0, D = dep[x] - dep[y]; D; ++j, D >>= 1)
			if (D & 1) x = f[x][j];
		if(x==y)return x;
		for (int j = 20; ~j; --j)
			if (f[x][j] != f[y][j])
				x = f[x][j], y = f[y][j];
		return f[x][0];
	}
	int querySTR(int x,int y,int val){
		int res=-INF;
		for(int i=21;i>=0;i--){
			if(dep[f[x][i]]>=dep[y]){
				if(val!=maxx[x][i])
					res=max(res,maxx[x][i]);
				else
					res=max(res,minn[x][i]);
				x=f[x][i];
			}
		}
		return res;
	}
	int query(int x,int y)
	{
		int res=-INF;
		for(int i=21;i>=0;i--){
			if(dep[f[x][i]]>=dep[y]){
				res=max(res,maxx[x][i]);
				x=f[x][i];
			}
		}
		return res;
	}
}tr;



class Tr{
public:
	struct Edge{int to,next,w;}edge[maxn];
	int head[maxn],cnt;
	int maxx[maxn][22];
	int f[maxn][22];
	int dep[maxn];
	void add(int from,int to,int w){
		edge[++cnt].w=w;
		edge[cnt].to=to;
		edge[cnt].next=head[from];
		head[from]=cnt;
	}
	void Add(int x,int y,int w){
		add(x,y,w);
		add(y,x,w);
	}
	void dfs(int x,int fa)
	{
		dep[x]=dep[fa]+1;
		f[x][0]=fa;
		for(int i=1;(1<<i)<=dep[x];i++)
		{
			f[x][i]=f[f[x][i-1]][i-1];
			maxx[x][i]=max(maxx[x][i-1],maxx[f[x][i-1]][i-1]);
		}
		for(int i=head[x];i;i=edge[i].next)
			if(edge[i].to!=fa){
				maxx[edge[i].to][0]=edge[i].w;
				dfs(edge[i].to,x);
			}
	}
	int lca(int x,int y){
		if(dep[x]<dep[y])swap(x,y);
		for (int j = 0, D = dep[x] - dep[y]; D; ++j, D >>= 1)
			if (D & 1) x = f[x][j];
		if(x==y)return x;
		for (int j = 20; ~j; --j)
			if (f[x][j] != f[y][j])
				x = f[x][j], y = f[y][j];
		return f[x][0];
	}
	int query(int x,int y)
	{
		int res=-INF;
		for(int i=21;i>=0;i--){
			if(dep[f[x][i]]>=dep[y]){
				res=max(res,maxx[x][i]);
				x=f[x][i];
			}
		}
		return res;
	}
}_tr;


class Kru{
public:
	struct node{int x,y,w,fl;};
	vector<node>p;
	int n,m;
	ll ans;
	Kru(){}
	void init(int _n){
		n=_n;ans=0;m=0;
		p.clear();
		p.resize(m+1);
		dsu.init(n);
	}
	void add(int x,int y,int w){
		// p[++m]={x,y,w};
		p.push_back({x,y,w});
	}
	int run(){
		sort(p.begin()+1,p.end(),[&](node a,node b){return a.w<b.w;});
		int num=n;
		for(int i=1;i<=m;i++)
		{
			auto &[x,y,w,fl]=p[i];
			if(!dsu.same(x,y)){
				num--;
				dsu.merge(x,y);
				tr.Add(x,y,w);
				ans+=w;
				fl=1;
			}
			if(num==1)break;
		}
		if(num!=1)ans=-1;
		return ans;
	}
	ll query()
	{
		tr.dfs(1,0);
		ll res=INF64;
		for(int i=1;i<=m;i++)
		{
			if(p[i].fl)continue;
			auto [x,y,w,fl]=p[i];
			int _lca=tr.lca(x,y);
			int tmpa=tr.query(x,_lca);
			int tmpb=tr.query(y,_lca);
			if(max(tmpa,tmpb)>-INF)
				res=min(res,ans-max(tmpa,tmpb)+w);
		}
		return (res==INF64?-1:res);
	}
}_k;





int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	// int __;cin>>__;
	// for(int i=1;i<=__;i++){
	// 	cout<<"Case #"<<i<<": ";
	// 	solve();
	// }
	return 0;
}
