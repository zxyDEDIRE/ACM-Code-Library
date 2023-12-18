/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long



	ascii 可见字符:
	32~126
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e7+100;
struct ExKmp{
//result: ext[i] = LCP(S[i,lens],T)
//require: nxt[i] = LCP(T[i,lent],T)
//nxt : s  Mode_String
//ext : s  Text_String t Mode_String
	void exkmp(char *s,int lens,char *t,int lent,int *ext,int *nxt)
	{
		ext[0]=0;
		for(int i=1,p0=0,p=0;i<=lens;i++)
		{
			ext[i]=i<=p?min(nxt[i-p0+1],p-i+1):0;
			while(i+ext[i]<=lens&&ext[i]<lent&&s[i+ext[i]]==t[ext[i]+1])ext[i]++;
			if(i+ext[i]-1>=p&&i!=1)p0=i,p=i+ext[i]-1;                  //最右端
		}
	}
	void debug_ext(int *ext,int len){
		for (int i=1;i<=len;i++){
			printf("[debug] ext[%d]=%d\n",i,ext[i]);
		}
	}
	void debug_nxt(int *nxt,int len){
		for (int i=1;i<=len;i++){
			printf("[debug] nxt[%d]=%d\n",i,nxt[i]);
		}
	}
}exKMP;
char s[maxn];
char t[maxn];
int nxt[maxn];
int ext[maxn];
void solve()
{ 
	scanf("%s",t+1);
	scanf("%s",s+1);
	exKMP.exkmp(s,strlen(s+1),s,strlen(s+1),nxt,nxt);//
	exKMP.exkmp(t,strlen(t+1),s,strlen(s+1),ext,nxt);
	int ans_1=0;
	int ans_2=0;
	// exKMP.debug_nxt(nxt,strlen(s+1));
	exKMP.debug_ext(ext,strlen(t+1));

	for(int i=1;i<=strlen(s+1);i++)
		ans_1=(ans_1^i*(nxt[i]+1));
	for(int i=1;i<=strlen(t+1);i++)
		ans_2=(ans_2^i*(ext[i]+1));
	cout<<ans_1<<endl<<ans_2<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}