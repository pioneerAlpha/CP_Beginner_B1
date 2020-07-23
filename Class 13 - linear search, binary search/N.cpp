#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(2e3 + 5))
#define MAX ((int)(1e9 + 5))
#define MOD ((int)(7901 + 0))
#define thr (1e-8)


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int arr[N];

int main()
{
    //fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int n , ans = 0;
        cin>>n;
        for(int i = 1 ; i<=n ; i++) cin>>arr[i];
        sort(arr+1,arr+n+1);
        for(int i = 1 ; i<n ; i++){
            for(int j = i+1 ; j<n ; j++){
                int l = j , r = n;
                while(l<r){
                    int mid = (l+r+1)/2;
                    if(arr[mid]<arr[i]+arr[j]) l = mid;
                    else r = mid-1;
                }
                ans += l - j;
            }
        }
        cout<<"Case "<<caseno++<<": "<<ans<<endl;
    }
    return 0;
}
