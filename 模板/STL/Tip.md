## cout精度
## 加 inline

c++17用cin
c++20用scanf

## 反转区间（1~x),(x+1~n) q次

>X=0,Y=0;
>	for(int i=1;i<=q;i++)
>	{
>		int x,y;
>		cin>>x>>y;![]()
>		X=(x-1-X+n)%n;
>		Y=(y-1-Y+m)%m;
>	}
>	for(int i=0;i<n;i++)
>	{
>		for(int j=0;j<m;j++)
>		{
>			int x=i,y=j;
>			if(q&1)
>			{
>				x=(X+n-x)%n;
>				y=(Y+m-y)%m;
>				ans[x][y]=mp[i][j];
>			}
>			else
>			{
>				x=(X+x+n)%n;
>				y=(Y+y+m)%m;
>				ans[x][y]=mp[i][j];
>			}
>		}
>	}

$\begin{split}
f(n)  &= \sum_{i=1}^{n} \sum_{h=1}^{n} \lfloor \frac{i}{j} \rfloor   \\
 &= \frac{k^{2}(k+1)^{2}}{4}-(n+1)K^{2}+\sum_{i=1}^{k}t_{i}(2n-2-i(1+t_{i}))
\end{split}$
