/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
int ksm(int b,int p,int mod){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
int sumq(int q,int n,int p)
{
	if(n==1)return 1;
	if(n%2==0)return ((1+ksm(q,n/2,p))*sumq(q,n/2,p)%p)%p;
	else return (1+q*sumq(q,n-1,p))%p;
}
// q^0 + q^1 + q^2 +q^(n-1)
void solve()
{
	int q,n,p;
	cin >> q >> n >> p;
	cout << sumq(q,n,p) % p << endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;c --)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}