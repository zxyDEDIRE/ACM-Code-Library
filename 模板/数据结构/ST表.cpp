#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cout.tie(0);
using namespace std;
const int maxn=1e5+7;
int f[maxn][30];//f[i][j]从i开始2^j长度的最大值 
int mn[maxn];//储存答案 
int p[maxn];//原数组 
int n,m;

int read(){
    int num=0;char ch;
    while((ch=getchar())<'0'||'9'<ch);
    do num=num*10+ch-48,ch=getchar();while('0'<=ch&&ch<='9');
    return num;
}
struct ST{
	int f[maxn][30];
	void init()
	{
		for(int i=1;i<=n;i++)//距离为0初始化 
			f[i][0]=p[i];
		int t=log(n)/log(2)+1;//j定位 
		for(int j=1;j<t;j++)
		{
			for(int i=1;i<=n-(1<<j)+1;i++)
			{
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
				//f[i][j-1]为f[i][j]的长为2^j-1的前半段，另一段为f[i+(1<<(j-1))][j-1] 
			}
		} 
	}
	int query(int l,int r)
	{
		int k=log2(r-l+1);
		return max(f[l][k],f[r-(1<<k)+1][k]);
	}
}st;
struct St{
int f[309][309][9][9];
void init(int m,int n){

	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			f[i][j][0][0]=mp[i][j];

	int t=log(n)/log(2)+1;//j定位 
	for(int i=0;i<=t;i++){
        for(int j=0;j<=t;j++){
            if(i==0&&j==0)
                continue;
            for(int row=1;row+(1<<i)-1<=m;row++){
                for(int col=1;col+(1<<j)-1<=n;col++){
                    if(i)f[row][col][i][j]=min(f[row][col][i-1][j],
                    	f[row+(1<<(i-1))][col][i-1][j]);
                    else f[row][col][i][j]=min(f[row][col][i][j-1],
                    	f[row][col+(1<<(j-1))][i][j-1]);
                }
            }
        }
    }
}
int query(int x1,int y1,int x2,int y2)
{
    int k1 = log(double(x2 - x1 + 1)) / log(2.0);
    int k2 = log(double(y2 - y1 + 1)) / log(2.0);
    int m1 = f[x1][y1][k1][k2];
    int m2 = f[x2 - (1<<k1) + 1][y1][k1][k2];
    int m3 = f[x1][y2 - (1<<k2) + 1][k1][k2];
    int m4 = f[x2 - (1<<k1) + 1][y2 - (1<<k2) + 1 ][k1][k2];
    int _max = min(min(m1,m2),min(m3,m4));
    return _max;
}
}sT;
int main()
{
	IOS
	n=read();m=read();
	for(int i=1;i<=n;i++)
		p[i]=read();
	clock_t start, finish;
	start = clock();
	st.init();
	while(m--)
	{
		int x,y;
		x=read();y=read();
		printf("%d\n",st.query(x,y));
	}
	finish = clock();
	 cout << "the time cost is" << double(finish - start) / CLOCKS_PER_SEC;
}