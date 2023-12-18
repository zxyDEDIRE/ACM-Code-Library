#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6+100;

int ksc(int x, int y, int mod){    return (x * y - (int)((long double)x / mod * y) * mod + mod) % mod;}
ll prime[maxn], id1[maxn], id2[maxn], flag[maxn], ncnt, m;
ll g[maxn], sum[maxn], a[maxn], T, n;
inline int ID(ll x){    return x <= T ? id1[x] : id2[n / x];}
inline ll calc(ll x){    return x * (x + 1) / 2 - 1;}
inline ll f(ll x){    return x;}
inline void init()
{
    T = sqrt(n + 0.5);
    for (int i = 2; i <= T; i++){
        if (!flag[i])
            prime[++ncnt] = i, sum[ncnt] = sum[ncnt - 1] + i;
        for (int j = 1; j <= ncnt && i * prime[j] <= T; j++){
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    for (ll l = 1; l <= n; l = n / (n / l) + 1){
        a[++m] = n / l;
        if (a[m] <= T)
            id1[a[m]] = m;
        else
            id2[n / a[m]] = m;
        g[m] = calc(a[m]);
    }
    for (int i = 1; i <= ncnt; i++)
        for (int j = 1; j <= m && (ll)prime[i] * prime[i] <= a[j]; j++)
            g[j] = g[j] - (ll)prime[i] * (g[ID(a[j] / prime[i])] - sum[i - 1]);
}
inline void clear()
{
	ncnt = m = 0;
}
// 1 - x 之间的质数
inline ll solve(ll x)
{
    if (x <= 1)
        return x;
    return n = x, init(), g[ID(n)];
}