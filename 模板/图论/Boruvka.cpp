#include<bits/stdc++.h>
using namespace std;
#define rep(x,y,z) for(register int x=y; x<=z; x++)
#define downrep(x,y,z) for(register int x=y; x>=z; x--)
#define LL long long
#define ms(x,y,z) memset(x,y,sizeof(z))
#define repedge(x,y) for(register int x=hed[y]; ~x; x=edge[x].nex)
inline int read(){
    int x=0; int w=0; char ch=0;
    while(ch<'0' || ch>'9') w|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return w? (-x):x;
}
#define mp make_pair
const int N=200005;
const int M=500005;
const LL inf=1e12;
int f[N],pd,n,m;
struct node{ int a,b; LL c; }p[M];
pair<LL,LL> E[N];
int find(int r){
	return f[r]=(r==f[r])?r:find(f[r]); 
}
LL Boruvka(){
	LL res=0; pd=1; int num=0;
	for(int i=1;i<=n;i++)
		f[i]=i;
	while(num<n-1)
	{
		int tmp=0;
		for(int i=1;i<=n;i++)
		{
			int fa=find(i);
			E[fa]={inf,inf};
		}
		for(int i=1;i<=m;i++)
		{
			int fa=find(p[i].a); 
			int fb=find(p[i].b);
			if (fa==fb) continue;
			tmp++;
			E[fa]=min(E[fa],{p[i].c,i*1ll});
			E[fb]=min(E[fb],{p[i].c,i*1ll});
		}
		if (tmp==0) break;
		for(int i=1;i<=m;i++)
		{
			int fa=find(p[i].a); int fb=find(p[i].b);
			if (fa==fb) continue;
			if ((E[fa]==mp(p[i].c,i*1ll))||(E[fb]==mp(p[i].c,i*1ll)))
			{ f[fa]=fb; res+=p[i].c; num++;	}
		}
	}
	if (num<n-1) pd=0; 
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%lld",&p[i].a,&p[i].b,&p[i].c); 
	LL ans=Boruvka(); 
	if (!pd) printf("orz\n");
	else printf("%lld\n",ans);
	return 0;
}