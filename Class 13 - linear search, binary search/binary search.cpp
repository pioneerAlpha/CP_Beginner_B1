/// problem: given an array of integers and some queries, in each query you are given an integer and asked if the integer exists in the array.

#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(3e5 + 5))
#define MAX ((int)(1e9 + 5))
#define MOD ((int)(7901 + 0))


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/


bool src(int x , int arr[] , int l , int r)
{
    while(l<r){
        int mid = (l+r)/2;
        if(arr[mid]<x) l = mid+1;
        else r = mid;
    }
    if(arr[l] == x) return 1;
    return 0;
}

int arr[N];

int main()
{
    int n , q;
    cin>>n>>q;
    for(int i = 1 ; i<=n ;  i++) cin>>arr[i];
    sort(arr+1,arr+n+1);
    while(q--){
        int x;
        cin>>x;
        if(src(x,arr,1,n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
