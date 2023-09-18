int n, fact[N];

int binpow(int b, int p){
    if(!p) return 1;
    int h = binpow(b, p>>1);
    return p&1
    ? h*h%mod*b%mod
    : h*h%mod;
}

void precalc(int k){
    fact[0] = 1;
    for(int i=1; i<=k; i++)
        fact[i] = fact[i-1] * i % mod;
}

int C(int m, int k){
    return fact[m] * binpow(fact[k], mod-2) % mod * binpow(fact[m-k], mod-2) % mod;
}

int catalan(int k){
    return binpow(k+1, mod-2) * C(2*k, k) % mod;
}
