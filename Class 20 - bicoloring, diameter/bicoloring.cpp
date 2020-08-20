#include<bits/stdc++.h>
#define ll long long
#define N ((int)3e5 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

vector < pair < int , int > > vec[N];

bool col[N] , vis[N];

bool dfs(int n, int val)
{
    vis[n] = 1;
    col[n] = val;
    for(auto p:vec[n]){
        int a = p.first , new_val = val^p.second;
        if(vis[a] == 0){
            if(dfs(a,new_val) == 0) return 0;
        }
        else{
            if(col[a] != new_val) return 0;
        }
    }
    return 1;
}


int main()
{
    fastio;
    int n , m;
    cin>>n>>m;

    while(m--){
        int a , b , c;
        cin>>a>>b>>c;   /// if(c == 0) we need to put a and b in the same group otherwise we need to put them in a different group
        vec[b].push_back({a,c});
        vec[a].push_back({b,c});
    }
    for(int i = 1 ; i<=n ; i++){
        if(vis[i] == 0){
            if(dfs(i,0) == 0){
                cout<<"impossible\n";
                return 0;
            }
        }
    }
    cout<<"possible\n";
    return 0;
}
