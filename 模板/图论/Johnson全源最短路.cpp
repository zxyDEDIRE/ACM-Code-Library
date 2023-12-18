#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int INF=1e9;
const int maxn=3e5;
struct node{
	int x;ll dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{int to,next;ll w;}edge[maxn];
int head[maxn],cnt;
ll dis[maxn];
ll h[maxn];
int n,m;
void add(int from,int to,ll w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool spfa(int s)
{
	for(int i=0;i<=n;i++)h[i]=INF;
	vector<int>in(n+10,0);
	bitset<maxn>vis;
	queue<int>q;
	vis[s]=1;
	h[s]=0;
	q.push(s);
	while(!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		in[x]++;
		if(in[x]>n)return 0;
		for(int i=head[x];i;i=edge[i].next){
			int y=edge[i].to;
			if(h[y]>h[x]+edge[i].w){
				h[y]=h[x]+edge[i].w;
				if(!vis[y])q.push(y),vis[y]=1;
			}
		}
	}
	return 1;
}
void dij(int s)
{
	for(int i=1;i<=n;i++)dis[i]=INF;
	priority_queue<node>q;
	bitset<maxn>vis;
	q.push({s,0});
	dis[s]=0;
	while(!q.empty()){
		auto [x,now]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next){
			int y=edge[i].to;
			if(dis[y]>dis[x]+edge[i].w){
				dis[y]=dis[x]+edge[i].w;
				q.push({y,dis[y]});
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
	}
	for(int i=1;i<=n;i++)
		add(0,i,0);
	//建立虚点，从0开始单源最短路
	//0开始单源最短路即为势能
	//同时spfa判断是否存在负环（in[x]>n)
	if(!spfa(0)){
		cout<<-1<<endl;
		return 0;
	}
	//每一条路加上势能差
	for(int u=1;u<=n;u++){
		for(int i=head[u];i;i=edge[i].next){
			edge[i].w+=h[u]-h[edge[i].to];
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
		ll ans=0;
		for(int j=1;j<=n;j++){
			if(dis[i]==INF)ans+=j*INF;
			else ans+=j*(dis[j]+h[j]-h[i]);
			//减去势能差
		}
		cout<<ans<<endl;
	}
}