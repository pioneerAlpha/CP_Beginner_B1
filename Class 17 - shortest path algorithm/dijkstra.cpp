#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)


using namespace std;

int dis[N];

bool vis[N];
vector < pair < int , int > > vec[N];

void dijkstra(int src, int n)
{
    for(int i = 1 ; i<=n ; i++){
        dis[i] = MAX;
        vis[i] = 0;
    }

    dis[src] = 0;
    priority_queue < pair < int , int > > prq; /// { dis , node }

    prq.push({0,src});


    while(!prq.empty()){
        pair < int , int > p = prq.top();
        prq.pop();
        int a = p.second;

        if(vis[a] == 1) continue;

        vis[a] = 1;

        for(int i = 0 ; i<vec[a].size() ; i++){
            int b = vec[a][i].first, c = vec[a][i].second;
            int val = dis[a] + c;
            if(dis[b] > val){
                dis[b] = val;
                prq.push({-dis[b],b});
            }
        }
    }
}

/// O ( m + m*log(m) )

int main()
{

    int n , m;

    cin>>n>>m;

    while(m--){

        int a , b , c;

        cin>>a>>b>>c;

        vec[a].push_back({b,c});
        vec[b].push_back({a,c});



    }

    dijkstra(1,n);
    return 0;
}
