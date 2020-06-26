#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ll long long

using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/



int main()
{
    fastio;
    ll n;
    cin>>n;
    if(n&1) cout<<(n-1)/2 - n<<endl;
    else cout<<n/2<<endl;
    return 0;
}
