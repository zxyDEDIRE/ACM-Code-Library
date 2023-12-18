/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dfn[maxn],low[maxn],indx;
vector<int>bcc[maxn];
int col[maxn],tot;
bitset<maxn>vis;
stack<int>s;
int bri[maxn];
int cut[maxn];
int n,m,bcc_cnt;
void add(int from,int to)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++indx;
	vis[x]=1;
	s.push(x);
	int num=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			num++;
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(dfn[x]<low[y])
				bri[i]=bri[i^1]=1;
			if(low[y]>=dfn[x])
			{
				cut[x]=1;
				bcc_cnt++;
				bcc[bcc_cnt].push_back(x);
				int v;
				do{
					v=s.top();s.pop();
					bcc[bcc_cnt].push_back(v);
				}while(v!=y);
			}
		}
		else if(vis[y]&&dfn[y]<dfn[x]&&i!=(fa^1))
			low[x]=min(low[x],dfn[y]);
	}
	if(fa==0&&num==1)cut[x]=0;
}
void solve()
{
	cin>>n>>m;
	cnt=1;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i,0);
	for(int i=1;i<=bcc_cnt;i++)
	{
		cout<<"bcc:["<<i<<"]: ";
		for(auto j:bcc[i])
			cout<<j<<" ";
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
		if(cut[i])cout<<"cut "<<i<<endl;
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
/*
5 6
1 2
2 3
1 3

1 4
4 5
1 5
*/