#include<bits/stdc++.h>
#define N ((int)2e5 + 5)
#define MOD ((int)1e9 + 7)
#define ll long long
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAX ((int)1e6 + 5)
#define endl "\n"

using namespace std;

int arr[N] , cnt[N];

int fun(int gap , int n)
{
    int ans = 0 , cur = 1;
    for(int i = 1 ; i<=n ; i++){
        if(arr[i] >= cur){
            cur = gap + arr[i];
            ans++;
        }
    }
    return ans;
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n , c;
        cin>>n>>c;
        for(int i = 1 ; i<=n ; i++) cin>>arr[i];
        sort(arr+1,arr+n+1);
        int lef = 0 , rig = arr[n];
        while(lef < rig){
            int mid = (lef + rig + 1) >> 1;
            if(fun(mid , n) >= c) lef = mid;
            else rig = mid-1;
        }
        cout<<lef<<endl;
    }
    return 0;
}
