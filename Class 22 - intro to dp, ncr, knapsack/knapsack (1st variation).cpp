#include<bits/stdc++.h>
#define ll long long
#define N ((int)3e4 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;


int vol[105] , val[105] , n;

ll dpp[105][100005];

/// n <= 100 , cap <= 10^5 , val[i] <= 10^9 , vol[i] <= 10^9

ll fun(int cur , int cap)  /// returns maximum profit from cur to n
{
    if(cap < 0) return -MAXL;
    if(cur > n) return 0;

    if(dpp[cur][cap] != -1) return dpp[cur][cap];

    ll ans = -MAXL; /// assuming there is no valid answer

    ans = max(ans , fun(cur+1,cap - vol[cur]) + val[cur]);

    ll tmp = fun(cur+1,cap);

    ans = max(ans , tmp);

    return dpp[cur][cap] = ans;

}


/// state/memory : O ( n*cap )

/// time: O( n*cap )

int main()
{
    memset(dpp,-1,sizeof dpp);
    int cap;
    cin>>n>>cap;
    for(int i = 1 ; i<=n ; i++) cin>>val[i]>>vol[i];
    ll ans = fun(1,cap);
    cout<<ans<<endl;
    return 0;
}
