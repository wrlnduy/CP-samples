class MergeSortTree{
private:
    ll n;
    vector<vector<ll>> t;

    void build(ll v, ll l, ll r){
        t[v].clear();
        if(l == r){
            t[v].p_b(inp[l]);
            return;
        }
        ll m = (l + r)/2;
        build(v*2, l, m), build(v*2+1, m+1, r);
        merge(all(t[v*2]), all(t[v*2+1]), back_inserter(t[v]));
    }

    ll get(ll v, ll tl, ll tr, ll l, ll r, ll k){
        if(l > r) return 0;
        if(l <= tl && tr <= r) return upper_bound(all(t[v]), k) - t[v].begin();
        ll tm = (tl + tr)/2;
        return get(v*2, tl, tm, l, min(tm, r), k) + get(v*2+1, tm+1 ,tr, max(l, tm+1), r, k);
    }
public:
    MergeSortTree(ll n):n(n){
        t.resize(4*n+10);
    }

    void build(){build(1, 1, n);}

    ll ans(ll l, ll r, ll val){return get(1, 1, n, l, r, val);}
};
