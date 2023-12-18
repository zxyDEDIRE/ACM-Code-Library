#include<bits/stdc++.h>
using namespace std;

#define ios ios::sync_with_stdio(false);
// #define int long long
using ll=long long;
// using pii=pair<int,int>;
using pii=pair<int,int>;
const int mod=1e9+7;
const int maxn=1e6;
int a[]={0,1,2,3,4,5,6,7,8,9,10};
int b[]={10,9,8,7,6,5,4,3,2,1,0};
unordered_map<int,int>mp;
unordered_set<int>s;
multiset<int>S;
void AAFsdf(){
	unordered_map<int,int>mp;
	unordered_set<int>s;
	multiset<int>S;
	int x=floor(0.1);//xia
	int y=ceil(1.0);//shang

}

pii operator+(const pii a,const pii b){
	return {a.first+b.first,a.second+b.second};
}
void SSS()
{
	int tmp;
	s.erase(s.find(tmp));
}
void solve()
{
	int x;cin>>x;
	int fl;
	fl=lower_bound(a,a+13,x)-a;//在从小到大的序列中找出大于等于x的数的地址 
	fl=upper_bound(a,a+13,x)-a;//在从小到大的序列中找出大于x的书的地址
	
	fl=lower_bound(b,b+13,x,greater<int>() )-b;//在从大到小的序列中找出小于等于x的数的地址 
	fl=upper_bound(b,b+13,x,greater<int>() )-b;//在从小到大的序列中找出小于x的数的地址 
}
void C()
{
	int x,cnt;
	ll X;
	//数字里面的 1 的个数
	cnt=__builtin_popcount(x);
	cnt=__builtin_popcountll(X);

	//二进制表示形式中末尾0的个数
	cnt=__builtin_ctz(x);
	cnt=__builtin_ctzll(X);

	//二进制表示形式中前导0的个数
	cnt=__builtin_clz(x);
	cnt=__builtin_clzll(X);

	//二进制表示形式中1的个数的奇偶性（偶：0，奇：1）
	cnt=__builtin_parity(x);
	cnt=__builtin_parityll(X);

	//二进制表示形式中最后一个1在第几位
	cnt= __builtin_ffs(x);
	cnt= __builtin_ffsll(X);
	
	//快速开平方
	cnt=__builtin_sqrt(x);
}
void A()
{
	int p[10];	int x;
	hypot(x,x);

	string a=string(10,'9'); 
	x=stoll(a);
	a=to_string(x);


	next_permutation(p+1,p+1+9);
	prev_permutation(p+1,p+1+9);


	string _s = a.substr(1,2);
	//substr(pos,len)
}
void V()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for(auto i:v)
		cout<<i<<" ";cout<<endl;

	
	v.back()-=1;

	
	v.erase(v.end()-1,v.end());
	v.erase(v.begin(),v.begin()+1);
	for(auto i:v)
		cout<<i<<" ";cout<<endl;


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
}
void LAM()
{
	auto dfs=[&](auto self,int x,int n)->void{
		cout<<x<<endl;
		if(x==n)return ;
		self(self,x+1,n);
	};
	dfs(dfs,1,5);
}
signed main()
{
	ios
	// solve();
	// V();
	LAM();
}