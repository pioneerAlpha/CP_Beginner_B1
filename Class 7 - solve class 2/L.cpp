#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(1e5 + 5))

using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/


ll gcd(ll a , ll b)
{
    if(a>b) swap(a,b);
    while(a != 0){
        ll mod = b%a;
        b = a;
        a = mod;
    }
    return b;
}

ll lcm(ll a , ll b)
{
    return (a/gcd(a,b))*b;
}

int main()
{
    fastio;
    int t;
    t = 1;
    while(t--){
        ll n;
        cin>>n;
        ll ans = 1;
        for(int i = 2 ; i<=10 ; i++) ans = lcm(ans,i);
        ans = n/ans;
        cout<<ans<<endl;
    }
    return 0;
}
