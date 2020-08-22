#include<bits/stdc++.h>
#define ll long long
#define N ((int)2e5 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

vector < int > vec[N];

bool col[N] , vis[N];

int u[N] , v[N];

bool dfs(int n , int val)
{
    vis[n] = 1;
    col[n] = val;
    val = !val;
    for(int a:vec[n]){
        if(vis[a] == 0){
            if(dfs(a,val) == 0) return 0;
        }
        else if(col[a] != val) return 0;
    }
    return 1;
}

int main()
{
    fastio;
    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++){
        int a , b;
        cin>>a>>b;
        vec[b].push_back(a);
        vec[a].push_back(b);

        u[i] = a;
        v[i] = b;

        vec[2*i-1].push_back(2*i);
        vec[2*i].push_back(2*i-1);
    }

    for(int i = 1 ; i<=n+n ; i++){
        if(vis[i] == 0){
            if(dfs(i,0) == 0){
                cout<<"-1\n";
                return 0;
            }
        }
    }

    for(int i = 1 ; i<=n ; i++){
        cout<<col[u[i]]+1<<" "<<col[v[i]]+1<<endl;
    }

    return 0;
}
