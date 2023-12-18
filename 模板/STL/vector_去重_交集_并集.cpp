/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;

//去重
vector<int> vector_unique(vector<int>v ){
	sort(v.begin(),v.end());
	auto v_it = unique(v.begin(),v.end());
	if(v_it != v.end())
		v.erase(v_it,v.end());
	return v;
}
//两个vector求并集
vector<int> vector_set_union(vector<int>v1 ,vector<int>v2){
	vector<int>v;
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v));
	return v;
}
//两个vector求交集
vector<int> vector_set_intersection(vector<int>v1 ,vector<int>v2){
	vector<int>v;
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v));
	return v;
}
//判断vector的某一元素是否存在
bool is_element_in_vector(vector<int>v,int element){
    // vector<int>::iterator it;
    auto it=find(v.begin(),v.end(),element);
    if (it!=v.end()){
        return true;
    }
    else{
        return false;
    }
}

void Erase()
{
	vector<int>v;
	v.push_back(1);	v.push_back(2);v.push_back(3);
	//直接引用
	v.back()-=1;
	//删除最后一个元素
	v.erase(v.end()-1,v.end());
	//删除第一个元素
	v.erase(v.begin(),v.begin()+1);
	for(auto i:v)
		cout<<i<<" ";cout<<endl;
	//sum
	int sum=accumulate(v.begin(),v.end(),0);
	// cout<<sum<<endl;
	string str= accumulate(
		next(v.begin()),
		v.end(),
		to_string(v[0]),
		[](string a,int b){
			return a+'-'+to_string(b);
		}
	);
	cout<<str<<endl;
	int MA = *max_element(v.begin(),v.end());//取值
	int MA_fl = max_element(v.begin(),v.end())-v.begin();//取下标

	int MI = *min_element(v.begin(),v.end());//取值
	int MI_fk = min_element(v.begin(),v.end())-v.begin();//取下标
}

void solve()
{
	vector<int>a,b;
	a.push_back(1);
	a.push_back(2);
	a.push_back(2);
	a.push_back(1);
	b.push_back(3);
	b.push_back(2);
	b.push_back(2);

	vector<int>c=vector_set_intersection(a,b);
	for(auto i:c)
		cout<<i<<" ";
	cout<<endl;
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