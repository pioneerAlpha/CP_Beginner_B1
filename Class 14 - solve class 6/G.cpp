#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)2e5 + 5)
#define MAX ((int)1e9 + 5)
#define MAXL ((ll)1e18 + 5)
#define MOD ((int)7901 + 0)
#define thr (1e-10)


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int arr[N];


int main()
{
    fastio;
    int n;
    cin>>n;

    for(int i = 1 ; i<=n ; i++){
        cin>>arr[i];
    }

    sort(arr+1,arr+n+1);

    int l = 0 , r = 1e9;
    while(l<r){
        int mid = (l+r)/2;
        int cur = 0 , cnt = 0;
        for(int i = 1 ; i<=n ; i++){
            if(arr[i] > cur){
                cur = arr[i] + mid;
                cnt++;
            }
        }

        if(cnt > 3) l = mid+1;
        else r = mid;

    }

    cout<<setprecision(1)<<fixed;

    cout<<(double)l/2.0<<endl;
    int cur = 0 , cnt = 0;
    for(int i = 1 ; i<=n ; i++){
        if(arr[i] > cur){
            cout<<(double)arr[i] + l/2.0<<" ";
            cur = arr[i] + l;
            cnt++;
        }
    }

    while(cnt < 3){
        cnt++;
        cout<<"0 ";
    }

    return 0;
}
