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

mt19937 engine;

int n;

int check(vector< int > &v)
{
    int ans=0;
    vector < bool > used1( 2 * n ), used2( 2 * n );
    for(int i=0; i<n; i++)
    {
        int pos = v[i]+i;
        used1[pos] ? ans++ : used1[pos]=1;
        used2[n+i-v[i]] ? ans++ : used2[n+i-v[i]]=1;
    }

    return ans;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    engine.seed(time(0));
    //freopen("haha.in","w",stdout);
    cin>>n;
    vector< int > v(n);
    iota(all(v),0);
    shuffle(all(v),engine);

    int ans=check(v);
    int it=1e6;
    long double t=1;

    for(int i = 0; i < it && ans!=0 ; i++)
    {
        t*=0.9999;
        vector<int> upd = v;
        swap(upd[engine()%n],upd[engine()%n]);
        int cnt=check(upd);
        if(cnt<ans || exp( ( ans - cnt ) / t ) )
        {
            v=upd;
            ans=cnt;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<< (v[i] == j) ? 1 : 0;
        cout<<endl;
    }
}
