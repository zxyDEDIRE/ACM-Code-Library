/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
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
const int N=1111;
int p[N][N];
int s[N][N];
int n,m,q;
/**************差分**************/
void insert(int x1,int y1,int x2,int y2,int c)
{
	s[x1][y1]+=c;
	s[x2+1][y2+1]+=c;
	s[x1][y2+1]-=c;
	s[x2+1][y1]-=c;
}
void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>p[i][j],insert(i,j,i,j,p[i][j]);
	while(q--)
	{
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		insert(a,b,c,d,k);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++){
			p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+s[i][j];
			cout<<p[i][j]<<" ";
		}
		cout<<endl;
	}
}
/********************************/
/**************前缀和*************/
int get(int x1,int y1,int x2,int y2)
{
	return s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];
}
void solve(int a)
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>p[i][j];
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+p[i][j];
		}
	while(q--)
	{
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1]<<endl;
	}
}
/******************************/
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}