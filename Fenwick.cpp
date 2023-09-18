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

class Fenwick
{
    private:
        int n;
        vector<int> f;

    public:

        Fenwick(int N)
        {
            n = N;
            f.resize(N);
        }

        void update(int i, int val)
        {
            for(; i<n; i |= i+1)
                f += val;
        }

        int get(int i)
        {
            int sum = 0;
            for(; i>=0; i = ((i&(i+1))-1))
                sum += f[i];
            return sum;
        }

        int get(int l, int r)
        {
            return get(r-1) - get(l-2);
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
