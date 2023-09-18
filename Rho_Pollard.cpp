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
#include <climits>

#define int long long
#define ul unsigned int
#define endl '\n'
#define f first
#define s second
#define p_b push_back
#define tiii tuple<int, int, int>
#define pii pair<int,int>
#define pw(x) (1LL<<x)
#define m_t make_tuple
#define ff(x) get<0>(x)
#define ss(x) get<1>(x)
#define tt(x) get<2>(x)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

using namespace std;

int f(int x){return (x+31)*(x+31);}

int pollard_rho(int n){
    int x = 1, y = 1, divisor = 1;
    while(divisor == 1){
        y = f(y) % n;
        x = f(f(x)%n)%n;
        divisor = __gcd(abs(x-y), n);
    }
    return divisor;
}

main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif // LOCAL

}
