#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
using hash_map=gp_hash_table<string, int>;


hash_map a;
int main()
{
    a["sdf"]=1;
    a["q"]=2;
    for(auto x:a)
        cout<<x.first<<" "<<x.second<<endl;
}