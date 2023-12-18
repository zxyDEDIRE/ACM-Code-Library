#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Maxll=0x3f3f3f3f3f3f3f3f;
const int N=20005,M=8e6+6;
const int Limits[]={24164832,1320323,50342,3049,211,1};
char buf[M],*p1,*p2,c;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin),p1==p2))?EOF:*p1++
inline int read(){
	int an=0,f=1;while(!isdigit(c=gc))if(c=='-')f=-f;
	do an=(an<<3)+(an<<1)+(c^'0');while(isdigit(c=gc));
	return an*f;
}
vector<int>lk[N];
int n,m,s,t,d[N],now[N],qr[N],hp,tp,ed[M],w[M],gap[N];
struct Edge{int u,v,w;}egs[M];
bool added[M],flag;
bool bfs(){
	int x,y;flag=false;
	for(x=1;x<=n;++x)d[x]=gap[x]=now[x]=0;
	d[qr[hp=tp=1]=s]=1;
	while(hp<=tp){
		x=qr[hp++];
		for(int i:lk[x])
			if(w[i]&&!d[y=ed[i]]){
				++gap[d[y]=d[x]+1];
				if(y==t){flag=true;break;}
				qr[++tp]=y;
			}
	}
	if(flag)for(x=1;x<=n;++x)if(x!=t&&d[x]==d[t])d[x]=0;
	return flag;
}
int Dinic(int x,int flow){
	if(x==t)return flow;
	int g,y,sz=lk[x].size();int k,rest=flow;
	for(int &i=now[x];i<sz&&flag;++i)
		if(w[g=lk[x][i]]&&d[y=ed[g]]==d[x]+1&&(k=Dinic(y,min(w[g],rest)))){
				w[g]-=k;w[g^1]+=k;if(!(rest-=k))return flow;
		}if(!--gap[d[x]])flag=false;d[x]=0;return flow-rest;
}
long long Maxflow;
int main(){
	n=read();m=read();s=read();t=read();int x,g;
	for(g=1;g<=m;++g)egs[g]={read(),read(),read()};
	for(bool Type:{1,0}){
        for(int lm:Limits){
            if(Type){
                for(g=1;g<=m;++g)
                    if(!added[g]&&egs[g].w>=lm){
                        x=g<<1;w[x]=egs[g].w;ed[x]=egs[g].v;
                        lk[egs[g].u].push_back(x);
                        ed[x|1]=egs[g].u;added[g]=true;
                    }
            }else{
                for(g=1;g<=m;++g)
                    if(added[g]&&egs[g].w>=lm){
                        lk[egs[g].v].push_back((g<<1)|1);
                        added[g]=false;
                    }
            }
            while(bfs())
                for(int i:lk[s])
                    if(w[i]&&(g=Dinic(ed[i],w[i])))
                        w[i]-=g,Maxflow+=g;
        }
    }
	printf("%lld\n",Maxflow);
	return 0;
}
/*
https://www.luogu.com.cn/blog/502410/ID-Algorithm
*/