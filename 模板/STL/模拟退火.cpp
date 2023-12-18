#include<bits/stdc++.h>
using namespace std;


const int maxn=1e6+100;
struct node{
	double x,y,z;
}a[maxn];
int n;
struct SaDown{
	//退火系数
	#define down 0.996
	double ansx,ansy,ansz,answ;
	//评估函数
	double energy(double x,double y,double z){
		double r=0;
		for(int i=1;i<=n;i++){
			r=max(r,sqrt((x-a[i].x)*(x-a[i].x)+(y-a[i].y)*(y-a[i].y)+(z-a[i].z)*(z-a[i].z)));
		}
		return r;
	}
	void sa()
	{
		double t=3000;
		while(t>1e-15)
		{
			double ex=ansx+(rand()*2-RAND_MAX)*t;
			double ey=ansy+(rand()*2-RAND_MAX)*t;
			double ez=ansz+(rand()*2-RAND_MAX)*t;
			double ew=energy(ex,ey,ez);
			double de=ew-answ; 
			if(answ>ew)
			{
				ansx=ex;
				ansy=ey;
				ansz=ez;
				answ=ew;
			}
			else if(exp(-de/t)*RAND_MAX>rand())
			{
				ansx=ex;
				ansy=ey;
				ansz=ez;
			}
			t*=down;
		}
	}
	void doit(){
		//退火次数
		for(int i=1;i<=4;i++)
			sa();
	}
}sa;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
		sa.ansx+=a[i].x;
		sa.ansy+=a[i].y;
		sa.ansz+=a[i].z;
	}
	sa.ansx/=n;
	sa.ansy/=n;
	sa.ansz/=n;
	sa.answ=sa.energy(sa.ansx,sa.ansy,sa.ansz);
	sa.doit();
	printf("%.3lf\n",sa.answ);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}