#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int dpp[105][100005] , coin[105] , n;

/// minimum number of coins needed

int call(int idx , int rem)
{
    if(rem < 0) return MAX;
    if(rem == 0) return 0;
    if(idx > n) return MAX;
    if(dpp[idx][rem] != -1) return dpp[idx][rem];
    return dpp[idx][rem] = min(call(idx+1,rem) , call(idx+1,rem - coin[idx]) + 1);
}

int main()
{
    fastio;
    int val;
    cin>>n>>val;
    for(int i = 1 ; i<=n ; i++) cin>>coin[i];
    memset(dpp,-1,sizeof dpp);
    int ans = call(1,val);
    if(ans >= MAX) ans = -1;
    cout<<ans<<endl;
    return 0;
}
