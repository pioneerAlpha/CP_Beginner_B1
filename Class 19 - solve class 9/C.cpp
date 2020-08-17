#include<bits/stdc++.h>
#define ll long long
#define N ((int)5e3 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)


using namespace std;

int dis[2][N];  /// dis[0][i] = shortest path of i
                /// dis[1][i] = 2nd best shortest path of i

bool vis[2][N];

vector < pair < int,int > > vec[N];

void dijkstra(int src, int n)
{
    for(int i = 1 ; i<=n ; i++){
        dis[0][i] = dis[1][i] = MAX;
        vis[0][i] = vis[1][i] = 0;
    }
    dis[0][src] = 0;
    priority_queue < pair < int , pair < bool , int > > > pqq;
    pqq.push({0,{0,src}});
    while(!pqq.empty()){
        pair < int , pair < bool , int > > p = pqq.top();
        pqq.pop();
        int cur = p.second.second , stt = p.second.first;
        if(vis[stt][cur] == 1) continue;
        vis[stt][cur] = 1;
        for(auto p:vec[cur])
        {
            int b = p.first;
            int val = dis[stt][cur] + p.second;
            if(dis[1][b] > val && val > dis[0][b]){
                dis[1][b] = val;
                pqq.push({-val,{1,b}});
            }
            else if(dis[0][b] > val){
                dis[1][b] = dis[0][b];
                dis[0][b] = val;
                pqq.push({-val,{0,b}});
                pqq.push({-dis[1][b],{1,b}});
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
        int n, m;
        cin>>n>>m;

        for(int i = 1 ; i<=n ; i++) vec[i].clear();

        while(m--){
            int a , b , w;
            cin>>a>>b>>w;
            vec[a].push_back({b,w});
            vec[b].push_back({a,w});
        }

        dijkstra(1,n);

        cout<<"Case "<<caseno++<<": "<<dis[1][n]<<endl;
    }
    return 0;
}
