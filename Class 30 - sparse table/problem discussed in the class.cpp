/// problem link: https://codeforces.com/contest/1291/problem/C
#include<bits/stdc++.h>
#define ll long long
#define N ((int)35e2 + 5)
#define MOD ((int)1e8 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e10 + 7)
#define MAXP ((int)1e6 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int arr[N] , dpp[N][N] , m;

int call(int lef , int rig , int idx)
{
    if(dpp[lef][rig] != -1) return dpp[lef][rig];
    if(idx == m) return dpp[lef][rig] = max(arr[lef],arr[rig]);
    int ans = min(call(lef+1,rig,idx+1),call(lef,rig-1,idx+1));
    return dpp[lef][rig] = ans;
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n ,k;
        cin>>n>>m>>k;
        for(int i = 1 ; i<=n ; i++) cin>>arr[i];
        for(int i = 1 ; i<=n ; i++){
            for(int j = i ; j<=n ; j++) dpp[i][j] = -1;
        }
        int ans = 0;
        for(int i = 0 ; i<=min(k,m-1) ; i++){
            for(int j = 0 ; j<=i ; j++) ans = max(ans , call(j+1,n-i+j,i+1));
        }
        cout<<ans<<endl;
    }
    return 0;
}
