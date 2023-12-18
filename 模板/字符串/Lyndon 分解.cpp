#include<bits/stdc++.h>
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
/*
将S分成若干个部分S=S1S2S3..Sm 每个串都是 Lyndon Word
一个字符串 s 是一个 Lyndon Word 表示 s 是其所有后缀中的最小者。
*/
vector<string> duval(string const &s) {
	int n = s.size(), i = 0;
	vector<string> fac;
	while (i < n) {
		int j = i + 1, k = i;
		while (j < n && s[k] <= s[j]) {
			if (s[k] < s[j]) k = i;
			else k++;
			j++;
		}
		while (i <= k) {
			fac.push_back(s.substr(i, j - k));
			i += j - k;
		}
	}
	return fac;
}
// duval_algorithm
vector<int> duval2(string const &s) {
	int n = s.size(), i = 0;
	vector<int> fac;
	while (i < n) {
		int j = i + 1, k = i;
		while (j < n && s[k] <= s[j]) {
			if (s[k] < s[j])k = i;
			else k++;
			j++;
		}
		while (i <= k) {
			i += j - k;
			fac.push_back(i);
		}
	}
	return fac;
}
void solve()
{
	string s;
	cin >> s;
	auto v = duval2(s);

	for (auto i : v) {
		cout << i << " ";
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