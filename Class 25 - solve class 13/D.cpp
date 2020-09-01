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

int dpp[102][10002] , arr[105];

//int call(int idx , int sum)
//{
//    if(sum < 0) return 0;
//    if(sum == 0) return 1;
//    if(idx > n) return 0;
//    if(dpp[idx][sum] != -1) return dpp[idx][sum];
//    int ans = call(idx+1,sum) + call(idx,sum-arr[idx]) ;
//    if(ans >= MOD) ans -= MOD;
//    return dpp[idx][sum] = ans;
//}

int main()
{
//    freopen("tour.in","r",stdin);
//    freopen("tour.out","w",stdout);
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int n , k;
        cin>>n>>k;
        for(int i = 1 ; i<=n ; i++){
            cin>>arr[i];
        }
        for(int sum = 1 ; sum <= k ; sum++) dpp[n+1][sum] = 0;
        dpp[n+1][0] = 1;
        for(int idx = n ; idx > 0 ; idx--){
            dpp[idx][0] = 1;
            for(int sum = 1 ; sum <= k ; sum++){
                int ans = dpp[idx+1][sum];
                if(sum - arr[idx] >= 0){
                    ans += dpp[idx][sum-arr[idx]];
                    if(ans >= MOD) ans -= MOD;
                }
                dpp[idx][sum] = ans;
            }
        }

        cout<<"Case "<<caseno++<<": "<<dpp[1][k]<<endl;
    }
    return 0;
}
