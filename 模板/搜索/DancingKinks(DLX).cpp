/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
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
const int MaxM=450010;
const int MaxP=510;
struct DLX{
	struct Dancing_Links_Node{
		int U,D,L,R;
		int Row,Col;
	}T[MaxM];
	// int U[MaxM],D[MaxM],L[MaxM],R[MaxM];
	int First[MaxP];
	int Size[MaxM];
	int tot=0;
	int ans;
	void Init_Node(int n,int num){	//初始化head和列元素,将其上下左右指针指好,行数和列数可不用初始化
		for(int i=0;i<=num;i++){
			T[i].L=i-1;T[i].R=i+1;		//左-1
			T[i].U=i;T[i].D=i;		//上下指向自己
			Size[i]=0;		//列个数清空
		}
		T[0].L=num;			//让head的左边指向最后一个的列元素
		T[num].R=0;			//让最后一个的列元素的右边指向head
		tot=num;			//更新结点个数
		for(int i=1;i<=n;i++)
			First[i]=-1;
	}
	void Insert_Node(int x,int y){		//插入新节点(按顺序放)
		T[++tot].Row=x;		//更新行数
		T[tot].Col=y;		//更新列数
		T[tot].D=T[y].D;		//更新当前元素的指向下面
		T[T[y].D].U=tot;		//之前的最后一个元素指向最后
		T[tot].U=y;
		T[y].D=tot;
		if(First[x]<0){			//表示该结点是其所在行的第一个元素
			T[tot].L=tot;		//自己指向自己
			T[tot].R=tot;		//自己指向自己
			First[x]=tot;		//更新当前行的第一个元素
		}
		else{		//表示该结点不是其所在行的第一个元素
			T[tot].R=T[First[x]].R;
			T[T[First[x]].R].L=tot;
			T[tot].L=First[x];
			T[First[x]].R=tot;
		}
		Size[y]++;		//当前列元素+1
	}
	void Remove_Link(int y){		//删除列元素所在的列链 及 其中元素所对应行
		T[T[y].R].L=T[y].L;
		T[T[y].L].R=T[y].R;
		for(int i=T[y].D;i!=y;i=T[i].D){		//枚举列链中的元素
			for(int j=T[i].R;j!=i;j=T[j].R){		//枚举列链中元素所对应行链中元素并删除
				T[T[j].D].U=T[j].U;
				T[T[j].U].D=T[j].D;
				Size[T[j].Col]--;		//当前列的元素-1
			}
		}
	}
	void Resume_Link(int y){		//恢复列元素所在列链 及 其中元素所对应行
		for(int i=T[y].U;i!=y;i=T[i].U){		//枚举列链中的元素
			for(int j=T[i].L;j!=i;j=T[j].L){		//枚举列链中元素所对应行链中元素并恢复
				T[T[j].U].D=j;
				T[T[j].D].U=j;
				Size[T[j].Col]++;//当前列的元素+1
			}
		}
		T[T[y].L].R=y;
		T[T[y].R].L=y;
	}
	void dance(int depth){		//depth表示答案的个数(所搜的层数)
		if(depth>=ans)		//剪枝
			return ;
		if(T[0].R==0){		//如果head.right=head,说明有解,输出答案
			ans=depth;
			return ;
		}
		int y=T[0].R;//取列元素y=head.right
		for(int i=T[0].R;i!=0;i=T[i].R)//剪枝(减少搜索树的分叉)
			if(Size[i]<Size[y])
				y=i;
		Remove_Link(y);//删除列链
		for(int i=T[y].D;i!=y;i=T[i].D){
			for(int j=T[i].R;j!=i;j=T[j].R)		//删除选择行链元素所在列链
				Remove_Link(T[j].Col);
			dance(depth+1);
			for(int j=T[i].L;j!=i;j=T[j].L)		//恢复选择行链元素所在列链
				Resume_Link(T[j].Col);
		}
		Resume_Link(y);		//恢复列链
	}
}dlx;
int n,m,p;
void solve()
{
	cin>>n>>m>>p;
	dlx.Init_Node(p,n*m);
	for(int i=1;i<=p;i++)
	{
		int x,y,_x,_y;
		cin>>x>>y>>_x>>_y;
		for(int I=x+1;I<=_x;I++)
			for(int J=y+1;J<=_y;J++)
				dlx.Insert_Node(i,(I-1)*m+J);
	}
	dlx.ans=inf;
	dlx.dance(0);
	if(dlx.ans==inf)cout<<-1<<endl;
	else cout<<dlx.ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}