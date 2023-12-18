#include<bits/stdc++.h>
#define int long long 
using namespace std;



const int maxn=3e6+7;
int inv[maxn];
int n,p;
void doit()
{
	inv[1]=1;
	for(int i=2;i<=n;i++){
		inv[i]=(p-p/i)*inv[p%i]%p;
	}
}

int exgcd(int a,int b,int& x,int& y)
{
	if(b==0)return x=1,y=0,a;
	int d=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return d;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>p;
	doit();
	for(int i=1;i<=n;i++){
		cout<<inv[i]<<"\n";
	}
	//对单个
	int x,y,a;
	exgcd(a,p,x,y);
	x=(x%p+p)%p;
	cout<<x;
	//x是a模p下的逆元
}    
