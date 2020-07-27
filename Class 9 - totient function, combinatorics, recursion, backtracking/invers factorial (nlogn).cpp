#include<bits/stdc++.h>
#define ll long long
#define MOD ((int)(1e9 + 7))

using namespace std;

ll ifac[55] , fac[55];


ll power(ll n, int p)
{
    if( p==0 ) return 1;
    ll ans = power(n,p/2);
    ans = ans*ans;
    if(p%2 == 1) ans = ans*n;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    fac[0] = 1;
    for(int i = 1 ; i<=n ; i++){
        fac[i] = fac[i-1]*i%MOD;
    }
    for(int i = 0 ; i<=n ; i++){
        ifac[i] = power(fac[i],MOD-2); /// ifac[i] = 1/i! = 1/fac[i]
    }

    return 0;
}
