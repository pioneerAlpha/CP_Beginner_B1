#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ll long long
#define endl "\n"
#define N ((int)(1e6 + 5))

using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int main()
{
    int n , m; /// m<=1e9 , n<=1e5
    cin>>n>>m;
    ll mul = 1%m;
    for(int i = 1 ; i<=n ; i++){
        ll a;
        cin>>a; /// a<=1e17
        a = a%m;
        mul = (mul*a)%m;
    }
    mul = mul%m;
    cout<<mul<<endl;
    return 0;
}
