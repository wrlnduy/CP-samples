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

struct mo{
int l, r, ind;
};

int n, q, N;
vector< mo > MO;
vector< int > v;
vector< int > output;

bool MoComp(mo a, mo b){
    if(a.l / N != b.l / N)
        return a.l < b.l;
    return a.r < b.r;
}

void find_ans(){
    sort(all(MO),MoComp);
    int l = 0, r = 0, sum = v[0];
    for(int i=0; i<q; i++){
        while( MO[i].l > l ){
            sum -= v[l];
            l++;
        }
        while( MO[i].l < l ){
            l--;
            sum += v[l];
        }
        while( MO[i].r > r ){
            r++;
            sum += v[r];
        }
        while( MO[i].r < r){
            sum -= v[r];
            r--;
        }
        output[ MO[i].ind ] = sum;
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    N = sqrt(n);
    mo ForPush;
    v.resize(n);
    output.resize(q);
    for(int i=0; i<n; i++)
        cin>>v[i];
    for(int i=0; i<q; i++){
        int l, r;
        cin >> l >> r;
        l--;r--;
        ForPush.l = l;
        ForPush.r = r;
        ForPush.ind = i;
        MO.p_b(ForPush);
    }
    find_ans();
    for(int i=0; i<q; i++)
        cout << output[i] << endl;
}
