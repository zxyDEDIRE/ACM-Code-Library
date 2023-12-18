/*
基尔霍夫局矩阵树
用于解决:
	给定n个点m条边的无向图，求图的生成树个数
基本定义：
1.无向图G:给定n个点，m条边的无向图，设点击为V，边集为E，记为G(V,E)
2.度数矩阵D[G]:当i!=j时，D[i][j]=0,当i==j时,D[i][j]=点v的度数
3.邻接矩阵A[G]:当vi，vj有边链接时，A[i][j]=1,当vi，vj无边连接时，A[i][j]=0
4.基尔霍夫矩阵:K[G]:K[G]=D[G]-A[G],K[i][j]=D[i][j]-A[i][j]
定理：
	对于已经得出的基尔霍夫矩阵，去掉随意一行一列得出的矩阵的行列式
其绝对值为生成树个数

一般来说求(1,1)~(n-1,n-1)这个行列式
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int inf=0x3f3f3f3f;
const int maxn=20;





class MatrixTree{
public:
	long long a[22][22];
	int n;
	void init(int _n){
		n=_n;
		memset(a,0,sizeof(a));
	}
	void add(int x,int y){
		a[x][x]++;
		a[y][y]++;
		a[x][y]--;
		a[y][x]--;
	}
	void del(int x,int y){
		a[x][x]--;
		a[y][y]--;
		a[x][y]++;
		a[y][x]++;
	}
	long long det()
	{
		ll res=1;
		for(int i=2;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				while(a[j][i]){
					ll t=a[i][i]/a[j][i];
					for(int k=i;k<=n;k++)
						a[i][k]=(a[i][k]-a[j][k]*t);
					for(int k=i;k<=n;k++)
						swap(a[i][k],a[j][k]);
					res=-res;
				}
			}
			if(a[i][i]==0)res=-res;
			res*=a[i][i];
		}
		if(res<0)res=-res;
		return res;
	}
}mt;
void A()
{
	int n,m;
	cin>>n>>m;
	mt.init(n);
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		mt.add(x,y);
	}
	cout<<mt.det()<<"\n";
}






ll a[maxn][maxn];
int n,m;
void init(){
	memset(a,0,sizeof(a));
}
ll det(int n)
{
	ll res=1;
	for(int i=2;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			while(a[j][i]){
				ll t=a[i][i]/a[j][i];
				for(int k=i;k<=n;k++)
					a[i][k]=(a[i][k]-a[j][k]*t);
				for(int k=i;k<=n;k++)
					swap(a[i][k],a[j][k]);
				res=-res;
			}
		}
		if(a[i][i]==0)res=-res;
		res*=a[i][i];
	}
	if(res<0)res=-res;
	return res;
}
void solve()
{
	init();
	cin>>n>>m;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		a[x][x]++;
		a[y][y]++;
		a[x][y]--;
		a[y][x]--;
	}
	cout<<det(n)<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}