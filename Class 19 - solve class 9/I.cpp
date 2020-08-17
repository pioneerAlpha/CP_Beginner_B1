#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e4 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)


using namespace std;


vector < pair < int,int > > vec[2][N];  /// vec[0] = original graph , vec[1] = reverse graph

int dis[2][N] , u[N*5] , v[5*N] , cost[5*N];  /// dis[0] = distance from source in the original graph
/// dis[1] = distance from destination in the reverse graph

bool vis[2][N];


void dijkstra(int src, int idx , int n)
{
    for(int i = 1 ; i<=n ; i++){
        dis[idx][i] = MAX;
        vis[idx][i] = 0;
    }
    dis[idx][src] = 0;
    priority_queue < pair < int , int > > pqq;
    pqq.push({0,src});
    while(!pqq.empty()){
        pair < int , int > p = pqq.top();
        pqq.pop();
        int cur = p.second;
        if(vis[idx][cur] == 1) continue;
        vis[idx][cur] = 1;
        for(auto p:vec[idx][cur])
        {
            int b = p.first;
            int val = dis[idx][cur] + p.second;
            if(dis[idx][b] > val){
                dis[idx][b] = val;
                pqq.push({-val,b});
            }
        }
    }
}

int main()
{
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--)
    {
        int n, m , src, des, tot;
        cin>>n>>m>>src>>des>>tot;

        for(int i = 1 ; i<=n ; i++){
            vec[0][i].clear();
            vec[1][i].clear();
        }

        for(int i = 1 ; i<=m ; i++){
            int a , b , w;
            cin>>a>>b>>w;
            vec[0][a].push_back({b,w});
            vec[1][b].push_back({a,w});
            u[i] = a;
            v[i] = b;
            cost[i] = w;
        }

        dijkstra(src,0,n);
        dijkstra(des,1,n);

        int ans = -1;
        for(int i = 1 ; i<=m ; i++){
            int a = u[i] , b = v[i] , w = cost[i];
            int tmp = dis[0][a] + w + dis[1][b];
            if(tmp <= tot) ans = max(ans , w);
        }

        cout<<"Case "<<caseno++<<": "<<ans<<endl;
    }
    return 0;
}
