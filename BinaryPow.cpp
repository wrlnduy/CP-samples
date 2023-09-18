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
#define endl '\n'
#define f first
#define s second
#define p_b push_back
#define pii pair<int,int>
#define pw(x) (1LL<<x)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

using namespace std;

int BinaryPow(int base, int pow, int Mod){
    if(pow == 1)
        return base;
    int half = BinaryPow(base, pow/2, Mod);
    if(pow % 2 == 0)
        return half * half % Mod;
    return (half * half % Mod) * base % Mod;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
