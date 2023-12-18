/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstring>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
map<int,int>mp;
int L[maxn],R[maxn];
string op[maxn];
int p[maxn];
int d[maxn];
int n,m,tot;
int find(int r){
	if(p[r]==r)return r;
	int rt=find(p[r]);
	d[r]^=d[p[r]];
	return p[r]=rt;
}
void T(int x){
	if(!mp.count(x))mp[x]=++tot,p[tot]=tot;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>L[i]>>R[i]>>op[i];
		R[i]++;
		T(L[i]);
		T(R[i]);
	}
	for(int i=1;i<=m;i++)
	{
		L[i]=mp[L[i]];
		R[i]=mp[R[i]];
		int fa=find(L[i]);
		int fb=find(R[i]);
		int fl=(op[i]=="even"?0:1);
		if(fa!=fb)
		{
			p[fa]=fb;
			d[fa]=(d[L[i]]^d[R[i]]^fl);
		}
		else
		{
			int now=(d[L[i]]^d[R[i]]);
			if(now==1&&fl==0){
				cout<<i-1<<endl;
				return ;
			}
			else if(now==0&&fl==1){
				cout<<i-1<<endl;
				return ;
			}
		}
	}
	cout<<m<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
*/