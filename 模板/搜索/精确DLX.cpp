/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int MaxM=450010;
const int MaxP=510;
struct DLX{
	int U[MaxM],D[MaxM],L[MaxM],R[MaxM];
	int Row[MaxM],Col[MaxM];
	int First[MaxP];
	int Size[MaxM];
	int tot=0;
	int ans;
	void build(int n,int num){
		for(int i=0;i<=num;i++){
			L[i]=i-1;R[i]=i+1;
			U[i]=i;D[i]=i;
			Size[i]=0;
		}
		L[0]=num;
		R[num]=0;
		tot=num;
		for(int i=1;i<=n;i++)
			First[i]=-1;
	}
	void insert(int r,int c){
		Row[++tot]=r; Col[tot]=c;
		D[tot]=D[c]; U[D[c]]=tot;
		U[tot]=c; D[c]=tot;
		if(First[r]<0){
			L[tot]=tot;
			R[tot]=tot;
			First[r]=tot;
		}
		else{
			R[tot]=R[First[r]];
			L[R[First[r]]]=tot;
			L[tot]=First[r];
			R[First[r]]=tot;
		}
		Size[c]++;
	}
	void remove(int c){
		L[R[c]]=L[c];
		R[L[c]]=R[c];
		for(int i=D[c];i!=c;i=D[i]){
			for(int j=R[i];j!=i;j=R[j]){
				U[D[j]]=U[j];
				D[U[j]]=D[j];
				Size[Col[j]]--;
			}
		}
	}
	void resume(int c){
		for(int i=U[c];i!=c;i=U[i]){
			for(int j=L[i];j!=i;j=L[j]){
				D[U[j]]=j;
				U[D[j]]=j;
				Size[Col[j]]++;
			}
		}
		R[L[c]]=c;
		L[R[c]]=c;
	}
	void dance(int depth){
		if(depth>=ans)
			return ;
		if(R[0]==0){
			ans=depth;
			return ;
		}
		int c=R[0];
		for(int i=R[0];i!=0;i=R[i])
			if(Size[i]<Size[c])
				c=i;
		remove(c);
		for(int i=D[c];i!=c;i=D[i]){
			for(int j=R[i];j!=i;j=R[j])
				remove(Col[j]);
			dance(depth+1);
			for(int j=L[i];j!=i;j=L[j])
				resume(Col[j]);
		}
		resume(c);
	}
}dlx;
int n,m,p;
void solve()
{
	cin>>n>>m>>p;
	dlx.build(p,n*m);
	for(int i=1;i<=p;i++)
	{
		int x,y,_x,_y;
		cin>>x>>y>>_x>>_y;
		for(int I=x+1;I<=_x;I++)
			for(int J=y+1;J<=_y;J++)
				dlx.insert(i,(I-1)*m+J);
	}
	dlx.ans=inf;
	dlx.dance(0);
	if(dlx.ans==inf)cout<<-1<<endl;
	else cout<<dlx.ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
(x,y,w)
x w y w

*/
