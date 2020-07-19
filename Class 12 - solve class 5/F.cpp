#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(1e5 + 5))
#define MAX ((int)(1e9 + 5))
#define MOD ((int)(7901 + 0))


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int arr[N];

int main()
{
    int t;
    t = 1;
    while(t--){
        int n;
        cin>>n;
        for(int i = 1 ; i<=n ; i++) cin>>arr[i];
        sort(arr+1,arr+n+1);
        if(arr[n] >= arr[n-1] + arr[n-2]) cout<<"NO\n";
        else{
            cout<<"YES\n";
            cout<<arr[n-1]<<" "<<arr[n]<<" ";
            for(int i = n-2 ; i>0; i--) cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
