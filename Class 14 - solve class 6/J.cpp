#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)1e5 + 5)
#define MAX ((int)1e9 + 5)
#define MAXL ((ll)1e18 + 5)
#define MOD ((int)7901 + 0)
#define thr (1e-10)


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int arr[N];


int main()
{
    fastio;
    int n;
    cin>>n;

    for(int i = 1 ; i<=n ; i++){
        cin>>arr[i];
        arr[i] += arr[i-1];
    }

    if(arr[n] % 3 != 0){
        cout<<"0\n";
        return 0;
    }
    int cnt = 0;
    ll ans = 0;
    for(int i = n-1 ; i>0 ; i--){
        if(arr[i] == arr[n]/3) ans += cnt;
        if(arr[i] == (arr[n]/3)*2) cnt++;
    }

    cout<<ans<<endl;
    return 0;
}
