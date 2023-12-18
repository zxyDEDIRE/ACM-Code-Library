ll division_block(ll n){
	ll res = 0;
	for(ll l = 1, r; l <= n; l = r + 1){
		r = n / (n / l);
		// cout<<r<<endl;
		res += n / l * (r - l + 1);
	}
	return res;
}