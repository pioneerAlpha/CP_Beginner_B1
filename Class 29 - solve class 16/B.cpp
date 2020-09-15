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

int dpp[16][2+(1<<15)] , arr[16] , c[16] , n;

int call(int pre , int idx , int mask)
{
    if(mask == 0) return 0;
    if(dpp[pre][mask] != -1) return dpp[pre][mask];
    int ans = MAX;
    for(int i = 0 ; i<n ; i++){
        if((mask&(1<<i)) != 0){
            int tmp = mask^(1<<i);
            int val = call(i,idx+1,tmp);
            if(idx > 0) val += abs(arr[i]-arr[pre])*c[idx];
            ans = min(ans , val);
        }
    }
    return dpp[pre][mask] = ans;
}

int main()
{
    fastio;

    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0 ; i<n ; i++) cin>>arr[i];
        for(int i = 0 ; i<n ; i++) cin>>c[i];
        memset(dpp,-1,sizeof dpp);
        cout<<call(0,0,(1<<n)-1)<<endl;
    }
    return 0;
}
