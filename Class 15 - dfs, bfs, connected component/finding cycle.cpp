#include<bits/stdc++.h>
#define ll long long
#define N ((int)2e6 + 5)
#define MOD ((int)1e9 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )

using namespace std;

vector < int > vec[N];  /// vec[i] = nodes adjacent to node 'i'

//vec[0] , vec[1] , vec[2] , vec[3] , vec[4]
//
//vec[2].push(3);
//vec[3].push(2);

bool vis[N] ; /// vis[i] = 0 is node 'i' is not visited


void dfs(int n , int par)
{
    vis[n] = 1;

    for(int i = 0; i<vec[n].size() ; i++){
        int a = vec[n][i];
        if(vis[a] == 0){
            dfs(a);
        }
        else{
            if(a != par){
                cout<<"cycle\n";
            }
        }
    }
}






int main()
{
    int n , m;
    cin>>n>>m;
    for(int i = 1 ; i<=n; i++) vis[i] = 0;
    for(int i = 1 ; i<=m ; i++){
        int a , b;
        cin>>a>>b;

        vec[a].push_back(b);
        vec[b].push_back(a);

    }

    dfs(1,-1);

    return 0;

}
