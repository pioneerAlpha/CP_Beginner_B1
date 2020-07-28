#include<bits/stdc++.h>
#define ll long long
#define N ((int)2e6 + 5)
#define MOD ((int)1e9 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )

using namespace std;


vector < int > vec[N] , aux[N];  /// vec[i] = nodes adjacent to node 'i'

//vec[0] , vec[1] , vec[2] , vec[3] , vec[4]
//
//vec[2].push(3);
//vec[3].push(2);

bool vis[N] , new_vis[N]; /// vis[i] = 0 is node 'i' is not visited
int cnt;

int com[N]; /// com[i] = size of the component of node 'i'

void dfs(int n)
{
    vis[n] = 1;
    cnt++;
    for(int i = 0; i<aux[n].size() ; i++){
        int a = aux[n][i];
        if(vis[a] == 0){
            dfs(a);
        }
    }
}


void new_dfs(int n)
{
    new_vis[n] = 1;
    com[n] = cnt;
    for(int i = 0; i<aux[n].size() ; i++){
        int a = aux[n][i];
        if(new_vis[a] == 0){
            new_dfs(a);
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
        cin>>a>>b; /// a->b

        vec[a].push_back(b);

        aux[a].push_back(b);
        aux[b].push_back(a);

    }

    int cc = 0;

    for(int i = 1 ; i<=n ; i++){
        if(vis[i] == 0){
            cnt = 0;
            dfs(i);
            cc++;
            new_dfs(i);

        }
    }

    return 0;


}
