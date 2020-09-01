#include<bits/stdc++.h>
#define ll long long
#define N ((int)2e3 + 5)
#define MOD ((int)1e8 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int dpp[52][1002] , arr[55] , cnt[55] , n;

int call(int idx , int sum)
{
    if(sum < 0) return 0;
    if(sum == 0) return 1;
    if(idx > n) return 0;
    if(dpp[idx][sum] != -1) return dpp[idx][sum];
    int ans = 0;
    for(int i = 0 ; i<=cnt[idx] ; i++){
        ans = (ans + call(idx+1,sum - arr[idx]*i)) % MOD;
    }
    return dpp[idx][sum] = ans;
}

int main()
{
//    freopen("tour.in","r",stdin);
//    freopen("tour.out","w",stdout);
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int k;
        cin>>n>>k;
        for(int i = 1 ; i<=n ; i++){
            cin>>arr[i];
        }
        for(int i = 1 ; i<=n ; i++){
            cin>>cnt[i];
        }
        memset(dpp,-1,sizeof dpp);
        cout<<"Case "<<caseno++<<": "<<call(1,k)<<endl;
    }
    return 0;
}
