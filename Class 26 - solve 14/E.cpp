/// this code will not give "TLE" verdict but it gives "MLE" verdict
/// i will discuss a trick to reduce the memory of this dp

#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
#define MOD ((int)1e8 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int arr[105] , cnt[105] , dpp[105][N] , from[N] ;


int main()
{
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int n , m;
        cin>>n>>m;
        for(int i = 1 ; i<=n ; i++) cin>>arr[i];
        for(int i = 1 ; i<=n ; i++) cin>>cnt[i];
        dpp[n+1][0] = 1;
        for(int i = 1 ; i<=m ; i++){
            dpp[n+1][i] = 0;
        }
        for(int idx = n ; idx>0 ; idx--){
            for(int val = 0 ; val <= m ; val++){
                bool ans = 0;
                int pnt = -MAX;
                if(dpp[idx+1][val] == 1){
                    ans = 1;
                    pnt = val;
                }
                else{
                    int pre = val - arr[idx];
                    if(pre >= 0){
                        if(dpp[idx][pre] == 1){
                            pnt = from[pre];
                            if((val - pnt)/arr[idx] <= cnt[idx]){
                                ans = 1;
                            }
                            else pnt = -MAX;
                        }
                    }
                    else{
                        for(int i = 0 ; i<=cnt[idx] ; i++){
                            if(val - i*arr[idx] < 0) break;
                            ans = ans | dpp[idx+1][val - i*arr[idx]];
                            if(ans == 1){
                                pnt = val - i*arr[idx];
                                break;
                            }
                        }
                    }
                }
                dpp[idx][val] = ans;
                from[val] = pnt;
            }


        }
        int ans = 0;
        for(int i = 1 ; i<=m ; i++) if(dpp[1][i]) ans++;
        cout<<"Case "<<caseno++<<": "<<ans<<endl;
    }
    return 0;
}
