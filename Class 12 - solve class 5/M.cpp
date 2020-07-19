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



int arr[N];
vector < int > v;
bool cmp(int a , int b)
{
    return a>b;
}
int main()
{
    fastio;
    int n, k;
    cin>>n>>k;
    for(int i = 1; i<=n; i++) cin>>arr[i];
    ll ans = 0;
    for(int i = 2; i<=n; i++){
        v.push_back(arr[i]-arr[i-1]);
        ans += arr[i] - arr[i-1];
    }
    sort(v.begin(),v.end(),cmp);
    for(int a:v){
        if(k == 1) break;
        k--;
        ans -= a;
    }
    cout<<ans<<endl;
    return 0;
}
