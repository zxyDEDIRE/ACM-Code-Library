// #include <bits/extc++.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Tree;
Tree tr;


// 求平衡树内排名为k的值是多少
template<typename T>
T getval(int k)
{
	auto it=tr.find_by_order(k-1);
	if(it!=tr.end())
		return *it;
	else
		return -1;
}


template<typename T>
int getRank(T x)
{
	return  tr.order_of_key(x)+1;
}


void test()
{
	tr.insert(10);
	tr.insert(20);
	cout<<getval<int>(1)<<endl;
	cout<<getval<int>(2)<<endl;



	cout<<endl;
	cout<<getRank<int>(11)<<endl;
	cout<<getRank<int>(21)<<endl;
}

namespace A{
	using pii=pair<int,int>;
tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> tr;
// pii //存储的类型
// null_type //无映射(低版本g++为null_mapped_type)
// less<pii> //从小到大排序
// rb_tree_tag //红黑树
// tree_order_statistics_node_update //更新方式 
// tr.insert(mp(x,y)); //插入;
// tr.erase(mp(x,y)); //删除;
// tr.order_of_key(pii(x,y)); //求排名 
// tr.find_by_order(x); //找k小值，返回迭代器 
// tr.join(b); //将b并入tr，前提是两棵树类型一样且没有重复元素 
// tr.split(v,b); //分裂，key小于等于v的元素属于tr，其余的属于b
// tr.lower_bound(x); //返回第一个大于等于x的元素的迭代器
// tr.upper_bound(x); //返回第一个大于x的元素的迭代器
// //以上所有操作的时间复杂度均为O(logn) 
}
int main()
{
	test();
}