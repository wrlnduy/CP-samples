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

class Trie{
    private:
        struct trie{
            int32_t to[26], amount = 0;
            bool terminal = 0;
            trie(){
                for(int i=0; i<26; i++)
                    to[i] = 0;
            }
        };
        trie t[(int)5e6];
        int sz = 1;
    public:
        void add(string &s){
            int v = 0;
            for(int i=0; i<s.size(); i++){
                int a = s[i] - 'a';
                if(t[v].to[a]){
                    v = t[v].to[a];
                    continue;
                }
                v = t[v].to[a] = sz;
                sz++;
            }
            t[v].terminal = 1;
            t[v].amount++;
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
    #endif // LOCAL

}
