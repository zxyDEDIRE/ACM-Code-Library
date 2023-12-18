/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
	https://www.luogu.com.cn/problem/P2756
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct node{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,m,s,t,num;
void init(){
	cnt=1;
	memset(head+1,0,sizeof(int)*(n+2));
}
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool bfs(int s,int y)
{
	memset(dep+1,0,sizeof(int)*(n+2));
	queue<int>q;
	q.push(s);
	dep[s]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(x==t)return true;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(w>0&&dep[y]==0)
			{
				dep[y]=dep[x]+1;
				q.push(y);
			}
		}
	}
	return false;
}
int dfs(int x,int flow,int t)
{
	if(x==t)return flow;
	int out=flow;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		int w=edge[i].w;
		if(w&&dep[y]==dep[x]+1)
		{
			int tmp=dfs(y,min(out,w),t);
			edge[i].w-=tmp;
			edge[i^1].w+=tmp;
			out-=tmp;
			if(!out)break;
		}
	}
	if(out==flow)dep[x]=0;
	return flow-out;
}
int DINIC(int s,int t)
{
	int ans=0;
	while(bfs(s,t))
		ans+=dfs(s,INF,t);
	return ans;
}
void solve()
{
	cin>>m>>n;
	s=n+1;
	t=n+2;
	for(int i=1;i<=m;i++)
		add(s,i,1),add(i,s,0);
	for(int i=m+1;i<=n;i++)
		add(i,t,1),add(t,i,0);
	int x,y;
	while(cin>>x>>y&&x!=-1)
	{
		add(x,y,1);
		add(y,x,0);
	}
	cout<<DINIC(s,t)<<endl;
	for(int x=1;x<=m;x++)
	{
		for(int i=head[x];i;i=edge[i].next)
		{
			if(edge[i].w==0&&edge[i].to!=s&&edge[i].to!=t)
			{
				cout<<x<<" "<<edge[i].to<<endl;
			}
		}
	}
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}