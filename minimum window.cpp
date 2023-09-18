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

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, a;
    cin>>n>>k;
    queue< int > q;
    stack< int > st1, st2;
    for(int i=0; i<k; i++)
    {
        cin>>a;
        st1.push(a);
    }
    for(int i=0; i<n-k; i++)
    {
        cin>>a;
        q.push(a);
    }
    while(q.size())
    {
        if(st2.empty())
        {
            st2.push(st1.top());
            st1.pop();
            a=1e9+7;
            while(st1.size())
            {
                st2.push( min( st1.top(), st2.top() ) );
                st1.pop();
            }
            cout<<st2.top()<<' ';
            continue;
        }
        st2.pop();
        st1.push( q.front() );
        a=min(a, st1.top());
        q.pop();
        if(st2.size())
            cout<<min(st2.top(),a)<<' ';
    }
    if(st1.size()==k)
    {
        a=1e9+7;
        while(st1.size())
        {
            a=min( a, st1.top() );
            st1.pop();
        }
        cout<<a;
    }
}
