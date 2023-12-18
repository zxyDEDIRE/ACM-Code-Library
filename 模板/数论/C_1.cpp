#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int M = 2e5+10;
int ff[M+5];  //打表，记录n!，避免重复计算
 
//求最大公因数
int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
//解线性同余方程，扩展欧几里德定理
int x,y;
void Extended_gcd(int a,int b){
    if(b==0){x=1;y=0;}
    else{Extended_gcd(b,a%b);long t=x;x=y;y=t-(a/b)*y;}
}
//计算不大的C(n,m)
int C(int a,int b){
    if(b>a)return 0;b=(ff[a-b]%mod*ff[b])%mod;a=ff[a];
    int c=gcd(a,b);a/=c;b/=c;Extended_gcd(b,M);x=(x+mod)%mod;
    x=(x*a)%mod;return x;
}
//Lucas定理
int Combination(int n, int m)
{
    int ans=1;int a,b;
    while(m||n){a=n%mod;b=m%mod;n/=mod;m/=mod;
        ans=(ans*C(a,b))%mod;}
    return ans;
}
int A(int n,int m){return (Combination(n,m)*ff[m])%mod;}
 
signed main()
{
    int i,m,n;
    ff[0]=1;
    for(int i=1; i<=M; i++) //预计算n!
        ff[i]=(ff[i-1]*i)%mod;
    while(~scanf("%lld%lld",&n, &m))
    {
        printf("%lld\n",Combination(n,m));
    }
    return 0;
}
