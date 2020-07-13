#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(1e5 + 5))
#define MOD ((int)(1e9 + 7))


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int arr[N] , cum[N];

int main()
{
    fastio;
    int n ,q;
    cin>>n>>q;
    for(int i = 1 ; i<=n ; i++){
        int a;
        cin>>a;
        if(a == 3 || a==4 || a==6) arr[i] = 1;
    }
    cum[0] = arr[0];
    for(int i = 1 ; i<=n ; i++) cum[i] = cum[i-1] + arr[i];
    while(q--){
        int l , r;
        cin>>l>>r;
        cout<<cum[r]-cum[l-1]<<endl;
    }
    return 0;
}
