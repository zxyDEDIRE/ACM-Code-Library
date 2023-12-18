#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int INF=1e9;
const int maxn=1e6;
struct Edge{int to,next,w;}edge[maxn];
int head[maxn],cnt;
int n,m;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool spfa(int s)
{
	vector<int>dis(n+10,INF);
	vector<int>in(n+10);
	bitset<maxn>vis;
	queue<int>q;
	q.push(s);
	vis[s]=0;
	dis[s]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		in[x]++;
		if(in[x]>n)return 0;//in[x]涓嶈兘绛変簬n灏辫繑鍥? 瑕佽嚦灏憂+1
		for(int i=head[x];i;i=edge[i].next){
			int y=edge[i].to;
			if(dis[y]>dis[x]+edge[i].w){
				dis[y]=dis[x]+edge[i].w;
				if(!vis[y])vis[y]=1,q.push(y);
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";
	return 1;
}
int main()
{
	int s;
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
	}
	cout<<spfa(s)<<endl;
}