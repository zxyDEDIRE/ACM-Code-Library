/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
string add(string a,string b){
	string c;
	int t=0;
	for(int i=a.size()-1,j=b.size()-1;i>=0||j>=0||t>0;i--,j--){
		if(i>=0)t+=(a[i]-'0');
		if(j>=0)t+=(b[j]-'0');
		c+=((t%10)+'0');
		t/=10;
	}
	reverse(c.begin(),c.end());
	return c;
}
string sub(string a,string b){
	string c;
	int t=0;
	for(int i=a.size()-1,j=b.size()-1;i>=0||j>=0||t>0;i--,j--){
		if(i>=0)t=(a[i]-'0')-t;
		if(j>=0)t-=(b[j]-'0');
		c+=((t+10)%10+'0');
		if(t<0)t=1;
		else t=0;
	}
	while(c.size()>1&&c.back()=='0')c.pop_back();
	reverse(c.begin(),c.end());
	return c;
};
bool cmp(string a,string b){
		if(a.size()!=b.size())return a.size()>b.size();
		for(int i=0;i<a.size();i++)
			if(a[i]!=b[i])return a[i]>b[i];
		return true;
};
string mull(string a,int b){
	string c;
	for(int i=a.size()-1,t=0;i>=0||t>0;i--){
		if(i>=0)t+=(a[i]-'0')*b;
		c+=(t%10)+'0';
		t/=10;
	}
	while(c.size()>1&&c.back()=='0')c.pop_back();
	reverse(c.begin(),c.end());
	if(c.size()==0)c="0";
	return c;
}
string div(string a,int b,int &r){
	string c;
	for(int i=0;i<a.size();i++){
		r=r*10+(a[i]-'0');
		c+=(r/b)+'0';
		r%=b;
	}
	while(c.size()>1&&c.front()=='0')c=c.substr(1);
    return c;
}
void solve()
{
	string a,b;
	int x,yu;

	// add
	cin>>a>>b;
	cout<<add(a,b);
	//sub
	cin>>a>>b;
	if(cmp(a,b))cout<<sub(a,b)<<endl;
	else cout<<"-"+sub(b,a)<<endl;

	cin>>a>>x;
	cout<<mull(a,x)<<endl;

	cin>>a>>x;
	yu=0;
	cout<<div(a,x,yu)<<"\n"<<yu<<endl;

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