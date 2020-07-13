#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(2e5 + 5))
#define MOD ((int)(1e9 + 7))


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int fac[N] , ifac[N];

int power(int n , int p)
{
    if(p == 0) return 1;
    int ans = power(n , p/2);
    ans = 1LL*ans*ans%MOD;
    if(p%2 == 1) ans = 1LL*ans*n%MOD;
    return ans;
}

int main()
{
    fac[0] = 1;
    for(int i = 1 ; i<N ; i++) fac[i] = 1LL*i*fac[i-1]%MOD;

    ifac[N-1] = power(fac[N-1] , MOD-2);
    for(int i = N-2 ; i>=0 ; i--) ifac[i] = 1LL*(i+1)*ifac[i+1]%MOD;
    fastio;
    int n , c, r , sum = 0;
    cin>>n>>c>>r;
    for(int i = 1 ; i<=n ; i++){
        int rem = max(0,r - (i - 1));
        int last = n-rem;
        ll tot = last - i + 1;
        //cout<<tot<<" ";
        tot = tot - 1LL*(c-1)*(r+1) - 1;
        //cout<<tot<<endl;
        if(tot < 0){
            if(i == 1){
                cout<<"-1\n";
                return 0;
            }
            break;
        }
        int ans = 1LL*fac[tot+c-1]*ifac[tot]%MOD;
        ans = 1LL*ans*ifac[c-1]%MOD;
        sum += ans;
        if(sum >= MOD) sum -= MOD;
    }
    sum = 1LL*sum*(n-c)%MOD;
    cout<<sum<<endl;
    return 0;
}
