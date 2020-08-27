#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e6 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int fac[N];

int fun(int n)
{
    if(n < 3) return 0;
    int ans = fun(n-1)*2;  /// if we put 1 in index 1 or n
    if(ans >= MOD) ans -= MOD;
    ans += 1LL*fac[n-1]*(n-2)%MOD;  /// if we put 1 in any index except 1 and n
    if(ans >= MOD) ans -= MOD;
    return ans;
}

int main()
{
    fastio;
    int n;
    cin>>n;
    fac[0] = 1;
    for(int i = 1 ; i<=n ; i++) fac[i] = 1LL*i*fac[i-1]%MOD;
    cout<<fun(n)<<endl;
    return 0;
}
