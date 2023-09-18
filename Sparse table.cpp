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

int n, logn;
vector< vector<int> > sparse_table;

void build(){
    for(int j=0; j < logn-1; j++)
        for(int i=0; i+(2LL<<j)<=n;i++)
             sparse_table[i][j+1] = min(sparse_table[i][j],sparse_table[i+(1LL<<j)][j]);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    logn=__lg(n)+1;
    sparse_table.resize(n,vector<int>(logn));
    for(int i=0;i<n;i++)
        cin>>sparse_table[i][0];
    build();
    int t, l, r, a;
    cin>>q;
    while(q--){
        cin >> l >> r;
        l--;r--;
        a = __lg(r-l+1);
        cout << min(sparse_table[l][a],sparse_table[r-(1LL<<a)+1][a])<<' ';
    }
}
