#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>

#define int long long
#define endl '\n'
#define f first
#define s second
#define p_b push_back
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

using namespace std;

template <class T>
vector<T> def;

template<class T>
class SegTree
{
    private:
        int n;
        vector<T> t;
        vector<T> lazy;
    public:
        SegTree(int a)
        {
            n = a;
            t.resize(4*n);
            lazy.resize(4*n);
        }

        void build(int tv, int tl, int tr)
        {
            if(tl == tr)
            {
                t[tv] = def<T>[tl];
                return;
            }
            int tm = (tl + tr)/2;
            build(tv*2, tl, tm);
            build(tv*2+1, tm+1, tr);
            t[tv] = t[tv*2] + t[tv*2+1];
        }

        void build()
        {
            build(1, 0, n-1);
        }

        void push(int tv, int tl, int tr)
        {
            t[tv] += lazy[tv] * (tr - tl + 1);
            if(tl != tr)
            {
                lazy[tv*2] += lazy[tv];
                lazy[tv*2+1] += lazy[tv];
            }
            lazy[tv] = 0;
        }

        void update(int tv, int tl, int tr, int l, int r, int val)
        {
            push(tv, tl, tr);
            if(l > r)
                return;
            if(l <= tl && tr <= r)
            {
                lazy[tv] += val;
                push(tv, tl, tr);
                return;
            }
            int tm = (tl + tr)/2;
            update(tv*2, tl, tm, l, min(tm, r), val);
            update(tv*2+1, tm+1, tr, max(tm+1, l), r, val);
            t[tv] = t[tv*2] + t[tv*2+1];
        }

        void update(int l, int r, int val)
        {
            update(1, 0, n-1, l, r, val);
        }

        T get(int tv, int tl, int tr, int l, int r)
        {
            push(tv, tl, tr);
            if(l > r)
                return 0;
            if(l <= tl && tr <= r)
                return t[tv];
            int tm = (tl + tr)/2;
            T left = get(tv*2, tl, tm, l, min(tm, r));
            T right = get(tv*2+1, tm+1, tr, max(tm+1, l), r);
            return left+right;
        }

        T get(int l, int r)
        {
            return get(1, 0, n-1, l, r);
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

