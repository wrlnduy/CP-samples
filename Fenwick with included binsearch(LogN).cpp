class Fenwick{
private:
    int N, logn;
    vector<int> f;

    void update(int i, int val){
        for(; i<=N; i += i & -i)
            f[i] += val;
    }

    int get(int i){
        int cnt = 0;
        for(; i>0; i -= i & -i)
            cnt += f[i];
        return cnt;
    }

    int l_b(int sum){
        int ans = 0;
        for(int i = logn; i>=0; i--){
            if(ans + pw(i) < N && f[i] < sum){
                sum-=f[i];
                ans += pw(i);
            }
        }
        return ans + 1;
    }
public:
    Fenwick(int n){
        N = n+1;
        logn = __lg(N);
        f.resize(N);
    }

    void upd(int pos, int val){
        update(pos, val);
    }

    int get(int i){
        return get(i);
    }

    int get(int l, int r){
        return get(r) - get(l-1);
    }

    int lower_bound(int sum){
        return l_b(sum);
    }
}
