/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int mod=1e9+7;
const int maxn=1e6;
const int N=105;
ll  n,power;
struct matrix{
    ll a[N][N];
    matrix(){
        memset(a,0,sizeof(a));
    }
    void build()
    {
        for(int i=1;i<=n;i++)
            a[i][i]=1;
    }
}a;
matrix operator*(const matrix&x,const matrix&y)
{
    matrix z;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
    return z;
}
matrix pow(matrix b,int p)
{
    matrix r;r.build();
    while(p)
    {
        if(p&1)r=r*b;
        b=b*b;
        p>>=1;
    }
    return r;
}
void solve()
{
    cin>>n>>power;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a.a[i][j];
    matrix ans=pow(a,power);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<ans.a[i][j]<<" ";
        cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}
/*

*/