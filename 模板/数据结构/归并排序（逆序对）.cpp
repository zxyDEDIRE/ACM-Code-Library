#include<bits/stdc++.h>
#define int long long
using ll=long long;
using namespace std;
const int maxn=1e6;
int p[maxn];
int n;
int merge_sort(int p[],int l,int r)
{
	if(l>=r)return 0;
	int t=0;
	int mid=l+r>>1;
	t=merge_sort(p,l,mid)+merge_sort(p,mid+1,r);
	int temp[r-l+1];
	int k=0,i=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(p[i]<=p[j])temp[k++]=p[i++];
		else
		{
			t+=mid-i+1;
			temp[k++]=p[j++];
		}
	}
	while(i<=mid)temp[k++]=p[i++];
	while(j<=r)temp[k++]=p[j++];
	for(int i=l,j=0;i<=r;i++,j++)p[i]=temp[j];
	return t;
}
void doit()
{
	int n;
	vector<int>p(n+1,0);
	auto mg_sort = [&](auto mg_sort,int l,int r)->ll{
		if(l>=r)return 0;
		int mid=(l+r)>>1;
		ll t = mg_sort(mg_sort,l,mid)+mg_sort(mg_sort,mid+1,r);
		vector<int>temp;
		int i=l,j=mid+1;
		while(i<=mid&&j<=r)
		{
			if(p[i]<=p[j])temp.push_back(p[i++]);
			else t+=mid-i+1,temp.push_back(p[j++]);
		}
		while(i<=mid)temp.push_back(p[i++]);
		while(j<=r)temp.push_back(p[j++]);
		for(int i=l,j=0;i<=r;i++,j++)
			p[i]=temp[j];
		return t;
	};
	mg_sort(mg_sort,1,n);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];
	int res=merge_sort(p,1,n);
	cout<<res;
}
