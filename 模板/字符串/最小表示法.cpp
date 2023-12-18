/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int INF=1e9+7;
const int maxn=1e6;

int Get_Min(int *p,int n)
{
	int i=0,j=1,k=0;
	while(i<n&&j<n&&k<n)
	{
		if(p[(i+k)%n]==p[(j+k)%n])k++;
		else
		{
			/*>最小   <最大*/
			if(p[(i+k)%n]>p[(j+k)%n])i=i+k+1;
			else j=j+k+1;
			if(i==j)i++;
			k=0;
		}
	}
	return min(i,j);
}
string str;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>p[i];
	int tmp=Get_Min(p,n);
	// cout<<tmp<<endl;
	for(int i=0;i<n;i++)
		cout<<p[(i+tmp)%n]<<" ";
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