#include<bits/stdc++.h>
#define MOD ((int)1e9 + 7)
#define N ((int)2e6 + 7)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long


using namespace std;



/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/



int fac[N] , ifac[N];

int power(int n , int p)
{
    if( p == 0 ) return 1;

    int ans = power(n,p>>1);
    ans = 1LL*ans*ans%MOD;
    if(p&1) ans = 1LL*ans*n%MOD;
    return ans;
}


int main()
{
    //fastio;
    fac[0] = 1;
    for(int i = 1 ; i<N ; i++) fac[i] = 1LL*fac[i-1]*i%MOD;
    ifac[N-1] = power(fac[N-1],MOD-2);
    for(int i = N-2 ; i>=0 ; i--) ifac[i] = 1LL*(i+1)*ifac[i+1]%MOD;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int n , k;
        cin>>n>>k;
        int ans = 1LL*fac[n+k-1]*ifac[n]%MOD;
        ans = 1LL*ans*ifac[k-1]%MOD;
        cout<<"Case "<<caseno++<<": "<<ans<<endl;
    }
    return 0;
}
