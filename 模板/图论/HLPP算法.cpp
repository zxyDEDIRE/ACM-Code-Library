#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <queue>
#include <cmath>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
struct Edge {
    int v, r;
    long long f;
};
struct _Flow {
    vector<long long> h, gap, e;
    long long ht, tag;
    vector<list<long long>> lst;
    vector<vector<Edge>> g;
    void init(int pcnt) {
        g.clear();
        g.resize(pcnt + 1);
        ht = tag = 0;
    }
    void add(int x,int y,long long w){
        g[x].push_back({y,(int)g[y].size(),w});
    }
    void Add(int x, int y, long long w) {
        g[x].push_back({y, (int)g[y].size(), w});
        g[y].push_back({x, (int)g[x].size()-1, 0});
    }
    void update(int p, long long th) {
        tag ++;
        if (h[p] < INF)gap[h[p]] --;
        h[p] = th;
        if (th >= INF)
            return;
        ht = th;
        gap[th] ++;
        if (e[p])lst[th].push_back(p);
    }
    void bfs(int s, int t, int pcnt) {
        h.clear();
        gap.clear();
        queue<int> q;
        h.resize(pcnt + 2);
        gap.resize(pcnt + 2);
        lst.clear();
        lst.resize(pcnt + 2);
        fill(h.begin(), h.end(), INF);
        h[s] = pcnt;
        e[s] = INF;
        h[t] = tag = 0;
        q.push(t);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &e : g[u]) {
                int v = e.v;
                if (h[v] == INF && g[v][e.r].f)
                    update(v, h[u] + 1), q.push(v);
            }
            ht = h[u];
        }
    }
    void pushflow(int u, Edge &cur) {
        int v = cur.v;
        if (!e[v])
            lst[h[v]].push_back(v);
        long long flow = min(cur.f, e[u]);
        e[u] -= flow, e[v] += flow;
        cur.f -= flow;
        g[v][cur.r].f += flow;
    }
    void push(int u, int pcnt) {
        long long th = INF;
        for (auto &cur : g[u]) {
            int v = cur.v;
            if (cur.f) {
                if (h[v] + 1 == h[u]) {
                    pushflow(u, cur);
                    if (e[u] <= 0)
                        return;
                } else
                    th = min(th, h[v] + 1);
            }
        }
        if (h[u] < INF && gap[h[u]] > 1)
            update(u, th);
        else {
            for (int i = 1; i <= pcnt; i++) {
                if (h[i] > h[u])
                    update(i, INF);
            }
            update(u, INF);
        }
    }
    long long maxFlow(int s, int t, int pcnt) {
        long long lim = pcnt * ceil(sqrt(pcnt));
        e.clear();
        e.resize(pcnt + 1);
        bfs(s, t, pcnt);
        for (auto &cur : g[s])
            pushflow(s, cur);
        for (; ~ht; ht --) {
            while (!lst[ht].empty()) {
                int u = lst[ht].back();
                lst[ht].pop_back();
                push(u, pcnt);
                if (tag > lim)
                    bfs(s, t, pcnt);
            }
        }
        return e[t];
    }
} f;
void solve(){
    int n, m, s, t;
    cin>>n>>m>>s>>t;
    f.init(n);
    for (int i = 1; i <= m; i ++) {
        int x, y, z;
        cin>>x>>y>>z;
        f.Add(x, y, z);
    }
    cout<<f.maxFlow(s,t,n)<<"\n";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}