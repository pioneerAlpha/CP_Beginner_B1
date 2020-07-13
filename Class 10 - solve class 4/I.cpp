#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(1e7 + 5))
#define MOD ((int)(1e9 + 7))
 
using namespace std;
 
 
/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/
 
int fun(int a , int b)
{
    if(a<b) swap(a,b);
    if(b == 1) return a - 1;
    if(b == 0) return MAX;
    return a/b + fun(b,a%b);
}
 
int main()
{
    fastio;
    int n;
    cin>>n;
    int ans = n-1;
    for(int i = n-1 ; i>0 ; i--){
        ans = min(ans , fun(n,i));
    }
    cout<<ans<<endl;
    return 0;
}
