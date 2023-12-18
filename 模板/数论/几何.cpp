#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1 ,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
class Point{
public:
	double x,y;
	Point(){}
	Point(double _a,double _b):x(_a),y(_b){}
};
class Line{
public:
	double k,b;
	Line(Point x,Point y){
		k=1.0*(x.y-y.y)/(x.x-y.x);
		b=x.y-k*x.x;
	}
	double dis(Point x){
		double ans=abs(k*x.x-x.y+b)/sqrt(1+k*k);
		return ans;
	};
};
double f(Point x,Point y,Point z)
{
	return abs(x.x*(y.y-z.y)+y.x*(z.y-x.y)+z.x*(x.y-y.y));
}
void solve()
{
	vector<Point>p(5);
	for(int i=0;i<5;i++){
		int x,y;cin>>x>>y;
		p[i]=Point(x,y);
	}
	double ans=0;
	ans+=f(p[0],p[1],p[2])+f(p[0],p[2],p[3])+f(p[0],p[3],p[4]);
	cout<<ans<<endl;
	
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}