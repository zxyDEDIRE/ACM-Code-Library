#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll qmi(ll a, ll k)//快速幂模板
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (ll)res * a % mod;
        a = (ll)a * a % mod;
        k >>= 1;
    }
    return res;
}
ll c(ll a, ll b)//通过定理求组合数C(a, b)
{
    ll res = 1;
    for (int i = 1, j = a; i <= b; i ++, j -- )
    {
        res = (ll)res * j % mod;
        res = (ll)res * ksm(i, mod - 2) % mod;
    }
    return res;
}
ll C(ll a, ll b)
{
    if (a < mod && b < mod) return c(a, b);
    return (ll)c(a % mod, b % mod)*C(a / mod, b / mod) % mod;
}