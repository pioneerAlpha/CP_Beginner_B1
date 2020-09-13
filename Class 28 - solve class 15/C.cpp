#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e6 + 5)
#define MOD ((int)1e8 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e10 + 7)
#define MAXP ((int)1e6 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int arr[N] , dpp[N] , val[N];

int main()
{
    int tc;
    cin >> tc;
    
    while(tc--){
    
    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++) cin>>arr[i];
    int q;
    cin >> q;
  
    val[0] = -MAX;
    for(int i = 1 ; i<=n ; i++) val[i] = MAX;
    for(int i = 1 ; i<=n ; i++){

        int lef = 0 , rig = n;
        while(lef < rig){
            int mid = (lef + rig)>>1;
            if(val[mid] < arr[i]) lef = mid+1;
            else rig = mid;
        }
        dpp[i] = rig;
        val[rig] = arr[i];
    }
    int ans = MAX;
    for(int i = 1; i <= n ; i++){
      if(dpp[i] >= q) ans = min(ans , arr[i]);
    } 
    if(ans == MAX) ans = -1;
    cout<<ans<<endl;
  }

  return 0;
}
