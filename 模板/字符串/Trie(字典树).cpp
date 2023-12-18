/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=3e6;
int t[maxn][70],indx;
int num[maxn];
int n,q;
void init()
{
	for(int i=0;i<=indx;i++)
	{
		num[i]=0;
		for(int j=0;j<70;j++)
			t[i][j]=0;
	}
	indx=0;
}
int get_num(char x)
{
	if(x>='A'&&x<='Z')
		return x-'A';
	else if(x>='a'&&x<='z')
		return x-'a'+26;
	else return x-'0'+52;
}
void insert(string &str)
{
	int rt=0;
	for(int i=0;i<str.size();i++)
	{
		int c=get_num(str[i]);
		if(!t[rt][c])
			t[rt][c]=++indx;
		rt=t[rt][c];
		num[rt]++;
	}
}
int query(string &str)
{
	int rt=0;
	for(int i=0;i<str.size();i++)
	{
		int c=get_num(str[i]);
		if(!t[rt][c])
			return 0;
		rt=t[rt][c];
	}
	return num[rt];
}
void solve()
{
	cin>>n>>q;
	init();

	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		insert(str);
	}
	while(q--)
	{
		string str;
		cin>>str;
		cout<<query(str)<<endl;
	}
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}