/// problem link: https://csacademy.com/contest/archive/task/simple-paths

#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e3 + 5)
#define MOD ((int)1e9 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)


using namespace std;

vector < int > vec[N];  /// vec[i] = nodes adjacent to node 'i'

//vec[0] , vec[1] , vec[2] , vec[3] , vec[4]
//
//vec[2].push(3);
//vec[3].push(2);

bool vis[N] ; /// vis[i] = 0 is node 'i' is not visited

int nxt[N];


bool dfs(int n , int des)
{
    vis[n] = 1;

    if(n == des) return 1;

    for(int i = 0; i<vec[n].size() ; i++){
        int a = vec[n][i];
        if(vis[a] == 0){
            if(dfs(a,des)){
                nxt[n] = a;
                return 1;
            }
        }
    }
    return 0;
}

bool new_dfs(int n , int des , bool path) /// returns 1 if there is more than one simple path
{
    vis[n] = 1;

    if(n == des){
        if(path == 1) return 1;
        else return 0;
    }

    for(int i = 0 ; i<vec[n].size() ; i++){
        int a = vec[n][i];
        if(vis[a] == 0 && nxt[n] != a){
            if(new_dfs(a,des,1) == 1) return 1;  /// we set third parameter to 1 as we are going through a different path
        }
    }
    int a = nxt[n];
    if(vis[a] == 0) return new_dfs(a,des,path);  /// if path = 1 when we enter this function then it means
                                                ///we have used a different path before reaching n
                                                /// if path = 0 when we enter this function then it means
                                                /// we are on the same path as before
    else return 0;
}






int main()
{
    fastio;
    int n , m , q;
    cin>>n>>m>>q;

    for(int i = 1 ; i<=m ; i++){
        int a , b;
        cin>>a>>b;

        vec[a].push_back(b);
        vec[b].push_back(a);

    }

    while(q--){
        memset(vis,0,sizeof vis);
        memset(nxt,0,sizeof nxt);
        int x , y;
        cin>>x>>y;
        if(dfs(x,y) == 0){
            cout<<"0\n";   /// y can't be reached from x
            continue;
        }
        memset(vis,0,sizeof vis);
        if(new_dfs(x,y,0) == 1){    /// there are more than one simple path;
                                        ///third parameter shows if there is one or more simple path.
                                        /// at first we are assuming there is one simple path and so the parameter is 0.
                                        /// if we find more than one simple path it will be set to 1
            cout<<"0\n";
        }
        else cout<<"1\n";
    }

    return 0;

}
