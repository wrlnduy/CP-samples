#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <stack>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <climits>

#define int long long
#define endl '\n'
#define f first
#define s second
#define p_b push_back
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

using namespace std;

class Hash
{
    private:
        int n;
        int mod = 1e9+7;
        vector<pii> pow;
        vector<pii> h;
    public:
        void build(string s)
        {
            n = s.size();
            pow.resize(n);
            h.resize(n);
            pow[0] = {1, 1};
            for(int i = 0; i < n; i++)
            {
                if(i)
                {
                    h[i] = h[i-1];
                    pow[i] = pow[i-1];
                }
                pow[i].f = pow[i].f * 47 % mod;
                pow[i].s = pow[i].s * 53 % mod;
                h[i].f = (h[i].f + ((s[i]-'A'+1) * pow[i].f % mod)) % mod;
                h[i].s = (h[i].s + ((s[i]-'A'+1) * pow[i].s % mod)) % mod;
            }
        }

        pii get_hash(int l, int r)
        {
            pii H = h[r];
            if(l)
            {
                H.f = (H.f - h[l-1].f + mod) % mod;
                H.s = (H.s - h[l-1].s + mod) % mod;
            }
            H.f = H.f * pow[n-r-1].f % mod;
            H.s = H.s * pow[n-r-1].s % mod;
            return H;
        }

        bool compare(int l1, int r1, int l2, int r2)
        {
            return get_hash(l1, r1) == get_hash(l2, r2);
        }
};

main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
}

