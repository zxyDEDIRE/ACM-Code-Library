#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int n,m,s;
int u,v;
int p[maxn];
int fa[maxn];
int lca[maxn];
int vis[maxn];
int cnt,head[maxn];
struct Edge{
	int to,next;
}edge[maxn];
vector<pair<int,int> >q[maxn];
int read(){
    int num=0;char ch;
    while((ch=getchar())<'0'||'9'<ch);
    do num=num*10+ch-48,ch=getchar();while('0'<=ch&&ch<='9');
    return num;
} 
void add(int from,int to)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
int find(int t){
	int r=t;
	while(p[r]!=r)r=p[r];
	return r;
}
void tarjan(int u)
{
	vis[u]=1;
	p[u]=u;
	for(int i=head[u];i;i=edge[i].next)
	{
		int j=edge[i].to;
		if(vis[j]==1)continue;
			fa[j]=u;
			tarjan(j);
			p[j]=u;
	}
	//vis[u]=1;
	int k=q[u].size();
	for(int i=0;i<k;i++){
		if(vis[q[u][i].first]==2)
			lca[q[u][i].second]=find(q[u][i].first);
	}
	vis[u]=2;
}
int main()
{
	cin>>n>>m>>s;
	//n=read();m=read();s=read();
	for(int i=1;i<n;i++){
		cin>>u>>v;
		//u=read();v=read();
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		//u=read();v=read();
		q[u].push_back(pair<int,int>(v,i));
		q[v].push_back(pair<int,int>(u,i));
	}
	tarjan(s);
	for(int i=1;i<=m;i++){
		cout<<lca[i]<<endl;
		//printf("%d\n",lca[i]);
	}
}
