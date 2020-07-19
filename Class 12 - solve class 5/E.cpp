#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(4e2 + 5))
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
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        n = n*4;
        for(int i = 1 ; i<=n ; i++) cin>>arr[i];
        sort(arr+1,arr+n+1);
        int val = arr[1]*arr[n];
        bool flag = 1;
        for(int i = 1 ; i<=n ; i += 2){
            if(arr[i] != arr[i+1] || arr[i]*arr[n-i+1] != val){
                flag = 0;
                break;
            }

        }

        if(flag) cout<<"YES\n";
        else cout<<"NO\n";

    }
    return 0;
}
