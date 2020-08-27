#include<bits/stdc++.h>
#define ll long long
#define N ((int)6e4 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int dpp[102][N]; /// rating can increase up to 60000

vector < pair < int , int > > neg;

int call(int idx , int rem) /// this is just knapsack
{
    if(rem < 0) return -MAX;
    if(idx >= neg.size()) return 0;
    if(dpp[idx][rem] != -1) return dpp[idx][rem];
    int ans = call(idx+1,rem);
    if(rem + neg[idx].second >= neg[idx].first) ans = max( ans , call(idx+1 , rem + neg[idx].second ) + 1);
    return dpp[idx][rem] = ans;
}

int main()
{
    fastio;
    int n , r;
    cin>>n>>r;
    vector < pair < int , int > > vec;
    for(int i = 1 ; i <= n ; i++){
        int a , b;
        cin>>a>>b;
        if(b >= 0) vec.push_back({a,b});
        else neg.push_back({a+b,b});  /// here c = a + b
    }
    sort(vec.begin(),vec.end());
    int ans = 0;
    for(auto p:vec){
        if(r >= p.first){
            r += p.second;
            ans++;
        }
    }

    sort(neg.begin(),neg.end());
    reverse(neg.begin(),neg.end());

//    cout<<r<<endl;
//    for(auto p:neg) cout<<p.first - p.second <<" "<<p.second<<endl;
    memset(dpp,-1,sizeof dpp);
    cout<<call(0,r) + ans<<endl;
    return 0;
}
