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


double dpp[20][2+(1<<18)] , arr[20][20];

bool vis[20][2+(1<<18)];

int n ;

double call(int win , int mask)
{
    if(mask == 0){
        if(win == 0) return 1; /// because i am the last person standing
        return 0;
    }

    if(vis[win][mask]  == 1) return dpp[win][mask];
    vis[win][mask] = 1;

    double ans = 0;
    for(int i = 0 ; i<n ; i++){
        if((mask&(1<<i)) != 0){
            int mask1 = mask^(1<<i);
            double tmp = call(win,mask1)*arr[win][i] + call(i,mask1)*arr[i][win];
            ans = max(ans , tmp);
        }
    }
    return dpp[win][mask] = ans;
}

int main()
{
    fastio;

    cin>>n;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++) cin>>arr[i][j];
    }
    memset(vis,0,sizeof vis);
    double ans = 0;
    for(int i = 0 ; i<n ; i++){
        int mask = (1<<n)-1;
        mask ^= 1<<i;  /// choosing i-th person to start the match.
        ans = max(ans , call(i,mask));
    }
    cout<<setprecision(10)<<fixed;
    cout<<ans<<endl;
    return 0;
}
