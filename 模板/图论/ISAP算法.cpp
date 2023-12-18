/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
bitset<maxn>vis;
int dep[maxn],cntd[maxn];
int n,m,s,t;
void init(){
	cnt=1;
	memset(head+1,0,sizeof(int)*n);
}
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void bfs()
{
	memset(dep+1,-1,sizeof(int)*n);
	memset(cntd+1,0,sizeof(int)*n);
	dep[t]=0;
	cntd[0]=1;
	queue<int>q;
	q.push(t);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dep[y]!=-1)continue;
			q.push(y);
			dep[y]=dep[x]+1;
			cntd[dep[y]]++;
		}
	}
	return ;
}
int dfs(int x,int flow)
{
	if(x==t)return flow;
	int sum=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		int w=edge[i].w;
		if(w>0&&dep[x]==dep[y]+1)
		{
			int tmp=dfs(y,min(w,flow-sum));
			edge[i].w-=tmp;
			edge[i^1].w+=tmp;
			sum+=tmp;
			if(sum==flow)return sum;
		}
	}
	//if(dep[s]>n)return sum;

	cntd[dep[x]]--;
	if(!cntd[dep[x]])dep[s]=n+1;
	dep[x]++;
	cntd[dep[x]]++;
	return sum;
}
int ISAP(int s,int t)
{
	int ans=0;
	bfs();
	while(dep[s]<n)
	{
		ans+=dfs(s,INF);
	}
	return ans;
}
void solve()
{
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		dep[i]=1;
		cntd[1]++;
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,0);
	}
	int tmp=ISAP(s,t);
	cout<<tmp<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}