#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif // LOCAL

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("tune=native")

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
#include <iterator>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <climits>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define f first
#define s second
#define p_b push_back
#define pw(x) (1LL<<((int)x))
#define sz(x) (int)x.size()
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define fbo find_by_order
#define ook order_of_key
#define YES cout<<"YES\n"
#define NO cout << "NO\n"
#define yes cout<<"yes\n"
#define no cout << "no\n"

typedef long long ll;
typedef unsigned long long ul;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 1e5, mod = 1e9+7;

template<class T> inline T sqr(T x){return x*x;}
template<class T> inline void amin(T &a, T b){a = a < b ? a : b;}
template<class T> inline void amax(T &a, T b){a = a > b ? a : b;}
template<class T> inline void smod(T &a, T b){a = a + b >= mod ? a + b - mod : a + b;}
template<class T> inline void dmod(T &a, T b){a = a - b >= 0 ? a - b : a - b + mod;}

mt19937 rnd(time(0));

main(){
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif // LOCAL

    #ifdef LOCAL
        cout << "\n\n===\nTime : " << (long double)clock() / CLOCKS_PER_SEC << '\n';
    #endif // LOCAL
}
