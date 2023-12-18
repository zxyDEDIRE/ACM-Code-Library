#include<bits/stdc++.h>
using namespace std;
bool su(int x)
{
	if(x==1)return 0;
	if(x==2||x==3)return 1;
	if(x%6!=5&&x%6!=1)return 0;
	int tmp=sqrt(x);
	for(int i=5;i<=tmp;i+=6)
		if(x%i==0||x%(i+2)==0)
			return 0;
	return 1;
}
int main()
{
	cout<<su(1e6+7)<<endl;
	int n;
	// while(cin>>n)cout<<su(n)<<endl;;
}