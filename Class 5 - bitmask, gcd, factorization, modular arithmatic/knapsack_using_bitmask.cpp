#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ll long long
#define endl "\n"

using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

ll val[22] , wgh[22];


int main()
{
    fastio;
    int n ;
    cin>>n;
    for(int i = 0 ; i<n ; i++){
        cin>>val[i]>>wgh[i];
    }
    ll cap;
    cin>>cap;

    int tot = 1<<n;
    ll ans = 0;
    for(int mask = 0  ; mask < tot ; mask++){
        ll sum = 0 , value = 0;
        for(int i = 0 ; i<n ; i++){
            if((mask&(1<<i)) != 0){ /// mask = 01010 , 1<<3 = 1000
                sum += wgh[i];
                value += val[i];
            }
        }
        if(sum <= cap) ans = max(ans , value);
    }

    cout<<ans<<endl;


    return 0;
}
