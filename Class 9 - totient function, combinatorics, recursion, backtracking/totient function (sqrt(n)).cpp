#include<bits/stdc++.h>
#define ll long long

using namespace std;

/// calculate phi for a given number (given number <= 1e12)

int main()
{
    ll n;
    cin>>n;
    ll ans = n;
    /// phi ( n ) = n*(p-1)/p * (q-1)/q * (r-1)/r  where n has prime factor p , q , r;
    vector < ll > prime ; /// this vector stores all the prime number from 1 to sqrt(n) (  that is 1e6 at most )
    for(ll p:prime){
        if(p*p>n) break;
        if(n%p == 0){
            ans /= p;
            ans *= p-1;
            while(n%p == 0) n /= p;
        }
    }
    if(n>1){
        ans /= n;
        ans *= n-1;
    }
    cout<<ans<<endl;
    /// complexity : O(sqrt(n))
    return 0;
}
