#include <ext/pb_ds/assoc_container.hpp>
#include<bits/stdc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> Tree;
Tree t;

	
template<typename T>
int getRank(T x)
{
	return t.order_of_key(x)+1;
}

template<typename T>
T getVal(int k)
{
	auto it=t.find_by_order(k-1);
	if(it!=t.end())
		return *it;
	else
		return {INF,0};
}

void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int op,x;
		cin>>op>>x;
		if(op==1) // 插入x数
		{
			t.insert({x,i});
		}
		else if(op==2) // 删除x数(若有多个相同的数，应只删除一个)
		{
			auto it=t.upper_bound({x,0});
			t.erase(it);
		}
		else if(op==3) //查询 x 数的排名(排名定义为比当前数小的数的个数 +1
		{
			int k=getRank<pii>({x,0});
			cout<<k<<endl;
		}
		else if(op==4) // 查询排名为 x 的数
		{
			auto v=getVal<pii>(x);
			cout<<v.first<<endl;
		}
		else if(op==5) // 求 x 的前驱(前驱定义为小于 x，且最大的数)
		{
			auto it=t.upper_bound({x,0});
			--it;
			auto v=*it;
			cout<<v.first<<endl;
		}
		else if(op==6) // 求 x 的后驱(前驱定义为大于 x，且最小的数)
		{
			auto v=*t.upper_bound({x,INF});
			cout<<v.first<<endl;
		}
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}