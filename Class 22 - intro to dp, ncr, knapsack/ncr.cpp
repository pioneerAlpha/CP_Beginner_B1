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

int dpp[1006][1006];

int ncr(int n , int r)
{
    if(n > r || r < 0 || n < 0) return 0;
    if(r == 0) return 1;
    if(dpp[n][r] != -1) return dpp[n][r];
    int ans = ncr(n-1,r) + ncr(n-1,r-1);
    return dpp[n][r] = ans%MOD;
}

/// state/memory : O ( n*r )

/// time: O( n*r )

int main()
{
    memset(dpp,-1,sizeof dpp);
    int q;
    cin>>q;
    while(q--){
        int n , r;
        cin>>n>>r;
        cout<<ncr(n,r)<<endl;
    }
    return 0;
}
