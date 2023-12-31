#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
  
#define MAX_N 30
#define INF 0x3f3f3f3f
  
int G[MAX_N][MAX_N];
int v[MAX_N];            //    v[i]代表节点i合并到的顶点
int w[MAX_N];            //    定义w(A,x) = ∑w(v[i],x)，v[i]∈A
bool visited[MAX_N];    //    用来标记是否该点加入了A集合
int squ[MAX_N];       //记录移除的节点次序
int index;//记录最小割的位置，以便分开整个图的节点
  
int stoer_wagner(int n)
{
    int min_cut = INF,r=0;
    for (int i = 0; i < n; ++i)
    {
        v[i] = i;        //    初始还未合并，都代表节点本身
    }
     
    while (n > 1)
    {
        int pre = 0;    //    pre用来表示之前加入A集合的点（在t之前一个加进去的点）
        memset(visited, 0, sizeof(visited));
        memset(w, 0, sizeof(w));
        for (int i = 1; i < n; ++i) //求出 某一轮最大生成树的最后两个节点，并且去除最后的t，将与t连接的边归并
        {
            int k = -1;
            for (int j = 1; j < n; ++j)  //    选取V-A中的w(A,x)最大的点x加入集合
            {
                if (!visited[v[j]])
                {
                    w[v[j]] += G[v[pre]][v[j]];
                    if (k == -1 || w[v[k]] < w[v[j]])
                    {
                        k = j;
                    }
                }
            }
            visited[v[k]] = true;        //    标记该点x已经加入A集合
            if (i == n - 1)                //    若|A|=|V|（所有点都加入了A），结束
            {
                const int s = v[pre], t = v[k];        //    令倒数第二个加入A的点（v[pre]）为s，最后一个加入A的点（v[k]）为t
                cout<<t<<"--->"<<s<<endl;
                squ[r++]=t;
                if(w[t]<min_cut)
                {
                    min_cut=w[t];
                    index=r;
                }
                //min_cut = min(min_cut, w[t]);        //    则s-t最小割为w(A,t)，用其更新min_cut
                for (int j = 0; j < n; ++j)            //    Contract(s, t)
                {
                    G[s][v[j]] += G[v[j]][t];
                    G[v[j]][s] += G[v[j]][t];
                }
                v[k] = v[--n];                        //    删除最后一个点（即删除t，也即将t合并到s）
            }
            // else 继续
            pre = k;
        }
    }
    return min_cut;
}
  
int main(int argc, char *argv[])
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(G, 0, sizeof(G));
        while (m--)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u][v] += w;
            G[v][u] += w;
        }
        int z=n;
        //printf("%d\n", stoer_wagner(n));
        cout<<"\r\n归并的步骤为："<<endl;
        int res=stoer_wagner(n);
        cout<<"\r\n最小割的总权值为： "<<res<<"\r\n图划分为部分A：";
        //cout<<"图划分为部分A：";
        for(int i=0;i<z;i++)
        {
            if(i==index)
                cout<<"部分B：";
            cout<<squ[i]<<"  ";
        }
    }
    return 0;
}