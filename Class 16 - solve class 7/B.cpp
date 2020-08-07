#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e3 + 5)
#define MOD ((int)1e9 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)


using namespace std;

int cnt[102] , vis[102] , arr[102];

int main()
{
    fastio;
    int caseno = 1 , t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(vis,0,sizeof vis);
        memset(cnt,0,sizeof cnt);
        for(int i = 1 ; i<=n+n ; i++){
            cin>>arr[i];
            vis[arr[i]] = !vis[arr[i]];
            if(vis[arr[i]]){
                for(int j = i-1 ; j>0 ; j--){
                    if(vis[arr[j]] == 1){
                        cnt[arr[j]]++;
                        break;
                    }
                }
            }
        }
        cout<<"Case "<<caseno++<<":\n";
        for(int i = 1 ; i<=n ; i++){
            cout<<i<<" -> "<<cnt[i]<<endl;
        }
    }
    return 0;
}
