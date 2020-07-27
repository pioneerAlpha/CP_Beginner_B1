#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)1e5 + 5)
#define MAX ((int)1e9 + 5)
#define MAXL ((ll)1e18 + 5)
#define MOD ((int)7901 + 0)
#define thr (1e-10)


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int arr[N] , b[N] , c[N];

ll cost(int n, int val)
{
    ll ans = 0 , tot = 0;
    vector < pair < int , int > > vec;
    for(int i = 1  ; i<=n ; i++){
        if(arr[i] > val){
            ans += 1LL*(arr[i] - val)*b[i];
            tot += arr[i] - val;
        }
        if(arr[i] < val) vec.push_back({c[i],arr[i]});
    }
    sort(vec.begin(),vec.end());
    for(auto p:vec){
        int cur = p.second , pay = p.first;
        if(tot >= cur){
            tot -= cur;
            ans += 1LL*cur*pay;
        }
        else{
            ans += 1LL*tot*pay;
            tot = 0;
        }
    }

    if(tot>0) return MAXL;
    else return ans;

}

int main()
{
    fastio;

    int n , l = 0 , r = 0;
    ll tot;

    cin>>n>>tot;

    for(int i = 1 ; i<=n ; i++){
        cin>>arr[i]>>b[i]>>c[i];
        r = max( r , arr[i] );
    }

    while(l<r){
        int mid = (l+r)/2;
        if(cost(n,mid) <= tot) r = mid;
        else l = mid+1;
    }

    cout<<r<<endl;

    return 0;
}
