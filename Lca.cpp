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

int n, l, timer = 0, r;
vector<int> tin, tout;
vector<vector<int>> g, p;

void dfs(int v = 1, int anc = 1){
    tin[v] = timer++;
    p[v][0] = anc;
    for(int i = 1; i <= l; i++)
        p[v][i] = p[p[v][i - 1]][i - 1];
    for(int i = 0; i < g[v].size(); i++)
    {
        int to=g[v][i];
        if(anc!=to)
            dfs(to, v);
    }
    tout[v] = timer++;
}

bool upper(int a, int b){
    return tin[a]<=tin[b] && tout[a]>=tout[b];
}

int lca(int a, int b){
    if(upper(a,b))return a;
    if(upper(b,a))return b;
    for(int i=l;i>=0;i--)
        if(!upper(p[a][i], b))
            a=p[a][i];
    return p[a][0];
}

void build(){
    l = __lg(n)+1;
    g.resize(n+1);
    p.resize(n+1, vector<int>(l+1));
    tin.resize(n+1);
    tout.resize(n+1);
    dfs();
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r;
    for(int i=0;i<r;i++){
        int v1,v2;
        cin >> v1 >> v2;
        g[v1].p_b(v2);
        g[v2].p_b(v1);
    }
    build();
    int q;
    cin >> q;
    while(m--){
        int l, r;
        cin >> l >> r;
        cout << lca(l, r) << endl;
    }
}
