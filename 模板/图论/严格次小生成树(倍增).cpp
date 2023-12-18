#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF64=1e18+7;
const int INF=1e9+7;
const int maxn=1e6+10;

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
	int query(int x,int y,int val){
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
}tr;







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


class Kru{
public:
	struct node{int x,y,w,fl;};
	vector<node>p;
	int n,m;
	ll ans;
	Kru(){}
	void init(int _n,int _m){
		n=_n;ans=0;
		m=_m;
		p.clear();
		p.resize(m+1);
		dsu.init(n);
	}
	void add(int x,int y,int w,int id){
		p[id]={x,y,w};
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
		return ans;
	}
	void query()
	{
		tr.dfs(1,0);
		ll res=INF64;
		for(int i=1;i<=m;i++)
		{
			if(p[i].fl)continue;
			auto [x,y,w,fl]=p[i];
			int _lca=tr.lca(x,y);
			int tmpa=tr.query(x,_lca,w);
			int tmpb=tr.query(y,_lca,w);
			if(max(tmpa,tmpb)>-INF)
				res=min(res,ans-max(tmpa,tmpb)+w);
		}
		cout<<(res==INF?-1:res)<<"\n";
	}
}_k;



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);


	int n,m;
	cin>>n>>m;
	_k.init(n,m);
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		_k.add(x,y,w,i);
	}
	_k.run();
	_k.query();
}