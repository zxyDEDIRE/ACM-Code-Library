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
class triangle{
	double S(pii x,pii y,pii z)
	{
		double s=0.5*abs((y.first-x.first)*(z.second-x.second)-(z.first-x.first)*(y.second-x.second));
		return s;
	}
	double S(double x,double y,double z)
	{
		//海伦公式
		double p = 0.5*(x+y+z);
		double s;
		s=sqrt(p*(p-x)*(p-y)*(p-z));
		// 或者
		s=0.25*sqrt((x+y+z)*(x+y-z)*(x+z-y)*(y+z-x));
		return s;
	}
	//能否构成三角形
	bool ok(pii x,pii y,pii z)
	{
		if(x.first!=y.first&&y.first!=z.first&&z.first!=x.first)
		{
			double k1 = 1.0 * (y.second - x.second) / (y.first - x.first);
			double k2 = 1.0 * (z.second - y.second) / (z.first - y.first);
			double k3 = 1.0 * (z.second - x.second) / (z.first - x.first);
			if(k1 == k2 && k2 == k3)
				return 0;
			else 
				return 1;
		}
		else if(x.first == y.first && y.first == z.first)
			return 0;
		else
		{
			if(x.second == y.second && y.second == z.second)
				return 0;
			else
				return 1;
		}
	}
	//能否构成三角形
	bool ok(int x1,int y1,int x2,int y2,int x3,int y3)
	{
		if (x1 != x2 && x2 != x3 && x3 != x1)
		{
			double k1 = 1.0 * (y2 - y1) / (x2 - x1);
			double k2 = 1.0 * (y3 - y2) / (x3 - x2);
			double k3 = 1.0 * (y3 - y1) / (x3 - x1);
			if (k1 == k2 && k2 == k3)
				return 0;
			else
				return 1;
			
		}
		else if (x1 == x2 && x2 == x3)
				return 0;
		else
		{
			if (y1 == y2 && y2 == y3)
				return 0;
			else
				return 1;
		}
	}
};
void solve()
{
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