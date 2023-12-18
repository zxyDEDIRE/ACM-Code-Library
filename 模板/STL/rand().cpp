#include<algorithm>
#include<iostream>
#include<vector>
#include<numeric>
#include<math.h>
#include<queue>
#include<iomanip>

#include<bits/stdc++.h>
using namespace std;
using ll=long long ;


void solve()
{

	//自定义开栈
	int size(512<<20); // 512M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size)); // YOUR CODE


	srand(time(0));

	for(int i=1;i<=100;i++)
	cout<<rand()<<endl;
}
void T()
{
	clock_t start, finish;
	start = clock();
	/*******代码*******/
	/****************/
	finish = clock();
	cout << "the time cost is" <<\
	double(finish - start) / CLOCKS_PER_SEC;
}
signed main(){
	// solve();
	T();
	// cout << fixed << setprecision(2) <<ans<<"\n";
}