int factmod (int n, int mod) {
	int ans = 1;
	while (n > 1) {
		ans = (ans * ((n/mod) % 2 ? mod-1 : 1)) % mod;
		for (int i=2; i <= n % mod; i++)
			ans = (ans * i) % mod;
		n /= mod;
	}
	return ans % mod;
}
