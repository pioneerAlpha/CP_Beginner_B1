#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ll long long
#define endl "\n"

using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

/// gcd ( 0 , a ) = a

ll gcd(ll a , ll b)
{
    if(b<a) swap(a,b);
//    if(a == 0) return b;

    while(a > 0){
        ll mod = b%a;   /// mod<a
        b = a;
        a = mod;
    }

    return b;
}

long long lcm(ll a , ll b)
{
    long long ans = 1LL*a*b;
    ans = ans/gcd(a,b);
    return ans;
}

int main()
{
    int a, b;


    int n;
    cin>>n;

    int ans = 0 ;
    ll val = 1; /// val ( 1 , a ) = a

    for(int i = 1 ; i<=n ; i++){
        int a;
        cin>>a;
        val = a*val/__gcd(a,val);
        ans = __gcd(ans , a);
    }

    while(1){
        cin>>a>>b;
        cout<<gcd(a,b)<<" "<<__gcd(a,b)<<endl;
        cout<<val(a,b)<<endl;
    }
    return 0;
}
