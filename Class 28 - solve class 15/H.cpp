#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
#define MOD ((int)1e8 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e10 + 7)
#define MAXP ((int)1e6 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int dpp[1005][2+(1<<10)] , n , arr[1005];

bool vis[2+(1<<10)];

int call(int idx , int val)
{
    if(idx > n){
        if(vis[val] == 1) return 0;
        else return 1;
    }
    if(dpp[idx][val] != -1) return dpp[idx][val];
    int ans ;
    ans = (call(idx+1,val) + call(idx+1,val^arr[idx]))%MOD;
    return dpp[idx][val] = ans;
}

int main()
{
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        memset(dpp,-1,sizeof dpp);
        memset(vis,0,sizeof vis);
        int m;
        cin>>n>>m;
        for(int i = 1 ; i<=n ; i++) cin>>arr[i];
        for(int i = 1 ; i<=m ; i++){
            int a;
            cin>>a;
            vis[a] = 1;
        }
        cout<<"Case "<<caseno++<<": "<<call(1,0)<<endl;
    }
    return 0;
}
