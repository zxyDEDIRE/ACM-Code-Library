#include<bits/stdc++.h>
using namespace std;
#define maxn 1000050
int x[maxn],y[maxn],c[maxn],sa[maxn],rk[maxn],height[maxn],wt[30];
char s[maxn];
int mm[maxn];
int best[maxn][20];
int RMQ[maxn];
int n,m;
void putout(int x)
{
    if(!x) {putchar(48);return;}
    int l=0;
    while(x) wt[++l]=x%10,x/=10;
    while(l) putchar(wt[l--]+48);
}
void get_SA()
{
    int i,j,k;
	for (i=1;i<=n;++i) ++c[x[i]=s[i]];
	//c数组是桶 
	//x[i]是第i个元素的第一关键字 
    for (i=2;i<=m;++i) c[i]+=c[i-1];
    //做c的前缀和，我们就可以得出每个关键字最多是在第几名 
    for (i=n;i>=1;--i) sa[c[x[i]]--]=i; 
    for (k=1;k<=n;k<<=1)//log(n)轮
    {
        int num=0;
        for (i=n-k+1;i<=n;++i) y[++num]=i;
        //y[i]表示第二关键字排名为i的数，第一关键字的位置 
		//第n-k+1到第n位是没有第二关键字的 所以排名在最前面 
        for (i=1;i<=n;++i) if (sa[i]>k) y[++num]=sa[i]-k;
        //排名为i的数 在数组中是否在第k位以后
		//如果满足(sa[i]>k) 那么它可以作为别人的第二关键字，就把它的第一关键字的位置添加进y就行了
		//所以i枚举的是第二关键字的排名，第二关键字靠前的先入队 
        for (i=1;i<=m;++i) c[i]=0;
        //初始化c桶 
        for (i=1;i<=n;++i) ++c[x[i]];
        //因为上一次循环已经算出了这次的第一关键字 所以直接加就行了 
        for (i=2;i<=m;++i) c[i]+=c[i-1];//第一关键字排名为1~i的数有多少个 
        for (i=n;i>=1;--i) sa[c[x[y[i]]]--]=y[i],y[i]=0;
        //因为y的顺序是按照第二关键字的顺序来排的 
        //第二关键字靠后的，在同一个第一关键字桶中排名越靠后 
        //基数排序 
        swap(x,y);
		//这里不用想太多，因为要生成新的x时要用到旧的，就把旧的复制下来，没别的意思 
        x[sa[1]]=1;num=1;
        for (i=2;i<=n;++i)
            x[sa[i]]=(y[sa[i]]==y[sa[i-1]] && y[sa[i]+k]==y[sa[i-1]+k]) ? num : ++num;
        //因为sa[i]已经排好序了，所以可以按排名枚举，生成下一次的第一关键字 
        if (num==n) break;
        m=num;
        //这里就不用那个122了，因为都有新的编号了 
    }
    for(int i=1;i<=n;i++)
    	cout<<sa[i]<<" ";cout<<endl;
}
void get_height()
{
    int k=0;
    for (int i=1;i<=n;++i) rk[sa[i]]=i;
    for (int i=1;i<=n;++i)  
    {
        if (rk[i]==1) continue;//第一名height为0 
        if (k) --k;//h[i]>=h[i-1]+1;
        int j=sa[rk[i]-1];
        while (j+k<=n && i+k<=n && s[i+k]==s[j+k]) ++k;
        height[rk[i]]=k;//h[i]=height[rk[i]];
    }
    for(int i=1;i<=n;i++)RMQ[i]=height[i];
    for(int i=1;i<=n;i++)
    	cout<<height[i]<<" ";cout<<endl;
}

void initST(int n){
	mm[0]=-1;
	for(int i=1;i<=n;i++)
		mm[i]=((1&(i-1))==0)?mm[i-1]+1:mm[i-1];
	for(int i=1;i<=n;i++)best[i][0]=i;
	for(int i=1;i<=mm[n];i++)
	{
		for(int j=1;j+(1<<i)-1<=n;j++){
			int a=best[j][i-1];
			int b=best[j+(1<<i-1)][j];
			if(RMQ[a]<RMQ[b])best[j][i]=a;
			else best[j][i]=b;
		}
	}
}
int queryST(int a,int b){
	int t;
	t=mm[b-a+1];
	b-=(1<<t)-1;
	a=best[a][t];
	b=best[b][t];
	return RMQ[a]<RMQ[b]?a:b;
}
int lcp(int a,int b){
	a=rk[a];b=rk[b];
	if(a>b)swap(a,b);
	return height[queryST(a+1,b)];
}
void solve()
{
    cin>>s+1;
    n=strlen(s+1);m=122;
	//n表示原字符串长度，m表示字符个数，ascll('z')=122 
    get_SA();
    get_height();
    initST(n);
    cout<<lcp(1,3)<<endl;

}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
}
/*
*/