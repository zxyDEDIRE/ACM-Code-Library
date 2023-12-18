/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int maxn=1e6;

//树上RMQ
struct Multiply_LCA{
	vector<int>v[maxn];
	int dep[maxn];
	int f[maxn][25];

	void dfs(int x,int fa)
	{	
		dep[x]=dep[fa]+1;
		f[x][0]=fa;
		for(int i=1;i<=20;i++)
			f[x][i]=f[f[x][i-1]][i-1];
		for(auto y:v[x])
			if(y!=fa)
				dfs(y,x);
	}
	int LCA(int x,int y)
	{
		if(dep[x]<dep[y])swap(x,y);
		for (int j = 0, D = dep[x] - dep[y]; D; ++j, D >>= 1)
			if (D & 1) x = f[x][j];
		if(x==y)return x;
		for (int j = 20; ~j; --j)
			if (f[x][j] != f[y][j])
				x = f[x][j], y = f[y][j];
		return f[x][0];
	}

};
void solve()
{

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}