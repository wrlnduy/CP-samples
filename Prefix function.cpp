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

vector<int> prefix_function(const string &s){
    vector<int> p(s.size());
    for(int i = 1; i < s.size(); i++){
        int j = p[i - 1];
        while(j > 0 && s[i] != s[j]){
            j = p[j - 1];
        }
        if(s[i] == s[j]){
            j++;
        }
        p[i] = j;
    }
    return p;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
