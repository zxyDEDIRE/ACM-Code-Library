/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
// n位格雷码
vector<int> grayCode(int n) {
	int count = 1 << n;
	vector<int> res(count,0);
	for(int i = 1 ; i < count; i ++)
	{
		int bin = i,cur = bin >> (n - 1);
		for(int k = n - 1;k > 0;k --)
			cur = (cur << 1) + (((bin >> k) & 1) ^ ((bin >>(k - 1)) & 1));
		res[i] = cur;
	}
	return res;
}
//递归实现n位格雷码
vector<string> gray_code(int n){
	if(n==1)return {"0","1"};
	else{
		vector<string>v,v1;
		v1=gray_code(n-1);
		for(int i=0;i<v1.size();i++)
			v.push_back("0"+v1[i]);
		for(int i=(v1.size()-1);i>-1;i--)
			v.push_back("1"+v1[i]);
		return v;
	}
}
void solve()
{
	int n;
	cin>>n;
	vector<string>v=gray_code(n);
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<endl;
	cout<<v.size()<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}