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

bool vis[N]; /// vis[i] = 0 is node 'i' is not visited

int lev[N];

void bfs(int n)
{
    queue < int > que;
    que.push(n);
    lev[n] = 0;
    vis[n] = 1;
    while(!que.empty()){
        int a = que.front();
        que.pop();
        for(int i = 0 ; i<vec[a].size() ; i++){
            int b = vec[a][i];
            if(vis[b] == 0){
                que.push(b);
                vis[b] = 1;
                lev[b] = lev[a] + 1;
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
        vec[a].push_back(b);  /// a = 1 , b = 3 ; vec[1].push_back(3)
        vec[b].push_back(a);  /// vec[3].push_back(1)

    }

    bfs(1);
    
    return 0;



}
