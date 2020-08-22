#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
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

int col[N] , con[N] , arr[N];

bool vis[N];

bool dfs(int nod)
{
    vis[nod] = 1;
    for(auto p:vec[nod]){
        int a = p.first , val = col[nod]^p.second;
        if(vis[a] == 0){
            col[a] = val;
            if(!dfs(a)) return 0;
        }
        else if(col[a] != val) return 0;
    }
    return 1;
}


int main()
{
//    freopen("tour.in","r",stdin);
//    freopen("tour.out","w",stdout);
    fastio;
    int n , m;
    cin>>n>>m;
    for(int i = 1 ; i <= n ; i++){
        cin>>con[i];
        con[i] = !con[i];
    }
    for(int i = 1 ; i <= m ; i++){
        int a;
        cin>>a;
        while(a--){
            int b;
            cin>>b;
            if(arr[b] == 0) arr[b] = i;
            else{
                int c = arr[b];
                vec[i].push_back({c,con[b]});
                vec[c].push_back({i,con[b]});
            }
        }
    }

    for(int i = 1 ; i<=m ; i++){
        if(vis[i] == 0){
            col[i] = 0;
            if(!dfs(i)){
                cout<<"NO\n";
                return 0;
            }
        }
    }

    cout<<"YES\n";
    return 0;
}
