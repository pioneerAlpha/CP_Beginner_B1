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

vector < int > vec[N];

void bfs(int src)
{
    memset(dis,-1,sizeof dis);
    dis[src] = 0;
    queue < int > que;
    que.push(src);
    while(!que.empty()){
        int a = que.front();
        que.pop();
        ///for(int b:vec[a]){
        ///
        ///}

        for(int i = 0 ; i<vec[a].size() ; i++){
            int b = vec[a][i];
            if(dis[b] == -1){
                dis[b] = dis[a] + 1;
                que.push(b);
            }
        }
    }
}

/// O (n + m)

int main()
{

    int n , m;

    cin>>n>>m;

    while(m--){

        int a , b;

        cin>>a>>b;

        vec[a].push_back(b);
        vec[b].push_back(a);



    }

    bfs(1);
    return 0;
}
