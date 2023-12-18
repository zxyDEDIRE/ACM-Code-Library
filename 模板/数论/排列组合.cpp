#include <stdio.h>
const int mod=998244353;
const int M = 2e5+10;


int ff[M+5];
int x,y;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
void Extended_gcd(int a,int b){
	if(b==0){x=1;y=0;}
	else{Extended_gcd(b,a%b);int t=x;x=y;y=t-(a/b)*y;}
} 
int C(int a,int b){
	if(b>a)return 0;b=(ff[a-b]*ff[b])%mod;a=ff[a];
	int c=gcd(a,b);a/=c;b/=c;Extended_gcd(b,M);
	x=(x+mod)%mod;x=(x*a)%mod;return x;
}
int Combination(int n, int m){
	int ans=1;int a,b;while(m||n){a=n%mod;b=m%mod;n/=mod;
	m/=mod;ans=(ans*C(a,b))%mod;}return ans;
}
int A(int n,int m){return (Combination(n,m)*ff[m])%mod;}
 
int main()
{
	int i,m,n;

	
	ff[0]=1;
	for(int i=1; i<=M; i++) //预计算n!
		ff[i]=(ff[i-1]*i)%mod;

	while(~scanf("%d%d",&n, &m))
	{
		printf("%d\n",Combination(n,m));
	}
	return 0;
}
