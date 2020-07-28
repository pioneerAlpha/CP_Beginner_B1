#include<bits/stdc++.h>
#define ll long long
#define N ((int)2e6 + 5)
#define MOD ((int)1e9 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )

using namespace std;

int u[N] , v[N] , adj[N][N];  /// N*N ;  N<=2000

pair < int , int > edg[N];

vector < int > vec[N] ;  /// vec[i] = nodes adjacent to node 'i'

//vec[0] , vec[1] , vec[2] , vec[3] , vec[4]
//
//vec[2].push(3);
//vec[3].push(2);



int main()
{
    int n , m;
    cin>>n>>m;
    for(int i = 1 ; i<=n; i++) vis[i] = 0;
    for(int i = 1 ; i<=m ; i++){
        int a , b;
        cin>>a>>b;
        u[i] = a;
        v[i] = b;

        edg[i] = make_pair(a,b);
        edg[i] = {a,b};

        adj[a][b] = adj[b][a] = 1;

        vec[a].push_back(b);  /// a = 1 , b = 3 ; vec[1].push_back(3)
        vec[b].push_back(a);  ///  vec[3].push_back(1)


    }
    
    return 0;


}
