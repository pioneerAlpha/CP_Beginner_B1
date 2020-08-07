#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
#define MOD ((int)1e9 + 7)
#define MAXP ((int)2e6 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)


using namespace std;

map < pair < int , int > , int > edg;

vector < int > vec[N];

int dfs(int n , int pre)
{
    if(n == 1) return 0;
    for(int a:vec[n]){
        if( a != pre ) return edg[{a,n}] + dfs(a,n);
    }
}

int main()
{
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 1 ; i<=n ; i++) vec[i].clear();
        edg.clear();
        for(int i = 1 ; i<=n ; i++){
            int a , b , c;
            cin>>a>>b>>c;
            edg[{a,b}] = c;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        int ans = 1e5;
        for(int a:vec[1]){
            ans = min(ans , edg[{a,1}] + dfs(a,1));
        }
        cout<<"Case "<<caseno++<<": "<<ans<<endl;
    }
    return 0;
}
