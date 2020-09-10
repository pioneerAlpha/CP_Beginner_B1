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

int arr[N] , dpp[N] , val[N] , nxt[N] , idx[N];

int main()
{

    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++) cin>>arr[i];
    memset(idx,-1,sizeof idx);
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
        nxt[i] = idx[rig-1];
        val[rig] = arr[i];
        idx[rig] = i;
    }
    int lis = 0 , last;
    for(int i = 1 ; i<=n ; i++){
        if(lis < dpp[i]){
            lis = dpp[i];
            last = i;
        }
    }
    vector < int > vec;
    while(last != -1){
        vec.push_back(last);
        last = nxt[last];
    }
    reverse(vec.begin(),vec.end());
    cout<<lis<<endl;
    for(int a:vec) cout<<arr[a]<<" ";
    cout<<endl;
    return 0;
}
