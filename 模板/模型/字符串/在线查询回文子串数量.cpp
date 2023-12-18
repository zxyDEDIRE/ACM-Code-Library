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
1：在字符串 s 的末尾添加一个字符串
2：在字符串 s 的前端添加一个字符串的 反序
3：查询字符串 s 的所有非空回文子串的数量
*/


struct PAM {
	char s[maxn];
	int ptrf, ptrb;
    int node, len[maxn + 5], fail[maxn + 5], ch[maxn + 5][26];
    int rlas, llas, dep[maxn + 5];

    PAM() { node = rlas = llas = 1, len[1] = -1, fail[0] = 1; }
    void set(int _x,int _y){
    	ptrf=_x;
    	ptrb=_y;
    }

    inline int push_front( char c ) {
        s[--ptrf] = c, c -= 'a'; int p = llas;
        for ( ; s[ptrf + len[p] + 1] != s[ptrf]; p = fail[p] );
        if ( !ch[p][c] ) {
            len[++node] = len[p] + 2; int q = fail[p];
            for ( ; s[ptrf + len[q] + 1] != s[ptrf]; q = fail[q] );
            dep[node] = dep[fail[node] = ch[q][c]] + 1, ch[p][c] = node;
        }
        llas = ch[p][c];
        if ( len[llas] == ptrb - ptrf + 1 ) rlas = llas;
        return dep[llas];
    }

    inline int push_back( char c ) {
        s[++ptrb] = c, c -= 'a'; int p = rlas;
        for ( ; s[ptrb - len[p] - 1] != s[ptrb]; p = fail[p] );
        if ( !ch[p][c] ) {
            len[++node] = len[p] + 2; int q = fail[p];
            for ( ; s[ptrb - len[q] - 1] != s[ptrb]; q = fail[q] );
            dep[node] = dep[fail[node] = ch[q][c]] + 1, ch[p][c] = node;
        }
        rlas = ch[p][c];
        if ( len[rlas] == ptrb - ptrf + 1 ) llas = rlas;
        return dep[rlas];
    }
}pam;
string str;
ll ans=0;
int q;
void solve()
{
	pam.set(3e5+1,3e5);
	cin>>str;
	for(auto i:str)
		ans+=pam.push_back(i);
	cin>>q;
	while(q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			cin>>str;
			for(auto i:str)
				ans+=pam.push_back(i);
		}
		else if(op==2)
		{
			cin>>str;
			for(auto i:str)
				ans+=pam.push_front(i);
		}
		else cout<<ans<<endl;
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