foo.size() 返回大小（位数）
foo.count() 返回1的个数
foo.any() 返回是否有1
foo.none() 返回是否没有1
foo.set() 全都变成1
foo.set(p) 将第p + 1位变成1
foo.set(p, x) 将第p + 1位变成x
foo.reset() 全都变成0
foo.reset(p) 将第p + 1位变成0
foo.flip() 全都取反
foo.flip(p) 将第p + 1位取反
foo.to_ulong() 返回它转换为unsigned long的结果，如果超出范围则报错
foo.to_ullong() 返回它转换为unsigned long long的结果，如果超出范围则报错
foo.to_string() 返回它转换为string的结果