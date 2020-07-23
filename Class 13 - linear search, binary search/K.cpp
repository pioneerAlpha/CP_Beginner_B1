/// problem: given an array of integers and some queries, in each query you are given an integer and asked if the integer exists in the array.

#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(2e5 + 5))
#define MAX ((int)(1e9 + 5))
#define MOD ((int)(7901 + 0))


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

ll cost(int val , int arr[] , int med , int n)
{
    ll ans = 0;
    for(int i = med ; i<=n ; i++){
        if(arr[i] < val) ans += val - arr[i];
    }
    return ans;
}

int arr[N];

int main()
{
    fastio;
    int n , k;
    cin>>n>>k;
    for(int i = 1 ; i<=n ;  i++) cin>>arr[i];
    sort(arr+1,arr+n+1);
    int med = (n+1)/2;
    int l = arr[med] , r = 2e9;
    while(l<r){
        int mid = (1+r-l)/2 + l;
        if(cost(mid,arr,med,n) <= k) l = mid;
        else r = mid-1;
    }
    cout<<l<<endl;
    return 0;
}
