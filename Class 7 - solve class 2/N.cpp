#include<bits/stdc++.h>
#define N ((int)2e5 + 5)
#define MOD ((int)1e9 + 7)
#define ll long long
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAX ((int)1e6 + 5)
#define endl "\n"

using namespace std;

int arr[N] , cnt[N];


int main()
{
    fastio;
    int n , x;
    cin>>n>>x;
    for(int i = 1 ; i<=n ; i++) cin>>arr[i];
    ll ans = 0;
    for(int i = n ; i>0 ; i--){
        int tmp = arr[i]^x;
        ans += cnt[tmp];
        cnt[arr[i]]++;
    }
    cout<<ans<<endl;
    return 0;
}
